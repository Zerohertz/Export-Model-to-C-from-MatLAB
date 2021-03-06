//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  DeepLearningNetwork.cpp
//
//  Code generation for function 'DeepLearningNetwork'
//


// Include files
#include "DeepLearningNetwork.h"
#include "classifyX_data.h"
#include "classifyX_internal_types.h"
#include "classifyX_mexutil.h"
#include "rt_nonfinite.h"
#include "MWConvLayer.hpp"
#include "MWDeepLearningUtils.hpp"
#include "MWElementwiseAffineLayer.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"

// Function Definitions
void net0_0::allocate()
{
  this->targetImpl->allocate(2, this->layers, this->numLayers, 0);
  for (int32_T idx = 0; idx < 10; idx++) {
    this->layers[idx]->allocate();
  }

  (static_cast<MWTensor<real32_T> *>(this->inputTensors[0]))->setData
    (this->layers[0]->getLayerOutput(0));
}

void net0_0::cleanup()
{
  this->deallocate();
  for (int32_T idx = 0; idx < 10; idx++) {
    this->layers[idx]->cleanup();
  }

  if (this->targetImpl) {
    this->targetImpl->cleanup();
  }
}

void net0_0::deallocate()
{
  this->targetImpl->deallocate();
  for (int32_T idx = 0; idx < 10; idx++) {
    this->layers[idx]->deallocate();
  }
}

void net0_0::postsetup()
{
  this->targetImpl->postSetup();
}

void net0_0::resetState()
{
}

void net0_0::setSize()
{
  for (int32_T idx = 0; idx < 10; idx++) {
    this->layers[idx]->propagateSize();
  }

  this->allocate();
  this->postsetup();
}

