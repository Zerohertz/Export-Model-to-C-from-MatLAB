//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  cellstr_unique.cpp
//
//  Code generation for function 'cellstr_unique'
//


// Include files
#include "cellstr_unique.h"
#include "anonymous_function.h"
#include "categorical.h"
#include "classifyX_data.h"
#include "indexShapeCheck.h"
#include "introsort.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo bb_emlrtRSI = { 17, // lineNo
  "cellstr_unique",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m"// pathName 
};

static emlrtRSInfo cb_emlrtRSI = { 20, // lineNo
  "cellstr_unique",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 28, // lineNo
  "cellstr_unique",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 30, // lineNo
  "cellstr_unique",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 37, // lineNo
  "cellstr_unique",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m"// pathName 
};

static emlrtRSInfo gb_emlrtRSI = { 39, // lineNo
  "cellstr_unique",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m"// pathName 
};

static emlrtRSInfo hb_emlrtRSI = { 14, // lineNo
  "cellstr_sort",                      // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m"// pathName 
};

static emlrtRSInfo mb_emlrtRSI = { 39, // lineNo
  "find",                              // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"// pathName 
};

static emlrtRSInfo nb_emlrtRSI = { 144,// lineNo
  "eml_find",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"// pathName 
};

static emlrtRSInfo ob_emlrtRSI = { 402,// lineNo
  "find_first_indices",                // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"// pathName 
};

static emlrtRSInfo qb_emlrtRSI = { 14, // lineNo
  "min",                               // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"// pathName 
};

static emlrtRSInfo rb_emlrtRSI = { 46, // lineNo
  "minOrMax",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName 
};

static emlrtRSInfo sb_emlrtRSI = { 92, // lineNo
  "minimum",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName 
};

static emlrtBCInfo o_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  59,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo p_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  59,                                  // lineNo
  16,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo q_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  37,                                  // lineNo
  13,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo r_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  13,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo s_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  59,                                  // lineNo
  18,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo t_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  37,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo u_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo v_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  56,                                  // lineNo
  8,                                   // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo w_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  18,                                  // lineNo
  5,                                   // colNo
  "",                                  // aName
  "cellstr_sort",                      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo x_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  18,                                  // lineNo
  17,                                  // colNo
  "",                                  // aName
  "cellstr_sort",                      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo y_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "cellstr_diff",                      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_diff.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo ab_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "cellstr_diff",                      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_diff.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo bb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  11,                                  // lineNo
  25,                                  // colNo
  "",                                  // aName
  "cellstr_diff",                      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_diff.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo cb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  18,                                  // lineNo
  19,                                  // colNo
  "",                                  // aName
  "cellstr_sort",                      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo db_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  59,                                  // lineNo
  11,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo eb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  18,                                  // lineNo
  12,                                  // colNo
  "",                                  // aName
  "cellstr_sort",                      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 28,  // lineNo
  29,                                  // colNo
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  4                                    // checkKind
};

static emlrtBCInfo fb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  37,                                  // lineNo
  35,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo gb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  37,                                  // lineNo
  44,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo hb_emlrtBCI = { -1, // iFirst
  -1,                                  // iLast
  39,                                  // lineNo
  35,                                  // colNo
  "",                                  // aName
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  56,                                  // lineNo
  5,                                   // colNo
  "cellstr_unique",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m"// pName 
};

static emlrtRTEInfo k_emlrtRTEI = { 97,// lineNo
  27,                                  // colNo
  "unaryMinOrMax",                     // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pName 
};

