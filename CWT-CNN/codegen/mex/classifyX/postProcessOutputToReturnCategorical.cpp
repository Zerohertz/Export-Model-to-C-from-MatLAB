//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  postProcessOutputToReturnCategorical.cpp
//
//  Code generation for function 'postProcessOutputToReturnCategorical'
//


// Include files
#include "postProcessOutputToReturnCategorical.h"
#include "categorical.h"
#include "classifyX_data.h"
#include "classifyX_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo h_emlrtRSI = { 1,   // lineNo
  "DeepLearningNetwork/postProcessOutputToReturnCategorical",// fcnName
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2020b\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearningN"
  "etwork\\postProcessOutputToReturnCategorical.p"// pathName
};

static emlrtECInfo emlrtECI = { 2,     // nDims
  1,                                   // lineNo
  1,                                   // colNo
  "DeepLearningNetwork/postProcessOutputToReturnCategorical",// fName
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2020b\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearningN"
  "etwork\\postProcessOutputToReturnCategorical.p"// pName
};

static emlrtRTEInfo emlrtRTEI = { 14,  // lineNo
  1,                                   // colNo
  "nonzeros",                          // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\sparfun\\nonzeros.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 20,// lineNo
  9,                                   // colNo
  "nonzeros",                          // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\sparfun\\nonzeros.m"// pName 
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  1,                                   // lineNo
  1,                                   // colNo
  "",                                  // aName
  "DeepLearningNetwork/postProcessOutputToReturnCategorical",// fName
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2020b\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearningN"
  "etwork\\postProcessOutputToReturnCategorical.p",// pName
  0                                    // checkKind
};

static emlrtDCInfo emlrtDCI = { 15,    // lineNo
  58,                                  // colNo
  "nonzeros",                          // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\sparfun\\nonzeros.m",// pName 
  4                                    // checkKind
};

// Function Definitions
namespace coder
{
  void c_DeepLearningNetwork_postProce(const emlrtStack *sp, const cell_wrap_7
    scores[1], categorical processedOutput[1])
  {
    static const char_T classNames[30] = { 'F', 'F', 'F', 'F', 'N', '1', '2',
      '3', '4', 'o', '\x00', '\x00', '\x00', '\x00', 'r', '\x00', '\x00', '\x00',
      '\x00', 'm', '\x00', '\x00', '\x00', '\x00', 'a', '\x00', '\x00', '\x00',
      '\x00', 'l' };

    bounded_array<cell_wrap_2, 5U, 2U> labelsCells;
    cell_wrap_2 predictedClassNames[1];
    emlrtStack b_st;
    emlrtStack st;
    int32_T i;
    int32_T iindx;
    int32_T k;
    int32_T n;
    char_T s[6];
    char_T v_data[6];
    st.prev = sp;
    st.tls = sp->tls;
    st.site = &h_emlrtRSI;
    b_st.prev = &st;
    b_st.tls = st.tls;
    if (!muSingleScalarIsNaN(scores[0].f1[0])) {
      i = 1;
    } else {
      boolean_T exitg1;
      i = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 6)) {
        if (!muSingleScalarIsNaN(scores[0].f1[k - 1])) {
          i = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (i == 0) {
      iindx = 0;
    } else {
      real32_T ex;
      ex = scores[0].f1[i - 1];
      iindx = i - 1;
      n = i + 1;
      for (k = n; k < 6; k++) {
        real32_T f;
        f = scores[0].f1[k - 1];
        if (ex < f) {
          ex = f;
          iindx = k - 1;
        }
      }
    }

    labelsCells.size[0] = 1;
    labelsCells.size[1] = 0;
    for (int32_T b_i = 0; b_i < 5; b_i++) {
      int32_T v_size_idx_0;
      char_T c;
      b_st.site = &h_emlrtRSI;
      n = 0;
      for (k = 0; k < 6; k++) {
        c = classNames[b_i + 5 * k];
        s[k] = c;
        if (c != 0) {
          n++;
        }
      }

      if (n > 6) {
        emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (static_cast<int8_T>(n) < 0) {
        emlrtNonNegativeCheckR2012b(static_cast<real_T>(static_cast<int8_T>(n)),
          &emlrtDCI, &b_st);
      }

      v_size_idx_0 = static_cast<int8_T>(n);
      i = 0;
      for (k = 0; k < 6; k++) {
        c = s[k];
        if (c != 0) {
          i++;
          if (i > n) {
            emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
              "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed",
              0);
          }

          v_data[i - 1] = c;
        }
      }

      if (5 < labelsCells.size[1] + 1) {
        emlrtDimSizeGeqCheckR2012b(5, labelsCells.size[1] + 1, &emlrtECI, &st);
      }

      i = labelsCells.size[1] + 1;
      labelsCells.size[0] = 1;
      labelsCells.size[1]++;
      if (labelsCells.size[1] - 1 < 0) {
        emlrtDynamicBoundsCheckR2012b(labelsCells.size[1] - 1, 0,
          labelsCells.size[1] - 1, &emlrtBCI, &st);
      }

      labelsCells.data[labelsCells.size[1] - 1].f1.size[0] = 1;
      if (i - 1 < 0) {
        emlrtDynamicBoundsCheckR2012b(i - 1, 0, i - 1, &emlrtBCI, &st);
      }

      labelsCells.data[i - 1].f1.size[1] = static_cast<int8_T>(n);
      for (n = 0; n < v_size_idx_0; n++) {
        if (i - 1 < 0) {
          emlrtDynamicBoundsCheckR2012b(i - 1, 0, i - 1, &emlrtBCI, &st);
        }

        labelsCells.data[i - 1].f1.data[n] = v_data[n];
      }
    }

    predictedClassNames[0].f1.size[0] = 1;
    if (iindx > labelsCells.size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(iindx, 0, labelsCells.size[1] - 1, &emlrtBCI,
        &st);
    }

    predictedClassNames[0].f1.size[1] = labelsCells.data[iindx].f1.size[1];
    if (iindx > labelsCells.size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(iindx, 0, labelsCells.size[1] - 1, &emlrtBCI,
        &st);
    }

    if (iindx > labelsCells.size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(iindx, 0, labelsCells.size[1] - 1, &emlrtBCI,
        &st);
    }

    i = labelsCells.data[iindx].f1.size[0] * labelsCells.data[iindx].f1.size[1];
    for (n = 0; n < i; n++) {
      if (iindx > labelsCells.size[1] - 1) {
        emlrtDynamicBoundsCheckR2012b(iindx, 0, labelsCells.size[1] - 1,
          &emlrtBCI, &st);
      }

      predictedClassNames[0].f1.data[n] = labelsCells.data[iindx].f1.data[n];
    }

    b_st.site = &h_emlrtRSI;
    processedOutput[0].init((&b_st), predictedClassNames, labelsCells.data,
      labelsCells.size);
  }
}

// End of code generation (postProcessOutputToReturnCategorical.cpp)
