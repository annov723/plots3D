#include "map.h"
#include < time.h>

void Map::getRanges(double xmi, double xma, double ymi, double yma, double zmi, double zma)
{
	xmin = xmi;
	xmax = xma;
	ymin = ymi;
	ymax = yma;
	zmin = zmi;
	zmax = zma;
}

void Map::repaint(wxPanel * drawingPanel, int w, int h)
{
	wxClientDC DC(drawingPanel);
	wxBufferedDC BufferedDC(&DC);
	int width = w;
	int height = h;
	BufferedDC.SetBackground(wxBrush(wxColour("white")));
	BufferedDC.Clear();

	for (int x = 0; x < w; x += 2) {

		for (int y = 0; y < h; y += 2) {

			BufferedDC.SetPen(wxPen(wxColour(pixelColors[x][y].R, pixelColors[x][y].G, pixelColors[x][y].B)));
			BufferedDC.DrawRectangle(x, y, 2, 2);
		}
	}

	BufferedDC.SetPen(*wxBLACK_PEN);
	BufferedDC.SetBrush(*wxTRANSPARENT_BRUSH);

	std::vector<std::array<wxPoint, 2>> contours;
	for (int i = 1; i <= 9; i++) {
		double threshold = zmin + i * (zmax - zmin) / (double)(9 + 1);
		for (int x = 1; x < width - 1; x++) {
			for (int y = 1; y < height - 1; y++) {
				int code = (values[x - 1][y + 1] > threshold ? 1 : 0) +
					(values[x + 1][y + 1] > threshold ? 1 : 0) * 2 +
					(values[x + 1][y - 1] > threshold ? 1 : 0) * 4 +
					(values[x - 1][y - 1] > threshold ? 1 : 0) * 8;

				if (values[x][y] < threshold) {
					if (code == 5) code = 10;
					if (code == 10) code = 5;
				}

				switch (code) {
				case 1:
				case 14:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y + 1) });
					break;
				case 2:
				case 13:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x + 1, y), wxPoint(x, y + 1) });
					break;
				case 3:
				case 12:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x + 1, y) });
					break;
				case 4:
				case 11:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x, y - 1), wxPoint(x + 1, y) });
					break;
				case 5:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x + 1, y), wxPoint(x, y + 1) });
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y - 1) });
					break;
				case 10:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y + 1) });
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x + 1, y), wxPoint(x, y - 1) });
					break;
				case 6:
				case 9:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x, y - 1), wxPoint(x, y + 1) });
					break;
				case 7:
				case 8:
					contours.push_back(std::array<wxPoint, 2> { wxPoint(x - 1, y), wxPoint(x, y - 1) });
					break;
				}
			}
		}
		for (auto& item : contours)
			BufferedDC.DrawLine(item[0], item[1]);
	}
}

Map::Color Map::evaluateColor(double value) {

	if (value > zmax || value < zmin) {

		return Color(255, 255, 255);
	}
	value = max(min(value, zmax), zmin);

	value -= zmin;

	value /= (zmax-zmin);

	return Color(255 * value, 0, 255 * (1. - value));
}

void Map::prepareData(const vector<vector<double>>&funValues, int width, int height, string function)
{
	double x, y;
	te_variable vars[] = { {"x", &x}, {"y", &y} };

	const char* c = function.c_str();

	int err;
	te_expr* expr = te_compile(c, vars, 2, &err);

	int sample = 50;

	double movex = (double)(xmax - xmin) / width;
	double movey = (double)(ymax - ymin) / height;

	values.clear();
	pixelColors.clear();

	vector < double > tempVec;
	vector <Color> tempVecColor;

	for (double xi = xmin; xi <= (xmax); xi += movex) {

		for (double yi = ymin; yi <= (ymax); yi += movey) {

			x = xi;
			y = yi;

			tempVec.push_back(te_eval(expr));
			tempVecColor.push_back(evaluateColor(tempVec.back()));
		}

		values.push_back(tempVec);
		tempVec.clear();
		pixelColors.push_back(tempVecColor);
		tempVecColor.clear();
	}

}