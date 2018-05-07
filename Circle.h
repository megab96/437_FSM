#pragma once
#ifndef CIRCLES_H
#define CIRCLES_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include "Circles.h"


using namespace cv;
using namespace std;

class Circle
{
public:
	Circle(string name);
	string getName();
	int drawCircle();
	~Circle();
private:
	string name;
	Circles cercle;
};

#endif // !CIRCLES_H

