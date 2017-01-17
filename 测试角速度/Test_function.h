#ifndef test_function
#define test_function
#include<string>
namespace test_functions
{
	

	void Test_erobe(const std::string& filepath);
	void Test_blur(const std::string& filepath);
	void Test_canny(const std::string& filepath);
	void Test_harris(const std::string&filepath);
	
	void Test_using_selfcamera(const int &);
}

#endif