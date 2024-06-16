#ifndef __MAP__
#define __MAP__

#include "GUI.h"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <array>

#include "tinyexpr.h"

	using namespace std;

class Map {
private:
	int numberOfPoints;
	vector<vector<double>> values;
	vector<vector<double>> functionPoints;

	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double zmin;
	double zmax;

public:
	void getRanges(double xmi, double xma, double ymi, double yma, double zmi, double zma);

	double shepard(double x, double y);
	void repaint(wxPanel* drawingPanel, int w, int h);
	void prepareData(const vector<vector<double>>& funValues, int width, int height, string function);
};

#endif