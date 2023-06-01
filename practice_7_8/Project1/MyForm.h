#pragma once
#include <iostream>
#include "app.h"
#include <vector>
using namespace System::Collections::Generic;

namespace Project1 {

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
			days = gcnew array<System::String^>(7);
			days[0] = "Понеділок";
			days[1] = "Вівторок";
			days[2] = "Середа";
			days[3] = "Четвер";
			days[4] = "П'ятниця";
			days[5] = "Субота";
			days[6] = "Неділя";
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
	private: System::Windows::Forms::Button^ newton_1_btn;
	private: System::Windows::Forms::TextBox^ day;
	private: System::Windows::Forms::TextBox^ year;


	private: System::Windows::Forms::TextBox^ month;


	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel;
	private: System::Windows::Forms::Label^ date_1;
	private: System::Windows::Forms::Label^ date_2;



	private: System::Windows::Forms::Button^ clear_date_1;
	private: System::Windows::Forms::Button^ clear_date_2;
	private: System::Windows::Forms::Button^ compare_dates;
	private: System::Windows::Forms::Label^ result;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->newton_1_btn = (gcnew System::Windows::Forms::Button());
			this->day = (gcnew System::Windows::Forms::TextBox());
			this->year = (gcnew System::Windows::Forms::TextBox());
			this->month = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->date_1 = (gcnew System::Windows::Forms::Label());
			this->date_2 = (gcnew System::Windows::Forms::Label());
			this->clear_date_1 = (gcnew System::Windows::Forms::Button());
			this->clear_date_2 = (gcnew System::Windows::Forms::Button());
			this->compare_dates = (gcnew System::Windows::Forms::Button());
			this->result = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// newton_1_btn
			// 
			this->newton_1_btn->Location = System::Drawing::Point(328, 69);
			this->newton_1_btn->Name = L"newton_1_btn";
			this->newton_1_btn->Size = System::Drawing::Size(24, 23);
			this->newton_1_btn->TabIndex = 134;
			this->newton_1_btn->Text = L"+";
			this->newton_1_btn->UseVisualStyleBackColor = true;
			this->newton_1_btn->Click += gcnew System::EventHandler(this, &MyForm::newton_1_btn_Click);
			// 
			// day
			// 
			this->day->Location = System::Drawing::Point(83, 71);
			this->day->Name = L"day";
			this->day->Size = System::Drawing::Size(32, 20);
			this->day->TabIndex = 135;
			this->day->Text = L"15";
			// 
			// year
			// 
			this->year->Location = System::Drawing::Point(241, 71);
			this->year->Name = L"year";
			this->year->Size = System::Drawing::Size(45, 20);
			this->year->TabIndex = 136;
			this->year->Text = L"2000";
			// 
			// month
			// 
			this->month->Location = System::Drawing::Point(158, 71);
			this->month->Name = L"month";
			this->month->Size = System::Drawing::Size(32, 20);
			this->month->TabIndex = 137;
			this->month->Text = L"1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(121, 74);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(36, 13);
			this->label10->TabIndex = 138;
			this->label10->Text = L"число";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(292, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(21, 13);
			this->label1->TabIndex = 139;
			this->label1->Text = L"рік";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(196, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 140;
			this->label2->Text = L"місяць";
			// 
			// flowLayoutPanel
			// 
			this->flowLayoutPanel->Location = System::Drawing::Point(86, 254);
			this->flowLayoutPanel->Name = L"flowLayoutPanel";
			this->flowLayoutPanel->Size = System::Drawing::Size(227, 235);
			this->flowLayoutPanel->TabIndex = 141;
			// 
			// date_1
			// 
			this->date_1->AutoSize = true;
			this->date_1->Location = System::Drawing::Point(83, 135);
			this->date_1->Name = L"date_1";
			this->date_1->Size = System::Drawing::Size(39, 13);
			this->date_1->TabIndex = 142;
			this->date_1->Text = L"дата 1";
			// 
			// date_2
			// 
			this->date_2->AutoSize = true;
			this->date_2->Location = System::Drawing::Point(247, 135);
			this->date_2->Name = L"date_2";
			this->date_2->Size = System::Drawing::Size(39, 13);
			this->date_2->TabIndex = 143;
			this->date_2->Text = L"дата 2";
			// 
			// clear_date_1
			// 
			this->clear_date_1->Location = System::Drawing::Point(91, 151);
			this->clear_date_1->Name = L"clear_date_1";
			this->clear_date_1->Size = System::Drawing::Size(24, 24);
			this->clear_date_1->TabIndex = 144;
			this->clear_date_1->Text = L"x";
			this->clear_date_1->UseVisualStyleBackColor = true;
			this->clear_date_1->Click += gcnew System::EventHandler(this, &MyForm::clear_date_1_Click);
			// 
			// clear_date_2
			// 
			this->clear_date_2->Location = System::Drawing::Point(250, 151);
			this->clear_date_2->Name = L"clear_date_2";
			this->clear_date_2->Size = System::Drawing::Size(24, 24);
			this->clear_date_2->TabIndex = 145;
			this->clear_date_2->Text = L"x";
			this->clear_date_2->UseVisualStyleBackColor = true;
			this->clear_date_2->Click += gcnew System::EventHandler(this, &MyForm::clear_date_2_Click);
			// 
			// compare_dates
			// 
			this->compare_dates->Location = System::Drawing::Point(91, 180);
			this->compare_dates->Name = L"compare_dates";
			this->compare_dates->Size = System::Drawing::Size(183, 24);
			this->compare_dates->TabIndex = 146;
			this->compare_dates->Text = L"порівняти дату 1 та дату 2";
			this->compare_dates->UseVisualStyleBackColor = true;
			this->compare_dates->Click += gcnew System::EventHandler(this, &MyForm::compare_dates_Click);
			// 
			// result
			// 
			this->result->AutoSize = true;
			this->result->Location = System::Drawing::Point(88, 221);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(0, 13);
			this->result->TabIndex = 147;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 507);
			this->Controls->Add(this->result);
			this->Controls->Add(this->compare_dates);
			this->Controls->Add(this->clear_date_2);
			this->Controls->Add(this->clear_date_1);
			this->Controls->Add(this->date_2);
			this->Controls->Add(this->date_1);
			this->Controls->Add(this->flowLayoutPanel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->month);
			this->Controls->Add(this->year);
			this->Controls->Add(this->day);
			this->Controls->Add(this->newton_1_btn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		
	private:
		int trigger0 = 1;
		int trigger1 = 1;
		array<System::String^>^ days;
		int id0;
		int id1;
		int length = 0;
		array<Date^>^ arr = gcnew array<Date^>(length);
		void label_Click(System::Object^ sender, System::EventArgs^ e) {
			Label^ clickedLabel = dynamic_cast<Label^>(sender);
			if (clickedLabel != nullptr) {

				/*std::cout<< clickedLabel->Text*/
				int index = flowLayoutPanel->Controls->IndexOf(clickedLabel->Parent);
				Date^ e = arr[index];
				if (trigger0) {
					this->date_1->Text = e->getDay()+"."+e->getMonth()+"."+e->getYear() + ".";
					trigger0 = 0;
					id0 = e->getId();
				}else if (trigger1) {
					this->date_2->Text = e->getDay() + "." + e->getMonth() + "." + e->getYear() + ".";
					trigger1 = 0;
					id1 = e->getId();
				}
				else {
					MessageBox::Show("Обидві поля для дат порівняння заповнені, звільніть одне з них", "помилка");
				}
			}
			std::cout << "id0:"<<id0<<std::endl;
			std::cout << "id1:" << id1<<std::endl;
		}
		void btn_Click(System::Object^ sender, System::EventArgs^ e) {

			Button^ clickedBtn = dynamic_cast<Button^>(sender);
			if (clickedBtn != nullptr) {
				Panel^ panel = dynamic_cast<Panel^>(clickedBtn->Parent);
				int index = flowLayoutPanel->Controls->IndexOf(panel);
				if (arr[index]->getId() == id0) {
					this->date_1->Text = "дата 1";
					trigger0 = 1;
				}
				if (arr[index]->getId() == id1) {
					this->date_2->Text = "дата 2";
					trigger1 = 1;
				}
				if (panel != nullptr) {
					Control^ parentControl = panel->Parent;
					if (parentControl != nullptr) {
						parentControl->Controls->Remove(panel);
						length--;
						array<Date^>^ arr_temp = gcnew array<Date^>(length);

						int counter = 0;
						for (int i = 0; i < length+1; i++) {
							if (i != index) {
								arr_temp[counter] = arr[i];
								counter++;
							}
							
						}
						arr = arr_temp;
					}
				}
			}
		}
		
	private: System::Void newton_1_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		bool isInteger = 1;
		int day,month, year;
		isInteger = System::Int32::TryParse(this->day->Text, day) ? isInteger : 0;
		isInteger = System::Int32::TryParse(this->month->Text, month) ? isInteger : 0;
		isInteger = System::Int32::TryParse(this->year->Text, year) ? isInteger : 0;
		if (isInteger) {
			Label^ label = gcnew Label();
			label->Padding = System::Windows::Forms::Padding(0, 5, 0, 0);
			Panel^ panel = gcnew Panel();
			panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			Button^ btn = gcnew Button();
			btn->Click += gcnew System::EventHandler(this, &MyForm::btn_Click);
			btn->Margin = System::Windows::Forms::Padding(-5, 0, 0, 0);
			btn->Text = "x";
			btn->Width = 23;
			btn->Height = 23;
			btn->Dock = DockStyle::Right;
			panel->Height = 25;
			try {
				Date^ date1 = gcnew Date(day, month, year);
				length++;
				array<Date^>^ arr_temp = gcnew array<Date^>(length);
				for (int i = 0; i < length-1; i++) {
					arr_temp[i] = arr[i];
				}
				arr_temp[length - 1] = date1;
				arr = arr_temp;
				label->Text = day + " число, " + month + " місяць, " + year + " рік.";
				label->Click += gcnew System::EventHandler(this, &MyForm::label_Click);
				label->AutoSize = true;
				panel->Controls->Add(label);
				panel->Controls->Add(btn);
				flowLayoutPanel->Controls->Add(panel);
				flowLayoutPanel->Controls->SetChildIndex(panel, flowLayoutPanel->Controls->Count - 1);

				// Опціонально: прокрутити панель вниз
				flowLayoutPanel->ScrollControlIntoView(label);
			}
			catch (System::Exception^ e) {
				MessageBox::Show(e->Message, "помилка");
			}
			catch (...) {
				MessageBox::Show("непередбачувана помилка", "помилка");
			}
		}
		else {
			MessageBox::Show("недопустимі данні полів дати", "помилка");
		}
		
	}




	private: System::Void clear_date_1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->date_1->Text = "дата 1";
		trigger0 = 1;
	}
	private: System::Void clear_date_2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->date_2->Text = "дата 2";
		trigger1 = 1;
	}
	private: System::Void compare_dates_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!trigger0 && !trigger1) {
			Date^ e0;
			Date^ e1;
			for (int i = 0; i < length; i++) {
				if (id0 == arr[i]->getId()) {
					e0 = arr[i];
				}
			}
			for (int i = 0; i < length; i++) {
				if (id1 == arr[i]->getId()) {
					e1 = arr[i];
				}
			}
			if (e0->getDayOfWeek() == e1->getDayOfWeek()) {
				result->Text = "Обидві дати відповідають одному дню тижня.("+days[e0->getDayOfWeek() -1]+")";
			}
			else {
				result->Text = "Дати відповідають різним дням тижня.(" + days[e0->getDayOfWeek() -1]+" та "+days[e1->getDayOfWeek() -1]+")";
			}
		}
		else {
			MessageBox::Show("Оберіть дати для порівняння", "помилка");
		}
	}
};
}
