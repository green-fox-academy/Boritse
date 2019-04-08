// drawing_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	/// General instructions
	printf("\n Zoom In-Out demo  \n ");
	printf("------------------ \n");
	printf(" * [u] -> Zoom in  \n");
	printf(" * [d] -> Zoom out \n");
	printf(" * [ESC] -> Close program \n \n");

	Mat apples, apple_sampled, temp;
	string window_name = "Pyramids Demo";

	/// Test image - Make sure it s divisible by 2^{n}
	apples = imread("apples.jpg");
	if (!apples.data)
	{
		printf(" No data! -- Exiting the program \n");
		return -1;
	}

	temp = apples;
	apple_sampled = temp;

	/// Create window
	namedWindow(window_name, WINDOW_AUTOSIZE);
	imshow(window_name, apple_sampled);

	/// Loop
	while (true)
	{
		int c;
		c = waitKey(10);

		if ((char)c == 27)
		{
			break;
		}
		if ((char)c == 'u')
		{
			pyrUp(temp, apple_sampled, Size(temp.cols * 2, temp.rows * 2));
			printf("** Zoom In: Image x 2 \n");
		}
		else if ((char)c == 'd')
		{
			pyrDown(temp, apple_sampled, Size(temp.cols / 2, temp.rows / 2));
			printf("** Zoom Out: Image / 2 \n");
		}

		imshow(window_name, apple_sampled);
		temp = apple_sampled;
	}
	return 0;
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
