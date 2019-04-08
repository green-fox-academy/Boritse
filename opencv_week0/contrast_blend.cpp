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
	
	// Check for failure
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	Mat imageHighContrast = Mat::zeros(image.size(), image.type());
	image.convertTo(imageHighContrast, -1, 4, 0); //increase the contrast by 4

	Mat imageLowContrast = Mat::zeros(image.size(), image.type());
	image.convertTo(imageLowContrast, -1, 0.25, 0); //decrease the contrast by 0.25

	Mat blend_back = Mat::zeros(image.size(), image.type());
	addWeighted(imageLowContrast, 0.5, imageHighContrast, 0.5, 0.0, blend_back);

	namedWindow("Original", WINDOW_NORMAL);
	namedWindow("HighContrast", WINDOW_NORMAL);
	namedWindow("LowContrast", WINDOW_NORMAL);
	namedWindow("Blended", WINDOW_NORMAL);

	//Show above images inside the created windows.
	imshow("Original", image);
	imshow("HighContrast", imageHighContrast);
	imshow("LowContrast", imageLowContrast);
	imshow("Blended", blend_back);

	resizeWindow("Original", image.cols / 4, image.rows / 4);
	resizeWindow("HighContrast", image.cols / 4, image.rows / 4);
	resizeWindow("LowContrast", image.cols / 4, image.rows / 4);
	resizeWindow("Blended", image.cols / 4, image.rows / 4);

	waitKey(0); // Wait for any key stroke

	destroyWindow("Original"); //destroy all open windows
	
	waitKey(0);

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
