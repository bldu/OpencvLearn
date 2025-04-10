#include "opencv2/opencv.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    cv::Mat m1{5, 5, CV_8UC3, cv::Scalar(255,255,255)};
    m1.convertTo(m1, CV_32FC3);
    cv::subtract(m1, cv::Scalar(100,200,300), m1);
    cv::divide(m1, cv::Scalar(255,255,255), m1);
    std::cout << m1 << std::endl;

    return 0;
}
