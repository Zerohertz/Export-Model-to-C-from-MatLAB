//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  insertionsort.cpp
//
//  Code generation for function 'insertionsort'
//


// Include files
#include "insertionsort.h"
#include "anonymous_function.h"
#include "categorical.h"
#include "classifyX_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ib_emlrtRSI = { 21, // lineNo
  "insertionsort",                     // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\insertionsort.m"// pathName 
};

static emlrtRSInfo jb_emlrtRSI = { 47, // lineNo
  "function_handle/parenReference",    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\function_handle.m"// pathName 
};

static emlrtRSInfo kb_emlrtRSI = { 14, // lineNo
  "@(i,j)sortidxCmp(i,j,c)",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m"// pathName 
};

static emlrtBCInfo ib_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  31,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "sortidxCmp",                        // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo jb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  32,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "sortidxCmp",                        // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo kb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  26,                                  // lineNo
  8,                                   // colNo
  "",                                  // aName
  "sortidxCmp",                        // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo lb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  27,                                  // lineNo
  8,                                   // colNo
  "",                                  // aName
  "sortidxCmp",                        // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    void insertionsort(const emlrtStack *sp, int32_T x_data[], int32_T xend,
                       const anonymous_function *cmp)
    {
      emlrtStack b_st;
      emlrtStack c_st;
      emlrtStack st;
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      c_st.prev = &b_st;
      c_st.tls = b_st.tls;
      for (int32_T k = 2; k <= xend; k++) {
        int32_T idx;
        int32_T xc;
        boolean_T exitg1;
        xc = x_data[k - 1] - 1;
        idx = k - 2;
        exitg1 = false;
        while ((!exitg1) && (idx + 1 >= 1)) {
          int32_T b_k;
          int32_T i;
          int32_T n;
          boolean_T exitg2;
          boolean_T varargout_1;
          st.site = &ib_emlrtRSI;
          b_st.site = &jb_emlrtRSI;
          c_st.site = &kb_emlrtRSI;
          if ((xc < 0) || (xc > cmp->tunableEnvironment[0].f1.size[0] - 1)) {
            emlrtDynamicBoundsCheckR2012b(xc, 0, cmp->tunableEnvironment[0].
              f1.size[0] - 1, &kb_emlrtBCI, &c_st);
          }

          i = x_data[idx] - 1;
          if ((i < 0) || (i > cmp->tunableEnvironment[0].f1.size[0] - 1)) {
            emlrtDynamicBoundsCheckR2012b(i, 0, cmp->tunableEnvironment[0].
              f1.size[0] - 1, &lb_emlrtBCI, &c_st);
          }

          n = static_cast<int32_T>(muDoubleScalarMin(static_cast<real_T>
            (cmp->tunableEnvironment[0].f1.data[xc].f1.size[1]),
            static_cast<real_T>(cmp->tunableEnvironment[0].f1.data[x_data[idx] -
                                1].f1.size[1])));
          varargout_1 = (cmp->tunableEnvironment[0].f1.data[xc].f1.size[1] <
                         cmp->tunableEnvironment[0].f1.data[x_data[idx] - 1].
                         f1.size[1]);
          b_k = 0;
          exitg2 = false;
          while ((!exitg2) && (b_k <= n - 1)) {
            int32_T i1;
            i = cmp->tunableEnvironment[0].f1.data[xc].f1.size[1];
            i1 = b_k + 1;
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ib_emlrtBCI, &c_st);
            }

            i = cmp->tunableEnvironment[0].f1.data[x_data[idx] - 1].f1.size[1];
            if (i1 > i) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &jb_emlrtBCI, &c_st);
            }

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

// End of code generation (insertionsort.cpp)
