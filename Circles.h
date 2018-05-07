#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace cv;
using namespace std;

class Circles
{
public:
	Circles();
	vector<Vec3f> getCircles();
	void setCircles();
	int getLimit();
	~Circles();

private:
	vector<Vec3f> circles;
};

