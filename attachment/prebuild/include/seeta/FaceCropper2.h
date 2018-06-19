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

	class FaceCropper2
	{
	public:
		SEETA_API FaceCropper2();
		SEETA_API ~FaceCropper2();
		/**
		 * \brief crop face
		 * \param image [in] color format
		 * \param points [in] the detected landmarks of face
		 * \return cropped face, size 256x256x3
		 * \note the detected landmarks of must have number of PointDetector2::LandmarkNum
		 * \note returning pointer was volatile, only accessable before next API called.
		 * \note return empty image(0x0x0) if failed
		 */
		SEETA_API SeetaImageData Crop(const SeetaImageData &image, const SeetaPointF *points) const;
		/**
		 * \brief crop face
		 * \param image [in] color format
		 * \param points [in] the detected landmarks of face
		 * \param face [out] color cropped face, size 256x256x3
		 * \note the detected landmarks of must have number of PointDetector2::LandmarkNum
		 * \note return false if failed
		 */
		SEETA_API bool CropEx(const SeetaImageData &image, const SeetaPointF *points, SeetaImageData &face) const;

	private:
		FaceCropper2(const FaceCropper2 &other) = delete;
		const FaceCropper2 &operator=(const FaceCropper2 &other) = delete;

		void *impl;
	};

}

