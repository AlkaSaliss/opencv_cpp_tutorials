#include <iostream>
#include <sstream>
#include "../headers/utils.h"
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc.hpp>

cv::Mat img;
bool applyGray = false;
bool applyBlur = false;
bool applySobel = false;

void grayCallback(int state, void *userData)
{
    applyGray = true;
    applyFilters();
}

void bgrCallback(int state, void *userData)
{
    applyGray = false;
    applyFilters();
}

void blurCallback(int state, void *userData)
{
    applyBlur = (bool)state;
    applyFilters();
}

void sobelCallback(int state, void *userData)
{
    applySobel = !applySobel;
    applyFilters();
}

void applyFilters()
{
    cv::Mat result;
    img.copyTo(result);
    if (applyGray)
        cv::cvtColor(result, result, cv::COLOR_BGR2GRAY);
    if (applyBlur)
        cv::blur(result, result, cv::Size(5, 5));
    if (applySobel)
        cv::Sobel(result, result, CV_8U, 1, 1);
    cv::imshow("Drake", result);
}

int main(int argc, char const *argv[])
{
    img = cv::imread("/home/alka/Documents/opencv_cpp_tutorials/chapter2_basics/drake.jpg");
    cv::namedWindow("Drake");

    cv::createButton("Blur", blurCallback, NULL, cv::QT_CHECKBOX, 0);
    cv::createButton("Gray", grayCallback, NULL, cv::QT_RADIOBOX, 0);
    cv::createButton("RGB", bgrCallback, NULL, cv::QT_RADIOBOX, 1);
    cv::createButton("Sobel", sobelCallback, NULL, cv::QT_PUSH_BUTTON, 0);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}