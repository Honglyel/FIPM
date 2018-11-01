#include "pch.h"
#include "Get_ROI.h"
#include <vector>




Mat GetFluorescenceImage(Mat InputImg, int n_threshold, vector<vector<Point>>contours, vector<Vec4i> hierarchy, vector<cv::Rect> bounding_boxes)
{

	Mat outimg,Cannyimg,resultimg;

	//2진화
	threshold(InputImg, outimg, n_threshold, 255, THRESH_BINARY);// 재설정 필요... 혹은 다른 방법 적용?
	//waitKey();

	//Canny(outimg, Cannyimg, 20, 40, 3);
	//imshow("img3", Cannyimg);
	////waitKey();
	//ROI 추출 후 HAT 씌우기........

	//경계선 추출
	findContours(outimg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 255)); // 뭔가 이상하다.... - 이미지 아래로 밀림.....
	resultimg = Mat::zeros(outimg.size(), CV_8U);
	vector<vector<Point> > contours_poly (contours.size());
	 //bounding_boxes = new vector<Rect>(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		bounding_boxes[i] = boundingRect(Mat(contours_poly[i]));
	
	}

	//Main으로 이동...
	//imshow("img3", outimg);
	//Scalar color = Scalar(255);
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	
	//	drawContours(resultimg, contours, i, color,1, 8, hierarchy, 0, Point());// 경계선 그리기
	//	// 사각형 그리기..... bounding box
	//	rectangle(resultimg, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0); // 박스 그리기...
			//}
	//imshow("img4", resultimg);
	//waitKey();




	//1. 경계선 추출
	//2. 사각형 그리기.
	//3. 이쁘게
	return resultimg;
}

void DisplayROI()
{

}