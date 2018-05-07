#include "Line.h"



Line::Line(bool enabile, string trans)
{
	isEnabled = enabile;
	name = trans;
}


bool Line::getIsEnabled()
{
	return isEnabled;
}

bool Line::isConnected()
{
	for (size_t i = 0; i < ca.getCircles().size(); i++)
	{
		for (size_t j = 0; j < lignes.getLines().size(); j++)
		{
			Vec4i l = lignes.getLines()[j];
			Point linePE(cvRound(l[2]), cvRound(l[3]));
			Point center(cvRound(ca.getCircles()[i][0]), cvRound(ca.getCircles()[i][1]));
			int radius = cvRound(ca.getCircles()[i][2]);
			double distance = sqrt(pow(linePE.x - center.x, 2) + pow(linePE.y - center.y, 2));
			if (radius >= (int)distance) {
				connected = true;
			}

		}
	}
	return false;
}

int Line::drawLine()
{
	int x = stoi(name);

	if (x > lignes.getLimit()) {
		cout << "Cannot do that" << endl;
		//return -1;
	}

	Mat src;

	/// Read the image
	src = cv::imread("plot-formula.jpg");

	if (!src.data)
	{
		return -1;
	}
	vector<Vec4i> lines;

	lignes.setLines(lines);

	lines = lignes.getLines();

	Mat dst, cdst;
	Canny(src, dst, 50, 200, 3);
	cvtColor(dst, cdst, CV_GRAY2BGR);

	Vec4i l = lines[x];
	line(cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);

	imshow("detected lines", src);
	waitKey(0);
}

Line::~Line()
{
}
