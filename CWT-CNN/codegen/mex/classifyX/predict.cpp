//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  predict.cpp
//
//  Code generation for function 'predict'
//


// Include files
#include "predict.h"
#include "DeepLearningNetwork.h"
#include "classifyX_data.h"
#include "classifyX_internal_types.h"
#include "classifyX_mexutil.h"
#include "rt_nonfinite.h"
#include "MWDeepLearningUtils.hpp"
#include "cnn_api.hpp"
#include <cstring>

// Type Definitions
struct cell_wrap_8
{
  real32_T f1[5];
};

struct cell_wrap_5
{
  real32_T f1[784];
};

// Variable Definitions
static emlrtRSInfo g_emlrtRSI = { 1,   // lineNo
  "DeepLearningNetwork/predict",       // fcnName
  "C:\\ProgramData\\MATLAB\\SupportPackages\\R2020b\\toolbox\\shared\\dlcoder_base\\supportpackages\\shared_dl_targets\\+coder\\@DeepLearningN"
  "etwork\\predict.p"                  // pathName
};

// Function Definitions
namespace coder
{
  void DeepLearningNetwork_predict(const emlrtStack *sp, net0_0 *obj, const
    uint8_T varargin_1[784], real32_T varargout_1[5])
  {
    cell_wrap_5 miniBatchT[1];
    cell_wrap_8 outputsMiniBatch[1];
    emlrtStack st;
    int32_T i;
    st.prev = sp;
    st.tls = sp->tls;
    for (i = 0; i < 28; i++) {
      for (int32_T i1 = 0; i1 < 28; i1++) {
        miniBatchT[0].f1[i1 + 28 * i] = varargin_1[i + 28 * i1];
      }
    }

    st.site = &g_emlrtRSI;
    memcpy(obj->getInputDataPointer(0), miniBatchT[0].f1, obj->layers[0]
           ->getOutputTensor(0)->getNumElements() * sizeof(real32_T));
    TRY_DL_ERROR_CHECK();
    obj->predict();
    CATCH_DL_ERROR_CHECK();
    checkRunTimeError(&st, err.what(), __FILE__, __LINE__);
    LEAVE_DL_ERROR_CHECK();
    memcpy(outputsMiniBatch[0].f1, obj->getLayerOutput(9, 0), obj->layers[9]
           ->getOutputTensor(0)->getNumElements() * sizeof(real32_T));
    for (i = 0; i < 5; i++) {
      varargout_1[i] = outputsMiniBatch[0].f1[i];
    }
  }
}

// End of code generation (predict.cpp)
