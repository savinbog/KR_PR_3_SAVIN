#include "MyForm.h"
#include "SPAVKA.h"
#include<vector>
#include<fstream>
#include <numeric>
#include<string>
#include<algorithm>
#include<cmath>

// ������������ ���� ����������� ��� ����������

using namespace System;
using namespace System::Windows::Forms;



// ������� ��� �������� �������� X � Y
std::vector<double> xValues;
std::vector<double> yValues;

// ������� ��� �������� �������� �������

 std::vector<double> FValues;

// ������� ��� �������� �� �����
std::vector<std::string> x_y;

// ������ ��� ������ ��������� �������
std::vector< int> for_delite;

// ����� ��� ���������� ���������� �������������� �������������

class koo_sted_der
{
protected:
	// ���������� ��� ������������
	double x_2 = 0;
	double x_1 = 0;
	double y_2 = 0;
	double x_y = 0;
	double y_1 = 0;
	double y_s = 0;
	double Y_minus_F = 0;
	double Y_minus_sY = 0;
	double x_4 = 0;
	double x_3 = 0;
	double x_2_y = 0;
	double ln_x_2 = 0;
	double ln_x_1 = 0;
	double ln_y_x = 0;
	double ln_y = 0;
	double x_ln_y = 0;
	double x_2_st_min_1 = 0;
	double y_x_1_st_min_1 = 0;
	double x_1_st_min_1 = 0;
	double y_1_ln_x = 0;
public:
	double koof_line();
	double sred();
	double kooff();
	double der(double const koof);

};

// ����� ��� �������� ����������

double koo_sted_der::koof_line() {
	double koof_line = 0;
	x_2 = 0;
	 x_1 = 0;
	y_2 = 0;
	 x_y = 0;
	y_1 = 0;
	for (size_t i = 0; i < xValues.size(); i++) {
		x_2 += pow(xValues[i], 2);
		x_1 += xValues[i];
		x_y += xValues[i] * yValues[i];
		y_2 += pow(yValues[i], 2);
		y_1 += yValues[i];
	}
	koof_line = (xValues.size() * x_y - x_1 * y_1) / (sqrt((xValues.size() * x_2 - x_1 * x_1) * xValues.size() * y_2 - y_1 * y_1));
	return koof_line;
}

// ����� ��� ��������� ��������

double koo_sted_der::sred() {
	double sred = 0;
	double raznost = 0;
	int j = 0;
	for (int i = FValues.size() - xValues.size(); i < FValues.size(); i++)
	{
		if (yValues[j] != 0)
			raznost += abs((yValues[j] - FValues[j + FValues.size() - xValues.size()]) / yValues[j]);
		j++;
	}
		
	sred = raznost / xValues.size();
	return sred;
}
double koo_sted_der::kooff() {
	double kooff = 0;
	 y_s = 0;
	 Y_minus_F = 0;
	 Y_minus_sY = 0;
	 y_1 = 0;
	for (size_t i = 0; i < xValues.size(); i++) {
		Y_minus_F += pow(yValues[i] - FValues[i], 2);
		y_1 += yValues[i];
	}
	y_s = y_1 / xValues.size();
	for (size_t i = 0; i < xValues.size(); i++)
	{
		Y_minus_sY += pow(yValues[i] - y_s, 2);
	}
	kooff = sqrt(abs(1 - Y_minus_F / Y_minus_sY));
	return kooff;
}

// ����� ��� ����������� �����������

double koo_sted_der::der(double const koof) {
	return koof*koof;
}

class Metod: public koo_sted_der
{
public:

// ������ ��� �������� �������� ������������ ������� 
	double koof[15];

//������ ��� ���������� ������������ ���������������� �������
	void linearRegression();
	void Min_kv();
	void stepen_reg();
	void exp_reg();
	void pokazat_reg();
	void giperbol_reg();
	void log_reg();

};


// ������� ��� ���������� ������������ �������� ���������
void Metod::linearRegression() {
	// ������ ������� �������� X � Y
	double xMean = std::accumulate(xValues.begin(), xValues.end(), 0.0) / xValues.size();
	double yMean = std::accumulate(yValues.begin(), yValues.end(), 0.0) / yValues.size();
	// ������ �������������
	double numerator = 0.0;
	double denominator = 0.0;
	for (int i = 0; i < xValues.size(); ++i) {
		numerator += (xValues[i] - xMean) * (yValues[i] - yMean);
		denominator += (xValues[i] - xMean) * (xValues[i] - xMean);
	}

	// ������������ �������� ���������
	koof[0] = numerator / denominator;
	koof[1] = yMean - koof[0] * xMean;

}


