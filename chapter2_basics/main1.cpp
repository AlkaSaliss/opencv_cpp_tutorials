#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Opencv imports
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"


int main(int argc, const char** argv) {

    // read image
    cv::Mat color = cv::imread("/home/alka/Documents/opencv_cpp_tutorials/chapter2_basics/drake.jpg");
    cv::Mat gray = cv::imread("/home/alka/Documents/opencv_cpp_tutorials/chapter2_basics/drake.jpg", cv::IMREAD_GRAYSCALE);

    // Check for invalid data
    if (!color.data) {
        cout << "Could not open or find image file !!!" << endl;
        return -1; 
    }


    // Write images
    cv::imwrite("/home/alka/Documents/opencv_cpp_tutorials/chapter2_basics/drake_grayscale.jpg", gray);

    // Get some pixels using opencv
    // int myRow = color.rows - 1;
    // int myCol = color.cols - 1;
    int myRow = 0;
    int myCol = 0;

    cv::Vec3b pixel = color.at<cv::Vec3b>(myRow, myCol);
    cout << "Pixel value (B, G, R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;

    // Display images
    cv::imshow("Drake Color", color);
    cv::imshow("Drake Grayscale", gray);
    cv::waitKey(0);
    return 0;

}