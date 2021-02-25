#include <cassert>
#include <cstring>
#include <stdio.h>
#include "MWCNNLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include "MWMkldnnUtils.hpp"
#include "MWCustomLayerForMKLDNN.hpp"
#include "mkldnn.hpp"
 void MWMkldnnUtils::configureReorder(MWCNNLayerImpl* layerImpl, MWTensorBase* 
srcTensor, mkldnn::memory::format_tag dstDataFormat, int index) { 
std::shared_ptr<mkldnn::memory> ipLayerMemory = 
MWMkldnnUtils::getLayerMemoryPrimitive(srcTensor); mkldnn::memory::dims 
layerMemoryDimensions; if (dstDataFormat == mkldnn::memory::format_tag::tnc) { 
layerMemoryDimensions = {srcTensor->getSequenceLength(), 
srcTensor->getBatchSize(), srcTensor->getChannels()}; } else { 
layerMemoryDimensions = {srcTensor->getBatchSize(), srcTensor->getChannels(), 
srcTensor->getHeight(), srcTensor->getWidth()}; } auto layerMemoryDescriptor = 
mkldnn::memory::desc(layerMemoryDimensions, mkldnn::memory::data_type::f32, 
dstDataFormat); layerImpl->setReorderLayerMemory( 
std::make_shared<mkldnn::memory>(layerMemoryDescriptor, 
*(layerImpl->getTargetImpl())->eng), index); layerImpl->setReorderPrim( 
std::make_shared<mkldnn::reorder>(*ipLayerMemory, 
*layerImpl->getReorderedIpMemory(index)), index); } void 
MWMkldnnUtils::TargetImplconfigureReorder(MWTargetNetworkImpl* targetImpl, 
MWTensorBase* srcTensor, mkldnn::memory::format_tag dstDataFormat) { 
std::shared_ptr<mkldnn::memory> ipLayerMemory = 
MWMkldnnUtils::getLayerMemoryPrimitive(srcTensor); mkldnn::memory::dims 
layerMemoryDimensions = {srcTensor->getBatchSize(), srcTensor->getChannels(), 
srcTensor->getHeight(), srcTensor->getWidth()}; auto layerMemoryDescriptor = 
mkldnn::memory::desc(layerMemoryDimensions, mkldnn::memory::data_type::f32, 
dstDataFormat); targetImpl->setReorderLayerMemory( 
std::make_shared<mkldnn::memory>(layerMemoryDescriptor, *(targetImpl)->eng)); 
targetImpl->setReorderPrim( std::make_shared<mkldnn::reorder>(*ipLayerMemory, 
*targetImpl->getReorderLayerMemory())); } format_type 
MWMkldnnUtils::getformatType(mkldnn::memory::desc inputdesc, MWTensorBase* 
srcTensor) { mkldnn::memory::dims layerMemoryDimensionsNC = { 
srcTensor->getSequenceLength() * srcTensor->getBatchSize(), 
srcTensor->getChannels() * srcTensor->getHeight() * srcTensor->getWidth()}; 
mkldnn::memory::dims layerMemoryDimensions = { srcTensor->getSequenceLength() * 
srcTensor->getBatchSize(), srcTensor->getChannels(), srcTensor->getHeight(), 
srcTensor->getWidth()}; mkldnn::memory::dims layerMemoryDimensionsTNC = { 
srcTensor->getSequenceLength(), srcTensor->getBatchSize(), 
srcTensor->getChannels()}; auto layerMemoryDescriptorNC = mkldnn::memory::desc( 
layerMemoryDimensionsNC, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::nc); if (inputdesc == layerMemoryDescriptorNC) { 
return format_type::NC_FORMAT; } auto layerMemoryDescriptorNCHW = 
mkldnn::memory::desc( layerMemoryDimensions, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::nchw); if (inputdesc == layerMemoryDescriptorNCHW) 
{ return format_type::NCHW_FORMAT; } auto layerMemoryDescriptorNHWC = 
mkldnn::memory::desc( layerMemoryDimensions, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::nhwc); if (inputdesc == layerMemoryDescriptorNHWC) 
{ return format_type::NHWC_FORMAT; } auto layerMemoryDescriptorNCHW8C = 
mkldnn::memory::desc( layerMemoryDimensions, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::nChw8c); if (inputdesc == 
layerMemoryDescriptorNCHW8C) { return format_type::NCHW8C_FORMAT; } auto 
layerMemoryDescriptorNCHW16C = mkldnn::memory::desc( layerMemoryDimensions, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::nChw16c); if 
(inputdesc == layerMemoryDescriptorNCHW16C) { return 
format_type::NCHW16C_FORMAT; } const int size = 4; int outDims_nchw[size]; int 
strides_nchw[size]; MWTensorBase::DIMSLABEL NCWHLayout[size] = 
{MWTensorBase::N, MWTensorBase::C, MWTensorBase::W, MWTensorBase::H}; 
MWTensorBase::DIMSLABEL srcLayout[size] = {MWTensorBase::N, MWTensorBase::C, 
MWTensorBase::H, MWTensorBase::W}; srcTensor->getDimsByLayout(NCWHLayout, size, 
outDims_nchw); MWTensorBase::getTransformStrides(srcLayout, NCWHLayout, 
outDims_nchw, size, strides_nchw); mkldnn::memory::dims layerMemoryStrides = 
{strides_nchw[0], strides_nchw[1], strides_nchw[2], strides_nchw[3]}; auto 
layerMemoryDescriptorNCWH = mkldnn::memory::desc( layerMemoryDimensions, 
mkldnn::memory::data_type::f32, layerMemoryStrides); if (inputdesc == 
layerMemoryDescriptorNCWH) { return format_type::NCWH_FORMAT; } 
MWTensorBase::DIMSLABEL HWCNLayout[size] = {MWTensorBase::H, MWTensorBase::W, 
MWTensorBase::C, MWTensorBase::N}; srcTensor->getDimsByLayout(HWCNLayout, size, 
outDims_nchw); MWTensorBase::getTransformStrides(srcLayout, HWCNLayout, 
outDims_nchw, size, strides_nchw); layerMemoryStrides = {strides_nchw[0], 
strides_nchw[1], strides_nchw[2], strides_nchw[3]}; auto 
layerMemoryDescriptorHWCN = mkldnn::memory::desc( layerMemoryDimensions, 
mkldnn::memory::data_type::f32, layerMemoryStrides); if (inputdesc == 
layerMemoryDescriptorHWCN) { return format_type::HWCN_FORMAT; } auto 
layerMemoryDescriptorTNC = mkldnn::memory::desc( layerMemoryDimensionsTNC, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::tnc); if (inputdesc 
== layerMemoryDescriptorTNC) { return format_type::TNC_FORMAT; } const int 
size_tnc = 3; int outDims_tnc[size_tnc]; int strides_tnc[size_tnc]; 
MWTensorBase::DIMSLABEL TNCLayout[size_tnc] = {MWTensorBase::C, 
MWTensorBase::N, MWTensorBase::S}; MWTensorBase::DIMSLABEL 
srcLayout_tnc[size_tnc] = {MWTensorBase::S, MWTensorBase::N, MWTensorBase::C}; 
srcTensor->getDimsByLayout(TNCLayout, size_tnc, outDims_tnc); 
MWTensorBase::getTransformStrides(srcLayout_tnc, TNCLayout, outDims_tnc, 
size_tnc, strides_tnc); layerMemoryStrides = {strides_tnc[0], strides_tnc[1], 
strides_tnc[2]}; auto layerMemoryDescriptorCNT = mkldnn::memory::desc( 
layerMemoryDimensionsTNC, mkldnn::memory::data_type::f32, layerMemoryStrides); 
if (inputdesc == layerMemoryDescriptorCNT) { return format_type::CNT_FORMAT; } 
return format_type::UNKNOWN_FORMAT; } bool 
MWMkldnnUtils::checkformatType(mkldnn::memory::desc inputdesc, MWTensorBase* 
srcTensor, mkldnn::memory::format_tag dstDataFormat) { mkldnn::memory::dims 
layerMemoryDimensions = { srcTensor->getSequenceLength() * 
srcTensor->getBatchSize(), srcTensor->getChannels(), srcTensor->getHeight(), 
srcTensor->getWidth()}; if (dstDataFormat == mkldnn::memory::format_tag::nc) { 
layerMemoryDimensions = { srcTensor->getSequenceLength() * 
srcTensor->getBatchSize(), srcTensor->getChannels() * srcTensor->getHeight() * 
srcTensor->getWidth()}; } else if (dstDataFormat == 
mkldnn::memory::format_tag::tnc) { layerMemoryDimensions = 
{srcTensor->getSequenceLength(), srcTensor->getBatchSize(), 
srcTensor->getChannels()}; } auto layerMemoryDescriptor = 
mkldnn::memory::desc(layerMemoryDimensions, mkldnn::memory::data_type::f32, 
dstDataFormat); bool isformatMatched = (layerMemoryDescriptor == inputdesc); 
return isformatMatched; } std::shared_ptr<mkldnn::memory> 
MWMkldnnUtils::getLayerMemoryPrimitive(MWTensorBase* aTensor) { auto 
owningLayer = aTensor->getOwner(); auto owningLayerImpl = 
owningLayer->getImpl(); if (owningLayerImpl == NULL) { if 
(owningLayer->isCustomLayer()) { return 
dynamic_cast<MWCustomLayerForMKLDNN*>(owningLayer) 
->getCustomLayerMemory(aTensor); } else { assert(owningLayer->getNumInputs() == 
1); return 
MWMkldnnUtils::getLayerMemoryPrimitive(owningLayer->getInputTensor(0)); } } 
else { auto layerMemory = 
owningLayerImpl->getLayerMemory(aTensor->getSourcePortIndex()); if 
(layerMemory) { return layerMemory; } else { assert(owningLayer->getNumInputs() 
== 1); return 
MWMkldnnUtils::getLayerMemoryPrimitive(owningLayer->getInputTensor(0)); } } } 
bool MWMkldnnUtils::isReorderNeeded(format_type formatTag) { return ((formatTag 
!= format_type::NC_FORMAT) && (formatTag != format_type::NCHW_FORMAT) && 
(formatTag != format_type::TNC_FORMAT) && (formatTag != 
format_type::NCHW8C_FORMAT)); } void 
MWMkldnnUtils::reorderInputsTo(MWCNNLayerImpl* layerImpl, format_type 
formatTag) { if (formatTag == format_type::OPTIMAL_FORMAT) {  bool isAVX512 = 
layerImpl->getTargetImpl()->isAVX512; formatTag = isAVX512 ? 
format_type::NCHW16C_FORMAT : format_type::NCHW8C_FORMAT; for (int k = 0; k < 
layerImpl->getLayer()->getNumInputs(); k++) { MWTensorBase* srcTensork = 
layerImpl->getLayer()->getInputTensor(static_cast<int>(k)); auto 
prevMemoryDesck = 
MWMkldnnUtils::getLayerMemoryPrimitive(srcTensork)->get_desc(); format_type 
ipFormatTag = MWMkldnnUtils::getformatType(prevMemoryDesck, srcTensork); 
assert(ipFormatTag != format_type::NC_FORMAT);  if ((isAVX512 && ipFormatTag != 
format_type::NCHW16C_FORMAT) || (!isAVX512 && (ipFormatTag != 
format_type::NCHW8C_FORMAT))) { if (ipFormatTag == format_type::TNC_FORMAT || 
ipFormatTag == format_type::CNT_FORMAT) {  formatTag = format_type::TNC_FORMAT; 
break; } else if ((isAVX512 && srcTensork->getChannels() % 16 <= 8 && 
srcTensork->getChannels() % 16 != 0) || (!isAVX512 && srcTensork->getChannels() 
% 8 <= 4 && srcTensork->getChannels() % 8 != 0)) { formatTag = 
format_type::NCHW_FORMAT; break; } } } } for (int k = 0; k < 
layerImpl->getLayer()->getNumInputs(); k++) { MWTensorBase* srcTensork = 
layerImpl->getLayer()->getInputTensor(static_cast<int>(k)); auto 
prevMemoryDesck = 
MWMkldnnUtils::getLayerMemoryPrimitive(srcTensork)->get_desc(); format_type 
ipFormatTag = MWMkldnnUtils::getformatType(prevMemoryDesck, srcTensork); 
format_type prevformatTag; if ((ipFormatTag != formatTag)) {  
mkldnn::memory::format_tag outputDataFormat = 
MWMkldnnUtils::getMKLDNNFormatTag(formatTag); 
MWMkldnnUtils::configureReorder(layerImpl, srcTensork, outputDataFormat, k); 
layerImpl->getPipeline().push_back(*(layerImpl->getReorderPrim(k))); 
layerImpl->getArgumentsPipeline().push_back( {{MKLDNN_ARG_FROM, 
*MWMkldnnUtils::getLayerMemoryPrimitive(srcTensork)}, {MKLDNN_ARG_TO, 
*(layerImpl->getReorderedIpMemory(k))}}); ipFormatTag = formatTag; } else { 
layerImpl->setReorderLayerMemory(MWMkldnnUtils::getLayerMemoryPrimitive(srcTensork), 
k); } if (k > 0) { assert(prevformatTag == ipFormatTag); } prevformatTag = 
ipFormatTag; } } mkldnn::memory::format_tag 
MWMkldnnUtils::getMKLDNNFormatTag(format_type formatType) { assert((formatType 
== format_type::NCHW_FORMAT) || (formatType == format_type::NHWC_FORMAT) || 
(formatType == format_type::NCHW8C_FORMAT) || (formatType == 
format_type::NCHW16C_FORMAT) || (formatType == format_type::TNC_FORMAT)); 
switch (formatType) { case format_type::NCHW_FORMAT: return 
mkldnn::memory::format_tag::nchw; case format_type::NHWC_FORMAT: return 
mkldnn::memory::format_tag::nhwc; case format_type::NCHW8C_FORMAT: return 
mkldnn::memory::format_tag::nChw8c; case format_type::NCHW16C_FORMAT: return 
mkldnn::memory::format_tag::nChw16c; default: assert(formatType == 
format_type::TNC_FORMAT); return mkldnn::memory::format_tag::tnc; } }