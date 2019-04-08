// drawing_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// Read the image file
	Mat image = imread("bebino_sitting.jpg");
	Mat black_and_white_image;
	
	cvtColor(image, black_and_white_image, COLOR_RGB2GRAY);

	// Check for failure
	if (image.empty() || black_and_white_image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	namedWindow("Original", WINDOW_NORMAL);
	namedWindow("Black and White", WINDOW_NORMAL);

	imshow("Original", image);
	imshow("Black and White", image);

	resizeWindow("Original", image.cols / 4, image.rows / 4);
	resizeWindow("Black and White", black_and_white_image.cols / 4, black_and_white_image.rows / 4);

	waitKey(0); // Wait for any key stroke

	destroyAllWindows();

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
