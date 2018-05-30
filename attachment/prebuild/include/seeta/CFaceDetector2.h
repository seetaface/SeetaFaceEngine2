#pragma once

#include "CStruct.h"

struct SeetaFaceDetector;

/**
 * \brief construct an facedetector
 * \param model model path
 * \return instance of FaceDetector
 */
SEETA_C_API SeetaFaceDetector *SeetaNew_FaceDetector(const char *model);

/**
 * \brief destruct an facedetector
 * \param ptr [in] pointer to the instance of FaceDetector
 */
SEETA_C_API void SeetaDelete_FaceDetector(const SeetaFaceDetector *ptr);

/**
 * \brief detect faces
 * \param ptr [in] pointer to the instance of FaceDetector
 * \param num [out] num of detected facess
 * \param image [in] 
 * \return pointer to an array of rectangle, contains each faces location, with length of *num
 * \note return nullptr if no face detected
 * \note faces were sorted by width * length
 */
SEETA_C_API SeetaRect *SeetaFaceDetector_Detect(const SeetaFaceDetector *ptr, const SeetaImageData *image, int *num);