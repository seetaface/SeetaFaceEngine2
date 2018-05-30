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

	class FaceRecognizer2
	{
	public:
		/**
		* \brief construct an facerecognizer
		* \param model model path
		*/
		SEETA_API FaceRecognizer2(const char *model);
		SEETA_API ~FaceRecognizer2();

		/**
		 * \brief return similarity of two faces
		 * \param image1 [in] the original image of face1
		 * \param points1 [in] the detected landmarks of face1
		 * \param image2 [in] the original image of face2
		 * \param points2 [in] the detected landmarks of face2
		 * \return return similarity of face1 and face2
		 * \note the detected landmarks of must have number of PointDetector2::LandmarkNum
		 * \note return 0 if failed
		 */
		SEETA_API float Compare(const SeetaImageData &image1, const SeetaPointF *points1, const SeetaImageData &image2, const SeetaPointF *points2) const;

		/**
		 * \brief register faces to database, return the index of registered face
		 * \param image [in] the original image of face
		 * \param points [in] the detected landmarks of face
		 * \return index of registered face
		 * \note the detected landmarks of must have number of PointDetector2::LandmarkNum
		 * \note return -1 if faild.
		 */
		SEETA_API int Register(const SeetaImageData &image, const SeetaPointF *points);

		/**
		 * \brief clear all registered face
		 * \sa Register
		 */
		SEETA_API void Clear();

		/**
		 * \brief get the number of registerd faces
		 * \return the number of registerd faces
		 */
		SEETA_API int MaxRegisterIndex() const;

		/**
		 * \brief recognize the given face from database, return the most similar face's index
		 * \param image [in] the original image of face
		 * \param points [in] the detected landmarks of face
		 * \param similarity [out] the most similarity
		 * \return the most similar face's index
		 * \note return -1 if faild.
		 * \sa Register
		 */
		SEETA_API int Recognize(const SeetaImageData &image, const SeetaPointF *points, float *similarity = nullptr) const;

		/**
		 * \brief recognize the given face from database, return each similarity of database
		 * \param image [in] the original image of face
		 * \param points [in] the detected landmarks of face
		 * \return pointer to an array of similarity, with length MaxRegisterIndex
		 * \note using index returned by Register to get exact face's similarity
		 * \note returning pointer was volatile, only accessable before next API called.
		 * \sa Register
		 * \sa MaxRegisterIndex
		 */
		SEETA_API float *RecognizeEx(const SeetaImageData &image, const SeetaPointF *points) const;

	private:
		FaceRecognizer2(const FaceRecognizer2 &other) = delete;
		const FaceRecognizer2 &operator=(const FaceRecognizer2 &other) = delete;

		void *impl;
	};

}

