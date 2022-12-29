#include <iostream>
#include <sstream>
#include "headers/utils.h"

using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc.hpp>

int blurAmount = 15;
// static void onChange(int pos, void *userInput);
// static void onMouse(int event, int x, int y, int, void *userInput);

static void onChange(int pos, void *userInput)
{
    if (pos <= 0)
        return;
    cv::Mat imgBlur;
    cv::Mat *img = (cv::Mat *)userInput;
    cv::blur(*img, imgBlur, cv::Size(pos, pos));
    cv::imshow("Drake", imgBlur);
}

static void onMouse(int event, int x, int y, int, void *userInput)
{
    if (event != cv::EVENT_LBUTTONDOWN)
        return;
    cv::Mat *img = (cv::Mat *)userInput;
    cv::circle(*img, cv::Point(x, y), 10, cv::Scalar(0, 255, 0), 3);
    onChange(blurAmount, img);
}

int main(int argc, char const *argv[])
{
    cv::Mat drake = cv::imread("/home/alka/Documents/opencv_cpp_tutorials/chapter2_basics/drake.jpg");
    cv::namedWindow("Drake");
    cv::createTrackbar("DrakeTb", "Drake", &blurAmount, 30, onChange, &drake);
    cv::setMouseCallback("Drake", onMouse, &drake);

    onChange(blurAmount, &drake);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}