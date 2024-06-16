#include "GUIMyFrame1.h"



GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	panelWidth = panelNaWykres->GetSize().GetWidth();
	panelHeight = panelNaWykres->GetSize().GetHeight();

	mouseX = panelWidth / 2;
	mouseY = panelHeight / 2;
}

void GUIMyFrame1::showInfo(wxMouseEvent& event)
{
	wxMessageDialog* infoDialog = new wxMessageDialog(this, "-> use only x and y variables\n-> use \"sqrt()\" as aquare root\n->use \"^n\" to raise to the n-th power\n-> use \".\" to create floating-point numbers\n-> you can use constants \"pi\" and \"e\"\n-> sin(), cos() and tan() are available to be used too",
		"How to plot?", wxOK | wxICON_INFORMATION);
	infoDialog->ShowModal();
	infoDialog->Destroy();
}

bool GUIMyFrame1::checkFunction()
{
	double x, y;
	te_variable vars[] = { {"x", &x}, {"y", &y} };

	const char* c = function.c_str();

	int err;
	te_expr* expr = te_compile(c, vars, 2, &err);

	if (!expr) {
		textCtrlFunkcja->SetValue("");
		return false;
	}

	if (!checkNumbers()) {
		return false;
	}

	int sample = 50;

	double move = std::max(((xMax - xMin) / sample), (yMax - yMin) / sample);
	double movex = std::min((xMax - xMin), move);
	double movey = std::min((yMax - yMin), move);

	zValuesVec.clear();

	vector < double > tempVec;

	for (double xi = xMin; xi <= (xMax); xi += movex) {

		for (double yi = yMin; yi <= (yMax); yi += movey) {

			x = xi;
			y = yi;

			tempVec.push_back(te_eval(expr));
		}

		zValuesVec.push_back(tempVec);
		tempVec.clear();
	}

	return true;
}

bool GUIMyFrame1::checkNumbers()
{
	try {
		xMin = stod(textCtrlXMin->GetValue().ToStdString());
		textCtrlXMin->SetValue(to_string(xMin));
	}
	catch (const std::invalid_argument&) {
		textCtrlXMin->SetValue("");
		return false;
	}
	catch (const std::out_of_range&) {
		textCtrlXMin->SetValue("");
		return false;
	}

	try {
		xMax = stod(textCtrlXMax->GetValue().ToStdString());
		textCtrlXMax->SetValue(to_string(xMax));
	}
	catch (const std::invalid_argument&) {
		textCtrlXMax->SetValue("");
		return false;
	}
	catch (const std::out_of_range&) {
		textCtrlXMax->SetValue("");
		return false;
	}

	try {
		yMin = stod(textCtrlYMin->GetValue().ToStdString());
		textCtrlYMin->SetValue(to_string(yMin));
	}
	catch (const std::invalid_argument&) {
		textCtrlYMin->SetValue("");
		return false;
	}
	catch (const std::out_of_range&) {
		textCtrlYMin->SetValue("");
		return false;
	}

	try {
		yMax = stod(textCtrlYMax->GetValue().ToStdString());
		textCtrlYMax->SetValue(to_string(yMax));
	}
	catch (const std::invalid_argument&) {
		textCtrlYMax->SetValue("");
		return false;
	}
	catch (const std::out_of_range&) {
		textCtrlYMax->SetValue("");
		return false;
	}

	try {
		zMin = stod(textCtrlZMin->GetValue().ToStdString());
		textCtrlZMin->SetValue(to_string(zMin));
	}
	catch (const std::invalid_argument&) {
		textCtrlZMin->SetValue("");
		return false;
	}
	catch (const std::out_of_range&) {
		textCtrlZMin->SetValue("");
		return false;
	}

	try {
		zMax = stod(textCtrlZMax->GetValue().ToStdString());
		textCtrlZMax->SetValue(to_string(zMax));
	}
	catch (const std::invalid_argument&) {
		textCtrlZMax->SetValue("");
		return false;
	}
	catch (const std::out_of_range&) {
		textCtrlZMax->SetValue("");
		return false;
	}

	if (xMax <= xMin) {
		textCtrlXMax->SetValue("");
		textCtrlXMin->SetValue("");
		return false;
	}
	if (yMax <= yMin) {
		textCtrlYMax->SetValue("");
		textCtrlYMin->SetValue("");
		return false;
	}
	if (zMax <= zMin) {
		textCtrlZMax->SetValue("");
		textCtrlZMin->SetValue("");
		return false;
	}

	return true;
}

