#ifndef videotopicture_h_
#define videotopicture_h_

#include<cv.h>
#include<string>

using cv::Mat;
using std::string;
using cv::VideoCapture;
namespace toPicture
{
	

	namespace VedioTo
	{
		void videotoP(VideoCapture& capture ,const string& outfolder );

		
	}

	namespace test_function
	{
		void test_video();
	}
}

#endif