// https://blog.csdn.net/cyhbrilliant/article/details/50471694

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

void MakeAnimation1(std::string img_path) {
  cv::Mat img = cv::imread(img_path);

  int a = 0;
  int b = 0;
  int t = 0;
  int k = 1;

  while (true) {
    cv::circle(img, cv::Point(b, a), k, cv::Scalar(255, 0, 255), 3);  //画圆
    cv::imshow("animation1", img);
    cv::waitKey(50);  // 20ms一帧图像
    a += 1;
    b += 1;
    k++;  //改变控制圆大小
  }
}

void MakeAnimation2(std::string img_path) {
  cv::Mat img = cv::imread(img_path);
  cv::Mat img_ani(img.rows, img.cols, CV_8UC3);

  int a = 0;
  int b = 0;
  int t = 0;
  int k = 1;

  while (true) {
    img_ani = img.clone();
    cv::circle(img_ani, cv::Point(b, a), k, cv::Scalar(255, 0, 255), 3);  //画圆
    cv::imshow("animation2", img_ani);
    cv::waitKey(50);  // 20ms一帧图像
    a += 1;
    b += 1;
    k++;  //改变控制圆大小
  }
}


int main(int argc, char *argv[]) {
  if (argc<2){
    std::cout << "Please input image path" << std::endl;
    return -1;
  }
  //  MakeAnimation1(argv[1]);
  MakeAnimation2(argv[1]);
  return 0;
}