void GUIMyFrame1::perspectiveClick(wxMouseEvent& event)
{
	inPerspective = true;
	inMap = false;

	mouseRotateX = 0;
	mouseRotateY = 0;


	if (radioRzut->GetValue()) {
		radioMapa->SetValue(false);

		//generujemy wykres!
		if (generateClicked) repaint();
	}
	else {
		radioRzut->SetValue(true);
	}
}

void GUIMyFrame1::outlineClick(wxMouseEvent& event)
{
	inPerspective = false;
	inMap = true;

	mouseRotateX = 0;
	mouseRotateY = 0;

	if (radioMapa->GetValue()) {
		radioRzut->SetValue(false);

		//generujemy wykres!
		if (generateClicked) repaint();
	}
	else {
		radioMapa->SetValue(true);
	}
}

void GUIMyFrame1::printClick(wxMouseEvent& event)
{
	wxClientDC dc(panelNaWykres);
	wxSize size = panelNaWykres->GetSize();
	wxBitmap bitmap(size);
	wxMemoryDC memDC;
	memDC.SelectObject(bitmap);
	memDC.Blit(0, 0, size.GetWidth(), size.GetHeight(), &dc, 0, 0);
	memDC.SelectObject(wxNullBitmap);
	wxImage printPicture = bitmap.ConvertToImage();
	printPicture.AddHandler(new wxJPEGHandler);
	printPicture.AddHandler(new wxPNGHandler);

	wxPrinter printer;
	ImagePrintout printout("Image Printout", printPicture);

	if (!printer.Print(this, &printout, true)) {
		if (wxPrinter::GetLastError() == wxPRINTER_ERROR) {
			wxMessageBox("There was a problem with printing.", "Error", wxOK);
		}
		else {
			wxMessageBox("The printing was cancelled.", "Info", wxOK);
		}
	}
}

