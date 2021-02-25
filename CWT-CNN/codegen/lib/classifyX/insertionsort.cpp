//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: insertionsort.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//

// Include Files
#include "insertionsort.h"
#include "anonymous_function.h"
#include "categorical.h"
#include "coder_array.h"
#include <cmath>

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
    void insertionsort(int x_data[], int xend, const anonymous_function *cmp)
    {
      for (int k = 2; k <= xend; k++) {
        int idx;
        int xc;
        boolean_T exitg1;
        xc = x_data[k - 1] - 1;
        idx = k - 2;
        exitg1 = false;
        while ((!exitg1) && (idx + 1 >= 1)) {
          int b_k;
          int n;
          boolean_T exitg2;
          boolean_T varargout_1;
          n = static_cast<int>(std::fmin(static_cast<double>
            (cmp->tunableEnvironment[0].f1.data[xc].f1.size[1]), static_cast<
            double>(cmp->tunableEnvironment[0].f1.data[x_data[idx] - 1].f1.size
                    [1])));
          varargout_1 = (cmp->tunableEnvironment[0].f1.data[xc].f1.size[1] <
                         cmp->tunableEnvironment[0].f1.data[x_data[idx] - 1].
                         f1.size[1]);
          b_k = 0;
          exitg2 = false;
          while ((!exitg2) && (b_k <= n - 1)) {
            if (cmp->tunableEnvironment[0].f1.data[xc].f1.data[b_k] !=
                cmp->tunableEnvironment[0].f1.data[x_data[idx] - 1].f1.data[b_k])
            {
              varargout_1 = (cmp->tunableEnvironment[0].f1.data[xc].f1.data[b_k]
                             < cmp->tunableEnvironment[0].f1.data[x_data[idx] -
                             1].f1.data[b_k]);
              exitg2 = true;
            } else {
              b_k++;
            }
          }

          if (varargout_1) {
            x_data[idx + 1] = x_data[idx];
            idx--;
          } else {
            exitg1 = true;
          }
        }

        x_data[idx + 1] = xc + 1;
      }
    }
  }
}

//
// File trailer for insertionsort.cpp
//
// [EOF]
//