// ������� ��� ���������� ������������ ������������ ���������
void Metod::Min_kv() {
	x_4 = 0;
	 x_3 = 0;
	 x_2 = 0;
	 x_1 = 0;
	 x_2_y = 0;
	x_y = 0;
	 y_1 = 0;


	for (size_t i = 0; i < xValues.size(); i++) {
		x_4 += pow(xValues[i], 4);
		x_3 += pow(xValues[i], 3);
		x_2 += pow(xValues[i], 2);
		x_1 += xValues[i];
		x_2_y += pow(xValues[i], 2) * yValues[i];
		x_y += xValues[i] * yValues[i];
		y_1 += yValues[i];
	}
	double tmp[9];
	tmp[0] = x_2_y / x_2;
	tmp[1] = x_4 / x_2;
	tmp[2] = x_3 / x_2;
	tmp[3] = x_3 - x_1 * tmp[1];
	tmp[4] = x_2 - x_1 * tmp[2];
	tmp[5] = x_y - x_1 * tmp[0];
	tmp[6] = x_2 - xValues.size() * tmp[1];
	tmp[7] = x_1 - xValues.size() * tmp[2];
	tmp[8] = y_1 - xValues.size() * tmp[0];
	// ������������ ������������  ���������
	koof[2] = (tmp[8] - tmp[7] * tmp[5] / tmp[4]) / (tmp[6] - tmp[7] * tmp[3] / tmp[4]);
	koof[3] = (tmp[5] - tmp[3] * koof[2]) / tmp[4];
	koof[4] = tmp[0] - tmp[1] * koof[2] - tmp[2] * koof[3];


}


// ������� ��� ���������� ������������ ��������� ���������
void Metod::stepen_reg() {

	 ln_x_2 = 0;
	 ln_x_1 = 0;
	 ln_y_x = 0;
	 ln_y = 0;


	for (size_t i = 0; i < xValues.size(); i++) {
		if (xValues[i] > 0) {
			ln_x_2 += pow(log(xValues[i]), 2);
			ln_x_1 += log(xValues[i]);
		}
		if (yValues[i] > 0) {

			ln_y += log(yValues[i]);
		}
		if (yValues[i] > 0 && xValues[i] > 0)
			ln_y_x += log(yValues[i]) * log(xValues[i]);


	}
	// ����������� ���������  ���������
	koof[5] = (xValues.size() * (ln_y_x)-ln_x_1 * ln_y) / (xValues.size() * ln_x_2 - pow(ln_x_1, 2));
	koof[6] = exp(ln_y / xValues.size() - koof[5] * ln_x_1 / xValues.size());
}


// ������� ��� ���������� ������������ ������������� ���������
void Metod::pokazat_reg() {

	x_2 = 0;
	 ln_y = 0;
	 x_1 = 0;
	ln_y_x = 0;


	for (size_t i = 0; i < xValues.size(); i++) {
		if (xValues[i] > 0) {

			x_1 += xValues[i];
			x_2 += xValues[i] * xValues[i];
		}
		if (yValues[i] > 0) {
			ln_y_x += xValues[i] * log(yValues[i]);
			ln_y += log(yValues[i]);
		}

	}
	// ������������ ������������� ���������
	koof[7] = exp((xValues.size() * ln_y_x - x_1 * ln_y) / (xValues.size() * x_2 - x_1 * x_1));
	koof[8] = exp(ln_y / xValues.size() - log(koof[7]) / xValues.size() * x_1);


}


