//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  classifyX.cpp
//
//  Code generation for function 'classifyX'
//


// Include files
#include "classifyX.h"
#include "DeepLearningNetwork.h"
#include "categorical.h"
#include "classifyX_data.h"
#include "classifyX_internal_types.h"
#include "postProcessOutputToReturnCategorical.h"
#include "predict.h"
#include "rt_nonfinite.h"

// Variable Definitions
static net0_0 net;
static boolean_T net_not_empty;
static emlrtRSInfo emlrtRSI = { 9,     // lineNo
  "classifyX",                         // fcnName
  "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\classifyX.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 4,   // lineNo
  "classifyX",                         // fcnName
  "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\classifyX.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 69,  // lineNo
  "loadDeepLearningNetwork",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\loadDeepLearningNetwork.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 1,   // lineNo
  "loadDeepLearningNetwork",           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\shared\\dlcoder_base\\dlcoder_base\\+coder\\+internal\\loadDeepLearningNetwork.p"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 1,   // lineNo
  "DeepLearningNetwork/callSetup",     // fcnName
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2020b\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearningN"
  "etwork\\DeepLearningNetwork.p"      // pathName
};

static emlrtRSInfo f_emlrtRSI = { 1,   // lineNo
  "DeepLearningNetwork/classify",      // fcnName
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2020b\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearningN"
  "etwork\\classify.p"                 // pathName
};

// Function Definitions
void classifyX(const emlrtStack *sp, const uint8_T X[784], coder::categorical
               *label)
{
  coder::categorical labelsCell[1];
  net0_0 *iobj_0;
  cell_wrap_7 rv[1];
  cell_wrap_7 r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  if (covrtLogIf(&emlrtCoverageInstance, 0, 0, 0, !net_not_empty)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
    st.site = &b_emlrtRSI;
    iobj_0 = &net;
    b_st.site = &c_emlrtRSI;
    c_st.site = &d_emlrtRSI;
    d_st.site = &e_emlrtRSI;
    d_st.site = &e_emlrtRSI;
    e_st.site = &e_emlrtRSI;
    coder::DeepLearningNetwork_setup(&e_st, iobj_0);
    net_not_empty = true;
  }

  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);

  // cfs = cwt(X);
  // IMG = uint8(mat2gray(abs(X))*255);
  // GryMat = imresize(IMG, [28 28]);
  st.site = &emlrtRSI;
  iobj_0 = &net;
  b_st.site = &f_emlrtRSI;
  coder::DeepLearningNetwork_predict(&b_st, iobj_0, X, r.f1);
  rv[0] = r;
  b_st.site = &f_emlrtRSI;
  coder::c_DeepLearningNetwork_postProce(&b_st, rv, labelsCell);
  *label = labelsCell[0];
}

void classifyX_init()
{
  net_not_empty = false;
}

// End of code generation (classifyX.cpp)
