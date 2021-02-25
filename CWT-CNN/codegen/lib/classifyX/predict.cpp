//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: predict.cpp
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//

// Include Files
#include "predict.h"
#include "DeepLearningNetwork.h"
#include "classifyX_internal_types.h"
#include "cnn_api.hpp"
#include <cstring>

// Type Definitions
struct cell_wrap_8
{
  float f1[5];
};

struct cell_wrap_5
{
  float f1[784];
};

// Function Definitions
//
// Arguments    : net0_0 *obj
//                const unsigned char varargin_1[784]
//                float varargout_1[5]
// Return Type  : void
//
namespace coder
{
  void DeepLearningNetwork_predict(net0_0 *obj, const unsigned char varargin_1
    [784], float varargout_1[5])
  {
    cell_wrap_5 miniBatchT[1];
    cell_wrap_8 outputsMiniBatch[1];
    int i;
    for (i = 0; i < 28; i++) {
      for (int i1 = 0; i1 < 28; i1++) {
        miniBatchT[0].f1[i1 + 28 * i] = varargin_1[i + 28 * i1];
      }
    }

    memcpy(obj->getInputDataPointer(0), miniBatchT[0].f1, obj->layers[0]
           ->getOutputTensor(0)->getNumElements() * sizeof(float));
    obj->predict();
    memcpy(outputsMiniBatch[0].f1, obj->getLayerOutput(9, 0), obj->layers[9]
           ->getOutputTensor(0)->getNumElements() * sizeof(float));
    for (i = 0; i < 5; i++) {
      varargout_1[i] = outputsMiniBatch[0].f1[i];
    }
  }
}

//
// File trailer for predict.cpp
//
// [EOF]
//
