/*
 * Copyright (c) The acados authors.
 *
 * This file is part of acados.
 *
 * The 2-Clause BSD License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.;
 */


// standard
#include <stdio.h>
#include <stdlib.h>
// acados
#include "acados/utils/print.h"
#include "acados/utils/math.h"
#include "acados_c/ocp_nlp_interface.h"
#include "acados_c/external_function_interface.h"
#include "acados_solver_payload_model.h"

// blasfeo
#include "blasfeo_d_aux_ext_dep.h"

#define NX     PAYLOAD_MODEL_NX
#define NP     PAYLOAD_MODEL_NP
#define NU     PAYLOAD_MODEL_NU
#define NBX0   PAYLOAD_MODEL_NBX0
#define NP_GLOBAL   PAYLOAD_MODEL_NP_GLOBAL


int main()
{

    payload_model_solver_capsule *acados_ocp_capsule = payload_model_acados_create_capsule();
    // there is an opportunity to change the number of shooting intervals in C without new code generation
    int N = PAYLOAD_MODEL_N;
    // allocate the array and fill it accordingly
    double* new_time_steps = NULL;
    int status = payload_model_acados_create_with_discretization(acados_ocp_capsule, N, new_time_steps);

    if (status)
    {
        printf("payload_model_acados_create() returned status %d. Exiting.\n", status);
        exit(1);
    }

    ocp_nlp_config *nlp_config = payload_model_acados_get_nlp_config(acados_ocp_capsule);
    ocp_nlp_dims *nlp_dims = payload_model_acados_get_nlp_dims(acados_ocp_capsule);
    ocp_nlp_in *nlp_in = payload_model_acados_get_nlp_in(acados_ocp_capsule);
    ocp_nlp_out *nlp_out = payload_model_acados_get_nlp_out(acados_ocp_capsule);
    ocp_nlp_solver *nlp_solver = payload_model_acados_get_nlp_solver(acados_ocp_capsule);
    void *nlp_opts = payload_model_acados_get_nlp_opts(acados_ocp_capsule);

    // initial condition
    double lbx0[NBX0];
    double ubx0[NBX0];
    lbx0[0] = 0;
    ubx0[0] = 0;
    lbx0[1] = 0;
    ubx0[1] = 0;
    lbx0[2] = 0;
    ubx0[2] = 0;
    lbx0[3] = 0;
    ubx0[3] = 0;
    lbx0[4] = 0;
    ubx0[4] = 0;
    lbx0[5] = 0;
    ubx0[5] = 0;
    lbx0[6] = 0;
    ubx0[6] = 0;
    lbx0[7] = 0;
    ubx0[7] = 0;
    lbx0[8] = 0;
    ubx0[8] = 0;
    lbx0[9] = 0;
    ubx0[9] = 0;
    lbx0[10] = 0;
    ubx0[10] = 0;
    lbx0[11] = 0;
    ubx0[11] = 0;
    lbx0[12] = 0;
    ubx0[12] = 0;

    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "lbx", lbx0);
    ocp_nlp_constraints_model_set(nlp_config, nlp_dims, nlp_in, 0, "ubx", ubx0);

    // initialization for state values
    double x_init[NX];
    x_init[0] = 0.0;
    x_init[1] = 0.0;
    x_init[2] = 0.0;
    x_init[3] = 0.0;
    x_init[4] = 0.0;
    x_init[5] = 0.0;
    x_init[6] = 0.0;
    x_init[7] = 0.0;
    x_init[8] = 0.0;
    x_init[9] = 0.0;
    x_init[10] = 0.0;
    x_init[11] = 0.0;
    x_init[12] = 0.0;

    // initial value for control input
    double u0[NU];
    u0[0] = 0.0;
    u0[1] = 0.0;
    u0[2] = 0.0;
    u0[3] = 0.0;
    u0[4] = 0.0;
    u0[5] = 0.0;
    u0[6] = 0.0;
    u0[7] = 0.0;
    u0[8] = 0.0;
    u0[9] = 0.0;
    u0[10] = 0.0;
    u0[11] = 0.0;
    u0[12] = 0.0;
    u0[13] = 0.0;
    u0[14] = 0.0;
    u0[15] = 0.0;
    u0[16] = 0.0;
    u0[17] = 0.0;
    u0[18] = 0.0;
    u0[19] = 0.0;
    u0[20] = 0.0;
    u0[21] = 0.0;
    u0[22] = 0.0;
    u0[23] = 0.0;
    u0[24] = 0.0;
    u0[25] = 0.0;
    u0[26] = 0.0;
    u0[27] = 0.0;
    u0[28] = 0.0;
    u0[29] = 0.0;
    u0[30] = 0.0;
    u0[31] = 0.0;
    u0[32] = 0.0;
    u0[33] = 0.0;
    u0[34] = 0.0;
    u0[35] = 0.0;
    u0[36] = 0.0;
    u0[37] = 0.0;
    u0[38] = 0.0;
    u0[39] = 0.0;
    u0[40] = 0.0;
    u0[41] = 0.0;
    u0[42] = 0.0;
    u0[43] = 0.0;
    u0[44] = 0.0;
    u0[45] = 0.0;
    u0[46] = 0.0;
    u0[47] = 0.0;
    u0[48] = 0.0;
    u0[49] = 0.0;
    u0[50] = 0.0;
    u0[51] = 0.0;
    u0[52] = 0.0;
    u0[53] = 0.0;
    u0[54] = 0.0;
    u0[55] = 0.0;
    u0[56] = 0.0;
    u0[57] = 0.0;
    u0[58] = 0.0;
    u0[59] = 0.0;
    u0[60] = 0.0;
    u0[61] = 0.0;
    u0[62] = 0.0;
    u0[63] = 0.0;
    u0[64] = 0.0;
    u0[65] = 0.0;
    u0[66] = 0.0;
    u0[67] = 0.0;
    u0[68] = 0.0;
    u0[69] = 0.0;
    u0[70] = 0.0;
    u0[71] = 0.0;
    u0[72] = 0.0;
    u0[73] = 0.0;
    u0[74] = 0.0;
    u0[75] = 0.0;
    u0[76] = 0.0;
    u0[77] = 0.0;
    u0[78] = 0.0;
    u0[79] = 0.0;
    u0[80] = 0.0;
    u0[81] = 0.0;
    u0[82] = 0.0;
    u0[83] = 0.0;
    u0[84] = 0.0;
    u0[85] = 0.0;
    u0[86] = 0.0;
    u0[87] = 0.0;
    u0[88] = 0.0;
    u0[89] = 0.0;
    u0[90] = 0.0;
    u0[91] = 0.0;
    u0[92] = 0.0;
    u0[93] = 0.0;
    u0[94] = 0.0;
    u0[95] = 0.0;
    u0[96] = 0.0;
    u0[97] = 0.0;
    u0[98] = 0.0;

    // prepare evaluation
    int NTIMINGS = 1;
    double min_time = 1e12;
    double kkt_norm_inf;
    double elapsed_time;
    int sqp_iter;

    double xtraj[NX * (N+1)];
    double utraj[NU * N];

    // solve ocp in loop
    for (int ii = 0; ii < NTIMINGS; ii++)
    {
        // initialize solution
        for (int i = 0; i < N; i++)
        {
            ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "x", x_init);
            ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, i, "u", u0);
        }
        ocp_nlp_out_set(nlp_config, nlp_dims, nlp_out, N, "x", x_init);
        status = payload_model_acados_solve(acados_ocp_capsule);
        ocp_nlp_get(nlp_solver, "time_tot", &elapsed_time);
        min_time = MIN(elapsed_time, min_time);
    }

    /* print solution and statistics */
    for (int ii = 0; ii <= nlp_dims->N; ii++)
        ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, ii, "x", &xtraj[ii*NX]);
    for (int ii = 0; ii < nlp_dims->N; ii++)
        ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, ii, "u", &utraj[ii*NU]);

    printf("\n--- xtraj ---\n");
    d_print_exp_tran_mat( NX, N+1, xtraj, NX);
    printf("\n--- utraj ---\n");
    d_print_exp_tran_mat( NU, N, utraj, NU );
    // ocp_nlp_out_print(nlp_solver->dims, nlp_out);

    printf("\nsolved ocp %d times, solution printed above\n\n", NTIMINGS);

    if (status == ACADOS_SUCCESS)
    {
        printf("payload_model_acados_solve(): SUCCESS!\n");
    }
    else
    {
        printf("payload_model_acados_solve() failed with status %d.\n", status);
    }

    // get solution
    ocp_nlp_out_get(nlp_config, nlp_dims, nlp_out, 0, "kkt_norm_inf", &kkt_norm_inf);
    ocp_nlp_get(nlp_solver, "sqp_iter", &sqp_iter);

    payload_model_acados_print_stats(acados_ocp_capsule);

    printf("\nSolver info:\n");
    printf(" SQP iterations %2d\n minimum time for %d solve %f [ms]\n KKT %e\n",
           sqp_iter, NTIMINGS, min_time*1000, kkt_norm_inf);



    // free solver
    status = payload_model_acados_free(acados_ocp_capsule);
    if (status) {
        printf("payload_model_acados_free() returned status %d. \n", status);
    }
    // free solver capsule
    status = payload_model_acados_free_capsule(acados_ocp_capsule);
    if (status) {
        printf("payload_model_acados_free_capsule() returned status %d. \n", status);
    }

    return status;
}
