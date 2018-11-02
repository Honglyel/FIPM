#pragma once
#include "pch.h" // 변경 필요....
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;


Mat GetFluorescenceImage(Mat InputImg,int n_threshold, vector<vector<Point>>*contours, vector<Vec4i> *hierarchy , Rect *bounding_boxes);



//todo....
//함수 이름변경........