static emlrtRTEInfo l_emlrtRTEI = { 392,// lineNo
  1,                                   // colNo
  "find_first_indices",                // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace matlab
  {
    namespace internal
    {
      namespace coder
      {
        namespace datatypes
        {
          void cellstr_unique(const emlrtStack *sp, const cell_wrap_2 a_data[],
                              const int32_T a_size[1], cell_wrap_2 u_data[],
                              int32_T u_size[1])
          {
            anonymous_function b_this;
            bounded_array<cell_wrap_2, 5U, 1U> c;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack st;
            int32_T ia_data[5];
            int32_T idx_data[5];
            int32_T y_data[5];
            int32_T iv[2];
            int32_T yk;
            int8_T b_y_data[5];
            int8_T ii_data[5];
            boolean_T b_d_data[5];
            boolean_T d_data[4];
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            c_st.prev = &b_st;
            c_st.tls = b_st.tls;
            d_st.prev = &c_st;
            d_st.tls = c_st.tls;
            if (a_size[0] == 0) {
              u_size[0] = 0;
            } else {
              int32_T b_i;
              int32_T b_y_size_idx_1;
              int32_T d_size_idx_0;
              int32_T i;
              int32_T ii_size_idx_0;
              int32_T k;
              int32_T n;
              int32_T y_size_idx_1;
              boolean_T exitg1;
              st.site = &bb_emlrtRSI;
              n = a_size[0];
              y_size_idx_1 = a_size[0];
              y_data[0] = 1;
              yk = 1;
              for (k = 2; k <= n; k++) {
                yk++;
                y_data[k - 1] = yk;
              }

              b_this.tunableEnvironment[0].f1.size[0] = a_size[0];
              yk = a_size[0];
              for (i = 0; i < yk; i++) {
                b_this.tunableEnvironment[0].f1.data[i] = a_data[i];
              }

              if (0 <= y_size_idx_1 - 1) {
                memcpy(&idx_data[0], &y_data[0], y_size_idx_1 * sizeof(int32_T));
              }

              b_st.site = &hb_emlrtRSI;
              ::coder::internal::introsort(&b_st, idx_data, a_size[0], &b_this);
              c.size[0] = a_size[0];
              i = a_size[0];
              for (b_i = 0; b_i < i; b_i++) {
                if ((b_i + 1 < 1) || (b_i + 1 > y_size_idx_1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y_size_idx_1,
                    &cb_emlrtBCI, &st);
                }

                k = idx_data[b_i];
                if ((k - 1 < 0) || (k - 1 > a_size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b(k - 1, 0, a_size[0] - 1,
                    &cb_emlrtBCI, &st);
                }

                if ((b_i + 1 < 1) || (b_i + 1 > y_size_idx_1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y_size_idx_1,
                    &cb_emlrtBCI, &st);
                }

                if ((k - 1 < 0) || (k - 1 > a_size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b(k - 1, 0, a_size[0] - 1,
                    &cb_emlrtBCI, &st);
                }

                yk = a_data[k - 1].f1.size[0] * a_data[k - 1].f1.size[1] - 1;
                if (b_i > c.size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, c.size[0] - 1,
                    &eb_emlrtBCI, &st);
                }

                c.data[b_i].f1.size[0] = 1;
                if ((b_i + 1 < 1) || (b_i + 1 > y_size_idx_1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y_size_idx_1,
                    &cb_emlrtBCI, &st);
                }

                if ((k - 1 < 0) || (k - 1 > a_size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b(k - 1, 0, a_size[0] - 1,
                    &cb_emlrtBCI, &st);
                }

                if (b_i > c.size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, c.size[0] - 1,
                    &eb_emlrtBCI, &st);
                }

                c.data[b_i].f1.size[1] = a_data[k - 1].f1.size[1];
                k = c.size[0];
                if (b_i > c.size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, c.size[0] - 1,
                    &eb_emlrtBCI, &st);
                }

                for (b_y_size_idx_1 = 0; b_y_size_idx_1 <= yk; b_y_size_idx_1++)
                {
                  if (b_i > k - 1) {
                    emlrtDynamicBoundsCheckR2012b(b_i, 0, k - 1, &w_emlrtBCI,
                      &st);
                  }

                  if ((b_i + 1 < 1) || (b_i + 1 > y_size_idx_1)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, y_size_idx_1,
                      &x_emlrtBCI, &st);
                  }

                  n = idx_data[b_i] - 1;
                  if ((n < 0) || (n > a_size[0] - 1)) {
                    emlrtDynamicBoundsCheckR2012b(n, 0, a_size[0] - 1,
                      &x_emlrtBCI, &st);
                  }

                  c.data[b_i].f1.data[b_y_size_idx_1] = a_data[n]
                    .f1.data[b_y_size_idx_1];
                }
              }

              st.site = &cb_emlrtRSI;
              d_size_idx_0 = c.size[0] - 1;
              yk = c.size[0];
              if (0 <= yk - 2) {
                memset(&d_data[0], 0, (yk + -1) * sizeof(boolean_T));
              }

              i = c.size[0];
              for (b_i = 0; b_i <= i - 2; b_i++) {
                if ((b_i + 1 < 1) || (b_i + 1 > d_size_idx_0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d_size_idx_0,
                    &y_emlrtBCI, &st);
                }

                if ((b_i + 1 < 0) || (b_i + 1 > c.size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 0, c.size[0] - 1,
                    &ab_emlrtBCI, &st);
                }

                if (b_i > c.size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, c.size[0] - 1,
                    &bb_emlrtBCI, &st);
                }

                d_data[b_i] = !::coder::internal::b_strcmp(c.data[b_i].f1.data,
                  c.data[b_i].f1.size, c.data[b_i + 1].f1.data, c.data[b_i + 1].
                  f1.size);
              }

              n = c.size[0];
              b_d_data[0] = true;
              if (0 <= d_size_idx_0 - 1) {
                memcpy(&b_d_data[1], &d_data[0], d_size_idx_0 * sizeof(boolean_T));
              }

              st.site = &db_emlrtRSI;
              b_st.site = &ab_emlrtRSI;
              yk = b_d_data[0];
              for (k = 2; k <= n; k++) {
                yk += b_d_data[k - 1];
              }

              i = static_cast<int32_T>(muDoubleScalarMin(static_cast<real_T>(yk),
                static_cast<real_T>(a_size[0])));
              if (i < 0) {
                emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &b_emlrtDCI,
                  sp);
              }

              u_size[0] = i;
              st.site = &eb_emlrtRSI;
              b_st.site = &mb_emlrtRSI;
              c_st.site = &nb_emlrtRSI;
              n = 0;
              ii_size_idx_0 = c.size[0];
              yk = 0;
              exitg1 = false;
              while ((!exitg1) && (yk <= d_size_idx_0)) {
                if (b_d_data[yk]) {
                  n++;
                  ii_data[n - 1] = static_cast<int8_T>(yk + 1);
                  if (n >= d_size_idx_0 + 1) {
                    exitg1 = true;
                  } else {
                    yk++;
                  }
                } else {
                  yk++;
                }
              }

              if (n > c.size[0]) {
                emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
                  "Coder:builtins:AssertionFailed",
                  "Coder:builtins:AssertionFailed", 0);
              }

              if (c.size[0] == 1) {
                if (n == 0) {
                  ii_size_idx_0 = 0;
                }
              } else {
                if (1 > n) {
                  ii_size_idx_0 = 0;
                } else {
                  ii_size_idx_0 = n;
                }

                iv[0] = 1;
                iv[1] = ii_size_idx_0;
                d_st.site = &ob_emlrtRSI;
                ::coder::internal::indexShapeCheck(&d_st, c.size[0], iv);
              }

              for (b_i = 0; b_i < ii_size_idx_0; b_i++) {
                if (b_i + 1 != ii_size_idx_0) {
                  int8_T i1;
                  i = b_i + 1;
                  if ((i < 1) || (i > ii_size_idx_0)) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, ii_size_idx_0,
                      &fb_emlrtBCI, sp);
                  }

                  if ((static_cast<int32_T>((static_cast<real_T>(b_i) + 1.0) +
                        1.0) < 1) || (static_cast<int32_T>((static_cast<real_T>
                         (b_i) + 1.0) + 1.0) > ii_size_idx_0)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>((
                      static_cast<real_T>(b_i) + 1.0) + 1.0), 1, ii_size_idx_0,
                      &gb_emlrtBCI, sp);
                  }

                  i = ii_data[b_i + 1] - 1;
                  i1 = ii_data[b_i];
                  if (i < i1) {
                    b_y_size_idx_1 = 0;
                  } else {
                    yk = i - i1;
                    b_y_size_idx_1 = yk + 1;
                    for (i = 0; i <= yk; i++) {
                      b_y_data[i] = static_cast<int8_T>(ii_data[b_i] +
                        static_cast<int8_T>(i));
                    }
                  }

                  st.site = &fb_emlrtRSI;
                  for (i = 0; i < b_y_size_idx_1; i++) {
                    k = b_y_data[i];
                    if ((k < 1) || (k > y_size_idx_1)) {
                      emlrtDynamicBoundsCheckR2012b(k, 1, y_size_idx_1,
                        &t_emlrtBCI, &st);
                    }
                  }

                  b_st.site = &qb_emlrtRSI;
                  c_st.site = &rb_emlrtRSI;
                  d_st.site = &sb_emlrtRSI;
                  if (b_y_size_idx_1 < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &k_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  n = idx_data[b_y_data[0] - 1];
                  for (k = 2; k <= b_y_size_idx_1; k++) {
                    i = idx_data[b_y_data[k - 1] - 1];
                    if (n > i) {
                      n = i;
                    }
                  }

                  if ((b_i + 1 < 1) || (b_i + 1 > ii_size_idx_0)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size_idx_0,
                      &q_emlrtBCI, sp);
                  }

                  ia_data[b_i] = n;
                } else {
                  int8_T i1;
                  i = b_i + 1;
                  if ((i < 1) || (i > ii_size_idx_0)) {
                    emlrtDynamicBoundsCheckR2012b(i, 1, ii_size_idx_0,
                      &hb_emlrtBCI, sp);
                  }

                  i1 = ii_data[b_i];
                  if (y_size_idx_1 < i1) {
                    b_y_size_idx_1 = 0;
                  } else {
                    n = static_cast<int8_T>(y_size_idx_1) - i1;
                    b_y_size_idx_1 = n + 1;
                    for (i = 0; i <= n; i++) {
                      b_y_data[i] = static_cast<int8_T>(ii_data[b_i] +
                        static_cast<int8_T>(i));
                    }
                  }

                  st.site = &gb_emlrtRSI;
                  for (i = 0; i < b_y_size_idx_1; i++) {
                    k = b_y_data[i];
                    if ((k < 1) || (k > y_size_idx_1)) {
                      emlrtDynamicBoundsCheckR2012b(k, 1, y_size_idx_1,
                        &u_emlrtBCI, &st);
                    }
                  }

                  b_st.site = &qb_emlrtRSI;
                  c_st.site = &rb_emlrtRSI;
                  d_st.site = &sb_emlrtRSI;
                  if (b_y_size_idx_1 < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &k_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  n = idx_data[b_y_data[0] - 1];
                  for (k = 2; k <= b_y_size_idx_1; k++) {
                    i = idx_data[b_y_data[k - 1] - 1];
                    if (n > i) {
                      n = i;
                    }
                  }

                  if ((b_i + 1 < 1) || (b_i + 1 > ii_size_idx_0)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size_idx_0,
                      &r_emlrtBCI, sp);
                  }

                  ia_data[b_i] = n;
                }
              }

              if (a_size[0] != c.size[0]) {
                emlrtSubAssignSizeCheck1dR2017a(a_size[0], c.size[0],
                  &b_emlrtECI, sp);
              }

              for (i = 0; i < y_size_idx_1; i++) {
                k = idx_data[i];
                if ((k < 1) || (k > d_size_idx_0 + 1)) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, d_size_idx_0 + 1,
                    &v_emlrtBCI, sp);
                }
              }

              for (b_i = 0; b_i < ii_size_idx_0; b_i++) {
                if ((b_i + 1 < 1) || (b_i + 1 > ii_size_idx_0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size_idx_0,
                    &s_emlrtBCI, sp);
                }

                i = ia_data[b_i];
                if ((i - 1 < 0) || (i - 1 > a_size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b(i - 1, 0, a_size[0] - 1,
                    &s_emlrtBCI, sp);
                }

                if ((b_i + 1 < 1) || (b_i + 1 > ii_size_idx_0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size_idx_0,
                    &s_emlrtBCI, sp);
                }

                if ((i - 1 < 0) || (i - 1 > a_size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b(i - 1, 0, a_size[0] - 1,
                    &s_emlrtBCI, sp);
                }

                yk = a_data[i - 1].f1.size[0] * a_data[i - 1].f1.size[1] - 1;
                if (b_i > u_size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, u_size[0] - 1,
                    &db_emlrtBCI, sp);
                }

                u_data[b_i].f1.size[0] = 1;
                if ((b_i + 1 < 1) || (b_i + 1 > ii_size_idx_0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size_idx_0,
                    &s_emlrtBCI, sp);
                }

                if ((i - 1 < 0) || (i - 1 > a_size[0] - 1)) {
                  emlrtDynamicBoundsCheckR2012b(i - 1, 0, a_size[0] - 1,
                    &s_emlrtBCI, sp);
                }

                if (b_i > u_size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, u_size[0] - 1,
                    &db_emlrtBCI, sp);
                }

                u_data[b_i].f1.size[1] = a_data[i - 1].f1.size[1];
                i = u_size[0];
                if (b_i > u_size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, u_size[0] - 1,
                    &db_emlrtBCI, sp);
                }

                if (b_i > u_size[0] - 1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 0, u_size[0] - 1,
                    &db_emlrtBCI, sp);
                }

                for (k = 0; k <= yk; k++) {
                  if (b_i > i - 1) {
                    emlrtDynamicBoundsCheckR2012b(b_i, 0, i - 1, &o_emlrtBCI, sp);
                  }

                  if ((b_i + 1 < 1) || (b_i + 1 > ii_size_idx_0)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size_idx_0,
                      &p_emlrtBCI, sp);
                  }

                  b_y_size_idx_1 = ia_data[b_i] - 1;
                  if ((b_y_size_idx_1 < 0) || (b_y_size_idx_1 > a_size[0] - 1))
                  {
                    emlrtDynamicBoundsCheckR2012b(b_y_size_idx_1, 0, a_size[0] -
                      1, &p_emlrtBCI, sp);
                  }

                  u_data[b_i].f1.data[k] = a_data[b_y_size_idx_1].f1.data[k];
                }
              }
            }
          }
        }
      }
    }
  }
}

// End of code generation (cellstr_unique.cpp)
