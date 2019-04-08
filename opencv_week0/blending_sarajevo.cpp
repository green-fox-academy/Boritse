// drawing_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

float alpha = 1.0;

Mat first_image = imread("sarajevo_clear.jpg");
Mat second_image = imread("sarajevo_snow.jpg");
Mat blended_image;

void blending();
void wait_key();

int main(int argc, char** argv)
{
	blending();

	wait_key();

	return 0;
}

void blending() 
{	
	float beta = 1.0 - alpha;
	addWeighted(first_image, alpha, second_image, beta, 0.0, blended_image);

	namedWindow("Sarajevo", WINDOW_KEEPRATIO); // Create a window
	imshow("Sarajevo", blended_image);

}

void wait_key() 
{
	while (true)
	{
		int c;
		c = waitKey(0);

		if ((char)c == 27)
		{
			break;
		}
		else if ((char)c == 97 && alpha != 1.0)
		{
			alpha += 0.2;
		}
		else if ((char)c == 98 && alpha != 0)
		{
			alpha -= 0.2;
		}

		blending();
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
