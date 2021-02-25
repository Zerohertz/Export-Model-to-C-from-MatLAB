/* Copyright 2019-2020 The MathWorks, Inc. */
#ifndef __ELEMENTWISE_AFFINE_LAYER_IMPL_HPP
#define __ELEMENTWISE_AFFINE_LAYER_IMPL_HPP

#include "MWCNNLayerImpl.hpp"

/**
 *  Codegen class for Scaling Factor layer
 **/
class MWCNNLayer;
class MWTargetNetworkImpl;
class MWElementwiseAffineLayerImpl : public MWCNNLayerImpl {
  public:
    MWElementwiseAffineLayerImpl(MWCNNLayer* layer,
                                 MWTargetNetworkImpl* ntwk_impl,
                                 int scale_H,
                                 int scale_W,
                                 int scale_C,
                                 int offset_H,
                                 int offset_W,
                                 int offset_C,
                                 bool isClipped,
                                 int lowerbound,
                                 int upperbound,
                                 const char* scale_file,
                                 const char* offsetfile);
    ~MWElementwiseAffineLayerImpl();

    virtual void predict();
    virtual void cleanup();
    virtual void propagateSize();

  private:
    std::shared_ptr<mkldnn::memory> intermediateOutput;

    void loadScale(const char*);
    void loadOffset(const char*);
    float* qWwjVYwfnvEnFKlgpqwA;
    float* hljcfGWsvZXJZNrImpJB;
    std::shared_ptr<float> intermediateOp;
    double sRECVoNNtDdcBOWgDyar;
    double sxuOMwKXOKfuExclRaSe;
    double rSmEWccbJFfPGddhPemm;
    double iPqBiFnIJMxelVhQBZex;
    double jaqKGCwoANNDMHgAsehk;
    double hnewnpwgzKmOdualajhn;
    bool bDTIjtxZiSHtjwzgEluE;
    int eVAFqeShtGZAZluKdMvQ;
    int vIWQzNvYZSuxmOTVDFhU;

    /* if the scale and offset are both scalar values then use this primitive*/
    std::unique_ptr<mkldnn::eltwise_forward::desc> scaling_d;
    std::unique_ptr<mkldnn::eltwise_forward::primitive_desc> scaling_pd;
    std::unique_ptr<mkldnn::eltwise_forward::primitive> scaling;


    void clipAffineOutput();
    void channelWiseOffsetAdd();
    void createScalarAffine();
    void createVectorAffine();
};



#endif
