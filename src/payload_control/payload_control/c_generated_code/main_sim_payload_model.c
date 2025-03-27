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
#include "acados_c/sim_interface.h"
#include "acados_sim_solver_payload_model.h"

#define NX     PAYLOAD_MODEL_NX
#define NZ     PAYLOAD_MODEL_NZ
#define NU     PAYLOAD_MODEL_NU
#define NP     PAYLOAD_MODEL_NP


int main()
{
    int status = 0;
    payload_model_sim_solver_capsule *capsule = payload_model_acados_sim_solver_create_capsule();
    status = payload_model_acados_sim_create(capsule);

    if (status)
    {
        printf("acados_create() returned status %d. Exiting.\n", status);
        exit(1);
    }

    sim_config *acados_sim_config = payload_model_acados_get_sim_config(capsule);
    sim_in *acados_sim_in = payload_model_acados_get_sim_in(capsule);
    sim_out *acados_sim_out = payload_model_acados_get_sim_out(capsule);
    void *acados_sim_dims = payload_model_acados_get_sim_dims(capsule);

    // initial condition
    double x_current[NX];
    x_current[0] = 0.0;
    x_current[1] = 0.0;
    x_current[2] = 0.0;
    x_current[3] = 0.0;
    x_current[4] = 0.0;
    x_current[5] = 0.0;
    x_current[6] = 0.0;
    x_current[7] = 0.0;
    x_current[8] = 0.0;
    x_current[9] = 0.0;
    x_current[10] = 0.0;
    x_current[11] = 0.0;
    x_current[12] = 0.0;

  
    x_current[0] = 0;
    x_current[1] = 0;
    x_current[2] = 0;
    x_current[3] = 0;
    x_current[4] = 0;
    x_current[5] = 0;
    x_current[6] = 0;
    x_current[7] = 0;
    x_current[8] = 0;
    x_current[9] = 0;
    x_current[10] = 0;
    x_current[11] = 0;
    x_current[12] = 0;
    
  


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
    // set parameters
    double p[NP];
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[18] = 0;
    p[19] = 0;
    p[20] = 0;
    p[21] = 0;
    p[22] = 0;
    p[23] = 0;
    p[24] = 0;
    p[25] = 0;
    p[26] = 0;
    p[27] = 0;
    p[28] = 0;
    p[29] = 0;

    payload_model_acados_sim_update_params(capsule, p, NP);
  

  


    int n_sim_steps = 3;
    // solve ocp in loop
    for (int ii = 0; ii < n_sim_steps; ii++)
    {
        // set inputs
        sim_in_set(acados_sim_config, acados_sim_dims,
            acados_sim_in, "x", x_current);
        sim_in_set(acados_sim_config, acados_sim_dims,
            acados_sim_in, "u", u0);

        // solve
        status = payload_model_acados_sim_solve(capsule);
        if (status != ACADOS_SUCCESS)
        {
            printf("acados_solve() failed with status %d.\n", status);
        }

        // get outputs
        sim_out_get(acados_sim_config, acados_sim_dims,
               acados_sim_out, "x", x_current);

    

        // print solution
        printf("\nx_current, %d\n", ii);
        for (int jj = 0; jj < NX; jj++)
        {
            printf("%e\n", x_current[jj]);
        }
    }

    printf("\nPerformed %d simulation steps with acados integrator successfully.\n\n", n_sim_steps);

    // free solver
    status = payload_model_acados_sim_free(capsule);
    if (status) {
        printf("payload_model_acados_sim_free() returned status %d. \n", status);
    }

    payload_model_acados_sim_solver_free_capsule(capsule);

    return status;
}
