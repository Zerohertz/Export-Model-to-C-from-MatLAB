#include "MWElementwiseAffineLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include <math.h>
#include <cassert>
#include <stdio.h>
#include <algorithm>
#include "MWMkldnnUtils.hpp"
 MWElementwiseAffineLayerImpl::MWElementwiseAffineLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int scale_H, int scale_W, int scale_C, int 
offset_H, int offset_W, int offset_C, bool isClipped, int lowerbound, int 
upperbound, const char* scale_file, const char* offset_file) : 
MWCNNLayerImpl(layer, ntwk_impl) , intermediateOp(NULL) , 
sRECVoNNtDdcBOWgDyar(scale_H) , sxuOMwKXOKfuExclRaSe(scale_W) , 
rSmEWccbJFfPGddhPemm(scale_C) , iPqBiFnIJMxelVhQBZex(offset_H) , 
jaqKGCwoANNDMHgAsehk(offset_W) , hnewnpwgzKmOdualajhn(offset_C) , 
bDTIjtxZiSHtjwzgEluE(isClipped) , eVAFqeShtGZAZluKdMvQ(lowerbound) , 
vIWQzNvYZSuxmOTVDFhU(upperbound) { long int shEncNmxJsMuJKwbrwok = (long 
int)(sRECVoNNtDdcBOWgDyar * sxuOMwKXOKfuExclRaSe * rSmEWccbJFfPGddhPemm); long int 
jLyhrFjMmVnNjoeDJCwH = (long int)(iPqBiFnIJMxelVhQBZex * jaqKGCwoANNDMHgAsehk * 
hnewnpwgzKmOdualajhn); qWwjVYwfnvEnFKlgpqwA = (float*)calloc(shEncNmxJsMuJKwbrwok, 
sizeof(float)); hljcfGWsvZXJZNrImpJB = (float*)calloc(jLyhrFjMmVnNjoeDJCwH, 
sizeof(float)); loadScale(scale_file); loadOffset(offset_file); } 
MWElementwiseAffineLayerImpl::~MWElementwiseAffineLayerImpl() { } void 
MWElementwiseAffineLayerImpl::createScalarAffine() { long int 
shEncNmxJsMuJKwbrwok = (long int)(sRECVoNNtDdcBOWgDyar * sxuOMwKXOKfuExclRaSe * 
rSmEWccbJFfPGddhPemm); long int jLyhrFjMmVnNjoeDJCwH = (long 
int)(iPqBiFnIJMxelVhQBZex * jaqKGCwoANNDMHgAsehk * hnewnpwgzKmOdualajhn); 
std::shared_ptr<mkldnn::memory> srcLayerMemory = getReorderedIpMemory(); 
std::shared_ptr<mkldnn::memory> dstLayerMemory = getLayerMemory(); float 
temp_offset = *hljcfGWsvZXJZNrImpJB; float temp_scale = *qWwjVYwfnvEnFKlgpqwA; if 
(shEncNmxJsMuJKwbrwok == 1 && jLyhrFjMmVnNjoeDJCwH != 1) { dstLayerMemory = 
intermediateOutput; temp_offset = 0.0f; } else if ((shEncNmxJsMuJKwbrwok != 1 && 
jLyhrFjMmVnNjoeDJCwH == 1)) { srcLayerMemory = intermediateOutput; temp_scale = 
1.0f; } if ((shEncNmxJsMuJKwbrwok == 1 && jLyhrFjMmVnNjoeDJCwH == 1) || 
(shEncNmxJsMuJKwbrwok == 1 && jLyhrFjMmVnNjoeDJCwH != 1) || (shEncNmxJsMuJKwbrwok != 
1 && jLyhrFjMmVnNjoeDJCwH == 1)) { scaling_d = 
std::unique_ptr<mkldnn::eltwise_forward::desc>(new 
mkldnn::eltwise_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::eltwise_linear, getReorderedIpMemory()->get_desc(), 
temp_scale, temp_offset)); scaling_pd = 
std::unique_ptr<mkldnn::eltwise_forward::primitive_desc>( new 
mkldnn::eltwise_forward::primitive_desc(*scaling_d, 
*eqOmMKQRpqBqRQCnJmxt->eng)); scaling = 
std::unique_ptr<mkldnn::eltwise_forward>(new 
mkldnn::eltwise_forward(*scaling_pd)); pipeline_memory_args.push_back( 
{{MKLDNN_ARG_FROM, *srcLayerMemory}, {MKLDNN_ARG_TO, *dstLayerMemory}}); 
pipeline.push_back(*scaling); } } void 
MWElementwiseAffineLayerImpl::createVectorAffine() { long int 
shEncNmxJsMuJKwbrwok = (long int)(sRECVoNNtDdcBOWgDyar * sxuOMwKXOKfuExclRaSe * 
rSmEWccbJFfPGddhPemm); long int jLyhrFjMmVnNjoeDJCwH = (long 
int)(iPqBiFnIJMxelVhQBZex * jaqKGCwoANNDMHgAsehk * hnewnpwgzKmOdualajhn); bool 
offsetVectorImpl = (iPqBiFnIJMxelVhQBZex == 1 && jaqKGCwoANNDMHgAsehk == 1 && 
jLyhrFjMmVnNjoeDJCwH > 1); bool scaleVectorImpl = (sRECVoNNtDdcBOWgDyar == 1 && 
sxuOMwKXOKfuExclRaSe == 1 && shEncNmxJsMuJKwbrwok > 1); 
std::shared_ptr<mkldnn::memory> srcLayerMemory1 = getReorderedIpMemory(); 
std::shared_ptr<mkldnn::memory> dstLayerMemory1 = getLayerMemory(); if 
(scaleVectorImpl && !offsetVectorImpl) { dstLayerMemory1 = intermediateOutput; 
} else if (!scaleVectorImpl && offsetVectorImpl) { srcLayerMemory1 = 
intermediateOutput; } } void MWElementwiseAffineLayerImpl::propagateSize() { 
clearLayerMapsAndVectors(); MWTensorBase* ipTensor = 
getLayer()->getInputTensor(0); int pzUAoBDvaKAtdsmkQuct = 
ipTensor->getSequenceLength(); int enPbWLzEmxYCBmzGJutZ = ipTensor->getBatchSize(); int 
PtkeOkuClHzhOfpmBevf = ipTensor->getChannels(); int SUleyRyvAggTFnSdxLru = 
ipTensor->getHeight(); int veFyKKHbdqBIvQLYBqfF = ipTensor->getWidth(); auto 
prevMemoryDesc = MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor)->get_desc(); 
format_type formatTag = MWMkldnnUtils::getformatType(prevMemoryDesc, ipTensor); 
bool isSequenecIp = (formatTag == format_type::TNC_FORMAT) || (formatTag == 
format_type::CNT_FORMAT); format_type reorderIpTo = isSequenecIp ? 
(format_type::TNC_FORMAT) : (format_type::NCHW_FORMAT); 
MWMkldnnUtils::reorderInputsTo(this, reorderIpTo); intermediateOp = 
std::shared_ptr<float>( new float[pzUAoBDvaKAtdsmkQuct * enPbWLzEmxYCBmzGJutZ * PtkeOkuClHzhOfpmBevf * 
SUleyRyvAggTFnSdxLru * veFyKKHbdqBIvQLYBqfF]); intermediateOutput = 
std::make_shared<mkldnn::memory>( getReorderedIpMemory()->get_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng, intermediateOp.get()); 
setLayerMemory(std::make_shared<mkldnn::memory>(getReorderedIpMemory()->get_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng)); createScalarAffine(); createVectorAffine(); } void 
MWElementwiseAffineLayerImpl::predict() { long int shEncNmxJsMuJKwbrwok = (long 
int)(sRECVoNNtDdcBOWgDyar * sxuOMwKXOKfuExclRaSe * rSmEWccbJFfPGddhPemm); long int 
jLyhrFjMmVnNjoeDJCwH = (long int)(iPqBiFnIJMxelVhQBZex * jaqKGCwoANNDMHgAsehk * 
hnewnpwgzKmOdualajhn); MWTensorBase* opTensorBase = 
getLayer()->getOutputTensor(0); MWTensor<float>* opTensor = 
static_cast<MWTensor<float>*>(opTensorBase); if (shEncNmxJsMuJKwbrwok == 1 && 
jLyhrFjMmVnNjoeDJCwH == 1) { auto s = mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); 
assert(pipeline.size() == pipeline_memory_args.size()); for (int i = 0; i < 
pipeline.size(); i++) { pipeline[i].execute(s, pipeline_memory_args[i]); } 
clipAffineOutput(); return; } MWTensorBase* ipTensor = 
getLayer()->getInputTensor(0); float* ipData = 
(float*)getReorderedIpMemory()->get_data_handle(); float* opData = 
intermediateOp.get(); long int ZCArwzdUdwQuFQUWjnUE = 
ipTensor->getHeight() * ipTensor->getWidth(); long int 
YgcpEBUCwCLaPhyntIio = ZCArwzdUdwQuFQUWjnUE * 
ipTensor->getChannels(); if (shEncNmxJsMuJKwbrwok == 1) { auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); } } else if 
(sRECVoNNtDdcBOWgDyar == 1 && sxuOMwKXOKfuExclRaSe == 1 && shEncNmxJsMuJKwbrwok > 1) 
{ for (int n = 0; n < ipTensor->getBatchSize() * ipTensor->getSequenceLength(); 
n++) { for (int c = 0; c < ipTensor->getChannels(); c++) { for (int wh = 0; wh 
< ZCArwzdUdwQuFQUWjnUE; wh++) { *opData++ = *ipData++ * 
qWwjVYwfnvEnFKlgpqwA[c]; } } } } else if (ZCArwzdUdwQuFQUWjnUE == 
shEncNmxJsMuJKwbrwok) { for (int n = 0; n < ipTensor->getBatchSize() * 
ipTensor->getSequenceLength(); n++) { for (int c = 0; c < 
ipTensor->getChannels(); c++) { for (int i = 0; i < 
ZCArwzdUdwQuFQUWjnUE; ++i) { opData[i + c * 
ZCArwzdUdwQuFQUWjnUE] = ipData[i + c * 
ZCArwzdUdwQuFQUWjnUE] * qWwjVYwfnvEnFKlgpqwA[i]; } } ipData += 
YgcpEBUCwCLaPhyntIio; opData += YgcpEBUCwCLaPhyntIio; } } else 
{ for (int n = 0; n < ipTensor->getBatchSize() * ipTensor->getSequenceLength(); 
n++) { for (int i = 0; i < YgcpEBUCwCLaPhyntIio; ++i) { opData[i] = 
ipData[i] * qWwjVYwfnvEnFKlgpqwA[i]; } ipData += YgcpEBUCwCLaPhyntIio; 
opData += YgcpEBUCwCLaPhyntIio; } } ipData = intermediateOp.get(); 
opData = opTensor->getData(); if (jLyhrFjMmVnNjoeDJCwH == 1) { auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); } } else if 
(iPqBiFnIJMxelVhQBZex == 1 && jaqKGCwoANNDMHgAsehk == 1 && jLyhrFjMmVnNjoeDJCwH > 
1) { for (int n = 0; n < ipTensor->getBatchSize() * 
ipTensor->getSequenceLength(); n++) { for (int c = 0; c < 
ipTensor->getChannels(); c++) { for (int wh = 0; wh < 
ZCArwzdUdwQuFQUWjnUE; wh++) { *opData++ = *ipData++ + 
hljcfGWsvZXJZNrImpJB[c]; } } } } else if (ZCArwzdUdwQuFQUWjnUE == 
jLyhrFjMmVnNjoeDJCwH) { for (int n = 0; n < ipTensor->getBatchSize() * 
ipTensor->getSequenceLength(); n++) { for (int c = 0; c < 
ipTensor->getChannels(); c++) { for (int i = 0; i < 
ZCArwzdUdwQuFQUWjnUE; ++i) { opData[i + c * 
ZCArwzdUdwQuFQUWjnUE] = ipData[i + c * 
ZCArwzdUdwQuFQUWjnUE] + hljcfGWsvZXJZNrImpJB[i]; } } ipData += 
YgcpEBUCwCLaPhyntIio; opData += YgcpEBUCwCLaPhyntIio; } } else 
{ for (int n = 0; n < ipTensor->getBatchSize() * ipTensor->getSequenceLength(); 
n++) { for (int i = 0; i < YgcpEBUCwCLaPhyntIio; ++i) { opData[i] = 
ipData[i] + hljcfGWsvZXJZNrImpJB[i]; } ipData += YgcpEBUCwCLaPhyntIio; 
opData += YgcpEBUCwCLaPhyntIio; } } clipAffineOutput();
#if MW_AFFINE_TAP
 mw_interm_tap(opData, YgcpEBUCwCLaPhyntIio, tap_count++);
