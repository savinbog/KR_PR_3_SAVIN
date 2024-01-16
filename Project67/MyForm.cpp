#include "MyForm.h"
#include "SPAVKA.h"
#include<vector>
#include<fstream>
#include <numeric>
#include<string>
#include<algorithm>
#include<cmath>

// Пространства имен необходимых для интерфейса

using namespace System;
using namespace System::Windows::Forms;



// Векторы для хранения значений X и Y
std::vector<double> xValues;
std::vector<double> yValues;

// Векторы для хранения значений функции

 std::vector<double> FValues;

// Векторы для проверки на дубли
std::vector<std::string> x_y;

// Вектор для номера удаляемой функции
std::vector< int> for_delite;

// Класс для реализации вычислений математический характеристик

class koo_sted_der
{
protected:
	// Переменные для суммирования
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

// Метод для линейной коориляции

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

// Метод для среденего значения

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

// Метод для коэффицента дереминации

double koo_sted_der::der(double const koof) {
	return koof*koof;
}

class Metod: public koo_sted_der
{
public:

// Массив для хранения значений коэффицентов функций 
	double koof[15];

//Методы для вичисления коэффицентов аппроксимирующей функции
	void linearRegression();
	void Min_kv();
	void stepen_reg();
	void exp_reg();
	void pokazat_reg();
	void giperbol_reg();
	void log_reg();

};


// Функция для вычислений коэффицентов линейной регрессии
void Metod::linearRegression() {
	// Расчет средних значений X и Y
	double xMean = std::accumulate(xValues.begin(), xValues.end(), 0.0) / xValues.size();
	double yMean = std::accumulate(yValues.begin(), yValues.end(), 0.0) / yValues.size();
	// Расчет коэффициентов
	double numerator = 0.0;
	double denominator = 0.0;
	for (int i = 0; i < xValues.size(); ++i) {
		numerator += (xValues[i] - xMean) * (yValues[i] - yMean);
		denominator += (xValues[i] - xMean) * (xValues[i] - xMean);
	}

	// Коэффициенты линейной регрессии
	koof[0] = numerator / denominator;
	koof[1] = yMean - koof[0] * xMean;

}


// Функция для вычислений коэффицентов квадратичной регрессии
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
	// Коэффициенты квадратичной  регрессии
	koof[2] = (tmp[8] - tmp[7] * tmp[5] / tmp[4]) / (tmp[6] - tmp[7] * tmp[3] / tmp[4]);
	koof[3] = (tmp[5] - tmp[3] * koof[2]) / tmp[4];
	koof[4] = tmp[0] - tmp[1] * koof[2] - tmp[2] * koof[3];


}


// Функция для вычислений коэффицентов степенной регрессии
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
	// Коэффициент степенной  регрессии
	koof[5] = (xValues.size() * (ln_y_x)-ln_x_1 * ln_y) / (xValues.size() * ln_x_2 - pow(ln_x_1, 2));
	koof[6] = exp(ln_y / xValues.size() - koof[5] * ln_x_1 / xValues.size());
}


// Функция для вычислений коэффицентов показательной регрессии
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
	// Коэффициенты показательной регрессии
	koof[7] = exp((xValues.size() * ln_y_x - x_1 * ln_y) / (xValues.size() * x_2 - x_1 * x_1));
	koof[8] = exp(ln_y / xValues.size() - log(koof[7]) / xValues.size() * x_1);


}


// Функция для вычислений коэффицентов гиперболической регрессии
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
	// Коэффициенты  гиперболической регрессии
	koof[9] = (xValues.size() * y_x_1_st_min_1 - x_1_st_min_1 * y_1) / (xValues.size() * x_2_st_min_1 - x_1_st_min_1 * x_1_st_min_1);
	koof[10] = y_1 / xValues.size() - koof[9] * x_1_st_min_1 / xValues.size();

}


// Функция для вычислений коэффицентов логарифмической регрессии
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
	// Коэффициенты логирифмической  регрессии
	koof[11] = (xValues.size() * y_1_ln_x - ln_x_1 * y_1) / (xValues.size() * ln_x_2 - ln_x_1 * ln_x_1);
	koof[12] = y_1 / xValues.size() - (koof[11] * ln_x_1) / xValues.size();
}

// Функция для вычислений коэффицентов экспоненциальной регрессии
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
	// Коэффициенты экспоненциальной  регрессии
	koof[13] = (xValues.size() * x_ln_y - x_1 * ln_y) / (xValues.size() * x_2 - x_1 * x_1);
	koof[14] = (ln_y - koof[13] * x_1) / xValues.size();
}

// Экземпляр класса koo_sted_der
koo_sted_der k_s_d;


// Экземпляр класса Metod
Metod metod;


[STAThreadAttribute]

// Функция для поиска длины числа

int countDigits(int number) {
	std::string numStr = std::to_string(number);
	return numStr.length();
}

// Функция для поиска нуля в векторе

