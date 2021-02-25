#include <cassert>
#include <cstring>
#include <stdio.h>
#include "MWCNNLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include "MWMkldnnUtils.hpp"
#include "mkldnn.hpp"
 MWCNNLayerImpl::MWCNNLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : bUVPfnrJhLfHzOLUUrKk(layer) , eqOmMKQRpqBqRQCnJmxt(ntwk_impl) { } 
std::shared_ptr<mkldnn::memory> MWCNNLayerImpl::getLayerMemory(int index) { if 
(layerMemory.size() >= 1) { std::map<int, 
std::shared_ptr<mkldnn::memory>>::iterator it = layerMemory.find(index); return 
it->second; } else { return nullptr; } } std::shared_ptr<mkldnn::memory> 
MWCNNLayerImpl::getReorderedIpMemory(int index) { if (reorderLayerMemory.size() 
>= 1) { std::map<int, std::shared_ptr<mkldnn::memory>>::iterator it = 
reorderLayerMemory.find(index); return it->second; } else { return nullptr; } } 
std::shared_ptr<mkldnn::reorder> MWCNNLayerImpl::getReorderPrim(int index) { if 
(reorderPrim.size() >= 1) { std::map<int, 
std::shared_ptr<mkldnn::reorder>>::iterator it = reorderPrim.find(index); 
return it->second; } else { return nullptr; } } void 
MWCNNLayerImpl::setLayerMemory(std::shared_ptr<mkldnn::memory> other, int 
index) { layerMemory[index] = other; } void 
MWCNNLayerImpl::setReorderPrim(std::shared_ptr<mkldnn::reorder> other, int 
index) { reorderPrim[index] = other; } void 
MWCNNLayerImpl::setReorderLayerMemory(std::shared_ptr<mkldnn::memory> other, 
int index) { reorderLayerMemory[index] = other; } template <class T> void 
MWCNNLayerImpl::allocateOutputData(int outIdx) { MWTensorBase* opTensorBase = 
getLayer()->getOutputTensor(outIdx); MWTensor<T>* opTensor = 
static_cast<MWTensor<T>*>(opTensorBase); int outBufIndex = 
opTensor->getopBufIndex(); int inIdx = getLayer()->getInPlaceIndex(outIdx); if 
(inIdx != -1) {  
opTensor->setData((T*)getReorderedIpMemory(inIdx)->get_data_handle()); } else { 
 if (outBufIndex < 0) { int fSKMHAqIghbYYgyIpNDw = 
static_cast<int>(this->getLayerMemory()->get_desc().get_size() / sizeof(T)); 
opTensor->setData((T*)calloc(fSKMHAqIghbYYgyIpNDw, sizeof(T))); } else {  
assert(opTensorBase->isFloat()); static_cast<MWTensor<float>*>(opTensorBase) 
->setData(eqOmMKQRpqBqRQCnJmxt->memBuffer[outBufIndex]); } } 
MWMkldnnUtils::getLayerMemoryPrimitive(opTensor)->set_data_handle(opTensor->getData()); 
} template void MWCNNLayerImpl::allocateOutputData<float>(int); template void 
MWCNNLayerImpl::allocateOutputData<signed char>(int); template <class T> void 
MWCNNLayerImpl::deallocateOutputData(int outIdx) { MWTensorBase* opTensorBase = 
getLayer()->getOutputTensor(outIdx); MWTensor<T>* opTensor = 
static_cast<MWTensor<T>*>(opTensorBase); bool doBufReleaseFlag = 
opTensor->getopBufIndex() < 0 && getLayer()->getInPlaceIndex(outIdx) == -1; T* 
opDataBuf = opTensor->getData(); if (opDataBuf) { if (doBufReleaseFlag) { 
free(opDataBuf); } opTensor->setData((T*)NULL); } return; } template void 
MWCNNLayerImpl::deallocateOutputData<float>(int); template void 
MWCNNLayerImpl::deallocateOutputData<signed char>(int); void 
MWCNNLayerImpl::clearLayerMapsAndVectors() { reorderLayerMemory.clear(); 
reorderPrim.clear(); pipeline.clear(); pipeline_memory_args.clear(); 
pipeline_weights_memory_args.clear(); pipeline_weights.clear(); } 
MWInputLayerImpl::MWInputLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { }
#if MW_LAYERS_TAP
 int tap_count = 0; void mw_interm_tap(float* inp, int size, int count) { FILE* 
fp; int i; std::string fileName{"taps/mw_interm_tap_"};
#define TXT_FILE 1
#if TXT_FILE
 fileName = fileName + std::to_string(count) + ".txt"; fp = 
fopen(fileName.c_str(), "w"); if (fp == NULL) { std::string errmsg = 
std::string("Error opening text file .Create taps folder to open") + fileName; 
printf("Error! Unable to open file %s\n", fileName); throw 
std::runtime_error(errmsg.c_str()); } for (i = 0; i < size; i++) { fprintf(fp, 
"%f\n", inp[i]); }
#else
 fileName = fileName + std::to_string(count) + ".bin"; fp = 
fopen(fileName.c_str(), "wb"); if (fp == NULL) { std::string errmsg = 
std::string("Error opening binary file .Create taps folder to open") + 
fileName; printf("Error! Unable to open file %s\n", fileName); throw 
std::runtime_error(errmsg.c_str()); } fwrite(inp, 4, size, fp);
#endif
 fclose(fp); } void MWCNNLayerImpl::reorderedLayerOutputTap(int portIndex) { 
MWTensorBase* opTensorBase = getLayer()->getOutputTensor(portIndex); 
MWTensor<float>* opTensor = static_cast<MWTensor<float>*>(opTensorBase); 
MWCNNLayerImpl* layerImpl = bUVPfnrJhLfHzOLUUrKk->getImpl(); int layerOutputSize = 
opTensor->getBatchSize() * opTensor->getSequenceLength() * 
opTensor->getChannels() * opTensor->getHeight() * opTensor->getWidth(); float* 
layerData = (float*)calloc(layerOutputSize, sizeof(float)); 
std::shared_ptr<mkldnn::memory> currentLayerMemory = 
MWMkldnnUtils::getLayerMemoryPrimitive(opTensor); bool isMemPrimitiveNC = 
MWMkldnnUtils::checkformatType(currentLayerMemory->get_desc(), opTensor, 
mkldnn::memory::format_tag::nc); bool isMemPrimitiveNCHW = 
MWMkldnnUtils::checkformatType( currentLayerMemory->get_desc(), opTensor, 
mkldnn::memory::format_tag::nchw); bool isMemPrimitiveTNC = 
MWMkldnnUtils::checkformatType( currentLayerMemory->get_desc(), opTensor, 
mkldnn::memory::format_tag::tnc); auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); if (!(isMemPrimitiveNC || 
isMemPrimitiveNCHW || isMemPrimitiveTNC)) { 
MWMkldnnUtils::configureReorder(layerImpl, opTensor, 
mkldnn::memory::format_tag::nchw); pipeline.clear(); 
pipeline_memory_args.clear(); pipeline_memory_args.push_back( 
{{MKLDNN_ARG_FROM, *MWMkldnnUtils::getLayerMemoryPrimitive(opTensor)}, 
{MKLDNN_ARG_TO, *getReorderedIpMemory()}}); 
pipeline.push_back(*layerImpl->getReorderPrim()); assert(pipeline.size() == 
pipeline_memory_args.size()); pipeline[0].execute(s, pipeline_memory_args[0]); 
memcpy(layerData, (float*)layerImpl->getReorderedIpMemory()->get_data_handle(), 
layerOutputSize * sizeof(float)); } else { memcpy(layerData, 
opTensor->getData(), layerOutputSize * sizeof(float)); } 
mw_interm_tap(layerData, layerOutputSize, tap_count++); if (layerData) { 
free(layerData); layerData = NULL; } }
#endif
 void MWInputLayerImpl::propagateSize() { MWTensorBase* ipTensor = 
getLayer()->getInputTensor(0); mkldnn::memory::dims layerMemoryDimensions = 
{ipTensor->getBatchSize(), ipTensor->getChannels(), ipTensor->getHeight(), 
ipTensor->getWidth()}; auto layerMemoryDescriptor = mkldnn::memory::desc( 
layerMemoryDimensions, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::nchw); setLayerMemory( 
std::make_shared<mkldnn::memory>(layerMemoryDescriptor, 
*eqOmMKQRpqBqRQCnJmxt->eng)); return; } void MWInputLayerImpl::predict() {
#if MW_INPUT_TAP
 reorderedLayerOutputTap(0);
#endif
 } MWReLULayerImpl::MWReLULayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { } 