void net0_0::setup()
{
  if (this->isInitialized) {
    this->resetState();
  } else {
    this->isInitialized = true;
    this->targetImpl->preSetup();
    (static_cast<MWInputLayer *>(this->layers[0]))->createInputLayer
      (this->targetImpl, this->inputTensors[0], 28, 28, 1, 0, "", 0);
    (static_cast<MWElementwiseAffineLayer *>(this->layers[1]))
      ->createElementwiseAffineLayer(this->targetImpl, this->layers[0]
      ->getOutputTensor(0), 1, 1, 1, 1, 1, 1, false, 1, 1,
      "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_imageinput_scale.bin",
      "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_imageinput_offset.bin",
      0);
    (static_cast<MWConvLayer *>(this->layers[2]))->createConvLayer
      (this->targetImpl, this->layers[1]->getOutputTensor(0), 5, 5, 1, 32, 3, 3,
       1, 1, 1, 1, 1, 1, 1,
       "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_conv_1_w.bin",
       "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_conv_1_b.bin",
       1);
    (static_cast<MWMaxPoolingLayer *>(this->layers[3]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[2]->getOutputTensor(0), 2, 2, 1, 1, 0, 0,
       0, 0, 0, 1, 0);
    (static_cast<MWConvLayer *>(this->layers[4]))->createConvLayer
      (this->targetImpl, this->layers[3]->getOutputTensor(0), 3, 3, 32, 64, 2, 2,
       0, 0, 0, 0, 1, 1, 1,
       "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_conv_2_w.bin",
       "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_conv_2_b.bin",
       1);
    (static_cast<MWMaxPoolingLayer *>(this->layers[5]))->createMaxPoolingLayer
      (this->targetImpl, this->layers[4]->getOutputTensor(0), 2, 2, 1, 1, 0, 0,
       0, 0, 0, 1, 0);
    (static_cast<MWFCLayer *>(this->layers[6]))->createFCLayer(this->targetImpl,
      this->layers[5]->getOutputTensor(0), 256, 256,
      "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_fc_1_w.bin",
      "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_fc_1_b.bin",
      1);
    (static_cast<MWFCLayer *>(this->layers[7]))->createFCLayer(this->targetImpl,
      this->layers[6]->getOutputTensor(0), 256, 5,
      "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_fc_2_w.bin",
      "D:\\Line-Center\\Export-Model-to-C-from-MatLAB\\CWT-CNN\\codegen\\mex\\classifyX\\cnn_net0_0_fc_2_b.bin",
      0);
    (static_cast<MWSoftmaxLayer *>(this->layers[8]))->createSoftmaxLayer
      (this->targetImpl, this->layers[7]->getOutputTensor(0), 1);
    (static_cast<MWOutputLayer *>(this->layers[9]))->createOutputLayer
      (this->targetImpl, this->layers[8]->getOutputTensor(0), 1);
    this->outputTensors[0] = this->layers[9]->getOutputTensor(0);
    this->setSize();
  }
}

int32_T net0_0::getBatchSize()
{
  return this->inputTensors[0]->getBatchSize();
}

real32_T *net0_0::getInputDataPointer(int32_T b_index)
{
  return (static_cast<MWTensor<real32_T> *>(this->inputTensors[b_index]))
    ->getData();
}

real32_T *net0_0::getInputDataPointer()
{
  return (static_cast<MWTensor<real32_T> *>(this->inputTensors[0]))->getData();
}

real32_T *net0_0::getLayerOutput(int32_T layerIndex, int32_T portIndex)
{
  return this->targetImpl->getLayerOutput(this->layers, layerIndex, portIndex);
}

real32_T *net0_0::getOutputDataPointer(int32_T b_index)
{
  return (static_cast<MWTensor<real32_T> *>(this->outputTensors[b_index]))
    ->getData();
}

real32_T *net0_0::getOutputDataPointer()
{
  return (static_cast<MWTensor<real32_T> *>(this->outputTensors[0]))->getData();
}

net0_0::net0_0()
{
  this->numLayers = 10;
  this->isInitialized = false;
  this->targetImpl = 0;
  this->layers[0] = new MWInputLayer;
  this->layers[0]->setName("imageinput");
  this->layers[1] = new MWElementwiseAffineLayer;
  this->layers[1]->setName("imageinput_normalization");
  this->layers[1]->setInPlaceIndex(0, 0);
  this->layers[2] = new MWConvLayer;
  this->layers[2]->setName("conv_1");
  this->layers[3] = new MWMaxPoolingLayer;
  this->layers[3]->setName("maxpool_1");
  this->layers[4] = new MWConvLayer;
  this->layers[4]->setName("conv_2");
  this->layers[5] = new MWMaxPoolingLayer;
  this->layers[5]->setName("maxpool_2");
  this->layers[6] = new MWFCLayer;
  this->layers[6]->setName("fc_1");
  this->layers[7] = new MWFCLayer;
  this->layers[7]->setName("fc_2");
  this->layers[8] = new MWSoftmaxLayer;
  this->layers[8]->setName("softmax");
  this->layers[9] = new MWOutputLayer;
  this->layers[9]->setName("classoutput");
  this->layers[9]->setInPlaceIndex(0, 0);
  this->targetImpl = new MWTargetNetworkImpl;
  this->inputTensors[0] = new MWTensor<real32_T>;
  this->inputTensors[0]->setHeight(28);
  this->inputTensors[0]->setWidth(28);
  this->inputTensors[0]->setChannels(1);
  this->inputTensors[0]->setBatchSize(1);
  this->inputTensors[0]->setSequenceLength(1);
}

net0_0::~net0_0()
{
  this->cleanup();
  for (int32_T idx = 0; idx < 10; idx++) {
    delete this->layers[idx];
  }

  if (this->targetImpl) {
    delete this->targetImpl;
  }

  delete this->inputTensors[0];
}

void net0_0::predict()
{
  for (int32_T idx = 0; idx < 10; idx++) {
    this->layers[idx]->predict();
  }
}

namespace coder
{
  void DeepLearningNetwork_setup(const emlrtStack *sp, net0_0 *obj)
  {
    TRY_DL_ERROR_CHECK();
    obj->setup();
    CATCH_DL_ERROR_CHECK();
    checkRunTimeError(sp, err.what(), __FILE__, __LINE__);
    LEAVE_DL_ERROR_CHECK();
  }
}

// End of code generation (DeepLearningNetwork.cpp)
