#ifndef test_function_h_
#define test_function_h_
#include<string>
#include<cv.h>
//using cv::Mat;
namespace test_functions
{
	

	void Test_erobe(const std::string& filepath);//input file
	void Test_blur(const std::string& filepath);
	void Test_canny(const std::string& filepath);
	void Test_harris(const std::string&filepath);
	
	/*overload input Mat for every mathods*/
	cv::Mat Test_erobe(const cv::Mat& );//input Mat
	cv::Mat Test_blur(const cv::Mat& );
	cv::Mat Test_canny(const cv::Mat& );
	cv::Mat Test_harris(const cv::Mat&);


	/*@param id is the opened video capturing device (i.e. a camera index).
		If there is a single camera connected, just pass 0.
	@param void(*pi)(const cv::Mat&) is a function pointer to get img processing methods
	@param int wait is a parameter for waitKey() in each frame process;
	*/
	void Test_using_selfcamera(const int &,cv::Mat(*)(const cv::Mat&),int waitkeynumber);
}

#endif