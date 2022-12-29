#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Opencv imports
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, const char **argv)
{
    cv::Mat img = cv::imread("/home/alka/Documents/opencv_cpp_tutorials/chapter2_basics/drake.jpg");
    for (int i = 0; i < 10; i++)
    {
        ostringstream ss;
        ss << "Photo " << i;
        cv::namedWindow(ss.str());
        cv::moveWindow(ss.str(), 20 * i, 20 * i);
        cv::imshow(ss.str(), img);
    }

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}