#include <cassert>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include "MWCNNLayerImpl.hpp"
#include "MWConvLayerImpl.hpp"
#include "MWConvLayer.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "MWMkldnnUtils.hpp"
#include "cnn_api.hpp"
#if MW_CONV_TAP
 extern int tap_count; extern void mw_interm_tap(float* inp, int size, int count);
#endif
 MWConvLayerImpl::MWConvLayerImpl(MWCNNLayer* layer, MWTargetNetworkImpl* 
ntwk_impl, int filt_H, int filt_W, int numGrps, int numChnls, int numFilts, int 
HJHXkKmgFxxIOsIvRRnF, int HtQBsWTCGEkpylRklilw, int CpMjJjtGOeWOzwxpAAQP, int 
ClEhcJFlvGCgiavziIag, int EvebzoroiuKkIxwjkGnD, int FeVcBgtQmTLtmnNcJGMY, 
int AIXLuRgdeiqpaCehGSYD, int ATEikvMQPqBefhJzjzhc, const char* 
zzWugmJRYlNEuAzHMpeQ, const char* ONvcEjLBnVNUdjMKOAwF) : 
MWCNNLayerImpl(layer, ntwk_impl) , AwZQzUhuWVLGrWgLHRuM(filt_H) , 
AzTsxYcYjIEJsGQbeYHm(filt_W) , CDJtexcMbXMWAmnNZsNf(numGrps) , 
AIXLuRgdeiqpaCehGSYD(AIXLuRgdeiqpaCehGSYD) , 
ATEikvMQPqBefhJzjzhc(ATEikvMQPqBefhJzjzhc) , 
CpMjJjtGOeWOzwxpAAQP(CpMjJjtGOeWOzwxpAAQP) , 
ClEhcJFlvGCgiavziIag(ClEhcJFlvGCgiavziIag) , 
EvebzoroiuKkIxwjkGnD(EvebzoroiuKkIxwjkGnD) , 
FeVcBgtQmTLtmnNcJGMY(FeVcBgtQmTLtmnNcJGMY) , 
HJHXkKmgFxxIOsIvRRnF(HJHXkKmgFxxIOsIvRRnF) , HtQBsWTCGEkpylRklilw(HtQBsWTCGEkpylRklilw) 
{ int euppfEoiaoCTcVgRPVhA = numChnls * numFilts * CDJtexcMbXMWAmnNZsNf * 
AwZQzUhuWVLGrWgLHRuM * AzTsxYcYjIEJsGQbeYHm; veFyKKHbdqBIvQLYBqfF = 
(float*)calloc(euppfEoiaoCTcVgRPVhA, sizeof(float)); NDjzAZSYJuWymuKDNZYB = 
(float*)calloc(numFilts * CDJtexcMbXMWAmnNZsNf, sizeof(float)); 
loadWeights(zzWugmJRYlNEuAzHMpeQ, euppfEoiaoCTcVgRPVhA); 
loadBias(ONvcEjLBnVNUdjMKOAwF, numFilts); auto weights_md = 
CDJtexcMbXMWAmnNZsNf > 1 ? mkldnn::memory::desc({{CDJtexcMbXMWAmnNZsNf, 
numFilts, numChnls, AwZQzUhuWVLGrWgLHRuM, AzTsxYcYjIEJsGQbeYHm}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::goihw}) : 
mkldnn::memory::desc({{numFilts, numChnls, AwZQzUhuWVLGrWgLHRuM, 
AzTsxYcYjIEJsGQbeYHm}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::oihw}); weights = std::shared_ptr<mkldnn::memory>( 
new mkldnn::memory(weights_md, *eqOmMKQRpqBqRQCnJmxt->eng, veFyKKHbdqBIvQLYBqfF)); auto 
bias_md = with_bias ? mkldnn::memory::desc({{numFilts * CDJtexcMbXMWAmnNZsNf}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::x}) : 
mkldnn::memory::desc( {{}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::x}); bias = with_bias ? 
std::shared_ptr<mkldnn::memory>( new mkldnn::memory(bias_md, 
*eqOmMKQRpqBqRQCnJmxt->eng, NDjzAZSYJuWymuKDNZYB)) : std::shared_ptr<mkldnn::memory>( 
new mkldnn::memory(bias_md, *eqOmMKQRpqBqRQCnJmxt->eng)); conv_weights_md = 
CDJtexcMbXMWAmnNZsNf > 1 ? std::unique_ptr<mkldnn::memory::desc>(new 
mkldnn::memory::desc( {CDJtexcMbXMWAmnNZsNf, numFilts, numChnls, 
AwZQzUhuWVLGrWgLHRuM, AzTsxYcYjIEJsGQbeYHm}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any)) : 
std::unique_ptr<mkldnn::memory::desc>(new mkldnn::memory::desc( {numFilts, 
numChnls, AwZQzUhuWVLGrWgLHRuM, AzTsxYcYjIEJsGQbeYHm}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any)); conv_bias_md 
= std::unique_ptr<mkldnn::memory::desc>( new mkldnn::memory::desc({numFilts * 
CDJtexcMbXMWAmnNZsNf}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any)); reorderedWeightsDesc = weights->get_desc(); 
} void MWConvLayerImpl::propagateSize() { MWConvLayer* convLayer = 
static_cast<MWConvLayer*>(getLayer()); MWTensorBase* ipTensor = 
convLayer->getInputTensor(0); MWTensorBase* opTensor = 
convLayer->getOutputTensor(0); int n = ipTensor->getBatchSize(); int c = 
ipTensor->getChannels(); int h = ipTensor->getHeight(); int w = 
ipTensor->getWidth(); int num_filts = opTensor->getChannels(); conv_src_md = 
std::unique_ptr<mkldnn::memory::desc>(new mkldnn::memory::desc( {n, c, h, w}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any)); conv_dst_md 
= std::unique_ptr<mkldnn::memory::desc>( new mkldnn::memory::desc({n, 
num_filts, opTensor->getHeight(), opTensor->getWidth()}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::any)); conv_d = 
with_bias ? std::unique_ptr<mkldnn::convolution_forward::desc>( new 
mkldnn::convolution_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::convolution_direct, *conv_src_md, *conv_weights_md, 
*conv_bias_md, *conv_dst_md, {HJHXkKmgFxxIOsIvRRnF, HtQBsWTCGEkpylRklilw}, 
{AIXLuRgdeiqpaCehGSYD - 1, ATEikvMQPqBefhJzjzhc - 1}, 
{CpMjJjtGOeWOzwxpAAQP, EvebzoroiuKkIxwjkGnD}, {ClEhcJFlvGCgiavziIag, 
FeVcBgtQmTLtmnNcJGMY})) : std::unique_ptr<mkldnn::convolution_forward::desc>( 
new mkldnn::convolution_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::convolution_direct, *conv_src_md, *conv_weights_md, 
*conv_dst_md, {HJHXkKmgFxxIOsIvRRnF, HtQBsWTCGEkpylRklilw}, 
{AIXLuRgdeiqpaCehGSYD - 1, ATEikvMQPqBefhJzjzhc - 1}, 
{CpMjJjtGOeWOzwxpAAQP, EvebzoroiuKkIxwjkGnD}, {ClEhcJFlvGCgiavziIag, 
FeVcBgtQmTLtmnNcJGMY})); conv_pd = 
std::unique_ptr<mkldnn::convolution_forward::primitive_desc>( new 
mkldnn::convolution_forward::primitive_desc(*conv_d, 
*eqOmMKQRpqBqRQCnJmxt->eng)); conv_src_memory = 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor); if 
(mkldnn::memory::desc(conv_pd->src_desc()) != 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor)->get_desc()) { conv_src_memory 
= std::make_shared<mkldnn::memory>(conv_pd->src_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng); conv_reorder_src = 
std::unique_ptr<mkldnn::reorder>(new mkldnn::reorder( 
*MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor), *conv_src_memory)); 
pipeline_memory_args.push_back( {{MKLDNN_ARG_FROM, 
*MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor)}, {MKLDNN_ARG_TO, 
*conv_src_memory}}); pipeline.push_back(*conv_reorder_src); } 
setReorderLayerMemory(conv_src_memory); conv_weights_memory = weights; if 
(mkldnn::memory::desc(conv_pd->weights_desc()) != weights->get_desc()) { if 
(conv_pd->weights_desc() != reorderedWeightsDesc) { conv_weights_memory = 
std::make_shared<mkldnn::memory>(conv_pd->weights_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng); conv_reorder_weights = 
std::unique_ptr<mkldnn::reorder>( new mkldnn::reorder(*weights, 
*conv_weights_memory)); pipeline_weights_memory_args.push_back( 
{{MKLDNN_ARG_FROM, *weights}, {MKLDNN_ARG_TO, *conv_weights_memory}}); 
pipeline_weights.push_back(*conv_reorder_weights); auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline_weights.size() == 
pipeline_weights_memory_args.size()); for (int i = 0; i < 
pipeline_weights.size(); i++) { pipeline_weights[i].execute(s, 
pipeline_weights_memory_args[i]); } reorderedWeightsDesc = 
conv_pd->weights_desc(); } } setLayerMemory( 
std::make_shared<mkldnn::memory>(conv_pd->dst_desc(), 
*eqOmMKQRpqBqRQCnJmxt->eng)); conv = 
std::unique_ptr<mkldnn::convolution_forward>(new 
mkldnn::convolution_forward(*conv_pd)); if (with_bias) { 
pipeline_memory_args.push_back({{MKLDNN_ARG_SRC, *conv_src_memory}, 
{MKLDNN_ARG_WEIGHTS, *conv_weights_memory}, {MKLDNN_ARG_BIAS, *bias}, 
{MKLDNN_ARG_DST, *getLayerMemory()}}); } else { 
pipeline_memory_args.push_back({{MKLDNN_ARG_SRC, *conv_src_memory}, 
{MKLDNN_ARG_WEIGHTS, *conv_weights_memory}, {MKLDNN_ARG_DST, 
*getLayerMemory()}}); } pipeline.push_back(*conv); return; } void 
MWConvLayerImpl::predict() { auto s = 
mkldnn::stream(*eqOmMKQRpqBqRQCnJmxt->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_CONV_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } MWConvLayerImpl::~MWConvLayerImpl() { } void 
MWConvLayerImpl::cleanup() { if (veFyKKHbdqBIvQLYBqfF) { free(veFyKKHbdqBIvQLYBqfF); 
veFyKKHbdqBIvQLYBqfF = NULL; } if (NDjzAZSYJuWymuKDNZYB) { free(NDjzAZSYJuWymuKDNZYB); NDjzAZSYJuWymuKDNZYB = 
NULL; } return; } void MWConvLayerImpl::loadWeights(const char* 
SDWKEQTZaTFZByPlzUDR, int euppfEoiaoCTcVgRPVhA) { FILE* SIBpKtDURUWQaaenbwrC = 
MWCNNLayer::openBinaryFile(SDWKEQTZaTFZByPlzUDR); call_fread(veFyKKHbdqBIvQLYBqfF, 
sizeof(float), euppfEoiaoCTcVgRPVhA, SIBpKtDURUWQaaenbwrC, SDWKEQTZaTFZByPlzUDR); 
fclose(SIBpKtDURUWQaaenbwrC); return; } void MWConvLayerImpl::loadBias(const char* 
SDWKEQTZaTFZByPlzUDR, int BlRIQPyqJZORKENzSdYf) { float* NMMfJylfQjiIUAKhXCJb = 
NDjzAZSYJuWymuKDNZYB; FILE* SIBpKtDURUWQaaenbwrC = 
MWCNNLayer::openBinaryFile(SDWKEQTZaTFZByPlzUDR); int euppfEoiaoCTcVgRPVhA = 
BlRIQPyqJZORKENzSdYf * CDJtexcMbXMWAmnNZsNf;  call_fread(NMMfJylfQjiIUAKhXCJb, 
sizeof(float), euppfEoiaoCTcVgRPVhA, SIBpKtDURUWQaaenbwrC, SDWKEQTZaTFZByPlzUDR); 
fclose(SIBpKtDURUWQaaenbwrC); return; }