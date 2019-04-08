// drawing_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <corecrt_math_defines.h>

using namespace cv;
using namespace std;

int y_coord = 600;
int x_coord = 800;
Mat plain_image = Mat::zeros(y_coord, x_coord, CV_8UC3);
int callback_count = 0;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void draw_center();
void draw_middle_line();
void wait_key();
int calculate_angle(int x, int y);

int main(int argc, char** argv)
{
	namedWindow("Project", WINDOW_KEEPRATIO);
	setMouseCallback("Project", CallBackFunc, NULL);
	imshow("Project", plain_image);
	wait_key();

	draw_center();
	imshow("Project", plain_image);
	wait_key();

	draw_middle_line();
	imshow("Project", plain_image);

	waitKey();

	return 0;
}

void draw_middle_line() {
	line(plain_image, Point(x_coord / 2, y_coord / 2), Point(x_coord, y_coord / 2), Scalar(0, 255, 0), 2, 8, 0);
}

void draw_center() {
	circle(plain_image, Point(x_coord / 2, y_coord / 2), 2, Scalar(0, 255, 0), 2, 8, 0);
}

void wait_key() {
	while (true) {
		int k = waitKey();
		if (k == 32) {
			break;
		}
		else if (k == 27) {
			destroyWindow("Project");
			break;
		}
	}
}

int calculate_angle(int x, int y) {

	int angle;
	int x_origo = x - x_coord / 2; 
	int y_origo = y - y_coord / 2; 

	float radian = atan((float)y_origo / (float)x_origo);
	angle = -1 * round((radian / M_PI) * 180);

	if (x < x_coord / 2 && y < y_coord / 2) {
		angle += 180;
	}else if (x < x_coord / 2 && y > y_coord / 2) {
		angle -= 180;
	}

	return angle;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		callback_count++;

		circle(plain_image, Point(x, y), 2, Scalar(0, 255, 0), 2, 8, 0);
		line(plain_image, Point(x, y), Point(x_coord / 2, y_coord / 2), Scalar(0, 255, 0), 2, 8, 0);
		imshow("Project", plain_image);
		wait_key();

		string message = "The angle is: " + to_string(calculate_angle(x, y));
		putText(plain_image, message, Point(20, 20 + callback_count * 25), FONT_HERSHEY_DUPLEX, 0.7, (0, 0, 255), 1, LINE_8);
		imshow("Project", plain_image);
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
