#pragma once

#include <opencv2/core/core.hpp>

#include <seeta/CStruct.h>

namespace seeta
{
	namespace cv
	{
		using namespace ::cv;
		class ImageData : public SeetaImageData
		{
		public:
			ImageData(const cv::Mat &mat)
				: cv_mat(mat.clone())
			{
				width = cv_mat.cols;
				height = cv_mat.rows;
				channels = cv_mat.channels();
				data = cv_mat.data;
			}
			bool empty() const { return cv_mat.empty(); }
		private:
			cv::Mat cv_mat;
		};

		inline ImageData read_image(const std::string &filename)
		{
			return cv::imread(filename, cv::IMREAD_COLOR);
		}
	}
}