// ������� ��� ���������� ������������ ��������������� ���������
void Metod::giperbol_reg() {

	 x_2_st_min_1 = 0;
	 y_x_1_st_min_1 = 0;
	 x_1_st_min_1 = 0;
	 y_1 = 0;



	for (size_t i = 0; i < xValues.size(); i++) {
		if (xValues[i] > 0) {

			x_1_st_min_1 += 1 / xValues[i];
			x_2_st_min_1 += 1 / (xValues[i] * xValues[i]);
		}
		if (xValues[i] != 0) {
			y_x_1_st_min_1 += yValues[i] / xValues[i];
			y_1 += yValues[i];

		}

	}
	// ������������  ��������������� ���������
	koof[9] = (xValues.size() * y_x_1_st_min_1 - x_1_st_min_1 * y_1) / (xValues.size() * x_2_st_min_1 - x_1_st_min_1 * x_1_st_min_1);
	koof[10] = y_1 / xValues.size() - koof[9] * x_1_st_min_1 / xValues.size();

}


// ������� ��� ���������� ������������ ��������������� ���������
void Metod::log_reg() {

	 y_1_ln_x = 0;
	 ln_x_1 = 0;
	 ln_x_2 = 0;
	 y_1 = 0;



	for (size_t i = 0; i < xValues.size(); i++) {
		if (xValues[i] > 0) {

			ln_x_1 += log(xValues[i]);
			y_1_ln_x += yValues[i] * log(xValues[i]);
			ln_x_2 += log(xValues[i]) * log(xValues[i]);
		}
		y_1 += yValues[i];
	}
	// ������������ ���������������  ���������
	koof[11] = (xValues.size() * y_1_ln_x - ln_x_1 * y_1) / (xValues.size() * ln_x_2 - ln_x_1 * ln_x_1);
	koof[12] = y_1 / xValues.size() - (koof[11] * ln_x_1) / xValues.size();
}

// ������� ��� ���������� ������������ ���������������� ���������
void Metod::exp_reg() {

	x_2 = 0;
	x_1 = 0;
	x_ln_y = 0;
	ln_y = 0;


	for (size_t i = 0; i < xValues.size(); i++) {
		if (xValues[i] > 0) {
			x_2 += pow(xValues[i], 2);
			x_1 += (xValues[i]);
		}
		if (yValues[i] > 0) {

			ln_y += log(yValues[i]);
			x_ln_y += xValues[i] * log(yValues[i]);
		}

	}
	// ������������ ����������������  ���������
	koof[13] = (xValues.size() * x_ln_y - x_1 * ln_y) / (xValues.size() * x_2 - x_1 * x_1);
	koof[14] = (ln_y - koof[13] * x_1) / xValues.size();
}

// ��������� ������ koo_sted_der
koo_sted_der k_s_d;


// ��������� ������ Metod
Metod metod;


[STAThreadAttribute]

// ������� ��� ������ ����� �����

int countDigits(int number) {
	std::string numStr = std::to_string(number);
	return numStr.length();
}

// ������� ��� ������ ���� � �������

bool findZero(const std::vector<double>& vec) {
	return std::find(vec.begin(), vec.end(), 0.0) != vec.end();
}

// ������� ��� ������ ����� � �������

bool findZnach(const std::vector<std::string>& vec, const std::string znach)
{
	return std::find(vec.begin(), vec.end(), znach) != vec.end();
}


// ������� ��� ������ �������������� ����� � �������

bool findOtr(const std::vector<double>& vec) {
	bool otr = false;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] * (-1) > 0) {
			otr = true;
			break;
		}
	}
	return otr;
}

// ������� ��� ������ ������������� ����� � �������

double findMax(const std::vector<double>& vec) {
	return *std::max_element(vec.begin(), vec.end());
}

// ������� ��� ������ ������������ ����� � �������

double findMin(const std::vector<double>& vec) {
	return *std::min_element(vec.begin(), vec.end());
}



System::Void Project67::MyForm::OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	try {
		// �������� ���������� ��������� ���� ������ �������
		double mouseX = this->chart1->ChartAreas[0]->AxisX->PixelPositionToValue(e->X);
		double mouseY = this->chart1->ChartAreas[0]->AxisY->PixelPositionToValue(e->Y);

		// ���������� ��� �������� ��������� ����� � ����������� ���������
		double closestX = 0;
		double closestY = 0;
		double FX = 0;
		double FY = 0;
		double minDistance = 0.5;

		// ����������� �� ���� ������ � ������� ��������� � ����������� ����
		for (size_t i = 0; i < xValues.size(); i++)
		{
			double distance = sqrt(pow((xValues[i] - mouseX), 2) + pow((yValues[i] - mouseY), 2));
			if (distance < minDistance)
			{
				// ��������� ��������� ����� � ����������� ���������
				minDistance = distance;
				closestX = xValues[i];
				closestY = yValues[i];

				// ���� ���� �������� �������, �� ������� �������� ������� ��������� �����
				if (FValues.size() != 0) {
					FX = xValues[i];
					FY = FValues[FValues.size() - xValues.size() + i];
				}
			}
		}

		// ������� �������� ��������� ����� �, ���� ����, �������� �������
		label16->Text = "X: " + FX.ToString() + ", Y: " + FY.ToString();
		label15->Text = "X: " + closestX.ToString() + ", Y: " + closestY.ToString();
	}
	catch (...) {
		// ��������� ����������
	}
}




