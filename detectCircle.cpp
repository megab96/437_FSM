#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Circle.h"
#include "Line.h"

using namespace cv;
using namespace std;

/** @function main */
int main(int argc, char** argv)
{
	/*Circle circle("0");
	circle.drawCircle();
	Line ligne(true, "0");
	ligne.drawLine();*/


	Mat src, src_gray;

	/// Read the image
	src = cv::imread("plot-formula.jpg");

	if (!src.data)
	{
		return -1;
	}

	Mat dst, cdst;
	Canny(src, dst, 50, 200, 3);
	cvtColor(dst, cdst, CV_GRAY2BGR);

	vector<Vec4i> lines;
	HoughLinesP(dst, lines, 1, CV_PI / 180, 50, 50, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);

		Point lineP(cvRound(l[0]), cvRound(l[1]));
		Point linePE(cvRound(l[2]), cvRound(l[3]));
		circle(cdst, lineP, 3, Scalar(0, 255, 0), -1, 8, 0);
		//circle(cdst, linePE, 3, Scalar(0, 255, 0), -1, 8, 0);
	}

	/// Convert it to gray
	cvtColor(src, src_gray, CV_BGR2GRAY);

	/// Reduce the noise so we avoid false circle detection
	GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);

	vector<Vec3f> circles;

	/// Apply the Hough Transform to find the circles
	HoughCircles(src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows / 8, 200, 100, 0, 0);

	/// Draw the circles detected
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		circle(cdst, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// circle outline
		circle(cdst, center, radius, Scalar(0, 0, 255), 3, 8, 0);
		Point extremite(cvRound(circles[i][0] + radius), cvRound(circles[i][1]));
		circle(cdst, extremite, 3, Scalar(0, 255, 0), -1, 8, 0);
		cvRound(extremite.x);
	}
	bool connected = false;
	for (size_t i = 0; i < circles.size(); i++)
	{
		for (size_t j = 0; j < lines.size(); j++)
		{
			Vec4i l = lines[j];
			Point linePE(cvRound(l[2]), cvRound(l[3]));
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			double distance = sqrt(pow(linePE.x - center.x,2) + pow(linePE.y - center.y,2));
			if (radius == (int)distance) {
				connected = true;
			}

		}
	}

	if (connected) {
		Point center(cvRound(circles[0][0]), cvRound(circles[0][1]));
		circle(cdst, center, 3, Scalar(0, 255, 255), -1, 8, 0);
	}


	/// Show your results
	imshow("detected lines", cdst);

	waitKey(0);
	return 0;
}