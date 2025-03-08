// https://blog.csdn.net/qq_29540745/article/details/52562101

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

#define WINDOW "11"
static bool P = false;
static cv::Point previousPoint;
static cv::Mat img;

static void UseMouse1(int event, int x, int y, int flags, void* param);

int main(int argc, char* argv[]) {
  std::string img_path = argv[1];
  img = cv::imread(img_path);
  cv::imshow(WINDOW, img);
  cv::setMouseCallback(WINDOW, UseMouse1, 0);
  cv::waitKey(0);
  return 0;
}

void UseMouse1(int event, int x, int y, int flags, void* param) {
  switch (event) {
    case cv::EVENT_LBUTTONUP: {
      P = false;
    } break;
    case cv::EVENT_LBUTTONDOWN: {
      previousPoint = cv::Point(x, y);

      P = true;
    } break;

    case cv::EVENT_MOUSEMOVE: {
      if (P) {
        cv::Point pt(x, y);
        cv::line(img, previousPoint, pt, cv::Scalar(0, 0, 255), 2, 5, 0);
        previousPoint = pt;
        cv::imshow(WINDOW, img);
      }
    } break;
  }
}

void UseMouse2(){};
