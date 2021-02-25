//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  categorical.cpp
//
//  Code generation for function 'categorical'
//


// Include files
#include "categorical.h"
#include "cellstr_unique.h"
#include "classifyX_data.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "strtrim.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo i_emlrtRSI = { 283, // lineNo
  "categorical/categorical",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pathName 
};

static emlrtRSInfo j_emlrtRSI = { 221, // lineNo
  "categorical/categorical",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pathName 
};

static emlrtRSInfo k_emlrtRSI = { 216, // lineNo
  "categorical/categorical",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pathName 
};

static emlrtRSInfo l_emlrtRSI = { 193, // lineNo
  "categorical/categorical",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pathName 
};

static emlrtRSInfo m_emlrtRSI = { 167, // lineNo
  "categorical/categorical",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pathName 
};

static emlrtRSInfo n_emlrtRSI = { 12,  // lineNo
  "cellstr_strtrim",                   // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_strtrim.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 29,  // lineNo
  "reshapeSizeChecks",                 // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 18,  // lineNo
  "isMissingValues",                   // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\isMissingValues.m"// pathName 
};

static emlrtRSInfo y_emlrtRSI = { 21,  // lineNo
  "isMissingValues",                   // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\isMissingValues.m"// pathName 
};

static emlrtRSInfo tb_emlrtRSI = { 475,// lineNo
  "categorical/initDataValueSet",      // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pathName 
};

static emlrtRSInfo ub_emlrtRSI = { 478,// lineNo
  "categorical/initDataValueSet",      // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pathName 
};

static emlrtRSInfo xb_emlrtRSI = { 53, // lineNo
  "categorical/getCodes",              // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCodes.m"// pathName 
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m",                              // pName
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  39,                                  // colNo
  "",                                  // aName
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m",                              // pName
  0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m",                              // pName
  0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  27,                                  // lineNo
  25,                                  // colNo
  "",                                  // aName
  "cellstr_ismember",                  // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  22,                                  // lineNo
  13,                                  // colNo
  "",                                  // aName
  "isMissingValues",                   // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\isMissingValues.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  21,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "isMissingValues",                   // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\isMissingValues.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  12,                                  // lineNo
  9,                                   // colNo
  "",                                  // aName
  "cellstr_strtrim",                   // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_strtrim.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  12,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "cellstr_strtrim",                   // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\cellstr_strtrim.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  34,                                  // colNo
  "",                                  // aName
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m",                              // pName
  0                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m",                              // pName
  0                                    // checkKind
};

static emlrtRTEInfo c_emlrtRTEI = { 230,// lineNo
  43,                                  // colNo
  "categorical/categorical",           // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pName 
};

static emlrtRTEInfo d_emlrtRTEI = { 218,// lineNo
  21,                                  // colNo
  "categorical/categorical",           // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\categorical.m"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 59,// lineNo
  23,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"// pName 
};

static emlrtRTEInfo f_emlrtRTEI = { 52,// lineNo
  13,                                  // colNo
  "reshapeSizeChecks",                 // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\reshapeSizeChecks.m"// pName 
};

static emlrtBCInfo l_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  48,                                  // lineNo
  27,                                  // colNo
  "",                                  // aName
  "isCharStrings",                     // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\isCharStrings.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo m_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  48,                                  // lineNo
  47,                                  // colNo
  "",                                  // aName
  "isCharStrings",                     // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+matlab\\+internal\\+coder\\+datatypes\\isCharStrings.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo h_emlrtRTEI = { 99,// lineNo
  35,                                  // colNo
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m"                               // pName
};

static emlrtRTEInfo i_emlrtRTEI = { 108,// lineNo
  35,                                  // colNo
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m"                               // pName
};

static emlrtBCInfo n_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "categorical/getCategoryNames",      // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
  "es.m",                              // pName
  0                                    // checkKind
};

