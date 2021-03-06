// FIPM.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h" // 변경 필요....

#include "Get_ROI.h"

#include<opencv2\opencv.hpp>
int main()
{
	cv::Mat image = cv::imread("D:/git/github/FIPM/FIPM/img/42_image.jpg", 0);

	
	//사용할 변수 선언......
	int threshold = 55;
	int num_bounding_boxes;
	vector<Vec4i> hierarchy;
	vector<vector<Point>> contours;
	Rect *bounding_boxes=NULL;



	//GetImg("D:/git/github/FIPM/FIPM/img/42_image.jpg");
	cv::Mat output = GetFluorescenceImage(image, threshold, contours, hierarchy, bounding_boxes);

	Scalar color = Scalar(255);
	for (int i = 0; i < contours.size(); i++)
	{
		
		drawContours(output, contours, i, color,1, 8, hierarchy, 0, Point());// 경계선 그리기
		// 사각형 그리기..... bounding box
		rectangle(output, bounding_boxes[i].tl(), bounding_boxes[i].br(), color, 2, 8, 0); // 박스 그리기...
	}
	imshow("img4", output);
	waitKey();
	//contours.size(); = num contours
	//bounding_boxes.size(); = num_bounding_boxes
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
