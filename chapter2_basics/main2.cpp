#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Opencv imports
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, const char **argv)
{

    // Opencv CLI parser
    const char *keys = {
        "{help h usage ? | | print this message}"
        "{@video | | Video file, if not defined try to read from webcam}"};

    cv::CommandLineParser parser(argc, argv, keys);

    if (parser.has("help"))
    {
        parser.printMessage();
        return 0;
    }

    cv::String videoFile = parser.get<cv::String>(0);

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }

    cv::VideoCapture cap;
    if (videoFile != "")
        cap.open(videoFile);
    else
        cap.open(0);
    
    if (!cap.isOpened())
        return -1;
    
    cv::namedWindow("Video", 1);
    for (;;) {
        cv::Mat frame;
        cap >> frame;
        if (frame.data)
            cv::imshow("Video", frame);
        if (cv::waitKey(30) > 0)
            break;
    }
    cap.release();

    return 0;
}