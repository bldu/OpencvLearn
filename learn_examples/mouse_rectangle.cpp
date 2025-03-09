// https://blog.csdn.net/qq_29540745/article/details/52562101

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;

static Rect g_select;
static bool select_flag = false;
static Mat img, showImg;

static void A_on_Mouse(int event, int x, int y, int flags, void* param)  //实现画矩形框
{
  Point p1, p2;
  if (event == EVENT_LBUTTONDOWN) {
    g_select.x = x;
    g_select.y = y;
    select_flag = true;
  } else if (select_flag && event == EVENT_MOUSEMOVE) {
    img.copyTo(showImg);
    p1 = Point(g_select.x, g_select.y);
    p2 = Point(x, y);
    rectangle(showImg, p1, p2, Scalar(0, 255, 0), 2);
    imshow("img", showImg);
  } else if (select_flag && event == EVENT_LBUTTONUP) {
    select_flag = false;
  }
}
static void B_on_Mouse(int event, int x, int y, int flags,
                void* param)  //实现画矩形框并截图
{
  Point p1, p2;
  switch (event) {
    case EVENT_LBUTTONDOWN: {
      g_select.x = x;
      g_select.y = y;
      select_flag = true;
    } break;
    case EVENT_MOUSEMOVE: {
      if (select_flag) {
        img.copyTo(showImg);
        p1 = Point(g_select.x, g_select.y);
        p2 = Point(x, y);
        rectangle(showImg, p1, p2, Scalar(0, 255, 0), 2);
        imshow("img", showImg);
      }
    } break;
    case EVENT_LBUTTONUP: {
      //显示框出的ROI
      //改成Rect roi = Rect(p1, p2);为什么不对？
      Rect roi = Rect(Point(g_select.x, g_select.y), Point(x, y));
      if (roi.width && roi.height)  //点一下时会没有反应
      {
        Mat roiImg = img(roi);
        imshow("roi", roiImg);
      }
      select_flag = false;

    } break;
  }
}

int main(int argc, char const *argv[])
{
  std::string img_path = argv[1];
  img = imread(img_path, 1);
  showImg = img.clone();
  g_select.x = g_select.y = 0;
  imshow("img", showImg);

  while (1) {
    int key = waitKey(10);
    switch (key) {
      case 'a':
        setMouseCallback("img", A_on_Mouse, 0);
        break;
      case 'b':
        setMouseCallback("img", B_on_Mouse, 0);
        break;
    }
    if (key == 27 || key == 'q') break;
  }
  waitKey(0);
  return 0;
}