bool findZero(const std::vector<double>& vec) {
	return std::find(vec.begin(), vec.end(), 0.0) != vec.end();
}

// Функция для поиска числа в векторе

bool findZnach(const std::vector<std::string>& vec, const std::string znach)
{
	return std::find(vec.begin(), vec.end(), znach) != vec.end();
}


// Функция для поиска отрицательного числа в векторе

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

// Функция для поиска максимального числа в векторе

double findMax(const std::vector<double>& vec) {
	return *std::max_element(vec.begin(), vec.end());
}

// Функция для поиска минимального числа в векторе

double findMin(const std::vector<double>& vec) {
	return *std::min_element(vec.begin(), vec.end());
}



System::Void Project67::MyForm::OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	try {
		// Получаем координаты указателя мыши внутри графика
		double mouseX = this->chart1->ChartAreas[0]->AxisX->PixelPositionToValue(e->X);
		double mouseY = this->chart1->ChartAreas[0]->AxisY->PixelPositionToValue(e->Y);

		// Переменные для хранения ближайшей точки и минимальной дистанции
		double closestX = 0;
		double closestY = 0;
		double FX = 0;
		double FY = 0;
		double minDistance = 0.5;

		// Итерируемся по всем точкам и находим ближайшую к координатам мыши
		for (size_t i = 0; i < xValues.size(); i++)
		{
			double distance = sqrt(pow((xValues[i] - mouseX), 2) + pow((yValues[i] - mouseY), 2));
			if (distance < minDistance)
			{
				// Обновляем ближайшую точку и минимальную дистанцию
				minDistance = distance;
				closestX = xValues[i];
				closestY = yValues[i];

				// Если есть значения функции, то находим значение фукнции ближайшей точки
				if (FValues.size() != 0) {
					FX = xValues[i];
					FY = FValues[FValues.size() - xValues.size() + i];
				}
			}
		}

		// Выводим значения ближайшей точки и, если есть, значения функции
		label16->Text = "X: " + FX.ToString() + ", Y: " + FY.ToString();
		label15->Text = "X: " + closestX.ToString() + ", Y: " + closestY.ToString();
	}
	catch (...) {
		// Обработка исключений
	}
}




void main(array<String^>^ args)
{
	//Этот метод включает использование визуальных стилей для элементов управления в Windows Forms, 
	//чтобы они выглядели соответствующим образом в зависимости от операционной системы.
	Application::EnableVisualStyles();


	//Этот метод устанавливает значение, указывающее, что текст в приложении не должен отображаться 
	//совместимым с предыдущими версиями GDI+.
	//Как правило, это значение остается false, чтобы использовать новый механизм рендеринга текста.
	Application::SetCompatibleTextRenderingDefault(false);
	


	//Создает экземпляр класса MyForm из пространства имён Project67.MyForm
	Project67::MyForm form;

	//Этот метод запускает главный цикл обработки сообщений приложения, который отвечает за обработку
	//  событий пользователя
	//  и обновление интерфейса. Он также указывает, что форма form является главной формой приложения.
	Application::Run(% form);
	

	
}

// Функция для добавления в векторы и прорисовки исходных значений

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
		label1->Text = L"Невозможно провести вычисления;";
	else
	{	
		this->chart1->Series[0]->Points->Clear();
		for (int i = 0; i < xValues.size(); i++) {
			this->chart1->Series[0]->Points->AddXY(xValues[i], yValues[i]);
		}
	}
	return System::Void();
}

// Функция для графика линейной регрессии

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

// Функция для графика квадратичной регрессии

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

// Функция для графика степенной регрессии

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

// Функция для графика показательной регрессии

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

// Функция для графика гиперболической регрессии

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

// Функция для графика логорифмической  регрессии

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

// Функция для графика экспоненциальной  регрессии

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

// Метод для кнопки "Добавить"

