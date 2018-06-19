#pragma once

#include "CStruct.h"

struct SeetaFaceCropper;

/**
 * \brief construct an facecropper
 * \return instance of FaceCropper
 */
SEETA_C_API SeetaFaceCropper *SeetaNew_FaceCropper();

/**
 * \brief destruct an facedetector
 * \param ptr [in] pointer to the instance of FaceCropper
 */
SEETA_C_API void SeetaDelete_FaceCropper(const SeetaFaceCropper *ptr);

/**
 * \brief crop face
 * \param ptr [in] pointer to the instance of FaceDetector
 * \param image [in] color format
 * \param points [in] the detected landmarks of face
 * \return cropped face, size 256x256x3
 * \note the detected landmarks of must have number of PointDetector2::LandmarkNum
 * \note returning pointer was volatile, only accessable before next API called.
 * \note return empty image(0x0x0) if failed
 */
SEETA_C_API SeetaImageData FaceCropper_Crop(const SeetaFaceCropper *ptr, const SeetaImageData *image, const SeetaPointF *points);
/**
 * \brief crop face
 * \param ptr [in] pointer to the instance of FaceDetector
 * \param image [in] color format
 * \param points [in] the detected landmarks of face
 * \param face [out] color cropped face, size 256x256x3
 * \note the detected landmarks of must have number of PointDetector2::LandmarkNum
 * \note return 0 failed if failed
 */
SEETA_C_API int FaceCropper_CropEx(const SeetaFaceCropper *ptr, const SeetaImageData *image, const SeetaPointF *points, SeetaImageData *face);