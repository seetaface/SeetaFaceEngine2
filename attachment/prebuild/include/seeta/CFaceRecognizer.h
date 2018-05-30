#pragma once

#include "CStruct.h"

struct SeetaFaceRecognizer;

/**
* \brief construct an FaceRecognizer
* \param model model path
* \return instance of FaceRecognizer
*/
SEETA_C_API SeetaFaceRecognizer *SeetaNew_FaceRecognizer(const char *model);

/**
* \brief destruct an FaceRecognizer
* \param ptr [in] pointer to the instance of FaceRecognizer
*/
SEETA_C_API void SeetaDelete_FaceRecognizer(const SeetaFaceRecognizer *ptr);

/**
* \brief return similarity of two faces
* \param ptr [in] pointer to the instance of FaceRecognizer
* \param image1 [in] the original image of face1
* \param points1 [in] the detected landmarks of face1
* \param image2 [in] the original image of face2
* \param points2 [in] the detected landmarks of face2
* \return return similarity of face1 and face2
* \note the detected landmarks of must have number of PointDetector2::LandmarkNum
* \note return 0 if failed
*/
SEETA_C_API float SeetaFaceRecognizer_Compare(const SeetaFaceRecognizer *ptr, const SeetaImageData *image1, const SeetaPointF *points1, const SeetaImageData *image2, const SeetaPointF *points2);

/**
* \brief register faces to database, return the index of registered face
* \param ptr [in] pointer to the instance of FaceRecognizer
* \param image [in] the original image of face
* \param points [in] the detected landmarks of face
* \return index of registered face
* \note the detected landmarks of must have number of PointDetector2::LandmarkNum
* \note return -1 if faild.
*/
SEETA_C_API int SeetaFaceRecognizer_Register(SeetaFaceRecognizer *ptr, const SeetaImageData *image, const SeetaPointF *points);

/**
* \brief clear all registered face
* \param ptr [in] pointer to the instance of FaceRecognizer
* \sa Register
*/
SEETA_C_API void SeetaFaceRecognizer_Clear(SeetaFaceRecognizer *ptr);

/**
* \brief get the number of registerd faces
* \param ptr [in] pointer to the instance of FaceRecognizer
* \return the number of registerd faces
*/
SEETA_C_API int SeetaFaceRecognizer_MaxRegisterIndex(const SeetaFaceRecognizer *ptr);

/**
* \brief recognize the given face from database, return the most similar face's index
* \param ptr [in] pointer to the instance of FaceRecognizer
* \param image [in] the original image of face
* \param points [in] the detected landmarks of face
* \param similarity [out] the most similarity
* \return the most similar face's index
* \note return -1 if faild.
* \sa Register
*/
SEETA_C_API int SeetaFaceRecognizer_Recognize(const SeetaFaceRecognizer *ptr, const SeetaImageData *image, const SeetaPointF *points, float *similarity);

/**
* \brief recognize the given face from database, return each similarity of database
* \param ptr [in] pointer to the instance of FaceRecognizer
* \param image [in] the original image of face
* \param points [in] the detected landmarks of face
* \return pointer to an array of similarity, with length MaxRegisterIndex
* \note using index returned by Register to get exact face's similarity
* \note returning pointer was volatile, only accessable before next API called.
* \sa Register
* \sa MaxRegisterIndex
*/
SEETA_C_API float *SeetaFaceRecognizer_RecognizeEx(const SeetaFaceRecognizer *ptr, const SeetaImageData *image, const SeetaPointF *points);