//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: classifyX_internal_types.h
//
// MATLAB Coder version            : 5.1
// C/C++ source code generated on  : 24-Feb-2021 20:45:00
//
#ifndef CLASSIFYX_INTERNAL_TYPES_H
#define CLASSIFYX_INTERNAL_TYPES_H

// Include Files
#include "classifyX_types.h"
#include "rtwtypes.h"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"

// Type Definitions
struct cell_wrap_7
{
  float f1[5];
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
  float *getLayerOutput(int layerIndex, int portIndex);
  float *getInputDataPointer(int b_index);
  float *getInputDataPointer();
  float *getOutputDataPointer(int b_index);
  float *getOutputDataPointer();
  int getBatchSize();
  ~net0_0();
 private:
  void allocate();
  void postsetup();
  void deallocate();
 public:
  int numLayers;
  MWCNNLayer *layers[10];
 private:
  boolean_T isInitialized;
  MWTensorBase *inputTensors[1];
  MWTensorBase *outputTensors[1];
  MWTargetNetworkImpl *targetImpl;
};

#endif

//
// File trailer for classifyX_internal_types.h
//
// [EOF]
//