// Function Definitions
namespace coder
{
  void categorical::init(const emlrtStack *sp, const cell_wrap_2 inputData[1],
    const cell_wrap_2 varargin_1_data[], const int32_T varargin_1_size[2])
  {
    bounded_array<cell_wrap_2, 5U, 2U> r;
    bounded_array<cell_wrap_2, 5U, 1U> r1;
    bounded_array<cell_wrap_2, 5U, 1U> valueSet;
    cell_wrap_2 inData[1];
    emlrtStack b_st;
    emlrtStack c_st;
    emlrtStack st;
    int32_T tmp_size[2];
    int32_T b_i;
    int32_T i;
    int32_T loop_ub;
    int32_T nz;
    int32_T x_size_idx_0;
    char_T tmp_data[6];
    int8_T mask_data[5];
    boolean_T bool_data[5];
    boolean_T x_data[5];
    boolean_T exitg1;
    st.prev = sp;
    st.tls = sp->tls;
    b_st.prev = &st;
    b_st.tls = st.tls;
    c_st.prev = &b_st;
    c_st.tls = b_st.tls;
    this->isOrdinal = false;
    this->isProtected = false;
    st.site = &m_emlrtRSI;
    b_st.site = &n_emlrtRSI;
    strtrim(&b_st, inputData[0].f1.data, inputData[0].f1.size, inData[0].f1.data,
            inData[0].f1.size);
    if (varargin_1_size[1] != 0) {
      st.site = &l_emlrtRSI;
      r.size[0] = varargin_1_size[0];
      r.size[1] = varargin_1_size[1];
      i = varargin_1_size[1];
      for (b_i = 0; b_i < i; b_i++) {
        if (b_i > r.size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, r.size[1] - 1, &h_emlrtBCI, &st);
        }

        if (b_i > varargin_1_size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, varargin_1_size[1] - 1,
            &i_emlrtBCI, &st);
        }

        b_st.site = &n_emlrtRSI;
        strtrim(&b_st, varargin_1_data[b_i].f1.data, varargin_1_data[b_i].
                f1.size, r.data[b_i].f1.data, r.data[b_i].f1.size);
      }

      st.site = &l_emlrtRSI;
      b_st.site = &v_emlrtRSI;
      nz = 1;
      if (r.size[1] > 1) {
        nz = r.size[1];
      }

      if (varargin_1_size[1] > muIntScalarMax_sint32(r.size[1], nz)) {
        emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
          "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
      }

      if (varargin_1_size[1] != r.size[1]) {
        emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
          "Coder:MATLAB:getReshapeDims_notSameNumel",
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
      }

