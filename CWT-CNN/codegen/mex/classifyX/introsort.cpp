//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  introsort.cpp
//
//  Code generation for function 'introsort'
//


// Include files
#include "introsort.h"
#include "anonymous_function.h"
#include "classifyX_data.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo lb_emlrtRSI = { 34, // lineNo
  "introsort",                         // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"// pathName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    void introsort(const emlrtStack *sp, int32_T x_data[], int32_T xend, const
                   anonymous_function *cmp)
    {
      emlrtStack st;
      st.prev = sp;
      st.tls = sp->tls;
      if (1 < xend) {
        st.site = &lb_emlrtRSI;
        insertionsort(&st, x_data, xend, cmp);
      }
    }
  }
}

// End of code generation (introsort.cpp)