#endif
 return; } void MWElementwiseAffineLayerImpl::clipAffineOutput() { 
MWTensorBase* opTensorBase = getLayer()->getOutputTensor(0); MWTensor<float>* 
opTensor = static_cast<MWTensor<float>*>(opTensorBase); float* outputBuffer = 
opTensor->getData(); if (!bDTIjtxZiSHtjwzgEluE) { return; } for (int n = 0; n < 
opTensor->getNumElements(); n++) { outputBuffer[n] = outputBuffer[n] > 
vIWQzNvYZSuxmOTVDFhU ? vIWQzNvYZSuxmOTVDFhU : outputBuffer[n]; 
outputBuffer[n] = outputBuffer[n] < eVAFqeShtGZAZluKdMvQ ? 
eVAFqeShtGZAZluKdMvQ : outputBuffer[n]; } } void 
MWElementwiseAffineLayerImpl::cleanup() { if (qWwjVYwfnvEnFKlgpqwA) { 
free(qWwjVYwfnvEnFKlgpqwA); qWwjVYwfnvEnFKlgpqwA = NULL; } if (hljcfGWsvZXJZNrImpJB) { 
free(hljcfGWsvZXJZNrImpJB); hljcfGWsvZXJZNrImpJB = NULL; } } void 
MWElementwiseAffineLayerImpl::loadScale(const char* tnTPxeDjBsqLAPkJcPJX) { 
FILE* SIBpKtDURUWQaaenbwrC = MWCNNLayer::openBinaryFile(tnTPxeDjBsqLAPkJcPJX); 
assert(SIBpKtDURUWQaaenbwrC); long int euppfEoiaoCTcVgRPVhA = (long int)(sRECVoNNtDdcBOWgDyar 
* sxuOMwKXOKfuExclRaSe * rSmEWccbJFfPGddhPemm); call_fread(qWwjVYwfnvEnFKlgpqwA, 
sizeof(float), euppfEoiaoCTcVgRPVhA, SIBpKtDURUWQaaenbwrC, tnTPxeDjBsqLAPkJcPJX); 
fclose(SIBpKtDURUWQaaenbwrC); } void MWElementwiseAffineLayerImpl::loadOffset(const 
char* jhFUWlztBndwjbXwYNaJ) { FILE* SIBpKtDURUWQaaenbwrC = 
MWCNNLayer::openBinaryFile(jhFUWlztBndwjbXwYNaJ); assert(SIBpKtDURUWQaaenbwrC); long 
int euppfEoiaoCTcVgRPVhA = (long int)(iPqBiFnIJMxelVhQBZex * jaqKGCwoANNDMHgAsehk * 
hnewnpwgzKmOdualajhn); call_fread(hljcfGWsvZXJZNrImpJB, sizeof(float), 
euppfEoiaoCTcVgRPVhA, SIBpKtDURUWQaaenbwrC, jhFUWlztBndwjbXwYNaJ); fclose(SIBpKtDURUWQaaenbwrC); }