void main(array<String^>^ args)
{
	//���� ����� �������� ������������� ���������� ������ ��� ��������� ���������� � Windows Forms, 
	//����� ��� ��������� ��������������� ������� � ����������� �� ������������ �������.
	Application::EnableVisualStyles();


	//���� ����� ������������� ��������, �����������, ��� ����� � ���������� �� ������ ������������ 
	//����������� � ����������� �������� GDI+.
	//��� �������, ��� �������� �������� false, ����� ������������ ����� �������� ���������� ������.
	Application::SetCompatibleTextRenderingDefault(false);
	


	//������� ��������� ������ MyForm �� ������������ ��� Project67.MyForm
	Project67::MyForm form;

	//���� ����� ��������� ������� ���� ��������� ��������� ����������, ������� �������� �� ���������
	//  ������� ������������
	//  � ���������� ����������. �� ����� ���������, ��� ����� form �������� ������� ������ ����������.
	Application::Run(% form);
	

	
}

// ������� ��� ���������� � ������� � ���������� �������� ��������

System::Void Project67::MyForm::Input_functoin(System::Object^ sender, System::EventArgs^ e)
{	std::ifstream File("data.txt");
	double x, y;
	xValues.clear();
	yValues.clear();
	while (File >> x >> y) {
		xValues.push_back(x);
		yValues.push_back(y);
		x_y.push_back(std::to_string(x) + std::to_string(y));
	}
	File.close();
	if(xValues.size()==0 && yValues.size()==0)
		label1->Text = L"���������� �������� ����������;";
	else
	{	
		this->chart1->Series[0]->Points->Clear();
		for (int i = 0; i < xValues.size(); i++) {
			this->chart1->Series[0]->Points->AddXY(xValues[i], yValues[i]);
		}
	}
	return System::Void();
}

// ������� ��� ������� �������� ���������

System::Void Project67::MyForm::Linefunction(System::Object^ sender, System::EventArgs^ e)
{

	this->chart1->Series[1]->Points->Clear();
	y = 0;
	x = findMin(xValues);
	while (x <=findMax(xValues) )
	{
		y = metod.koof[0] *x + metod.koof[1];
		this->chart1->Series[1]->Points->AddXY(x, y);
		x += h;
	}
	for (int i = 0; i < xValues.size(); i++)
	{
		double y = metod.koof[0] * xValues[i] + metod.koof[1];
		FValues.push_back(y);
	}
	
	return System::Void();
}

// ������� ��� ������� ������������ ���������

System::Void Project67::MyForm::kv_min_function(System::Object^ sender, System::EventArgs^ e)
{

	this->chart1->Series[2]->Points->Clear();
	y = 0;
	x = findMin(xValues);
	while (x <= findMax(xValues))
	{
		y = metod.koof[2] * x * x + metod.koof[3] * x + metod.koof[4];
		this->chart1->Series[2]->Points->AddXY(x, y);
		x += h;
	}
	for (int i = 0; i < xValues.size(); i++)
	{
		double y= metod.koof[2] *pow(xValues[i],2) + metod.koof[3] *xValues[i] + metod.koof[4];
		FValues.push_back(y);
	}

	return System::Void();
}

// ������� ��� ������� ��������� ���������

System::Void Project67::MyForm::stepen_reget_function(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[4]->Points->Clear();
	y = 0;
	x = findMin(xValues);
	while (x <= findMax(yValues))
	{
		y = metod.koof[6] * pow(x,metod.koof[5]);
		this->chart1->Series[4]->Points->AddXY(x, y);
		x += h;
	}
	for (int i = 0; i < xValues.size(); i++)
	{
		double y = metod.koof[6] * pow(xValues[i], metod.koof[5]);
		FValues.push_back(y);
	}
	return System::Void();
}

