#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using cv::Mat;
using cv::Scalar;
using std::cout;
using std::endl;

int main()
{
    Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
    cout << "M = " << endl
         << " " << M << endl
         << endl;
    M.create(4, 4, CV_8UC(2));
    cout << "M = " << endl
         << " " << M << endl
         << endl;
    return 0;
}
