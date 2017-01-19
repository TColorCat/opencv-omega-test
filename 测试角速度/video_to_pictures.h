#ifndef videotopicture_h_
#define videotopicture_h_

#include<cv.h>
#include<string>
#include<e:\Opencv30\opencv\build\include\opencv2\videoio.hpp>
using cv::Mat;
using std::string;
namespace toPicture
{
	

	namespace VedioTo
	{
		void videotoP(cv::VideoCapture&,const string& outfolder );

		
	}
}

#endif