// ������� ��� ������� ������������� ���������

System::Void  Project67::MyForm::pokazat_reget_function(System::Object^ sender, System::EventArgs^ e) {

	this->chart1->Series[5]->Points->Clear();
	y = 0;
	x = findMin(xValues) ;
	while (x <= findMax(yValues) )
	{
		y = metod.koof[8] * pow(metod.koof[7], x);
		this->chart1->Series[5]->Points->AddXY(x, y);
		x += h;
	}
	for (int i = 0; i < xValues.size(); i++)
	{
		double y = metod.koof[8] * pow(metod.koof[7], xValues[i]);
		FValues.push_back(y);
	}

	return System::Void();
}

// ������� ��� ������� ��������������� ���������

System::Void  Project67::MyForm::giper_reget_function(System::Object^ sender, System::EventArgs^ e) {

	this->chart1->Series[3]->Points->Clear();
	y = 0;
	x = findMin(xValues);
	h = 1;
	while (x <=findMax(xValues))
	{
		if (x!=0){
			y = metod.koof[10] + metod.koof[9] / x;
			this->chart1->Series[3]->Points->AddXY(x, y);
			x += h;
		}
		else
			x += h;
	}

	for (int i = 0; i < xValues.size(); i++)
	{		if(xValues[i]!=0){
		double y = metod.koof[10] + metod.koof[9] / xValues[i];
		FValues.push_back(y);
		}

	}

	return System::Void();
}

// ������� ��� ������� ���������������  ���������

System::Void Project67::MyForm::log_reget_function(System::Object^ sender, System::EventArgs^ e) {

	this->chart1->Series[6]->Points->Clear();
	y = 0;
	x = findMin(xValues);
	while (x <= findMax(xValues) )
	{
		if (x != 0) {
			y = metod.koof[12] + metod.koof[11] * log(x);
			this->chart1->Series[6]->Points->AddXY(x, y);
			x += h;
		}
		else
			x += h;
	}
	for (int i = 0; i < xValues.size(); i++)
	{
		double y = metod.koof[12] + metod.koof[11] * log(xValues[i]);
		FValues.push_back(y);
	}

	return System::Void();

}

// ������� ��� ������� ����������������  ���������

System::Void Project67::MyForm::exp_reget_function(System::Object^ sender, System::EventArgs^ e) {

	this->chart1->Series[7]->Points->Clear();
	y = 0;
	x = findMin(xValues);
	while (x <= findMax(xValues) )
	{
		y = exp(metod.koof[14] + metod.koof[13] * x);
		this->chart1->Series[7]->Points->AddXY(x, y);
			x += h;
	}
	for (int i = 0; i < xValues.size(); i++)
	{
		double y = exp(metod.koof[14] + metod.koof[13] * xValues[i]);
		FValues.push_back(y);
	}
	return System::Void();

}

// ����� ��� ������ "��������"

