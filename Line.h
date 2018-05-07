#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include "Lines.h"
#include "Circles.h"


using namespace cv;
using namespace std;

class Line
{
public:
	Line(bool isEnabled, string name);
	bool getIsEnabled();
	bool isConnected();
	int drawLine();
	~Line();

private:
	bool isEnabled;
	bool connected = false;
	string name;
	Lines lignes;
	Circles ca;
};

