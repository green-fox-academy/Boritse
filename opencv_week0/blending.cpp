// drawing_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	Mat first_image = imread("bebino_bending.jpg");
	Mat second_image = imread("bebino_sitting.jpg");
	Mat blended_image;

	if (!first_image.data || !second_image.data)
	{
		printf("No image data \n");
		return -1;
	}

	resize(second_image, second_image, first_image.size());
	addWeighted(first_image, 0.5, second_image, 1, 0.0, blended_image);

	namedWindow("Blended Bebino", WINDOW_KEEPRATIO); // Create a window
	imshow("Blended Bebino", blended_image);
	
	waitKey(0);

	destroyWindow("Blended Bebino"); 

	imwrite("blended_bebino.jpg", blended_image);

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
