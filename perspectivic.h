#ifndef __PERS__
#define __PERS__

#include "GUI.h"
#include "vecmat.h"

#include <iostream>
#include <vector>

using namespace std;

class Perspectivic {
private:
	struct Point {
		float x, y, z;
		Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	};

	struct Color {
		int R, G, B;
		Color(int _R, int _G, int _B) : R(_R), G(_G), B(_B) {}
	};

	struct Segment {
		Point begin, end;
		Color color;
		Segment(Point _begin, Point _end, Color _color) : begin(_begin), end(_end), color(_color) {}
	};

	struct AxisNumbers {
		vector<Perspectivic::Segment> nextSegmentsToDrawCircle;
		double numberOnAxis;

		AxisNumbers(vector<Perspectivic::Segment> inside, double number) : nextSegmentsToDrawCircle(inside), numberOnAxis(number) {}
	};

	vector<Perspectivic::Segment> data;

	vector<Perspectivic::AxisNumbers> dataOnAxis;

	Matrix4 t;
	Matrix4 t1;

	double scale;

	double maxY = -1.0e30;
	double minY = 1.0e30;

	double xmax = 1;
	double xmin = -1;
	double ymax = 1;
	double ymin = -1;
	double zmax = 1;
	double zmin = -1;
	//double moveXDirectionInDegrees;
	//double moveXDirectionInDegrees;
	//static double moveXOld;
	//static double moveYOld;


public:

	void getAxis(double xmi, double xma, double ymi, double yma, double zmi, double zma) {
		xmin = xmi; xmax = xma; ymin = ymi; ymax = yma; zmin = zmi; zmax = zma;
	}

	double countFunction(double x, double y);
	void RecountFunctionIntoData(const vector<vector<double>>& funValues);

	Matrix4 XRotation(double alpha);
	Matrix4 YRotation(double alpha);
	Matrix4 ZRotation(double alpha);

	void GenerateTransformMatrix(int width, int height, double rotateX, double rotateY);

	void getMinYMaxY();

	void Repaint(wxPanel* drawingPanel, int w, int h, double rotatX, double rotatY);

};

#endif