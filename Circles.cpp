#include "Circles.h"



Circles::Circles()
{
}

vector<Vec3f> Circles::getCircles()
{
	return circles;
}


void Circles::setCircles()
{
	Mat src, src_gray;

	/// Read the image
	src = cv::imread("images.png");

	if (!src.data)
	{
		exit(0);
	}

	/// Convert it to gray
	cvtColor(src, src_gray, CV_BGR2GRAY);

	/// Reduce the noise so we avoid false circle detection
	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);

	/// Apply the Hough Transform to find the circles
	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows / 8, 200, 100, 0, 0);
}

int Circles::getLimit()
{
	return circles.size();
}


Circles::~Circles()
{
}
