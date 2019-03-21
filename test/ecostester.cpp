

/*
 * ECOS - Embedded Conic Solver.
 * Copyright (C) 2012-14 Alexander Domahidi [domahidi@control.ee.ethz.ch],
 * Automatic Control Laboratory, ETH Zurich.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * aidxint with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ECOS TESTER MODULE */
/* THE CODE FOR MINIMAL UNIT TESTING HAS BEEN TAKEN FROM http://www.jera.com/techinfo/jtns/jtn002.html */
#include <stdio.h>
#include "minunit.h"
#include "ecos.h"

#include <RInside.h>

/* Make a copy of idxint vector to an int vector */
int * idxint2int(idxint *data, int len) {
  int *result = (int *) malloc(len * sizeof(int)); 
  for (int i = 0; i < len; i++) {
    result[i] = data[i];
  }
  return(result);
}

/* Make a copy of idxint vector to an int vector */
double * pfloat2double(pfloat *data, int len) {
  double *result = (double *) malloc(len * sizeof(double)); 
  for (int i = 0; i < len; i++) {
    result[i] = data[i];
  }
  return(result);
}

std::vector< double > dVec(pfloat *data, int len) {
  double * ddata = pfloat2double(data, len);
  std::vector< double > result;
  for (int i = 0; i < len; i++) result.push_back(ddata[i]);
  free(ddata);
  return(result);
}

std::vector< int > iVec(idxint *data, int len) {
  int * ddata = idxint2int(data, len);  
  std::vector< int > result;
  for (int i = 0; i < len; i++) result.push_back(ddata[i]);
  free(ddata);
  return(result);
}

#define DLEN(x) x? (int) (sizeof(x) / sizeof(pfloat)) : 0
#define ILEN(x) x? (int) (sizeof(x) / sizeof(idxint)) : 0

/* Include Tests */
#include "MPC/MPC01.h"
#include "MPC/MPC02.h"
#include "cvxpyProblems/githubIssue98.h"
#include "generated/generated_tests.h"
#include "feasibilityProblems/feas.h"
#include "unboundedProblems/unboundedLP1.h"
#include "infeasibleProblems/infeasible1.h"
#include "unboundedProblems/unboundedMaxSqrt.h"
#include "emptyProblem/emptyProblem.h"
#include "LPnetlib/lp_25fv47.h"
#include "LPnetlib/lp_adlittle.h"
#include "LPnetlib/lp_afiro.h"
#include "LPnetlib/lp_agg.h"
#include "LPnetlib/lp_agg2.h"
#include "LPnetlib/lp_agg3.h"
#include "LPnetlib/lp_bandm.h"
#include "LPnetlib/lp_beaconfd.h"
#include "LPnetlib/lp_blend.h"
#include "LPnetlib/lp_bnl1.h"
#include "updateData/update_data.h"

#if defined EXPCONE
#include "exponential/random_feasible.h"
#include "exponential/random_infeasible.h"
#include "exponential/random_unbounded.h"
#include "exponential/num_err.h"
#include "exponential/log_ax_x.h"
#endif

int tests_run = 0;

static char * all_tests(RInside  *R) {
  mu_run_test(test_MPC01);
  mu_run_test(test_MPC02);
    mu_run_test(test_norm);
    mu_run_test(test_quad_over_lin);
    mu_run_test(test_sq_norm);
    mu_run_test(test_sum_sq);
    mu_run_test(test_inv_pos);
    mu_run_test(test_feas);
    mu_run_test(test_unboundedLP1);
    mu_run_test(test_infeasible1);
    mu_run_test(test_lp_25fv47);
    mu_run_test(test_lp_adlittle);
    mu_run_test(test_lp_afiro);
    mu_run_test(test_lp_agg);
    mu_run_test(test_lp_agg2);
    mu_run_test(test_lp_agg3);
    mu_run_test(test_lp_bandm);
    mu_run_test(test_lp_beaconfd);
    mu_run_test(test_lp_blend);
    mu_run_test(test_lp_bnl1);
/*    mu_run_test(test_unboundedMaxSqrt); */
    mu_run_test(test_emptyProblem);
    mu_run_test(test_issue98);
    mu_run_test(test_update_data);

    #ifdef EXPCONE
        mu_run_test(test_random_feasible);
        mu_run_test(test_random_infeasible);
        mu_run_test(test_random_unbounded);
        mu_run_test(test_num_err);
	mu_run_test(test_log_ax_x);
    #endif
    return 0;
}

int main(int argc, char* argv[]) {
  RInside R(argc, argv);

  char *result = all_tests(&R);
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    printf("Size of pfloat %d\n", sizeof(pfloat));
    printf("Size of idxint %d\n", sizeof(idxint));
    printf("Size of long %d\n", sizeof(long));
    return result != 0;
}
