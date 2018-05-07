#include "Lines.h"



Lines::Lines()
{
}

int Lines::getLimit()
{
	return lines.size();
}

vector<Vec4i> Lines::getLines()
{
	return lines;
}

void Lines::setLines(vector<Vec4i> l)
{
	Mat src;
	src = cv::imread("plot-formula.jpg");

	Mat dst, cdst;
	Canny(src, dst, 50, 200, 3);
	cvtColor(dst, cdst, CV_GRAY2BGR);

	HoughLinesP(dst, l, 1, CV_PI / 180, 50, 50, 10);

	lines = l;

}


Lines::~Lines()
{
}
