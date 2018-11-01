#include "pch.h"
#include "Get_ROI.h"
#include <vector>




Mat GetFluorescenceImage(Mat InputImg, int n_threshold, vector<vector<Point>>contours, vector<Vec4i> hierarchy, vector<cv::Rect> bounding_boxes)
{

	Mat outimg,Cannyimg,resultimg;

	//2��ȭ
	threshold(InputImg, outimg, n_threshold, 255, THRESH_BINARY);// �缳�� �ʿ�... Ȥ�� �ٸ� ��� ����?
	//waitKey();

	//Canny(outimg, Cannyimg, 20, 40, 3);
	//imshow("img3", Cannyimg);
	////waitKey();
	//ROI ���� �� HAT �����........

	//��輱 ����
	findContours(outimg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 255)); // ���� �̻��ϴ�.... - �̹��� �Ʒ��� �и�.....
	resultimg = Mat::zeros(outimg.size(), CV_8U);
	vector<vector<Point> > contours_poly (contours.size());
	 //bounding_boxes = new vector<Rect>(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		bounding_boxes[i] = boundingRect(Mat(contours_poly[i]));
	
	}

	//Main���� �̵�...
	//imshow("img3", outimg);
	//Scalar color = Scalar(255);
	//for (int i = 0; i < contours.size(); i++)
	//{
	//	
	//	drawContours(resultimg, contours, i, color,1, 8, hierarchy, 0, Point());// ��輱 �׸���
	//	// �簢�� �׸���..... bounding box
	//	rectangle(resultimg, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0); // �ڽ� �׸���...
			//}
	//imshow("img4", resultimg);
	//waitKey();




	//1. ��輱 ����
	//2. �簢�� �׸���.
	//3. �̻ڰ�
	return resultimg;
}

void DisplayROI()
{

}