MWReLULayerImpl::~MWReLULayerImpl() { } void MWReLULayerImpl::propagateSize() { 
clearLayerMapsAndVectors(); MWMkldnnUtils::reorderInputsTo(this); const float 
negative_slope = 0.0; 
setLayerMemory(std::make_shared<mkldnn::memory>(getReorderedIpMemory()->get_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng)); relu_d = 
std::unique_ptr<mkldnn::eltwise_forward::desc>(new 
mkldnn::eltwise_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::eltwise_relu, getReorderedIpMemory()->get_desc(), 
negative_slope)); relu_pd = 
std::unique_ptr<mkldnn::eltwise_forward::primitive_desc>( new 
mkldnn::eltwise_forward::primitive_desc(*relu_d, *eqOmMKQRpqBqRQCnJmxt->eng)); 
relu = std::unique_ptr<mkldnn::eltwise_forward>(new 
mkldnn::eltwise_forward(*relu_pd)); pipeline_memory_args.push_back( 
{{MKLDNN_ARG_FROM, *getReorderedIpMemory()}, {MKLDNN_ARG_TO, 
*getLayerMemory()}}); pipeline.push_back(*relu); } void 
MWReLULayerImpl::predict() { auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_RELU_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } MWNormLayerImpl::MWNormLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, unsigned IAlDgIFcchbwRGBSfVfA, double 
AFQBkxwYGKLsACiDKwRM, double AHqhysOOIgbDpWZoPUFT, double BRSPqxNffoBYKqpSVHne) : 
MWCNNLayerImpl(layer, ntwk_impl) , AFQBkxwYGKLsACiDKwRM(AFQBkxwYGKLsACiDKwRM) , 
AHqhysOOIgbDpWZoPUFT(AHqhysOOIgbDpWZoPUFT) , BRSPqxNffoBYKqpSVHne(BRSPqxNffoBYKqpSVHne) , 
IAlDgIFcchbwRGBSfVfA(IAlDgIFcchbwRGBSfVfA) { } 
MWNormLayerImpl::~MWNormLayerImpl() { } void MWNormLayerImpl::propagateSize() { 
MWMkldnnUtils::reorderInputsTo(this); 
setLayerMemory(std::make_shared<mkldnn::memory>(getReorderedIpMemory()->get_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng)); lrn_d = 
std::unique_ptr<mkldnn::lrn_forward::desc>(new mkldnn::lrn_forward::desc( 
mkldnn::prop_kind::forward_inference, mkldnn::algorithm::lrn_across_channels, 
getReorderedIpMemory()->get_desc(), IAlDgIFcchbwRGBSfVfA, 
(float)(AFQBkxwYGKLsACiDKwRM), (float)AHqhysOOIgbDpWZoPUFT, (float)BRSPqxNffoBYKqpSVHne)); 
lrn_pd = std::unique_ptr<mkldnn::lrn_forward::primitive_desc>( new 
mkldnn::lrn_forward::primitive_desc(*lrn_d, *eqOmMKQRpqBqRQCnJmxt->eng)); lrn = 
std::unique_ptr<mkldnn::lrn_forward>(new mkldnn::lrn_forward(*lrn_pd)); 
pipeline_memory_args.push_back( {{MKLDNN_ARG_FROM, *getReorderedIpMemory()}, 
{MKLDNN_ARG_TO, *getLayerMemory()}}); pipeline.push_back(*lrn); return; } void 
MWNormLayerImpl::predict() { auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_NORM_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } MWMaxPoolingLayerImpl::MWMaxPoolingLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int FrpxvsDMwwgbpqHXWxmN, int GsZlHFuhbvjLtRMDjXnW, int 
HJHXkKmgFxxIOsIvRRnF, int HtQBsWTCGEkpylRklilw, int CpMjJjtGOeWOzwxpAAQP, int 
ClEhcJFlvGCgiavziIag, int EvebzoroiuKkIxwjkGnD, int FeVcBgtQmTLtmnNcJGMY, 
bool IwKnaBoXVubIRYcxEJLH, int fhikqqlnUKCjleVKDqiG) : MWCNNLayerImpl(layer, 
ntwk_impl) , BLjrjqvCcCommiXWQLjs(IwKnaBoXVubIRYcxEJLH) , 
FrpxvsDMwwgbpqHXWxmN(FrpxvsDMwwgbpqHXWxmN) , GsZlHFuhbvjLtRMDjXnW(GsZlHFuhbvjLtRMDjXnW) , 
CpMjJjtGOeWOzwxpAAQP(CpMjJjtGOeWOzwxpAAQP) , 
ClEhcJFlvGCgiavziIag(ClEhcJFlvGCgiavziIag) , 
EvebzoroiuKkIxwjkGnD(EvebzoroiuKkIxwjkGnD) , 
FeVcBgtQmTLtmnNcJGMY(FeVcBgtQmTLtmnNcJGMY) , 
HJHXkKmgFxxIOsIvRRnF(HJHXkKmgFxxIOsIvRRnF) , HtQBsWTCGEkpylRklilw(HtQBsWTCGEkpylRklilw) 
, fhikqqlnUKCjleVKDqiG(fhikqqlnUKCjleVKDqiG) { } 
MWMaxPoolingLayerImpl::~MWMaxPoolingLayerImpl() { } float* 
MWMaxPoolingLayerImpl::getIndexData() { return WIxRBCJtmETvfxpuRuus; } 
std::shared_ptr<mkldnn::pooling_forward::primitive_desc> 
MWMaxPoolingLayerImpl::getPoolPrimitiveDesc() { return pool_pd; } 
mkldnn::memory::dims MWMaxPoolingLayerImpl::getPoolKernel() { return 
FwLnexHgxHRquTKmNpoa; } mkldnn::memory::dims 
MWMaxPoolingLayerImpl::getPoolStrides() { return GnxRkpzrPZimKtYYHSuG; } 
mkldnn::memory::dims MWMaxPoolingLayerImpl::getPoolPadTL() { return 
GeeOVBfQrpMacIFBLKOo; } mkldnn::memory::dims 
MWMaxPoolingLayerImpl::getPoolPadBR() { return GFienSVKLlDQuZeqAdLC; } void 
createMaxpoolingIndicesPrimitive( mkldnn::memory::desc pool_dst_md, 
std::shared_ptr<mkldnn::pooling_forward::desc> pool_d, 
std::shared_ptr<mkldnn::pooling_forward::primitive_desc>& pool_pd, 
std::shared_ptr<mkldnn::memory> srcMemory, std::shared_ptr<mkldnn::memory>& 
layerMemory, std::shared_ptr<mkldnn::memory>& indices_Memory, 
std::shared_ptr<mkldnn::pooling_forward::primitive>& pool, mkldnn::memory::dims 
FwLnexHgxHRquTKmNpoa, mkldnn::memory::dims GnxRkpzrPZimKtYYHSuG, 
mkldnn::memory::dims GeeOVBfQrpMacIFBLKOo, mkldnn::memory::dims 
GFienSVKLlDQuZeqAdLC) { pool_d = 
std::make_shared<mkldnn::pooling_forward::desc>( 
mkldnn::prop_kind::forward_training, mkldnn::algorithm::pooling_max, 
srcMemory->get_desc(), pool_dst_md, GnxRkpzrPZimKtYYHSuG, FwLnexHgxHRquTKmNpoa, 
GeeOVBfQrpMacIFBLKOo, GFienSVKLlDQuZeqAdLC); pool_pd = 
std::make_shared<mkldnn::pooling_forward::primitive_desc>(*pool_d, 
srcMemory->get_engine()); layerMemory = 
std::make_shared<mkldnn::memory>(pool_pd->dst_desc(), srcMemory->get_engine()); 
indices_Memory = std::make_shared<mkldnn::memory>(pool_pd->workspace_desc(), 
srcMemory->get_engine()); pool = 
std::make_shared<mkldnn::pooling_forward>(*pool_pd); } void 
createMaxpoolingPrimitive(mkldnn::memory::desc pool_dst_md, 
std::shared_ptr<mkldnn::pooling_forward::desc> pool_d, 
std::shared_ptr<mkldnn::pooling_forward::primitive_desc>& pool_pd, 
std::shared_ptr<mkldnn::memory> srcMemory, std::shared_ptr<mkldnn::memory>& 
layerMemory, std::shared_ptr<mkldnn::pooling_forward::primitive>& pool, 
mkldnn::memory::dims FwLnexHgxHRquTKmNpoa, mkldnn::memory::dims 
GnxRkpzrPZimKtYYHSuG, mkldnn::memory::dims GeeOVBfQrpMacIFBLKOo, 
mkldnn::memory::dims GFienSVKLlDQuZeqAdLC) { pool_d = 
std::make_shared<mkldnn::pooling_forward::desc>( 
mkldnn::prop_kind::forward_inference, mkldnn::algorithm::pooling_max, 
srcMemory->get_desc(), pool_dst_md, GnxRkpzrPZimKtYYHSuG, FwLnexHgxHRquTKmNpoa, 
GeeOVBfQrpMacIFBLKOo, GFienSVKLlDQuZeqAdLC); pool_pd = 
std::make_shared<mkldnn::pooling_forward::primitive_desc>(*pool_d, 
srcMemory->get_engine()); layerMemory = 
std::make_shared<mkldnn::memory>(pool_pd->dst_desc(), srcMemory->get_engine()); 
pool = std::make_shared<mkldnn::pooling_forward>(*pool_pd); } void 
MWMaxPoolingLayerImpl::propagateSize() { MWMaxPoolingLayer* maxPoolLayer = 
static_cast<MWMaxPoolingLayer*>(getLayer()); MWTensorBase* ipTensor = 
maxPoolLayer->getInputTensor(); MWTensorBase* opTensor = 
maxPoolLayer->getOutputTensor(); MWMkldnnUtils::reorderInputsTo(this); int n = 
ipTensor->getBatchSize(); int c = ipTensor->getChannels(); int h = 
ipTensor->getHeight(); int w = ipTensor->getWidth(); mkldnn::memory::dims 
pool_usr_tz = {n, c, h, w}; mkldnn::memory::dims pool_dst_tz = {n, c, 
opTensor->getHeight(), opTensor->getWidth()}; FwLnexHgxHRquTKmNpoa = 
{FrpxvsDMwwgbpqHXWxmN, GsZlHFuhbvjLtRMDjXnW}; GnxRkpzrPZimKtYYHSuG = 
{HJHXkKmgFxxIOsIvRRnF, HtQBsWTCGEkpylRklilw}; GeeOVBfQrpMacIFBLKOo = 
{CpMjJjtGOeWOzwxpAAQP, EvebzoroiuKkIxwjkGnD}; GFienSVKLlDQuZeqAdLC = 
{ClEhcJFlvGCgiavziIag, FeVcBgtQmTLtmnNcJGMY}; auto pool_dst_md = 
mkldnn::memory::desc({pool_dst_tz}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any); if (BLjrjqvCcCommiXWQLjs) { 
createMaxpoolingIndicesPrimitive(pool_dst_md, pool_d, pool_pd, 
getReorderedIpMemory(), layerMemory[0], layerMemory[1], pool, 
FwLnexHgxHRquTKmNpoa, GnxRkpzrPZimKtYYHSuG, GeeOVBfQrpMacIFBLKOo, 
GFienSVKLlDQuZeqAdLC); fYaOQTeunPwVjnhhTECh = 
static_cast<int>(getLayerMemory(1)->get_desc().get_size() / sizeof(float)); 
pipeline_memory_args.push_back({{MKLDNN_ARG_FROM, *getReorderedIpMemory()}, 
{MKLDNN_ARG_DST, *layerMemory[0]}, {MKLDNN_ARG_WORKSPACE, *layerMemory[1]}}); } 
else { createMaxpoolingPrimitive(pool_dst_md, pool_d, pool_pd, 
getReorderedIpMemory(), layerMemory[0], pool, FwLnexHgxHRquTKmNpoa, 
GnxRkpzrPZimKtYYHSuG, GeeOVBfQrpMacIFBLKOo, GFienSVKLlDQuZeqAdLC); 
pipeline_memory_args.push_back( {{MKLDNN_ARG_FROM, *getReorderedIpMemory()}, 
{MKLDNN_ARG_DST, *layerMemory[0]}}); } pipeline.push_back(*pool); return; } 
void MWMaxPoolingLayerImpl::predict() { auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_POOL_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } MWFCLayerImpl::~MWFCLayerImpl() { } 
MWFCLayerImpl::MWFCLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* ntwk_impl, 
int XLJXOFXdnZOyJvtltbyr, int oYbqYsqgVhrUzFEKbBbR, const char* 
zzWugmJRYlNEuAzHMpeQ, const char* ONvcEjLBnVNUdjMKOAwF) : 
MWCNNLayerImpl(layer, ntwk_impl) { veFyKKHbdqBIvQLYBqfF = 
(float*)calloc(XLJXOFXdnZOyJvtltbyr * oYbqYsqgVhrUzFEKbBbR, sizeof(float)); 
NDjzAZSYJuWymuKDNZYB = (float*)calloc(oYbqYsqgVhrUzFEKbBbR, sizeof(float)); 
loadWeights(zzWugmJRYlNEuAzHMpeQ, XLJXOFXdnZOyJvtltbyr * 
oYbqYsqgVhrUzFEKbBbR); loadBias(ONvcEjLBnVNUdjMKOAwF, oYbqYsqgVhrUzFEKbBbR); 
mkldnn::memory::dims fc_bias_tz = {oYbqYsqgVhrUzFEKbBbR}; bias_md = 
std::make_shared<mkldnn::memory::desc>(fc_bias_tz, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::x); bias = 
std::make_shared<mkldnn::memory>(*bias_md, *eqOmMKQRpqBqRQCnJmxt->eng, 
NDjzAZSYJuWymuKDNZYB); } void MWFCLayerImpl::propagateSize() { 
clearLayerMapsAndVectors(); MWFCLayer* fcLayer = 
static_cast<MWFCLayer*>(getLayer()); MWTensorBase* ipTensor = 
fcLayer->getInputTensor(); MWTensorBase* opTensor = fcLayer->getOutputTensor(); 
mkldnn::memory::dims fc_src_tz = {ipTensor->getBatchSize() * 
ipTensor->getSequenceLength(), ipTensor->getChannels(), ipTensor->getHeight(), 
ipTensor->getWidth()}; mkldnn::memory::dims dim1 = {opTensor->getChannels(), 
ipTensor->getChannels()}; mkldnn::memory::dims dim2 = {opTensor->getChannels(), 
ipTensor->getChannels(), ipTensor->getHeight(), ipTensor->getWidth()}; auto 
prevMemoryDesc = MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor)->get_desc(); 
format_type formatTag = MWMkldnnUtils::getformatType(prevMemoryDesc, ipTensor); 
bool isSequenceIp = (formatTag == format_type::TNC_FORMAT) || (formatTag == 
format_type::CNT_FORMAT); bool dimNCHWFlag = ((ipTensor->getHeight() != 1) && 
(ipTensor->getWidth() != 1)) || !(isSequenceIp); fc_src_memory = 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor); 
std::shared_ptr<mkldnn::memory::desc> fc_src_md; if (isSequenceIp) { 
MWMkldnnUtils::reorderInputsTo(this, format_type::TNC_FORMAT); fc_src_tz = 
{ipTensor->getBatchSize() * ipTensor->getSequenceLength(), 
ipTensor->getChannels()}; fc_src_md = std::make_shared<mkldnn::memory::desc>( 
fc_src_tz, mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::nc); 
fc_src_memory = getReorderedIpMemory(); } else { fc_src_md = 
std::make_shared<mkldnn::memory::desc>( fc_src_tz, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any); } 
mkldnn::memory::dims fc_weights_tz = (dimNCHWFlag) ? dim2 : dim1; if 
(dimNCHWFlag) { weights_md = std::make_shared<mkldnn::memory::desc>( 
fc_weights_tz, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::oihw); } else { weights_md = 
std::make_shared<mkldnn::memory::desc>( fc_weights_tz, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::nc); } 
mkldnn::memory::desc fc_weights_md = mkldnn::memory::desc(fc_weights_tz, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any); 
prepareWeights(); weights = std::make_shared<mkldnn::memory>(*weights_md, 
*eqOmMKQRpqBqRQCnJmxt->eng, veFyKKHbdqBIvQLYBqfF); auto fc_bias_md = 
mkldnn::memory::desc( {opTensor->getChannels()}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any); auto 
fc_dst_md = mkldnn::memory::desc( {ipTensor->getSequenceLength() * 
ipTensor->getBatchSize(), opTensor->getChannels()}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any); ip_d = 
std::unique_ptr<mkldnn::inner_product_forward::desc>( new 
mkldnn::inner_product_forward::desc(mkldnn::prop_kind::forward, *fc_src_md, 
fc_weights_md, fc_bias_md, fc_dst_md)); ip_pd = 
std::unique_ptr<mkldnn::inner_product_forward::primitive_desc>( new 
mkldnn::inner_product_forward::primitive_desc(*ip_d, 
*eqOmMKQRpqBqRQCnJmxt->eng)); if (dimNCHWFlag) { if 
(mkldnn::memory::desc(ip_pd->src_desc()) != fc_src_memory->get_desc()) { 
fc_src_memory = std::make_shared<mkldnn::memory>(ip_pd->src_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng); fc_reorder_src = 
std::unique_ptr<mkldnn::reorder>(new mkldnn::reorder( 
*MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor), *fc_src_memory)); 
pipeline_memory_args.push_back( {{MKLDNN_ARG_FROM, 
*MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor)}, {MKLDNN_ARG_TO, 
*fc_src_memory}}); pipeline.push_back(*fc_reorder_src); } } fc_weights_memory = 
weights; if (mkldnn::memory::desc(ip_pd->weights_desc()) != 
fc_weights_memory->get_desc()) { fc_weights_memory = 
std::make_shared<mkldnn::memory>(ip_pd->weights_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng); fc_reorder_weights = 
std::unique_ptr<mkldnn::reorder>(new mkldnn::reorder(*weights, 
*fc_weights_memory)); pipeline_weights.push_back(*fc_reorder_weights); auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); 
pipeline_weights_memory_args.push_back( {{MKLDNN_ARG_FROM, *weights}, 
{MKLDNN_ARG_TO, *fc_weights_memory}}); assert(pipeline_weights.size() == 
pipeline_weights_memory_args.size()); for (int i = 0; i < 
pipeline_weights.size(); i++) { pipeline_weights[i].execute(s, 
pipeline_weights_memory_args[i]); } } mkldnn::memory::desc layerOpdesc; if 
(isSequenceIp) { layerOpdesc = mkldnn::memory::desc( 
{ipTensor->getSequenceLength(), ipTensor->getBatchSize(), 
opTensor->getChannels()}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::tnc); } else { layerOpdesc = 
mkldnn::memory::desc({ipTensor->getBatchSize(), opTensor->getChannels(), 
opTensor->getHeight(), opTensor->getWidth()}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::nchw); } assert(opTensor->getHeight() == 1 && 
opTensor->getWidth() == 1); 
setLayerMemory(std::make_shared<mkldnn::memory>(layerOpdesc, 
*eqOmMKQRpqBqRQCnJmxt->eng)); ip = 
std::unique_ptr<mkldnn::inner_product_forward>(new 
mkldnn::inner_product_forward(*ip_pd)); 
pipeline_memory_args.push_back({{MKLDNN_ARG_SRC, *fc_src_memory}, 
{MKLDNN_ARG_WEIGHTS, *fc_weights_memory}, {MKLDNN_ARG_BIAS, *bias}, 
{MKLDNN_ARG_DST, *getLayerMemory()}}); pipeline.push_back(*ip); return; } void 
MWFCLayerImpl::predict() { auto s = mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); 
assert(pipeline.size() == pipeline_memory_args.size()); for (int i = 0; i < 
pipeline.size(); i++) { pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_FC_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } void MWFCLayerImpl::loadWeights(const char* SDWKEQTZaTFZByPlzUDR, int 
euppfEoiaoCTcVgRPVhA) { FILE* SIBpKtDURUWQaaenbwrC = 
MWCNNLayer::openBinaryFile(SDWKEQTZaTFZByPlzUDR); call_fread(veFyKKHbdqBIvQLYBqfF, 
sizeof(float), euppfEoiaoCTcVgRPVhA, SIBpKtDURUWQaaenbwrC, SDWKEQTZaTFZByPlzUDR); 
fclose(SIBpKtDURUWQaaenbwrC); return; } void MWFCLayerImpl::prepareWeights() { 
MWTensorBase* ipTensor = getLayer()->getInputTensor(); MWTensorBase* opTensor = 
getLayer()->getOutputTensor(); int AwZQzUhuWVLGrWgLHRuM = 
ipTensor->getHeight(); int AzTsxYcYjIEJsGQbeYHm = ipTensor->getWidth(); int 
CGbFsczkgkhjcHoCKzBx = AwZQzUhuWVLGrWgLHRuM * AzTsxYcYjIEJsGQbeYHm 
* ipTensor->getChannels(); int euppfEoiaoCTcVgRPVhA = CGbFsczkgkhjcHoCKzBx * 
opTensor->getChannels(); if (AwZQzUhuWVLGrWgLHRuM != 1 && 
AzTsxYcYjIEJsGQbeYHm != 1) { float* vjDFlBZzKvbpPseAtMBP = 
(float*)malloc(sizeof(float) * AwZQzUhuWVLGrWgLHRuM * 
AzTsxYcYjIEJsGQbeYHm); for (int k = 0; k < euppfEoiaoCTcVgRPVhA / 
AwZQzUhuWVLGrWgLHRuM / AzTsxYcYjIEJsGQbeYHm; k++) { for (int i = 0; i < 
AwZQzUhuWVLGrWgLHRuM * AzTsxYcYjIEJsGQbeYHm; i++) { vjDFlBZzKvbpPseAtMBP[i] = 
veFyKKHbdqBIvQLYBqfF[k * AwZQzUhuWVLGrWgLHRuM * AzTsxYcYjIEJsGQbeYHm + i]; } for 
(int j = 0; j < AwZQzUhuWVLGrWgLHRuM; j++) for (int i = 0; i < 
AzTsxYcYjIEJsGQbeYHm; i++) { veFyKKHbdqBIvQLYBqfF[k * AwZQzUhuWVLGrWgLHRuM * 
AzTsxYcYjIEJsGQbeYHm + j * AzTsxYcYjIEJsGQbeYHm + i] = vjDFlBZzKvbpPseAtMBP[j + i 
* AwZQzUhuWVLGrWgLHRuM]; } } free(vjDFlBZzKvbpPseAtMBP); } return; } void 
MWFCLayerImpl::loadBias(const char* SDWKEQTZaTFZByPlzUDR, int euppfEoiaoCTcVgRPVhA) { 
FILE* SIBpKtDURUWQaaenbwrC = MWCNNLayer::openBinaryFile(SDWKEQTZaTFZByPlzUDR); 
call_fread(NDjzAZSYJuWymuKDNZYB, sizeof(float), euppfEoiaoCTcVgRPVhA, SIBpKtDURUWQaaenbwrC, 
SDWKEQTZaTFZByPlzUDR); fclose(SIBpKtDURUWQaaenbwrC); return; } void 
MWFCLayerImpl::cleanup() { if (veFyKKHbdqBIvQLYBqfF) { free(veFyKKHbdqBIvQLYBqfF); veFyKKHbdqBIvQLYBqfF 
= NULL; } if (NDjzAZSYJuWymuKDNZYB) { free(NDjzAZSYJuWymuKDNZYB); NDjzAZSYJuWymuKDNZYB = NULL; } 
return; } MWSoftmaxLayerImpl::MWSoftmaxLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { } 
MWSoftmaxLayerImpl::~MWSoftmaxLayerImpl() { } void 
MWSoftmaxLayerImpl::propagateSize() { clearLayerMapsAndVectors(); MWTensorBase* 
ipTensor = getLayer()->getInputTensor(0); MWTensorBase* opTensor = 
getLayer()->getOutputTensor(0); MWMkldnnUtils::reorderInputsTo(this); auto 
prevMemoryDesc = getReorderedIpMemory()->get_desc(); bool isInpMemPrimitiveTNC 
= MWMkldnnUtils::checkformatType(prevMemoryDesc, ipTensor, 
mkldnn::memory::format_tag::tnc); mkldnn::memory::desc layerMemoryDescriptor; 
if (isInpMemPrimitiveTNC) { mkldnn::memory::dims layerMemoryDimensions = { 
ipTensor->getSequenceLength() * ipTensor->getBatchSize(), 
ipTensor->getChannels(), ipTensor->getHeight(), ipTensor->getWidth()}; 
layerMemoryDescriptor = mkldnn::memory::desc(layerMemoryDimensions, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::nchw); } else { 
layerMemoryDescriptor = getReorderedIpMemory()->get_desc(); } softmax_d = 
std::unique_ptr<mkldnn::softmax_forward::desc>(new 
mkldnn::softmax_forward::desc( mkldnn::prop_kind::forward_inference, 
layerMemoryDescriptor, 1)); softmax_pd = 
std::unique_ptr<mkldnn::softmax_forward::primitive_desc>( new 
mkldnn::softmax_forward::primitive_desc(*softmax_d, 
*eqOmMKQRpqBqRQCnJmxt->eng)); if (isInpMemPrimitiveTNC) { 
assert(opTensor->getHeight() == 1 && opTensor->getWidth() == 1); 
layerMemoryDescriptor = mkldnn::memory::desc( {ipTensor->getSequenceLength(), 
ipTensor->getBatchSize(), opTensor->getChannels()}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::tnc); } 
setLayerMemory( std::make_shared<mkldnn::memory>(layerMemoryDescriptor, 
*eqOmMKQRpqBqRQCnJmxt->eng)); softmax = 
std::unique_ptr<mkldnn::softmax_forward>(new 
mkldnn::softmax_forward(*softmax_pd)); pipeline_memory_args.push_back( 
{{MKLDNN_ARG_FROM, *getReorderedIpMemory()}, {MKLDNN_ARG_TO, 
*getLayerMemory()}}); pipeline.push_back(*softmax); return; } void 
MWSoftmaxLayerImpl::predict() { auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_SFMX_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } MWAvgPoolingLayerImpl::MWAvgPoolingLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int FrpxvsDMwwgbpqHXWxmN, int GsZlHFuhbvjLtRMDjXnW, int 
HJHXkKmgFxxIOsIvRRnF, int HtQBsWTCGEkpylRklilw, int CpMjJjtGOeWOzwxpAAQP, int 
ClEhcJFlvGCgiavziIag, int EvebzoroiuKkIxwjkGnD, int FeVcBgtQmTLtmnNcJGMY) : 
MWCNNLayerImpl(layer, ntwk_impl) , FrpxvsDMwwgbpqHXWxmN(FrpxvsDMwwgbpqHXWxmN) , 
GsZlHFuhbvjLtRMDjXnW(GsZlHFuhbvjLtRMDjXnW) , HJHXkKmgFxxIOsIvRRnF(HJHXkKmgFxxIOsIvRRnF) , 
HtQBsWTCGEkpylRklilw(HtQBsWTCGEkpylRklilw) , 
CpMjJjtGOeWOzwxpAAQP(CpMjJjtGOeWOzwxpAAQP) , 
ClEhcJFlvGCgiavziIag(ClEhcJFlvGCgiavziIag) , 
EvebzoroiuKkIxwjkGnD(EvebzoroiuKkIxwjkGnD) , 
FeVcBgtQmTLtmnNcJGMY(FeVcBgtQmTLtmnNcJGMY) { } 
MWAvgPoolingLayerImpl::~MWAvgPoolingLayerImpl() { } void 
MWAvgPoolingLayerImpl::propagateSize() { MWAvgPoolingLayer* avgpoolLayer = 
static_cast<MWAvgPoolingLayer*>(getLayer()); MWTensorBase* ipTensor = 
avgpoolLayer->getInputTensor(0); MWTensorBase* opTensor = 
avgpoolLayer->getOutputTensor(0); MWMkldnnUtils::reorderInputsTo(this); if 
((FrpxvsDMwwgbpqHXWxmN == -1) && (GsZlHFuhbvjLtRMDjXnW == -1)) { FrpxvsDMwwgbpqHXWxmN = 
ipTensor->getHeight(); GsZlHFuhbvjLtRMDjXnW = ipTensor->getWidth(); } int n = 
ipTensor->getBatchSize(); int c = ipTensor->getChannels(); int h = 
ipTensor->getHeight(); int w = ipTensor->getWidth(); mkldnn::memory::dims 
pool_usr_tz = {n, c, h, w}; mkldnn::memory::dims pool_dst_tz = {n, c, 
opTensor->getHeight(), opTensor->getWidth()}; mkldnn::memory::dims pool_kernel 
= {FrpxvsDMwwgbpqHXWxmN, GsZlHFuhbvjLtRMDjXnW}; mkldnn::memory::dims 
GnxRkpzrPZimKtYYHSuG = {HJHXkKmgFxxIOsIvRRnF, HtQBsWTCGEkpylRklilw}; 
mkldnn::memory::dims GeeOVBfQrpMacIFBLKOo = {CpMjJjtGOeWOzwxpAAQP, 
EvebzoroiuKkIxwjkGnD}; mkldnn::memory::dims GFienSVKLlDQuZeqAdLC = 
{ClEhcJFlvGCgiavziIag, FeVcBgtQmTLtmnNcJGMY}; auto pool_dst_md = 
mkldnn::memory::desc({pool_dst_tz}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any); pool_d = 
std::unique_ptr<mkldnn::pooling_forward::desc>(new 
mkldnn::pooling_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::pooling_avg_include_padding, 
getReorderedIpMemory()->get_desc(), pool_dst_md, GnxRkpzrPZimKtYYHSuG, 
pool_kernel, GeeOVBfQrpMacIFBLKOo, GFienSVKLlDQuZeqAdLC)); pool_pd = 
std::unique_ptr<mkldnn::pooling_forward::primitive_desc>( new 
mkldnn::pooling_forward::primitive_desc(*pool_d, *eqOmMKQRpqBqRQCnJmxt->eng)); 
setLayerMemory( std::make_shared<mkldnn::memory>(pool_pd->dst_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng)); pool = 
std::unique_ptr<mkldnn::pooling_forward>(new 
mkldnn::pooling_forward(*pool_pd)); pipeline.push_back(*pool); 
pipeline_memory_args.push_back( {{MKLDNN_ARG_FROM, *getReorderedIpMemory()}, 
{MKLDNN_ARG_TO, *getLayerMemory()}}); } void MWAvgPoolingLayerImpl::predict() { 
auto s = mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_POOL_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } MWOutputLayerImpl::MWOutputLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl) : MWCNNLayerImpl(layer, ntwk_impl) { } 
MWOutputLayerImpl::~MWOutputLayerImpl() { } void 
MWOutputLayerImpl::propagateSize() { MWTensorBase* ipTensor = 
getLayer()->getInputTensor(0); auto prevMemoryDesc = 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor)->get_desc(); format_type 
formatTag = MWMkldnnUtils::getformatType(prevMemoryDesc, ipTensor); bool 
isSequenceIp = (formatTag == format_type::TNC_FORMAT) || (formatTag == 
format_type::CNT_FORMAT); format_type reorderIpTo = isSequenceIp ? 
(format_type::TNC_FORMAT) : (format_type::NCHW_FORMAT); 
MWMkldnnUtils::reorderInputsTo(this, reorderIpTo); 
setLayerMemory(std::make_shared<mkldnn::memory>(getReorderedIpMemory()->get_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng)); } void MWOutputLayerImpl::predict() { 
MWOutputLayer* outputLayer = static_cast<MWOutputLayer*>(getLayer()); int 
VCbcPxtPsBLTrHYdEvqn = outputLayer->getInPlaceIndex(0); 
assert(VCbcPxtPsBLTrHYdEvqn != -1); auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); } }