System::Void Project67::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	// Открытие файла "data.txt" для добавления новых данных в конец файла
	std::ofstream File_new("data.txt", std::ios_base::app);
	std::string znach; // Переменная для хранения значения

	// Проверка, открыт ли файл "data.txt" для записи
	if (File_new.is_open()) {
		// Вычисление значения X и Y c учётом дробной части
		double X = (double)numericUpDown_x->Value + (int)numericUpDown_x_d->Value / pow(10, countDigits((int)numericUpDown_x_d->Value));
		double Y = (double)numericUpDown_y->Value + (int)numericUpDown_x_d->Value / pow(10, countDigits((int)numericUpDown_x_d->Value));
		znach = (std::to_string(X) + std::to_string(Y)); // Формирование строки значения

		// Если значение znach ещё не содержится в массиве x_y
		if (!findZnach(x_y, znach)) {
			// Запись в файл "data.txt" в зависимости от наличия дробной части для X и Y
			if ((double)numericUpDown_x_d->Value == 0 && (double)numericUpDown_y_d->Value == 0)
				File_new << std::endl << X << ".0 " << Y << ".0";
			if ((double)numericUpDown_x_d->Value == 0 && (double)numericUpDown_y_d->Value != 0)
				File_new << std::endl << X << ".0 " << Y;
			if ((double)numericUpDown_x_d->Value != 0 && (double)numericUpDown_y_d->Value == 0)
				File_new << std::endl << X << " " << Y << ".0";
			if ((double)numericUpDown_x_d->Value != 0 && (double)numericUpDown_y_d->Value != 0)
				File_new << std::endl << X << " " << Y;
		}
		File_new.close(); // Закрытие файла "data.txt"
	}

	// Если значение znach не содержится в массиве x_y
	if (!findZnach(x_y, znach)) {
		x_y.push_back(znach); // Добавление значения в массив
		std::ifstream File("data.txt"); // Открытие файла "data.txt" для чтения
		double x, y;
		xValues.clear(); // Очистка вектора для хранения координат X
		yValues.clear(); // Очистка вектора для хранения координат Y
		while (File >> x >> y) {
			xValues.push_back(x); // Добавление значения X в вектор
			yValues.push_back(y); // Добавление значения Y в вектор
		}
		File.close(); // Закрытие файла "data.txt"

		// Добавление точек на график по координатам из векторов xValues и yValues
		for (int i = 0; i < xValues.size(); i++) {
			this->chart1->Series[0]->Points->AddXY(xValues[i], yValues[i]);
		}
	}
}


// Метод для кнопки "Удалить"

System::Void Project67::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::vector<std::string> lines;
	std::string line;

	std::ifstream infile("data.txt");
	while (std::getline(infile, line)) {
		lines.push_back(line);
	}if (lines.size() == 0) {
		label1->Text = L"Невозможно провести вычисления;";
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




// Метод для кнопки "Вычислить

System::Void Project67::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{



	if (comboBox->SelectedItem == "Линейная регрессия")
	{
		
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"Слишком мало исходных данных";
		else{
			label1->Text = L"Линейная регрессия";

			this->chart1->Series[1]->LegendText = L"Линейная функция";
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
	if (comboBox->SelectedItem == "Квадратичная регрессия")
		{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"Слишком мало исходных данных";

		else{ label1->Text = L"Квадратичная регрессия";
			this->chart1->Series[2]->LegendText = L"Квадратичная функция";
			metod.Min_kv();
			function->Text = metod.koof[2].ToString() + "* X^2 + (" + metod.koof[3].ToString() + ")*X + (" + metod.koof[1].ToString() + ")";
			kv_min_function(sender, e);
			for_delite.push_back(2);
			double k = k_s_d.kooff();
			label5->Text = k.ToString();
			label8->Text = k_s_d.der(k).ToString();
			label6->Text = k_s_d.sred().ToString(); }
			

	}
		
	if (comboBox->SelectedItem == "Гиперболическая регрессия")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"Слишком мало исходных данных";
		else
		{
			if (findZero(xValues))
				label1->Text = L"Невозможно провести вычисления при x=0";
			else
			{
				label1->Text = L"Гиперболическая регрессия";

				this->chart1->Series[3]->LegendText = L"Гиперболическая функция";
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

	if (comboBox->SelectedItem == "Степенная регрессия")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"Слишком мало исходных данных";
		else
		{
			if (findZero(xValues) || findOtr(xValues) || findOtr(yValues) || findZero(yValues))
				label1->Text = L"Невозможно провести вычисления при y<=0 или x<=0";
			else
			{
				label1->Text = L"Степенная регрессия";
				this->chart1->Series[4]->LegendText = L"Степенная функция";
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

	if (comboBox->SelectedItem == "Показательная регрессия")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"Слишком мало исходных данных";
		else
		{
			if (findOtr(yValues) || findZero(yValues))
				label1->Text = L"Невозможно провести вычисления при y<=0";
			else
			{
				label1->Text = L"Показательная регрессия";
				this->chart1->Series[5]->LegendText = L"Показательная функция";
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
						
	if (comboBox->SelectedItem == "Логорафмическая регрессия")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"Слишком мало исходных данных";
		else
		{
			if (findZero(xValues) || findOtr(xValues))
				label1->Text = L"Невозможно провести вычисления при x<=0";
			else
			{
				label1->Text = L"Логорафмическая регрессия";
				this->chart1->Series[6]->LegendText = L"Логорафмическая регрессия";
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
							

	if (comboBox->SelectedItem == "Экспоненциальная регрессия")
	{
		label5->Text = L"NaN";
		label8->Text = L"NaN";
		label6->Text = L"NaN";
		if ((xValues.size() < 4 && yValues.size() < 4))
			label1->Text = L"Слишком мало исходных данных";
		else
		{
			if (findZero(xValues) || findOtr(xValues) || findOtr(yValues) || findZero(yValues))
				label1->Text = L"Невозможно провести вычисления при x<=0 или y<=0";
			else {

				label1->Text = L"Экспоненциальная регрессия";
				this->chart1->Series[7]->LegendText = L"Экспоненциальная регрессия";
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

// Метод для кнопки "Сбросить"

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