      valueSet.size[0] = varargin_1_size[1];
      loop_ub = varargin_1_size[1];
      for (i = 0; i < loop_ub; i++) {
        valueSet.data[i] = r.data[i];
      }
    } else {
      valueSet.size[0] = 0;
    }

    st.site = &k_emlrtRSI;
    b_st.site = &k_emlrtRSI;
    c_st.site = &x_emlrtRSI;
    i = valueSet.size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if (b_i > valueSet.size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, valueSet.size[0] - 1, &l_emlrtBCI,
          &c_st);
      }

      if (b_i > valueSet.size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, valueSet.size[0] - 1, &m_emlrtBCI,
          &c_st);
      }
    }

    x_size_idx_0 = static_cast<int8_T>(valueSet.size[0]);
    loop_ub = static_cast<int8_T>(valueSet.size[0]);
    if (0 <= loop_ub - 1) {
      memset(&x_data[0], 0, loop_ub * sizeof(boolean_T));
    }

    i = valueSet.size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if (b_i > valueSet.size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, valueSet.size[0] - 1, &g_emlrtBCI,
          &b_st);
      }

      c_st.site = &y_emlrtRSI;
      strtrim(&c_st, valueSet.data[b_i].f1.data, valueSet.data[b_i].f1.size,
              tmp_data, tmp_size);
      if (static_cast<int8_T>(tmp_size[1]) == 0) {
        if ((b_i + 1 < 1) || (b_i + 1 > x_size_idx_0)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, x_size_idx_0, &f_emlrtBCI,
            &b_st);
        }

        x_data[b_i] = true;
      }
    }

    b_st.site = &ab_emlrtRSI;
    if (static_cast<int8_T>(valueSet.size[0]) == 0) {
      nz = 0;
    } else {
      nz = x_data[0];
      for (loop_ub = 2; loop_ub <= x_size_idx_0; loop_ub++) {
        nz += x_data[loop_ub - 1];
      }
    }

    if (nz > 1) {
      emlrtErrorWithMessageIdR2018a(sp, &d_emlrtRTEI,
        "MATLAB:categorical:MultipleMissingInValueset",
        "MATLAB:categorical:MultipleMissingInValueset", 0);
    }

    st.site = &j_emlrtRSI;
    matlab::internal::coder::datatypes::cellstr_unique(&st, valueSet.data,
      valueSet.size, r1.data, r1.size);
    if (static_cast<int8_T>(r1.size[0]) != valueSet.size[0]) {
      emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
        "MATLAB:categorical:DuplicatedValues",
        "MATLAB:categorical:DuplicatedValues", 0);
    }

    st.site = &i_emlrtRSI;
    b_st.site = &tb_emlrtRSI;
    if (valueSet.size[0] != 0) {
      boolean_T y;
      x_size_idx_0 = valueSet.size[0];
      nz = valueSet.size[0];
      for (loop_ub = 0; loop_ub < nz; loop_ub++) {
        bool_data[loop_ub] = false;
        if (0 == valueSet.data[loop_ub].f1.size[1]) {
          bool_data[loop_ub] = true;
        }
      }

      y = false;
      nz = 1;
      exitg1 = false;
      while ((!exitg1) && (nz <= x_size_idx_0)) {
        if (!bool_data[nz - 1]) {
          nz++;
        } else {
          y = true;
          exitg1 = true;
        }
      }

      if (y) {
        emlrtErrorWithMessageIdR2018a(&b_st, &h_emlrtRTEI,
          "MATLAB:categorical:EmptyCategoryName",
          "MATLAB:categorical:EmptyCategoryName", 0);
      }

      x_size_idx_0 = valueSet.size[0];
      loop_ub = valueSet.size[0];
      if (0 <= loop_ub - 1) {
        memset(&mask_data[0], 0, loop_ub * sizeof(int8_T));
      }

      i = valueSet.size[0];
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        if (loop_ub > valueSet.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 0, valueSet.size[0] - 1,
            &n_emlrtBCI, &b_st);
        }

        if ((loop_ub + 1 < 1) || (loop_ub + 1 > x_size_idx_0)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, x_size_idx_0,
            &d_emlrtBCI, &b_st);
        }

        mask_data[loop_ub] = 1;
      }

      for (i = 0; i < x_size_idx_0; i++) {
        x_data[i] = (mask_data[i] == 1);
      }

      y = true;
      nz = 1;
      exitg1 = false;
      while ((!exitg1) && (nz <= x_size_idx_0)) {
        if (!x_data[nz - 1]) {
          y = false;
          exitg1 = true;
        } else {
          nz++;
        }
      }

      if (!y) {
        emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
          "MATLAB:categorical:CantCreateCategoryNames",
          "MATLAB:categorical:CantCreateCategoryNames", 0);
      }

      i = valueSet.size[0];
      this->categoryNames.size[0] = valueSet.size[0];
      for (b_i = 0; b_i < i; b_i++) {
        if (b_i > valueSet.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, valueSet.size[0] - 1,
            &k_emlrtBCI, &b_st);
        }

        if (b_i > valueSet.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, valueSet.size[0] - 1,
            &k_emlrtBCI, &b_st);
        }

        loop_ub = valueSet.data[b_i].f1.size[0] * valueSet.data[b_i].f1.size[1]
          - 1;
        if (b_i > this->categoryNames.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, this->categoryNames.size[0] - 1,
            &j_emlrtBCI, &b_st);
        }

        this->categoryNames.data[b_i].f1.size[0] = 1;
        if (b_i > valueSet.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, valueSet.size[0] - 1,
            &k_emlrtBCI, &b_st);
        }

        if (b_i > this->categoryNames.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, this->categoryNames.size[0] - 1,
            &j_emlrtBCI, &b_st);
        }

        this->categoryNames.data[b_i].f1.size[1] = valueSet.data[b_i].f1.size[1];
        nz = this->categoryNames.size[0];
        if (b_i > this->categoryNames.size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, this->categoryNames.size[0] - 1,
            &j_emlrtBCI, &b_st);
        }

        for (x_size_idx_0 = 0; x_size_idx_0 <= loop_ub; x_size_idx_0++) {
          if (b_i > nz - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, nz - 1, &b_emlrtBCI, &b_st);
          }

          if (b_i > valueSet.size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(b_i, 0, valueSet.size[0] - 1,
              &c_emlrtBCI, &b_st);
          }

          this->categoryNames.data[b_i].f1.data[x_size_idx_0] =
            valueSet.data[b_i].f1.data[x_size_idx_0];
        }
      }
    } else {
      this->categoryNames.size[0] = 0;
    }

    b_st.site = &ub_emlrtRSI;
    c_st.site = &xb_emlrtRSI;
    i = 0;
    nz = 0;
    exitg1 = false;
    while ((!exitg1) && (nz <= valueSet.size[0] - 1)) {
      if ((nz < 0) || (nz > valueSet.size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(nz, 0, valueSet.size[0] - 1, &e_emlrtBCI,
          &c_st);
      }

      if (internal::b_strcmp(inData[0].f1.data, inData[0].f1.size,
                             valueSet.data[nz].f1.data, valueSet.data[nz].
                             f1.size)) {
        i = nz + 1;
        exitg1 = true;
      } else {
        nz++;
      }
    }

    if (i < 0) {
      i = 0;
    }

    this->codes = static_cast<uint64_T>(i);
  }
}

// End of code generation (categorical.cpp)
