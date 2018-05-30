#pragma once

#include "CStruct.h"

struct SeetaPointDetector;

/**
 * \brief construct an pointdetector
 * \param model model path
 * \return instance of PointDetector
 */
SEETA_C_API SeetaPointDetector *SeetaNew_PointDetector(const char *model);

/**
 * \brief destruct an pointdetector
 * \param ptr [in] pointer to the instance of PointDetector
 */
SEETA_C_API void SeetaDelete_PointDetector(const SeetaPointDetector *ptr);

/**
 * \brief get number of landmarks can be detected
 * \param ptr [in] pointer to the instance of PointDetector
 * \return number of landmarks can be detected
 */
SEETA_C_API int inline SeetaPointDetector_LandmarkNum(const SeetaPointDetector* ptr);

/**
 * \brief detect points on face
 * \param ptr [in] pointer to the instance of PointDetector
 * \param image [in] the orignal image
 * \param face [in] detected face location
 * \return pointer to an array of points, contains each point location, with length of LandmarkNum
 * \sa LandmarkNum
 * \note return nullptr if no detect failed
 */
SEETA_C_API SeetaPointF *SeetaPointDetector_Detect(const SeetaPointDetector *ptr, const SeetaImageData *image, const SeetaRect *face);

/**
* \brief detect points on face
* \param image [in] the orignal image
* \param face [in] detected face location
* \param points [out] detected landmarks on faces, with length of LandmarkNum
* \return return ture only if succeed.
*/
SEETA_C_API bool SeetaPointDetector_DetectEx(const SeetaPointDetector *ptr, const SeetaImageData *image, const SeetaRect *face, SeetaPointF *points);