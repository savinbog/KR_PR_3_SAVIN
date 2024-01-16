#pragma once

namespace Project67 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_x;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_x_d;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_y_d;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown_y;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ function;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;







	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_x = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_x_d = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_y_d = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_y = (gcnew System::Windows::Forms::NumericUpDown());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->function = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_x))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_x_d))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_y_d))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_y))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(332, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Метод аппроксимации";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(18, 280);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(257, 53);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(18, 355);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(257, 52);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Сбросить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox
			// 
			this->comboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Линейная регрессия", L"Квадратичная регрессия",
					L"Гиперболическая регрессия", L"Степенная регрессия", L"Показательная регрессия", L"Логорафмическая регрессия", L"Экспоненциальная регрессия"
			});
			this->comboBox->Location = System::Drawing::Point(933, 11);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(369, 33);
			this->comboBox->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(436, 32);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Аппроксимирующая функция:\r\n";
			// 
			// chart1
			// 
			this->chart1->BorderSkin->BackColor = System::Drawing::Color::Orange;
			this->chart1->BorderSkin->BackHatchStyle = System::Windows::Forms::DataVisualization::Charting::ChartHatchStyle::BackwardDiagonal;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(275, 255);
			this->chart1->Name = L"chart1";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series1->Legend = L"Legend1";
			series1->LegendText = L"Исходные значения";
			series1->Name = L"Series1";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::MidnightBlue;
			series2->Legend = L"Legend1";
			series2->LegendText = L"F(x)";
			series2->Name = L"Series2";
			series3->BorderWidth = 3;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series3->Legend = L"Legend1";
			series3->LegendText = L"F(x)";
			series3->Name = L"Series3";
			series4->BorderWidth = 4;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			series4->Legend = L"Legend1";
			series4->LegendText = L"F(x)";
			series4->Name = L"Series4";
			series5->BorderWidth = 3;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series5->Color = System::Drawing::Color::Black;
			series5->Legend = L"Legend1";
			series5->LegendText = L"F(x)";
			series5->Name = L"Series5";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series6->Legend = L"Legend1";
			series6->LegendText = L"F(x)";
			series6->Name = L"Series6";
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Legend = L"Legend1";
			series7->LegendText = L"F(x)";
			series7->Name = L"Series7";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series8->Legend = L"Legend1";
			series8->LegendText = L"F(x)";
			series8->Name = L"Series8";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Series->Add(series7);
			this->chart1->Series->Add(series8);
			this->chart1->Size = System::Drawing::Size(1113, 490);
			this->chart1->TabIndex = 8;
			this->chart1->Text = L"chart";
			title1->Name = L"Title1";
			title1->Text = L"Графики функций";
			this->chart1->Titles->Add(title1);
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			this->chart1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OnMouseMove);
		

