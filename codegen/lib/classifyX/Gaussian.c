/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Gaussian.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 16-Feb-2021 10:17:26
 */

/* Include Files */
#include "Gaussian.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double svT[2]
 *                double svInnerProduct
 *                double x
 *                double kernelProduct[2]
 * Return Type  : void
 */
void Gaussian(const double svT[2], double svInnerProduct, double x, double
              kernelProduct[2])
{
  double a;
  double b;
  a = -2.0 * x;
  b = x * x;
  kernelProduct[0] = exp(-((a * svT[0] + b) + svInnerProduct));
  kernelProduct[1] = exp(-((a * svT[1] + b) + svInnerProduct));
}

/*
 * File trailer for Gaussian.c
 *
 * [EOF]
 */
