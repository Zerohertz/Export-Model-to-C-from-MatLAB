//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  classifyX_internal_types.h
//
//  Code generation for function 'classifyX'
//


#pragma once

// Include files
#include "classifyX_types.h"
#include "rtwtypes.h"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include "emlrt.h"

// Type Definitions
struct cell_wrap_7
{
  real32_T f1[5];
};

class net0_0
{
 public:
  net0_0();
  void setSize();
  void resetState();
  void setup();
  void predict();
  void cleanup();
  real32_T *getLayerOutput(int32_T layerIndex, int32_T portIndex);
  real32_T *getInputDataPointer(int32_T b_index);
  real32_T *getInputDataPointer();
  real32_T *getOutputDataPointer(int32_T b_index);
  real32_T *getOutputDataPointer();
  int32_T getBatchSize();
  ~net0_0();
 private:
  void allocate();
  void postsetup();
  void deallocate();
 public:
  int32_T numLayers;
  MWCNNLayer *layers[10];
 private:
  boolean_T isInitialized;
  MWTensorBase *inputTensors[1];
  MWTensorBase *outputTensors[1];
  MWTargetNetworkImpl *targetImpl;
};

// End of code generation (classifyX_internal_types.h)