void GUIMyFrame1::saveClick(wxMouseEvent& event)
{
	wxFileDialog saveFileDialog(this, "Choose a file", "", "", "PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

	wxClientDC dc(panelNaWykres);
	wxSize size = panelNaWykres->GetSize();
	wxBitmap bitmap(size);
	wxMemoryDC memDC;
	memDC.SelectObject(bitmap);
	memDC.Blit(0, 0, size.GetWidth(), size.GetHeight(), &dc, 0, 0);
	memDC.SelectObject(wxNullBitmap);
	wxImage savePicture = bitmap.ConvertToImage();
	savePicture.AddHandler(new wxJPEGHandler);
	savePicture.AddHandler(new wxPNGHandler);
	savePicture.SaveFile(saveFileDialog.GetPath());
}

void GUIMyFrame1::generateClick(wxMouseEvent& event)
{
	function = textCtrlFunkcja->GetValue();

	mouseRotateX = 0;
	mouseRotateY = 0;

	if (!checkFunction()) return;

	repaint();
	generateClicked = true;
}

void GUIMyFrame1::panelRepaint(wxSizeEvent& event)
{
	if ((panelWidth != panelNaWykres->GetSize().GetWidth() || panelHeight != panelNaWykres->GetSize().GetHeight()) && generateClicked) {
		panelWidth = panelNaWykres->GetSize().GetWidth();
		panelHeight = panelNaWykres->GetSize().GetHeight();
		repaint();

		return;
	}

	panelWidth = panelNaWykres->GetSize().GetWidth();
	panelHeight = panelNaWykres->GetSize().GetHeight();
}

void GUIMyFrame1::repaint()
{
	//gerneruj wykres
	if (isPerspective()) {
		//generuj rzut perspektywiczny
		objPer.getAxis(xMin, xMax, yMin, yMax, zMin, zMax);
		objPer.RecountFunctionIntoData(zValuesVec);
		objPer.Repaint(panelNaWykres, panelWidth, panelHeight, mouseRotateX, mouseRotateY);
	}
	else {
		//generuj mape konturowa
		objMap.getRanges(xMin, xMax, yMin, yMax, zMin, zMax);
		objMap.prepareData(zValuesVec, panelWidth, panelHeight, function);
		objMap.repaint(panelNaWykres, panelWidth, panelHeight);

	}
}

void GUIMyFrame1::onMouseEnter(wxMouseEvent& event)
{
	movingAllowed = true;
}

void GUIMyFrame1::onMouseMove(wxMouseEvent& event)
{
	if (!movingAllowed || isMap() || !leftPressed) return;

	if (mouseX == -10000 && mouseY == -10000) {

		mouseX = event.GetPosition().x;
		mouseY = event.GetPosition().y;
		return;
	}

	int newMouseX = event.GetPosition().x;
	int newMouseY = event.GetPosition().y;

	double rotateX = (double)(newMouseX - mouseX) / (double)panelWidth * 180;
	double rotateY = (double)(newMouseY - mouseY) / (double)panelHeight * 180;

	//tutaj przekazujemy do perspectivic i rysujemy
	if (abs(rotateX - lastRotateX) > M_PI / 100 || abs(rotateY - lastRotateY) > M_PI / 100) {
		lastRotateX = rotateX;
		lastRotateY = rotateY;

		objPer.Repaint(panelNaWykres, panelWidth, panelHeight, mouseRotateX + rotateX, mouseRotateY + rotateY);
	}
}

void GUIMyFrame1::onMouseLeave(wxMouseEvent& event)
{
	movingAllowed = false;

	int newMouseX = event.GetPosition().x;
	int newMouseY = event.GetPosition().y;
	double rotateX = (double)(newMouseX - mouseX) / (double)panelWidth * 180;
	double rotateY = (double)(newMouseY - mouseY) / (double)panelHeight * 180;

	leftPressed = false;

	mouseX = -10000;
	mouseY = -10000;

	lastRotateX = 0;
	lastRotateY = 0;

	mouseRotateX += rotateX;
	mouseRotateY += rotateY;

	mouseRotateX -= (double)((int)mouseRotateX / 360) * 360;
	mouseRotateY -= (double)((int)mouseRotateY / 360) * 360;
}

void GUIMyFrame1::onLeftMouseDown(wxMouseEvent& event)
{
	leftPressed = true;
}

void GUIMyFrame1::onLeftMouseUp(wxMouseEvent& event)
{
	leftPressed = false;

	int newMouseX = event.GetPosition().x;
	int newMouseY = event.GetPosition().y;
	double rotateX = (double)(newMouseX - mouseX) / (double)panelWidth * 180;
	double rotateY = (double)(newMouseY - mouseY) / (double)panelHeight * 180;

	mouseX = -10000;
	mouseY = -10000;

	lastRotateX = 0;
	lastRotateY = 0;

	mouseRotateX += rotateX;
	mouseRotateY += rotateY;

	mouseRotateX -= (double)((int)mouseRotateX / 360) * 360;
	mouseRotateY -= (double)((int)mouseRotateY / 360) * 360;
}

void GUIMyFrame1::onMouseScroll(wxMouseEvent& event)
{
	if ( isMap() || !movingAllowed ) return;

	int rotation = event.GetWheelRotation();
	int delta = event.GetWheelDelta();
	int linesPerAction = event.GetLinesPerAction();
	int scrollAmount = rotation / delta;

	//zoom rzutu perspektywicznego

}
