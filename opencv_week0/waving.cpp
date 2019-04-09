
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

void wave(cv::Mat &image, cv::Mat &result);

int main(int argc, char** argv)
{
	if ((argc != 3 && argc != 4) || argv[2] != "wave") {
		std::cout << "Invalid command arguments.\nUsage: \nargv[3]: ./file_to_run image_to_remap wave -- makes the image look wavy \nargv[4]: ./file_to_run image_to_remap wave -s -- makes the image look wavy and saves the new version" << std::endl;
		return -1;
	}

	if (argc == 3 && argv[2] == "wave") {

		std::string image_name = argv[1];
		cv::Mat image = cv::imread("sarajevo_clear.jpg");
		cv::Mat result = cv::Mat::zeros(image.rows, image.cols, image.type());

		if (!image.data) {
			std::cout << "Could not find or open the image.\nUsage:" << std::endl;
		}

		wave(image, result);

		cv::namedWindow("Wavy image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Wavy image", result);

		cv::waitKey();

		return 0;

	}else if(argc == 4 && argv[2] == "wave" && argv[3] == "-s") {

		std::string image_name = argv[1];
		cv::Mat image = cv::imread("sarajevo_clear.jpg");
		cv::Mat result = cv::Mat::zeros(image.rows, image.cols, image.type());

		if (!image.data) {
			std::cout << "Could not find or open the image.\nUsage:" << std::endl;
		}

		wave(image, result);
		cv::imwrite("wavy_image.jpg", result);

		cv::namedWindow("Wavy image", cv::WINDOW_AUTOSIZE);
		cv::imshow("Wavy image", result);

		cv::waitKey();

		return 0;
	}

	return 0;
}

void wave(cv::Mat &image, cv::Mat &result) {

	// the map functions
	cv::Mat srcX(image.rows, image.cols, CV_32F);
	cv::Mat srcY(image.rows, image.cols, CV_32F);

	// creating the mapping
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {

			//new location of pixel at (i, j)
			srcX.at<float>(i, j) = j;
			// remain on same column;
			//pixels originally on row i are now
			//moved following sinusoid
			srcY.at<float>(i, j) = i + 5 * sin(j / 10.0);
		}
	}

	//applying the mapping
	cv::remap(image, result, srcX, srcY, cv::INTER_LINEAR);
}