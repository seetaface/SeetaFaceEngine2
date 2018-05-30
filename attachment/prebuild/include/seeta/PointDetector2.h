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

	class PointDetector2
	{
	public:
		/**
		 * \brief construct an pointdetector
		 * \param model model path
		 */
		SEETA_API PointDetector2(const char *model);
		SEETA_API ~PointDetector2();
		/**
		 * \brief get number of landmarks can be detected
		 * \return number of landmarks can be detected
		 */
		SEETA_API int LandmarkNum() const;
		/**
		* \brief detect points on face
		* \param image [in] the orignal image
		* \param face [in] detected face location
		* \return pointer to an array of points, contains each point location, with length of LandmarkNum
		* \sa LandmarkNum
		* \note return nullptr if no detect failed
		* \note returning pointer was volatile, only accessable before next API called.
		*/
		SEETA_API SeetaPointF *Detect(const SeetaImageData &image, const SeetaRect &face) const;

		/**
		* \brief detect points on face
		* \param image [in] the orignal image
		* \param face [in] detected face location
		* \param points [out] detected landmarks on faces, with length of LandmarkNum
		* \return return ture only if succeed.
		*/
		SEETA_API bool DetectEx(const SeetaImageData &image, const SeetaRect &face, SeetaPointF *points) const;

	private:
		PointDetector2(const PointDetector2 &other) = delete;
		const PointDetector2 &operator=(const PointDetector2 &other) = delete;

		void *impl;
	};

}

