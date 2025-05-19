#include <vector>
#include <algorithm>
#include <iostream>

#include "opencv2/opencv.hpp"


struct Box{
    float x1, y1, x2, y2;
    float confidence;
};

std::ostream &operator<<(std::ostream &os, const Box &box){
    os << "{" << box.x1 << ", " << box.y1 << ", " << box.x2 << ", " << box.y2 << ", " << box.confidence << "}";
    return os;
}


static cv::Rect2f BoxToRect(const Box &box){
    return cv::Rect2f(cv::Point2f(box.x1, box.y1), cv::Point2f(box.x2, box.y2));
}


static float CalcIOU(const cv::Rect2f &rect1, const cv::Rect2f &rect2){
    cv::Rect2f intersection = rect1 & rect2;
    if (intersection.empty()){
        return 0.0;
    }
    float inter_area = intersection.area();
    float union_area = rect1.area() + rect2.area() - inter_area;
    float iou = inter_area/union_area;
    return iou;
}

static float CalcIOU(const Box &box1, const Box &box2){
    cv::Rect2f rect1 = BoxToRect(box1);
    cv::Rect2f rect2 = BoxToRect(box2);
    return CalcIOU(rect1, rect2);
}



static std::vector<Box> NMS(std::vector<Box> &boxes, float iou_thresh){
    std::vector<Box> result;
    std::sort(boxes.begin(), boxes.end(), [](const Box &box1, const Box &box2){return box1.confidence > box2.confidence;});

    while (boxes.size()>0){
        result.push_back(boxes[0]);
        std::vector<Box> tmp;
        for (int i=1; i<boxes.size(); i++){
            if (CalcIOU(boxes[0], boxes[i])<iou_thresh){
                tmp.push_back(boxes[i]);
            }
        }
        // boxes = tmp;
        boxes = std::move(tmp);
    }

    return result;
}


int main(int argc, char **argv){
    std::vector<Box> boxes = {
        {100, 100, 200, 200, 0.9},
        {110, 110, 210, 210, 0.8},
        {300, 300, 400, 400, 0.85}
    };
    auto filtered_boxes = NMS(boxes, 0.5);
    for (auto &b : filtered_boxes){
        std::cout << b << std::endl;
    }

    return 0;
}
