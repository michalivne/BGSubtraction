/*
 * A SWIG wrapper to bgs library.
 */

#ifndef _PYBGS_H_
#define _PYBGS_H_

#include <string>
#include <list>

#include "common.h"

#include "package_bgs/IBGS.h"

#include "package_bgs/AdaptiveBackgroundLearning.h"
#include "package_bgs/FrameDifferenceBGS.h"
#include "package_bgs/StaticFrameDifferenceBGS.h"
#include "package_bgs/WeightedMovingMeanBGS.h"
#include "package_bgs/WeightedMovingVarianceBGS.h"
#include "package_bgs/MixtureOfGaussianV1BGS.h"
#include "package_bgs/MixtureOfGaussianV2BGS.h"
#include "package_bgs/GMG.h"

#include "package_bgs/dp/DPAdaptiveMedianBGS.h"
#include "package_bgs/dp/DPGrimsonGMMBGS.h"
#include "package_bgs/dp/DPZivkovicAGMMBGS.h"
#include "package_bgs/dp/DPMeanBGS.h"
#include "package_bgs/dp/DPWrenGABGS.h"
#include "package_bgs/dp/DPPratiMediodBGS.h"
#include "package_bgs/dp/DPEigenbackgroundBGS.h"
#include "package_bgs/dp/DPTextureBGS.h"

#include "package_bgs/tb/T2FGMM_UM.h"
#include "package_bgs/tb/T2FGMM_UV.h"
#include "package_bgs/tb/T2FMRF_UM.h"
#include "package_bgs/tb/T2FMRF_UV.h"
#include "package_bgs/tb/FuzzySugenoIntegral.h"
#include "package_bgs/tb/FuzzyChoquetIntegral.h"

#include "package_bgs/lb/LBSimpleGaussian.h"
#include "package_bgs/lb/LBFuzzyGaussian.h"
#include "package_bgs/lb/LBMixtureOfGaussians.h"
#include "package_bgs/lb/LBAdaptiveSOM.h"
#include "package_bgs/lb/LBFuzzyAdaptiveSOM.h"

#include "package_bgs/jmo/MultiLayerBGS.h"
#include "package_bgs/av/VuMeter.h"
#include "package_bgs/ae/KDE.h"

// Base class

template <class NUMPY_TYPE, int NUMPY_K_DIM, int CV_IMAGE_TYPE, int CV_MASK_TYPE>
class BGSBase {
public:
	BGSBase(unsigned int rows, unsigned int cols,
			const std::string& name = "FrameDifferenceBGS");
	virtual ~BGSBase();
	void process(int* OUT_i, int* OUT_j, int* OUT_k, NUMPY_TYPE** OUT, int IN_i,
			int IN_j, int IN_k, NUMPY_TYPE* IN);
	static std::list<std::string> get_bgs_names();


protected:
	std::string name;
	IBGS* bgs_filter;
	cv::Mat img_bkgmodel;
};


template <class NUMPY_TYPE, int NUMPY_K_DIM, int CV_IMAGE_TYPE, int CV_MASK_TYPE>
BGSBase<NUMPY_TYPE, NUMPY_K_DIM, CV_IMAGE_TYPE, CV_MASK_TYPE>::
BGSBase(unsigned int rows, unsigned int cols, const std::string& name) :
		name(name), img_bkgmodel(cv::Size(rows, cols), CV_IMAGE_TYPE) {
	if (name == "AdaptiveBackgroundLearning") {
		bgs_filter = new AdaptiveBackgroundLearning;
	} else if (name == "FrameDifferenceBGS") {
		bgs_filter = new FrameDifferenceBGS;
	} else if (name == "StaticFrameDifferenceBGS") {
		bgs_filter = new StaticFrameDifferenceBGS;
	} else if (name == "WeightedMovingMeanBGS") {
		bgs_filter = new WeightedMovingMeanBGS;
	} else if (name == "WeightedMovingVarianceBGS") {
		bgs_filter = new WeightedMovingVarianceBGS;
	} else if (name == "MixtureOfGaussianV1BGS") {
		bgs_filter = new MixtureOfGaussianV1BGS;
	} else if (name == "MixtureOfGaussianV2BGS") {
		bgs_filter = new MixtureOfGaussianV2BGS;
	} else if (name == "GMG") {
		bgs_filter = new GMG;
	} else if (name == "DPAdaptiveMedianBGS") {
		bgs_filter = new DPAdaptiveMedianBGS;
	} else if (name == "DPGrimsonGMMBGS") {
		bgs_filter = new DPGrimsonGMMBGS;
	} else if (name == "DPZivkovicAGMMBGS") {
		bgs_filter = new DPZivkovicAGMMBGS;
	} else if (name == "DPMeanBGS") {
		bgs_filter = new DPMeanBGS;
	} else if (name == "DPWrenGABGS") {
		bgs_filter = new DPWrenGABGS;
	} else if (name == "DPPratiMediodBGS") {
		bgs_filter = new DPPratiMediodBGS;
	} else if (name == "DPEigenbackgroundBGS") {
		bgs_filter = new DPEigenbackgroundBGS;
	} else if (name == "DPTextureBGS") {
		bgs_filter = new DPTextureBGS;
	} else if (name == "T2FGMM_UM") {
		bgs_filter = new T2FGMM_UM;
	} else if (name == "T2FGMM_UV") {
		bgs_filter = new T2FGMM_UV;
	} else if (name == "T2FMRF_UM") {
		bgs_filter = new T2FMRF_UM;
	} else if (name == "T2FMRF_UV") {
		bgs_filter = new T2FMRF_UV;
	} else if (name == "FuzzySugenoIntegral") {
		bgs_filter = new FuzzySugenoIntegral;
	} else if (name == "FuzzyChoquetIntegral") {
		bgs_filter = new FuzzyChoquetIntegral;
	} else if (name == "MultiLayerBGS") {
		bgs_filter = new MultiLayerBGS;
	} else if (name == "LBSimpleGaussian") {
		bgs_filter = new LBSimpleGaussian;
	} else if (name == "LBFuzzyGaussian") {
		bgs_filter = new LBFuzzyGaussian;
	} else if (name == "LBMixtureOfGaussians") {
		bgs_filter = new LBMixtureOfGaussians;
	} else if (name == "LBAdaptiveSOM") {
		bgs_filter = new LBAdaptiveSOM;
	} else if (name == "LBFuzzyAdaptiveSOM") {
		bgs_filter = new LBFuzzyAdaptiveSOM;
	} else if (name == "VuMeter") {
		bgs_filter = new VuMeter;
	} else if (name == "KDE") {
		bgs_filter = new KDE;
	} else {
		throw FORMAT_STR("Unknown BGS filter name '%s'", name);
	}
}

