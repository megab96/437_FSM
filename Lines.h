#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace cv;
using namespace std;

class Lines
{
public:
	Lines();
	int getLimit();
	vector<Vec4i> getLines();
	void setLines(vector<Vec4i> l);
	~Lines();

private:
	vector<Vec4i> lines;
};

