/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: classifyX.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 16-Feb-2021 10:17:26
 */

/* Include Files */
#include "classifyX.h"
#include "Gaussian.h"
#include "classifyX_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double X
 *                cell_wrap_0 label[1]
 * Return Type  : void
 */
void classifyX(double X, cell_wrap_0 label[1])
{
  static const char cv[12] = { 'f', 'n', 'a', 'o', 'u', 'r', 'l', 'm', 't', 'a',
    ' ', 'l' };

  double dv[2];
  double svT[2];
  double d;
  int i;
  int k;
  int loop_ub;
  boolean_T b[2];
  boolean_T b_tmp;
  boolean_T exitg1;
  boolean_T y;
  svT[0] = 0.17677669529663687;
  svT[1] = -0.17677669529663687;
  Gaussian(svT, 0.062499999999999986, (X - 0.5) / 0.70710678118654757 / 4.0, dv);
  d = -dv[0] + dv[1];
  b[0] = rtIsNaN(-d);
  b_tmp = rtIsNaN(d);
  b[1] = b_tmp;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!b[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  label[0].f1.size[0] = 1;
  label[0].f1.size[1] = 5;
  for (i = 0; i < 5; i++) {
    label[0].f1.data[i] = cv[i << 1];
  }

  if (!y) {
    if ((-d < d) || (rtIsNaN(-d) && (!b_tmp))) {
      k = 1;
    } else {
      k = 0;
    }

    loop_ub = k + 4;
    label[0].f1.size[0] = 1;
    label[0].f1.size[1] = k + 5;
    for (i = 0; i <= loop_ub; i++) {
      label[0].f1.data[i] = cv[k + (i << 1)];
    }
  }
}

/*
 * File trailer for classifyX.c
 *
 * [EOF]
 */