System::Void Project67::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	// �������� ����� "data.txt" ��� ���������� ����� ������ � ����� �����
	std::ofstream File_new("data.txt", std::ios_base::app);
	std::string znach; // ���������� ��� �������� ��������

	// ��������, ������ �� ���� "data.txt" ��� ������
	if (File_new.is_open()) {
		// ���������� �������� X � Y c ������ ������� �����
		double X = (double)numericUpDown_x->Value + (int)numericUpDown_x_d->Value / pow(10, countDigits((int)numericUpDown_x_d->Value));
		double Y = (double)numericUpDown_y->Value + (int)numericUpDown_x_d->Value / pow(10, countDigits((int)numericUpDown_x_d->Value));
		znach = (std::to_string(X) + std::to_string(Y)); // ������������ ������ ��������

		// ���� �������� znach ��� �� ���������� � ������� x_y
		if (!findZnach(x_y, znach)) {
			// ������ � ���� "data.txt" � ����������� �� ������� ������� ����� ��� X � Y
			if ((double)numericUpDown_x_d->Value == 0 && (double)numericUpDown_y_d->Value == 0)
				File_new << std::endl << X << ".0 " << Y << ".0";
			if ((double)numericUpDown_x_d->Value == 0 && (double)numericUpDown_y_d->Value != 0)
				File_new << std::endl << X << ".0 " << Y;
			if ((double)numericUpDown_x_d->Value != 0 && (double)numericUpDown_y_d->Value == 0)
				File_new << std::endl << X << " " << Y << ".0";
			if ((double)numericUpDown_x_d->Value != 0 && (double)numericUpDown_y_d->Value != 0)
				File_new << std::endl << X << " " << Y;
		}
		File_new.close(); // �������� ����� "data.txt"
	}

	// ���� �������� znach �� ���������� � ������� x_y
	if (!findZnach(x_y, znach)) {
		x_y.push_back(znach); // ���������� �������� � ������
		std::ifstream File("data.txt"); // �������� ����� "data.txt" ��� ������
		double x, y;
		xValues.clear(); // ������� ������� ��� �������� ��������� X
		yValues.clear(); // ������� ������� ��� �������� ��������� Y
		while (File >> x >> y) {
			xValues.push_back(x); // ���������� �������� X � ������
			yValues.push_back(y); // ���������� �������� Y � ������
		}
		File.close(); // �������� ����� "data.txt"

		// ���������� ����� �� ������ �� ����������� �� �������� xValues � yValues
		for (int i = 0; i < xValues.size(); i++) {
			this->chart1->Series[0]->Points->AddXY(xValues[i], yValues[i]);
		}
	}
}


// ����� ��� ������ "�������"

System::Void Project67::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::vector<std::string> lines;
	std::string line;

	std::ifstream infile("data.txt");
	while (std::getline(infile, line)) {
		lines.push_back(line);
	}if (lines.size() == 0) {
		label1->Text = L"���������� �������� ����������;";
		infile.close();
	}
		
	else
	{

		lines.pop_back();
		x_y.pop_back();
		std::ofstream outfile("data.txt", std::ios::trunc);
		for (int i = 0; i <lines.size();i++)
		{
			if ((lines.size() == 1))
				outfile << lines[i];
			if(lines.size()-i==1)
				outfile << lines[i];
			else
				outfile << lines[i] << std::endl;
			
		}
		outfile.close();

		std::ifstream File("data.txt");
		double x, y;
		xValues.clear();
		yValues.clear();
		while (File >> x >> y) {
			xValues.push_back(x);
			yValues.push_back(y);
		}
		File.close();
		
		this->chart1->Series[0]->Points->Clear();
		for (int i = 0; i < xValues.size(); i++) {
			this->chart1->Series[0]->Points->AddXY(xValues[i], yValues[i]);
		}
	}
	

}




// ����� ��� ������ "���������

