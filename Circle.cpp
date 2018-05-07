#include "Circle.h"

Circle::Circle(string stateName)
{
	name = stateName;
}

string Circle::getName()
{
	return name;
}

int Circle::drawCircle()
{
	int x = stoi(name);

	if (x > cercle.getLimit()) {
		cout << "Cannot do that" << endl;
		return -1;
	}

	Mat src, src_gray;

	/// Read the image
	src = cv::imread("images.png");

	if (!src.data)
	{
		return -1;
	}

	cercle.setCircles();

	Point center(cvRound(cercle.getCircles()[x][0]), cvRound(cercle.getCircles()[x][1]));
	int radius = cvRound(cercle.getCircles()[x][2]);
	// circle center
	circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
	// circle outline
	circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);

	/**for (size_t i = 0; i < cercles.size(); i++)
	{
		Point center(cvRound(cercles[i][0]), cvRound(cercles[i][1]));
		int radius = cvRound(cercles[i][2]);
		// circle center
		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// circle outline
		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}*/

	imshow("detected lines", src);
	waitKey(0);

	/**Mat src, src_gray;

	/// Read the image
	src = cv::imread("plot-formula.jpg");

	if (!src.data)
	{
		return -1;
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
		circle(src, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// circle outline
		circle(src, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	}

	imshow("detected lines", src);
	waitKey(0);
	return 1;*/
}


Circle::~Circle()
{
}
