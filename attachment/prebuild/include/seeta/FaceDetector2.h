#pragma once

#define _SDK_MIN_MSC_VER 1800
#define _SDK_MAX_MSC_VER 1900

#if defined(_MSC_VER)
#if _MSC_VER < _SDK_MIN_MSC_VER || _MSC_VER > _SDK_MAX_MSC_VER
#error "Unsupported MSVC. Please use VS2013(v120) or compatible VS2015(v140)."
#endif // _MSC_VER < 1800 || _MSC_VER > 1900
#endif // defined(_MSC_VER)

#include "CStruct.h"

namespace seeta {

	class FaceDetector2
	{
	public:
		/**
		 * \brief construct an facedetector
		 * \param model model path
		 */
		SEETA_API FaceDetector2(const char *model);
		SEETA_API ~FaceDetector2();
		/**
		 * \brief detect faces
		 * \param num [out] num of detected facess
		 * \param image [in] 
		 * \return pointer to an array of rectangle, contains each faces location, with length of *num
		 * \note return nullptr if no face detected
		 * \note faces were sorted by width * length
		 * \note returning pointer was volatile, only accessable before next API called.
		 */
		SEETA_API SeetaRect *Detect(const SeetaImageData &image, int *num = nullptr) const;

	private:
		FaceDetector2(const FaceDetector2 &other) = delete;
		const FaceDetector2 &operator=(const FaceDetector2 &other) = delete;

		void *impl;
	};

}