System::Void Project67::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{



	if (comboBox->SelectedItem == "�������� ���������")
	{
		
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"������� ���� �������� ������";
		else{
			label1->Text = L"�������� ���������";

			this->chart1->Series[1]->LegendText = L"�������� �������";
			metod.linearRegression();
			function->Text = metod.koof[0].ToString() + "* X + (" + metod.koof[1].ToString() + ")";
			Linefunction(sender, e);
			for_delite.push_back(1);
			double k = k_s_d.koof_line();
			label5->Text = k.ToString();
			label8->Text = k_s_d.der(k).ToString();
			label6->Text = k_s_d.sred().ToString();
		}
		
	}
	if (comboBox->SelectedItem == "������������ ���������")
		{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"������� ���� �������� ������";

		else{ label1->Text = L"������������ ���������";
			this->chart1->Series[2]->LegendText = L"������������ �������";
			metod.Min_kv();
			function->Text = metod.koof[2].ToString() + "* X^2 + (" + metod.koof[3].ToString() + ")*X + (" + metod.koof[1].ToString() + ")";
			kv_min_function(sender, e);
			for_delite.push_back(2);
			double k = k_s_d.kooff();
			label5->Text = k.ToString();
			label8->Text = k_s_d.der(k).ToString();
			label6->Text = k_s_d.sred().ToString(); }
			

	}
		
	if (comboBox->SelectedItem == "��������������� ���������")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"������� ���� �������� ������";
		else
		{
			if (findZero(xValues))
				label1->Text = L"���������� �������� ���������� ��� x=0";
			else
			{
				label1->Text = L"��������������� ���������";

				this->chart1->Series[3]->LegendText = L"��������������� �������";
				metod.giperbol_reg();
				function->Text = metod.koof[10].ToString() + " + (" + metod.koof[9].ToString() + ")/X";
				giper_reget_function(sender, e);
				for_delite.push_back(3);
				double k = k_s_d.kooff();
				label5->Text = k.ToString();
				label8->Text = k_s_d.der(k).ToString();
				label6->Text = k_s_d.sred().ToString();
			}
		}
		
		
	}

	if (comboBox->SelectedItem == "��������� ���������")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"������� ���� �������� ������";
		else
		{
			if (findZero(xValues) || findOtr(xValues) || findOtr(yValues) || findZero(yValues))
				label1->Text = L"���������� �������� ���������� ��� y<=0 ��� x<=0";
			else
			{
				label1->Text = L"��������� ���������";
				this->chart1->Series[4]->LegendText = L"��������� �������";
				metod.stepen_reg();
				function->Text = metod.koof[6].ToString() + " * X^" + metod.koof[5].ToString();
				stepen_reget_function(sender, e);
				for_delite.push_back(4);
				double k = k_s_d.kooff();
				label5->Text = k.ToString();
				label8->Text = k_s_d.der(k).ToString();
				label6->Text = k_s_d.sred().ToString();
			}

		}
		
		
	}

	if (comboBox->SelectedItem == "������������� ���������")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"������� ���� �������� ������";
		else
		{
			if (findOtr(yValues) || findZero(yValues))
				label1->Text = L"���������� �������� ���������� ��� y<=0";
			else
			{
				label1->Text = L"������������� ���������";
				this->chart1->Series[5]->LegendText = L"������������� �������";
				metod.pokazat_reg();
				function->Text = metod.koof[8].ToString() + " * (" + metod.koof[7].ToString() + ")^X";
				pokazat_reget_function(sender, e);
				for_delite.push_back(5);
				double k = k_s_d.kooff();
				label5->Text = k.ToString();
				label8->Text = k_s_d.der(k).ToString();
				label6->Text = k_s_d.sred().ToString();
			}
		}
		
		
	
	}
						
	if (comboBox->SelectedItem == "��������������� ���������")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"������� ���� �������� ������";
		else
		{
			if (findZero(xValues) || findOtr(xValues))
				label1->Text = L"���������� �������� ���������� ��� x<=0";
			else
			{
				label1->Text = L"��������������� ���������";
				this->chart1->Series[6]->LegendText = L"��������������� ���������";
				metod.log_reg();
				function->Text = metod.koof[12].ToString() + " + (" + metod.koof[11].ToString() + ") * ln(X)";
				log_reget_function(sender, e);
				for_delite.push_back(6);
				double k = k_s_d.kooff();
				label5->Text = k.ToString();
				label8->Text = k_s_d.der(k).ToString();
				label6->Text = k_s_d.sred().ToString();

			}

		}
	
	
	}
							

	if (comboBox->SelectedItem == "���������������� ���������")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"������� ���� �������� ������";
		else
		{
			if (findZero(xValues) || findOtr(xValues) || findOtr(yValues) || findZero(yValues))
				label1->Text = L"���������� �������� ���������� ��� x<=0 ��� y<=0";
			else {

				label1->Text = L"���������������� ���������";
				this->chart1->Series[7]->LegendText = L"���������������� ���������";
				metod.exp_reg();
				function->Text = "e^(" + metod.koof[14].ToString() + " + (" + metod.koof[13].ToString() + " * X))";
				exp_reget_function(sender, e);
				for_delite.push_back(7);
				double k = k_s_d.kooff();
				label5->Text = k.ToString();
				label8->Text = k_s_d.der(k).ToString();
				label6->Text = k_s_d.sred().ToString();
			}
		}
	
		

	}

	return System::Void();
}

// ����� ��� ������ "��������"

System::Void Project67::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!for_delite.empty()) {
		this->chart1->Series[for_delite.back()]->LegendText = L"F(x)";
		this->chart1->Series[for_delite.back()]->Points->Clear();
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		for_delite.pop_back();
		FValues.clear();
	}	
	
	return System::Void();
}

System::Void Project67::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	SPAVKA spravka;
	spravka.ShowDialog();
	return System::Void();
}

