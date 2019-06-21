// angle-project.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "pch.h"
#include <math.h>

cv::Mat image(800, 800, CV_8UC3);
cv::Mat image2;
float radian = 57.345;

void MouseCallBackFunc(int event, int x, int y, int flags, void *userdata);
float angle_calculator(int y, int x);

int main()
{

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			image.at<cv::Vec3b>(i, j)[0] = (i * j) % 255;
			image.at<cv::Vec3b>(i, j)[1] = (i + j) % 255;
			image.at<cv::Vec3b>(i, j)[2] = (j) % 255;
		}
	}
	cv::imshow("Ablak2", image);
	image2 = image.clone();
	cv::Scalar lineColor = { 0, 0, 0 };
	cv::line(image, { image.rows / 2, image.cols / 2 },
		{ image.rows, image.cols / 2 }, lineColor, 5);
	cv::circle(image, { image.rows / 2, image.cols / 2 }, 10, lineColor, 1);
	cv::imshow("Ablak", image2);
	cv::setMouseCallback("Ablak", MouseCallBackFunc);
	cv::waitKey(0);
}

void MouseCallBackFunc(int event, int x, int y, int flags, void *userdata)
{
	if (flags & cv::MouseEventFlags::EVENT_FLAG_LBUTTON) {
		image2 = image.clone();
		cv::circle(image2, { x, y }, 10, { 0, 0, 0 }, 1);
		cv::line(image2, { image2.rows / 2, image2.cols / 2 },
			{ x , y }, { 0, 0, 0 }, 5);
		std::string text = std::to_string(angle_calculator(y, x));
		cv::putText(image2, text, { image2.cols /2, image2.rows / 2 }, cv::FONT_HERSHEY_SIMPLEX, 2, { 0,0,0 }, 5 , cv::LINE_AA);
		cv::imshow("Ablak", image2);
	}
	if (flags & cv::MouseEventFlags::EVENT_FLAG_RBUTTON) {
		image2 = image.clone();
		cv::imshow("Ablak", image2);
	}
}

float angle_calculator(int y, int x)
{
	double angle = 0;
	double a;
	double b;

	if (x > image2.cols / 2 && y < image2.rows / 2) {
		a = image2.rows / 2 - y;
		b = x - image2.cols / 2;
		angle = atan(a / b) * radian;
		return angle;
	} else if (x < image2.cols / 2 && y < image2.rows / 2) {
		a = image2.rows / 2 - y;
		b = image2.cols / 2 - x;
		angle = 180 - atan(a / b) * radian;
		return angle;
	} else if (x < image2.cols / 2 && y > image2.rows / 2) {
		a = y - image2.rows / 2;
		b = image2.cols / 2 - x;
		angle = 180 + atan(a / b) * radian;
		return angle;
	} else if (x > image2.cols / 2 && y > image2.rows / 2) {
		a = y - image2.rows / 2;
		b = image2.cols / 2 - x;
		angle = 360 + atan(a / b) * radian;
		return angle;
	} else if (x > image2.cols / 2 && y == image2.rows / 2) {
		return angle;
	} else if (x == image2.cols / 2 && y < image2.rows / 2) {
		angle = 90;
		return angle;
	} else if (x < image2.cols / 2 && y == image2.rows / 2) {
		angle = 180;
		return angle;
	} else if (x == image2.cols / 2 && y > image2.rows / 2) {
		angle = 270;
		return angle;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
