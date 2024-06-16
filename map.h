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

	struct Color {
		int R, G, B;
		Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
	};

	int numberOfPoints;
	vector<vector<double>> values;
	vector<vector<Color>> pixelColors;

	double xmin;
	double xmax;
	double ymin;
	double ymax;
	double zmin;
	double zmax;

	Color evaluateColor(double value);

public:

	void getRanges(double xmi, double xma, double ymi, double yma, double zmi, double zma);

	void repaint(wxPanel* drawingPanel, int w, int h);
	void prepareData(const vector<vector<double>>& funValues, int width, int height, string function);
};

#endif