template <class NUMPY_TYPE, int NUMPY_K_DIM, int CV_IMAGE_TYPE, int CV_MASK_TYPE>
BGSBase<NUMPY_TYPE, NUMPY_K_DIM, CV_IMAGE_TYPE, CV_MASK_TYPE>::~BGSBase() {
	delete this->bgs_filter;
}


template <class NUMPY_TYPE, int NUMPY_K_DIM, int CV_IMAGE_TYPE, int CV_MASK_TYPE>
void
BGSBase<NUMPY_TYPE, NUMPY_K_DIM, CV_IMAGE_TYPE, CV_MASK_TYPE>::
process(int* OUT_i, int* OUT_j, int* OUT_k, NUMPY_TYPE** OUT,
		int IN_i, int IN_j, int IN_k, NUMPY_TYPE* IN) {

	if (IN_k != NUMPY_K_DIM)
		throw "Image matrix must be an NxMx3 matrix";

	(*OUT) = new NUMPY_TYPE[IN_i * IN_j];
	(*OUT_i) = IN_i;
	(*OUT_j) = IN_j;
	(*OUT_k) = 1;

	cv::Mat img_input(cv::Size(IN_i, IN_j), CV_IMAGE_TYPE, IN,
			cv::Mat::AUTO_STEP);
	cv::Mat img_mask(cv::Size(IN_i, IN_j), CV_MASK_TYPE, *OUT,
			cv::Mat::AUTO_STEP);

	bgs_filter->process(img_input, img_mask, img_bkgmodel);
}


template <class NUMPY_TYPE, int NUMPY_K_DIM, int CV_IMAGE_TYPE, int CV_MASK_TYPE>
std::list<std::string>
BGSBase<NUMPY_TYPE, NUMPY_K_DIM, CV_IMAGE_TYPE, CV_MASK_TYPE>::get_bgs_names() {
	std::list<std::string> nl;
	nl.push_back("AdaptiveBackgroundLearning");
	nl.push_back("FrameDifferenceBGS");
	nl.push_back("StaticFrameDifferenceBGS");
	nl.push_back("WeightedMovingMeanBGS");
	nl.push_back("WeightedMovingVarianceBGS");
	nl.push_back("MixtureOfGaussianV1BGS");
	nl.push_back("MixtureOfGaussianV2BGS");
	nl.push_back("GMG");
	nl.push_back("DPAdaptiveMedianBGS");
	nl.push_back("DPGrimsonGMMBGS");
	nl.push_back("DPZivkovicAGMMBGS");
	nl.push_back("DPMeanBGS");
	nl.push_back("DPWrenGABGS");
	nl.push_back("DPPratiMediodBGS");
	nl.push_back("DPEigenbackgroundBGS");
	nl.push_back("DPTextureBGS");
	nl.push_back("T2FGMM_UM");
	nl.push_back("T2FGMM_UV");
	nl.push_back("T2FMRF_UM");
	nl.push_back("T2FMRF_UV");
	nl.push_back("FuzzySugenoIntegral");
	nl.push_back("FuzzyChoquetIntegral");
	nl.push_back("LBSimpleGaussian");
	nl.push_back("LBFuzzyGaussian");
	nl.push_back("LBMixtureOfGaussians");
	nl.push_back("LBAdaptiveSOM");
	nl.push_back("LBFuzzyAdaptiveSOM");
	nl.push_back("MultiLayerBGS");
	nl.push_back("VuMeter");
	nl.push_back("KDE");

	return nl;
}

/////////////////////////////////////////
// Class instantiations
/////////////////////////////////////////
typedef BGSBase<double, 3, CV_64FC3, CV_64FC1> BGSdouble_c3;
typedef BGSBase<float, 3, CV_32FC3, CV_32FC1> BGSfloat_c3;
typedef BGSBase<unsigned short, 3, CV_16UC3, CV_16UC1> BGSuint16_c3;
typedef BGSBase<unsigned char, 3, CV_8UC3, CV_8UC1> BGSuchar_c3;

#endif // _PYBGS_H_
