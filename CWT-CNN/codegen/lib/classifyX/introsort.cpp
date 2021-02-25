//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: introsort.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//

// Include Files
#include "introsort.h"
#include "anonymous_function.h"
#include "insertionsort.h"

// Function Definitions
//
// Arguments    : int x_data[]
//                int xend
//                const anonymous_function *cmp
// Return Type  : void
//
namespace coder
{
  namespace internal
  {
    void introsort(int x_data[], int xend, const anonymous_function *cmp)
    {
      if (1 < xend) {
        insertionsort(x_data, xend, cmp);
      }
    }
  }
}

//
// File trailer for introsort.cpp
//
// [EOF]
//