// Добавление новой области графика
			if (chart1->ChartAreas->Count == 1) {
				chart1->ChartAreas->Add(gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			}
			chart1->Size = System::Drawing::Size(1100, 1000);
			// Получение объекта ChartArea для дальнейшей настройки
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea = chart1->ChartAreas[0];

			// Настройка оси OX (AxisX)
			chartArea->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True; // включаем отображение
			chartArea->AxisX->MajorGrid->Enabled = true; // включаем отображение сетки
			chartArea->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray; // цвет линий сетки
			chartArea->AxisX->MajorTickMark->Enabled = true; // включаем отображение основных делений
			chartArea->AxisX->LineColor = System::Drawing::Color::Black; // цвет линии оси

			// Настройка оси OY (AxisY)
			chartArea->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True; // включаем отображение
			chartArea->AxisY->MajorGrid->Enabled = true; // включаем отображение сетки
			chartArea->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray; // цвет линий сетки
			chartArea->AxisY->MajorTickMark->Enabled = true; // включаем отображение основных делений
			chartArea->AxisY->LineColor = System::Drawing::Color::Black; // цвет линии оси

			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(13, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(285, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Коэффицент корреляции:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(13, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(352, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Средняя ошибка аппроксомации:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(395, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(278, 25);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Коэффицент корреляции";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(395, 176);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(345, 25);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Средняя ошибка аппроксимации";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(13, 227);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(328, 25);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Коэффициент детерминации:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(395, 227);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(321, 25);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Коэффициент детерминации";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(18, 502);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(257, 52);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Добавить точку";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// numericUpDown_x
			// 
			this->numericUpDown_x->Location = System::Drawing::Point(12, 585);
			this->numericUpDown_x->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->numericUpDown_x->Name = L"numericUpDown_x";
			this->numericUpDown_x->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_x->TabIndex = 16;
			// 
			// numericUpDown_x_d
			// 
			this->numericUpDown_x_d->Location = System::Drawing::Point(151, 585);
			this->numericUpDown_x_d->Name = L"numericUpDown_x_d";
			this->numericUpDown_x_d->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_x_d->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(72, 557);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(130, 25);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Значения X";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(15, 610);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 16);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Целая часть";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(154, 610);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(117, 16);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Нецелая часть";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(72, 626);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(129, 25);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Значения Y";
			// 
			// numericUpDown_y_d
			// 
			this->numericUpDown_y_d->Location = System::Drawing::Point(151, 654);
			this->numericUpDown_y_d->Name = L"numericUpDown_y_d";
			this->numericUpDown_y_d->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_y_d->TabIndex = 22;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(154, 679);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(117, 16);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Нецелая часть";
			// 
			// numericUpDown_y
			// 
			this->numericUpDown_y->Location = System::Drawing::Point(12, 654);
			this->numericUpDown_y->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->numericUpDown_y->Name = L"numericUpDown_y";
			this->numericUpDown_y->Size = System::Drawing::Size(120, 22);
			this->numericUpDown_y->TabIndex = 24;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(15, 679);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(98, 16);
			this->label14->TabIndex = 25;
			this->label14->Text = L"Целая часть";
			// 
			// function
			// 
			this->function->AutoSize = true;
			this->function->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->function->Location = System::Drawing::Point(515, 76);
			this->function->Name = L"function";
			this->function->Size = System::Drawing::Size(282, 22);
			this->function->TabIndex = 26;
			this->function->Text = L"Аппроксимирующая функция";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(18, 429);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(257, 52);
			this->button4->TabIndex = 27;
			this->button4->Text = L"Удалить точку";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(1171, 501);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(51, 16);
			this->label15->TabIndex = 28;
			this->label15->Text = L"label15";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(1171, 546);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(51, 16);
			this->label16->TabIndex = 29;
			this->label16->Text = L"label16";
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::Info;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(1308, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 24);
			this->button5->TabIndex = 30;
			this->button5->Text = L"Справка";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(1171, 488);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(106, 13);
			this->label17->TabIndex = 31;
			this->label17->Text = L"Исходное значение:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(1171, 533);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(102, 13);
			this->label18->TabIndex = 32;
			this->label18->Text = L"Значение функции:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1400, 767);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->function);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->numericUpDown_y);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->numericUpDown_y_d);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->numericUpDown_x_d);
			this->Controls->Add(this->numericUpDown_x);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Аппроксимация";
			this->Load += gcnew System::EventHandler(this, &MyForm::Input_functoin);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_x))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_x_d))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_y_d))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_y))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion


		// шаг

		private:double h = 0.1;

		private:double x, y;
		private:
					System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
					System::Windows::Forms::Label^ label;
				
	

	private:System::Void Input_functoin(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Linefunction(System::Object^ sender, System::EventArgs^ e);

	private: System::Void kv_min_function(System::Object^ sender, System::EventArgs^ e);

	private:System::Void stepen_reget_function(System::Object^ sender, System::EventArgs^ e);

	private:System::Void pokazat_reget_function(System::Object^ sender, System::EventArgs^ e);

	private:System::Void giper_reget_function(System::Object^ sender, System::EventArgs^ e);

	private:System::Void log_reget_function(System::Object^ sender, System::EventArgs^ e);

	private:System::Void exp_reget_function(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);

private:  void OnMouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);


private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);


};
}
