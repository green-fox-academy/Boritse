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

		//Blur the image with 3x3 kernel
		Mat image_blurred_with_3x3_kernel;
		blur(image, image_blurred_with_3x3_kernel, Size(3, 3));

		//Blur the image with 5x5 kernel
		Mat image_blurred_with_5x5_kernel;
		blur(image, image_blurred_with_5x5_kernel, Size(9, 9));

		//Define names of the windows
		String window_name = "Bebino";
		String window_name_blurred_with_3x3_kernel = "Bebino Blurred with 3 x 3 Kernel";
		String window_name_blurred_with_5x5_kernel = "Bebino Blurred with 5 x 5 Kernel";

		// Create windows with above names
		namedWindow(window_name, WINDOW_KEEPRATIO);
		namedWindow(window_name_blurred_with_3x3_kernel, WINDOW_KEEPRATIO);
		namedWindow(window_name_blurred_with_5x5_kernel, WINDOW_KEEPRATIO);

		// Show our images inside the created windows.
		imshow(window_name, image);
		imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
		imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

		resizeWindow(window_name, image.cols / 4, image.rows / 4);
		resizeWindow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel.cols / 4, image_blurred_with_3x3_kernel.rows / 4);
		resizeWindow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel.cols / 4, image_blurred_with_5x5_kernel.rows / 4);

		waitKey(0); // Wait for any keystroke in the window

		destroyAllWindows(); //destroy all opened windows

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
