#include <Eigen/Eigen>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "acados/utils/math.h"
#include "payload_model_model.h"
#include "acados_solver_payload_model.h"


#define NX      PAYLOAD_MODEL_NX
#define NZ      PAYLOAD_MODEL_NZ
#define NU      PAYLOAD_MODEL_NU
#define NP      PAYLOAD_MODEL_NP
#define NBX     PAYLOAD_MODEL_NBX
#define NBX0    PAYLOAD_MODEL_NBX0
#define NBU     PAYLOAD_MODEL_NBU
#define NSBX    PAYLOAD_MODEL_NSBX
#define NSBU    PAYLOAD_MODEL_NSBU
#define NSH     PAYLOAD_MODEL_NSH
#define NSH0    PAYLOAD_MODEL_NSH0
#define NSG     PAYLOAD_MODEL_NSG
#define NSPHI   PAYLOAD_MODEL_NSPHI
#define NSHN    PAYLOAD_MODEL_NSHN
#define NSGN    PAYLOAD_MODEL_NSGN
#define NSPHIN  PAYLOAD_MODEL_NSPHIN
#define NSPHI0  PAYLOAD_MODEL_NSPHI0
#define NSBXN   PAYLOAD_MODEL_NSBXN
#define NS      PAYLOAD_MODEL_NS
#define NS0     PAYLOAD_MODEL_NS0
#define NSN     PAYLOAD_MODEL_NSN
#define NG      PAYLOAD_MODEL_NG
#define NBXN    PAYLOAD_MODEL_NBXN
#define NGN     PAYLOAD_MODEL_NGN
#define NY0     PAYLOAD_MODEL_NY0
#define NY      PAYLOAD_MODEL_NY
#define NYN     PAYLOAD_MODEL_NYN
//#define N       PAYLOAD_MODEL_N
#define NH      PAYLOAD_MODEL_NH
#define NHN     PAYLOAD_MODEL_NHN
#define NH0     PAYLOAD_MODEL_NH0
#define NPHI0   PAYLOAD_MODEL_NPHI0
#define NPHI    PAYLOAD_MODEL_NPHI
#define NPHIN   PAYLOAD_MODEL_NPHIN
#define NR      PAYLOAD_MODEL_NR
const int N = PAYLOAD_MODEL_N;
namespace nmpc_control_nodelet
{
    static constexpr int kStateSize = PAYLOAD_MODEL_NX;
    static constexpr int kInputSize = PAYLOAD_MODEL_NU;
    static constexpr int kSamples = N;
    static constexpr int yRefSize = PAYLOAD_MODEL_NX + PAYLOAD_MODEL_NU;

    struct solver_output
    {
        // The Eigen Maps initialized in the class can directly change these values below
        // without worrying about transforming between matrices and arrays
        // the relevant sections of the arrays can then be passed to the solver
        double status, KKT_res, cpu_time;
        double u0[NU];
        double u1[NU];
        double x1[NX];
        double x2[NX];
        double x4[NX];
        double xi[NU];
        double ui[NU];
        double u_out[NU * (N)];
        double x_out[NX * (N)];


    };
    struct solver_input
    {
      double x0[NX];
      double x[NX * (N)];
      double u[NU * N];
      double yref[(NX + NU) * N];
      double yref_e[(NX + NU)];
      #if (NY > 0)
      
        double W[NY * NY];
      #endif 
      
      double WN[NX * NX];
    };

    extern solver_input acados_in;
    extern solver_output acados_out;

    class NMPCWrapper
    {
    public:
    NMPCWrapper();
    NMPCWrapper(const Eigen::VectorXd Q_, const Eigen::VectorXd R_,
              const Eigen::VectorXd lbu_, const Eigen::VectorXd ubu_);

    void setTrajectory(const Eigen::Ref<const Eigen::Matrix<double, kStateSize, kSamples>> states,
                       const Eigen::Ref<const Eigen::Matrix<double, kInputSize, kSamples>> inputs);
    
    bool prepare(const Eigen::Ref<const Eigen::Matrix<double, kStateSize, 1>> state);
    bool update(const Eigen::Ref<const Eigen::Matrix<double, kStateSize, 1>> state);
    void getStates(Eigen::Matrix<double, kStateSize, kSamples> &return_state);
    void getInputs(Eigen::Matrix<double, kInputSize, kSamples> &return_input);

    void setMass(double mass);
    void setGravity(double gravity);
    void initStates();

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    private:
    payload_model_solver_capsule *acados_ocp_capsule;
    ocp_nlp_in *nlp_in;
    ocp_nlp_out *nlp_out;
    //ocp_nlp_out *sens_out;
    ocp_nlp_solver *nlp_solver;
    void *nlp_opts;
    ocp_nlp_plan_t *nlp_solver_plan;
    ocp_nlp_config *nlp_config;
    ocp_nlp_dims *nlp_dims;
    double *new_time_steps;
    int status;
    double mass_;
    double gravity_;
    bool acados_is_prepared_{false};
    int acados_status;
    double *initial_state;

    Eigen::Map<Eigen::Matrix<double, yRefSize, kSamples, Eigen::ColMajor>> acados_reference_states_{acados_in.yref};
    Eigen::Map<Eigen::Matrix<double, kStateSize, 1, Eigen::ColMajor>> acados_initial_state_{acados_in.x0};
    Eigen::Map<Eigen::Matrix<double, yRefSize, 1, Eigen::ColMajor>> acados_reference_end_state_{acados_in.yref_e};
    Eigen::Map<Eigen::Matrix<double, kStateSize, kSamples, Eigen::ColMajor>> acados_states_in_{acados_in.x};
    Eigen::Map<Eigen::Matrix<double, kInputSize, kSamples, Eigen::ColMajor>> acados_inputs_in_{acados_in.u};
    Eigen::Map<Eigen::Matrix<double, kStateSize, kSamples, Eigen::ColMajor>> acados_states_{acados_out.x_out};
    Eigen::Map<Eigen::Matrix<double, kInputSize, kSamples, Eigen::ColMajor>> acados_inputs_{acados_out.u_out};
    Eigen::Matrix<real_t, kInputSize, 1> kHoverInput_ = (Eigen::Matrix<real_t, kInputSize, 1>() << 0,0,0,  0,0,0, 0,0,0.0).finished();
    };

}// namespace control nodelet ends here