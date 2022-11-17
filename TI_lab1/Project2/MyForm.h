#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#using <System.DLL>
#using <System.Drawing.DLL>
#using <System.Windows.Forms.DLL>
#include <clocale>
using namespace std;
using namespace System::IO;
extern int collisionX[2000] = { 0 };
extern int collisionIJ[2000] = { 0 };
#pragma once
namespace Project2 {
	using namespace std;
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
	private: System::Windows::Forms::RadioButton^ Playfair;
	protected:

	private: System::Windows::Forms::RadioButton^ Vigner;
	protected:

	private: System::Windows::Forms::RadioButton^ RailwayFance;
	private: System::Windows::Forms::TextBox^ BoxInput;
	private: System::Windows::Forms::TextBox^ BoxOutput;



	private: System::Windows::Forms::Button^ Encrypt;
	private: System::Windows::Forms::Button^ File;
	private: System::Windows::Forms::Button^ Decrypt;
	private: System::Windows::Forms::TextBox^ BoxKey;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ Type;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Playfair = (gcnew System::Windows::Forms::RadioButton());
			this->Vigner = (gcnew System::Windows::Forms::RadioButton());
			this->RailwayFance = (gcnew System::Windows::Forms::RadioButton());
			this->BoxInput = (gcnew System::Windows::Forms::TextBox());
			this->BoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->Encrypt = (gcnew System::Windows::Forms::Button());
			this->File = (gcnew System::Windows::Forms::Button());
			this->Decrypt = (gcnew System::Windows::Forms::Button());
			this->BoxKey = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Type = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Type->SuspendLayout();
			this->SuspendLayout();
			// 
			// Playfair
			// 
			this->Playfair->AutoSize = true;
			this->Playfair->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Playfair->Location = System::Drawing::Point(406, 26);
			this->Playfair->Margin = System::Windows::Forms::Padding(2);
			this->Playfair->Name = L"Playfair";
			this->Playfair->Size = System::Drawing::Size(111, 21);
			this->Playfair->TabIndex = 0;
			this->Playfair->Text = L"Playfair[ENG]";
			this->Playfair->UseVisualStyleBackColor = true;
			this->Playfair->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Playfair_CheckedChanged);
			// 
			// Vigner
			// 
			this->Vigner->AutoSize = true;
			this->Vigner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Vigner->Location = System::Drawing::Point(213, 26);
			this->Vigner->Margin = System::Windows::Forms::Padding(2);
			this->Vigner->Name = L"Vigner";
			this->Vigner->Size = System::Drawing::Size(112, 21);
			this->Vigner->TabIndex = 1;
			this->Vigner->Text = L"Vigener[RUS]";
			this->Vigner->UseVisualStyleBackColor = true;
			this->Vigner->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Vigner_CheckedChanged);
			// 
			// RailwayFance
			// 
			this->RailwayFance->AutoSize = true;
			this->RailwayFance->Checked = true;
			this->RailwayFance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RailwayFance->Location = System::Drawing::Point(24, 26);
			this->RailwayFance->Margin = System::Windows::Forms::Padding(2);
			this->RailwayFance->Name = L"RailwayFance";
			this->RailwayFance->Size = System::Drawing::Size(151, 21);
			this->RailwayFance->TabIndex = 2;
			this->RailwayFance->TabStop = true;
			this->RailwayFance->Text = L"RailwayFance[ENG]";
			this->RailwayFance->UseVisualStyleBackColor = true;
			this->RailwayFance->CheckedChanged += gcnew System::EventHandler(this, &MyForm::RailwayFance_CheckedChanged);
			// 
			// BoxInput
			// 
			this->BoxInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxInput->Location = System::Drawing::Point(18, 124);
			this->BoxInput->Margin = System::Windows::Forms::Padding(2);
			this->BoxInput->MaxLength = 1620;
			this->BoxInput->Multiline = true;
			this->BoxInput->Name = L"BoxInput";
			this->BoxInput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->BoxInput->Size = System::Drawing::Size(193, 103);
			this->BoxInput->TabIndex = 3;
			this->BoxInput->TabStop = false;
			this->BoxInput->TextChanged += gcnew System::EventHandler(this, &MyForm::BoxInput_TextChanged);
			// 
			// BoxOutput
			// 
			this->BoxOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxOutput->Location = System::Drawing::Point(369, 124);
			this->BoxOutput->Margin = System::Windows::Forms::Padding(2);
			this->BoxOutput->MaxLength = 1620;
			this->BoxOutput->Multiline = true;
			this->BoxOutput->Name = L"BoxOutput";
			this->BoxOutput->ReadOnly = true;
			this->BoxOutput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->BoxOutput->Size = System::Drawing::Size(193, 103);
			this->BoxOutput->TabIndex = 4;
			this->BoxOutput->TabStop = false;
			// 
			// Encrypt
			// 
			this->Encrypt->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Encrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Encrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Encrypt->Location = System::Drawing::Point(255, 123);
			this->Encrypt->Margin = System::Windows::Forms::Padding(2);
			this->Encrypt->Name = L"Encrypt";
			this->Encrypt->Size = System::Drawing::Size(82, 29);
			this->Encrypt->TabIndex = 5;
			this->Encrypt->TabStop = false;
			this->Encrypt->Text = L"Encrypt";
			this->Encrypt->UseVisualStyleBackColor = false;
			this->Encrypt->Click += gcnew System::EventHandler(this, &MyForm::Encrypt_Click);
			// 
			// File
			// 
			this->File->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->File->Cursor = System::Windows::Forms::Cursors::Hand;
			this->File->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->File->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->File->Location = System::Drawing::Point(55, 245);
			this->File->Margin = System::Windows::Forms::Padding(2);
			this->File->Name = L"File";
			this->File->Size = System::Drawing::Size(119, 44);
			this->File->TabIndex = 6;
			this->File->TabStop = false;
			this->File->Text = L"Open File";
			this->File->UseVisualStyleBackColor = false;
			this->File->Click += gcnew System::EventHandler(this, &MyForm::File_Click);
			// 
			// Decrypt
			// 
			this->Decrypt->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Decrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Decrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Decrypt->Location = System::Drawing::Point(255, 198);
			this->Decrypt->Margin = System::Windows::Forms::Padding(2);
			this->Decrypt->Name = L"Decrypt";
			this->Decrypt->Size = System::Drawing::Size(82, 29);
			this->Decrypt->TabIndex = 7;
			this->Decrypt->TabStop = false;
			this->Decrypt->Text = L"Decrypt";
			this->Decrypt->UseVisualStyleBackColor = false;
			this->Decrypt->Click += gcnew System::EventHandler(this, &MyForm::Decrypt_Click);
			// 
			// BoxKey
			// 
			this->BoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxKey->Location = System::Drawing::Point(245, 308);
			this->BoxKey->Margin = System::Windows::Forms::Padding(2);
			this->BoxKey->Name = L"BoxKey";
			this->BoxKey->Size = System::Drawing::Size(109, 23);
			this->BoxKey->TabIndex = 8;
			this->BoxKey->TabStop = false;
			this->BoxKey->TextChanged += gcnew System::EventHandler(this, &MyForm::BoxKey_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label1->Location = System::Drawing::Point(280, 288);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 18);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Key";
			// 
			// Type
			// 
			this->Type->Controls->Add(this->RailwayFance);
			this->Type->Controls->Add(this->Vigner);
			this->Type->Controls->Add(this->Playfair);
			this->Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Type->Location = System::Drawing::Point(18, 17);
			this->Type->Margin = System::Windows::Forms::Padding(2);
			this->Type->Name = L"Type";
			this->Type->Padding = System::Windows::Forms::Padding(2);
			this->Type->Size = System::Drawing::Size(544, 81);
			this->Type->TabIndex = 10;
			this->Type->TabStop = false;
			this->Type->Text = L"Type";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(404, 245);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 44);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Save to File";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(38, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 20);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Input text:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(387, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 20);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Result:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(585, 356);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Type);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BoxKey);
			this->Controls->Add(this->Decrypt);
			this->Controls->Add(this->File);
			this->Controls->Add(this->Encrypt);
			this->Controls->Add(this->BoxOutput);
			this->Controls->Add(this->BoxInput);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TI_Lab1";
			this->Type->ResumeLayout(false);
			this->Type->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		void MyForm::Encrypt_fance()
		{
			System::String^ plainText = BoxInput->Text;
			System::String^ keyText = BoxKey->Text;
			int64_t lentext1 = keyText->Length;
			for (int i = 0; i < lentext1; i++)
			{
				if (keyText[i] < '0' || keyText[i] > '9' || (i == 0 && keyText[i] == '0')) {
					keyText = keyText->Remove(i, 1);
					lentext1--;
					i--;
				}
			}
			if (keyText == "")
				MessageBox::Show(this, "Ключ введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			else {
				if(keyText->Length > 6)
				{
					MessageBox::Show(this, "Ключ слишком длинный!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				int64_t key = Convert::ToInt64(keyText);
				int64_t i = -2, j = 0, k, len;
				if (key == 1) {
					BoxOutput->Text = plainText;
				}
				else {
					len = plainText->Length;
					wchar_t** ptrarray = new wchar_t* [key];
					for (int64_t count = 0; count < key; count++)
						ptrarray[count] = new wchar_t[len] {'0'};
					for (k = 0; k < len; k++) {
						i = i + 2;
						while (i != key && k < len) {
							if (plainText[k] >= 'A' && plainText[k] <= 'z') {
								ptrarray[i][j] = plainText[k];
								i++;
								j++;
							}
							k++;
						}
						i = i - 2;
						while (i >= 0 && k < len) {
							if (plainText[k] >= 'A' && plainText[k] <= 'z') {
								ptrarray[i][j] = plainText[k];
								i--;
								j++;
							}
							k++;
						}
						k--;
					}
					
					System::String^ res = "";
					for (i = 0; i < key; i++)
						for (j = 0; j < len + 1; j++)
							if (ptrarray[i][j] >= 'A' && ptrarray[i][j] <= 'z')
								res = res + ptrarray[i][j];
					if(res == "")
						MessageBox::Show(this, "Текст введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					else 
						BoxOutput->Text = res;
					for (int64_t count = 0; count < key; count++)
						delete[] ptrarray[count];
					delete[] ptrarray;
				}
	
					
				
			}
		}



		void MyForm::Decrypt_fance()
		{
			System::String^ plainText = BoxInput->Text;
			int64_t len = plainText->Length;
			for (int i = 0; i < len; i++)
			{
				if (plainText[i] >= 'a' && plainText[i] <= 'z' || plainText[i] >= 'A' && plainText[i] <= 'Z') int pio = 0;
				else {
					plainText = plainText->Remove(i, 1);
					len--;
					i--;
				}
			}
			
				System::String^ keyText = BoxKey->Text;
				int64_t lentext1 = keyText->Length;
				for (int64_t i = 0; i < lentext1; i++)
				{
					if (keyText[i] < '0' || keyText[i] > '9' || (i == 0 && keyText[i] == '0')) {
						keyText = keyText->Remove(i, 1);
						lentext1--;
						i--;
					}
				}
				if (keyText == "")
					MessageBox::Show(this, "Ключ введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				else {
					int64_t key = Convert::ToInt64(keyText);
				if (key == 1) {
					BoxOutput->Text = plainText;
				}
				else {
					wchar_t** rail = new wchar_t* [key];
					for (int64_t count = 0; count < key; count++)
						rail[count] = new wchar_t[len];
					for (int64_t i = 0; i < key; i++)
						for (int64_t j = 0; j < len; j++)
							rail[i][j] = '\n';
					bool dir_down;
					int64_t row = 0, col = 0;
					for (int i = 0; i < len; i++)
					{
						if (row == 0)
							dir_down = true;
						if (row == key - 1)
							dir_down = false;
						rail[row][col++] = '*';
						dir_down ? row++ : row--;

					}
					int index = 0;
					for (int i = 0; i < key; i++)
						for (int j = 0; j < len; j++)
							if (rail[i][j] == '*' && index < len)
								rail[i][j] = plainText[index++];
					string result = "";
					row = 0, col = 0;
					for (int i = 0; i < len; i++)
					{
						if (row == 0)
							dir_down = true;
						if (row == key - 1)
							dir_down = false;
						if (rail[row][col] != '*')
							result.push_back(rail[row][col++]);
						dir_down ? row++ : row--;
					}

					System::String^ res = gcnew String(result.data());
					if (res == "")
						MessageBox::Show(this, "Текст введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					else
						BoxOutput->Text = res;
				}
			}
		}

System::String^ MyForm::Progress_Key(System::String^ key, System::String^ plainText,int lenkey, int lentext)
{
	System::String^ A = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя"; 
	wchar_t c;
	int j = 0;
	int len1 = lenkey;
	if (len1 < lentext)
		while (len1 < lentext) {
			for (int i = 0; i < 33; i++)
				if (key[j] == L'я')
					c = A[0];
				else {
					if (key[j] == A[i])
						c = A[i + 1];
				}
			key = key + c;
			j++;
			len1++;
		}
	return key;
}

void MyForm::Encrypt_Vigner(System::String^ plainText1) {
	
	int k = 0;
	setlocale(LC_ALL, "Russian");
	System::String^ plainText = "";
	System::String^ key1 = BoxKey->Text;
	System::String^ key = "";
	int lentext12 = key1->Length;
	for (int i = 0; i < lentext12; i++)
	{
		if(key1[i] >= L'а' && key1[i] <= L'я' || key1[i] >= L'А' && key1[i] <= L'Я' || key1[i] == L'Ё' || key1[i] == L'ё')
			;
		else {
			key1 = key1->Remove(i, 1);
			lentext12--;
			i--;
		}
	}
	if (key1 == "")
		MessageBox::Show(this, "Ключ введен неверно", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		wchar_t* txt2 = new wchar_t[lentext12];
		for (int d = 0; d < lentext12; d++) {
			txt2[d] = key1[d];
		}
		for (int d = 0; d < lentext12; d++) {
			if (txt2[d] >= L'А' && txt2[d] <= L'Я'  )
				txt2[d] = txt2[d] - 'А' + 'а';
			else if (txt2[d] == L'Ё')
				txt2[d] = L'ё';
			key = key + txt2[d];
		}
		int lentext1 = plainText1->Length;
		wchar_t* txt = new wchar_t[lentext1];
		for (int d = 0; d < lentext1; d++) {
			txt[d] = plainText1[d];
		}
		for (int d = 0; d < lentext1; d++) {
			if (txt[d] >= L'А' && txt[d] <= L'Я')
				txt[d] = txt[d] - 'А' + 'а';
			else if (txt[d] == L'Ё')
				txt[d] = L'ё';
			plainText = plainText + txt[d];
		}


		for (int i = 0; i < lentext1; i++)
		{
			if (plainText[i] >= L'а' && plainText[i] <= L'я' || plainText[i] >= L'А' && plainText[i] <= L'Я' || plainText[i] == L'Ё' || plainText[i] == L'ё')
				;
			else {
				plainText = plainText->Remove(i, 1);
				lentext1--;
				i--;
			}

		}
		int j = 0;
		System::String^ str = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
		int lentext = plainText->Length;
		key = Progress_Key(key, plainText, lentext12, lentext1);
		int pos1;
		int pos2;
		System::String^ res = "";
		wchar_t* array = new wchar_t[lentext];
		for (int i = 0; i < lentext; i++) {
			for (int j = 0; j < 33; j++) {
				if (plainText[i] == str[j])
					pos1 = j;
				if (key[i] == str[j])
					pos2 = j;
			}
			int ind = (pos1 + pos2) % 33;
			array[i] = str[ind];
		}
		for (int i = 0; i < lentext; i++)
			res = res + array[i];
		if (res == "")
			MessageBox::Show(this, "Текст введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			BoxOutput->Text = res;
	}

}
void MyForm::Decrypt_Vigner() 
{
	System::String^ str = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	System::String^ key1 = BoxKey->Text;
	System::String^ key = "";
	int lentext12 = key1->Length;
	for (int i = 0; i < lentext12; i++)
	{
		if (key1[i] >= L'а' && key1[i] <= L'я' || key1[i] >= L'А' && key1[i] <= L'Я' || key1[i] == L'Ё' || key1[i] == L'ё')
			int pio = 0;
		else {
			key1 = key1->Remove(i, 1);
			lentext12--;
			i--;
		}
	}
	if(key1=="")
	MessageBox::Show(this, "Ключ введен неверно", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		System::String^ plainText = "";
		wchar_t* txt2 = new wchar_t[lentext12];
		for (int d = 0; d < lentext12; d++) {
			txt2[d] = key1[d];
		}
		for (int d = 0; d < lentext12; d++) {
			if (txt2[d] >= L'А' && txt2[d] <= L'Я'  )
				txt2[d] = txt2[d] - 'А' + 'а';
			else if (txt2[d] == L'Ё')
				txt2[d] = L'ё';
			key = key + txt2[d];
		}
		System::String^ plainText1 = BoxInput->Text;
		/*int lentext = plainText->Length;*/
		int lentext1 = plainText1->Length;
		wchar_t* txt = new wchar_t[lentext1];
		for (int d = 0; d < lentext1; d++) {
			txt[d] = plainText1[d];
		}

		for (int d = 0; d < lentext1; d++) {
			if (txt[d] >= L'А' && txt[d] <= L'Я')
				txt[d] = txt[d] - 'А' + 'а';
			else if (txt[d] == L'Ё')
				txt[d] = L'ё';
			plainText = plainText + txt[d];
		}


		for (int i = 0; i < lentext1; i++)
		{
			if (plainText[i] >= L'а' && plainText[i] <= L'я' || plainText[i]==L'ё')
				;
			else {
				plainText = plainText->Remove(i, 1);
				lentext1--;
				i--;
			}

		}

		key = Progress_Key(key, plainText, lentext12, lentext1);
		int pos1;
		int pos2;
		System::String^ res = "";
		for (int i = 0; i < plainText->Length; i++)
		{
			for (int j = 0; j < 33; j++) {
				if (plainText[i] == str[j])
					pos1 = j;
				if (key[i] == str[j])
					pos2 = j;

			}
			int p = (pos1 + 33 - pos2) % 33;
			res = res + str[p];
		}

		if (res == "")
			MessageBox::Show(this, "Текст введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			BoxOutput->Text = res;
	}
}

int MyForm::Encrypt_Playfair()
{
	char str[26] = { 'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };//abcdefghiklmnopqrstuvwxyz
	System::String^ res;
	// индексы букв в столбцах
	System::String^ key1 = BoxKey->Text;
	System::String^ key = "";
	int lentext12 = key1->Length;
	for (int i = 0; i < lentext12; i++)
	{
		if (key1[i] >= 'a' && key1[i] <= 'z' || key1[i] >= 'A' && key1[i] <= 'Z')
			int pio = 0;
		else {
			key1 = key1->Remove(i, 1);
			lentext12--;
			i--;
		}
	}
	if (key1 == "")
		MessageBox::Show(this, "Ключ введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		int fg = 0, flag1 = 0;
		wchar_t* txt2 = new wchar_t[lentext12 + 25];
		for (int d = 0; d < lentext12; d++) {
			txt2[d] = key1[d];
		}
		for (int d = 0; d < lentext12; d++) {
			if (txt2[d] >= 'A' && txt2[d] <= 'Z')
			{
				txt2[d] = txt2[d] - 'A' + 'a';
			}

		}
		int lenta = lentext12;
		for (int d = 0; d < lentext12; d++)
		{
			for (int oi = 0; oi < fg; oi++)
				if (key[oi] == txt2[d])
				{
					flag1 = 1;
					//break;
				}
			if (flag1 != 1)
			{
				key = key + txt2[d];
				fg++;

			}
			else
				lenta = lenta - 1;
			flag1 = 0;

		}



		System::String^ plainText1 = BoxInput->Text;
		int lentext1 = plainText1->Length;
		for (int i = 0; i < lentext1; i++)
		{
			if (plainText1[i] >= 'a' && plainText1[i] <= 'z' || plainText1[i] >= 'A' && plainText1[i] <= 'Z')
				int pio = 0;
			else
			{
				plainText1 = plainText1->Remove(i, 1);
				lentext1--;
				i--;
			}
		}
		System::String^ plainText = "";
		wchar_t* txt0 = new  wchar_t[lentext1 + 25];
		for (int d = 0; d < lentext1; d++) {
			txt0[d] = plainText1[d];
		}
		for (int d = 0; d < lentext1; d++) {
			if (txt0[d] >= 'A' && txt0[d] <= 'Z')
				txt0[d] = txt0[d] - 'А' + 'а';
			plainText = plainText + txt0[d];
		}
		int ind_x1 = 0;
		int ind_y1 = 0;
		int ind_x2 = 0;
		int ind_y2 = 0;
		wchar_t Resh[30][30];



		int length = 25;
		for (int i = 0; i < lenta; i++)
			for (int j = 0; j < length; j++)
				if (key[i] == str[j])
				{
					for (int per = j; per < length; per++)
						str[per] = str[per + 1];
					length--;
					j--;
				}

		int p = 0, l = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (p < lenta) {
					Resh[i][j] = key[p];
					p++;
				}
				else {
					Resh[i][j] = str[l];
					l++;
				}


		int k = 0;
		int i = 0;
		int64_t len2 = plainText->Length;
		wchar_t* txt = new wchar_t[plainText->Length + 25];
		for (int d = 0; d < plainText->Length; d++)
			txt[d] = plainText[d];
		for (int d = 0; d < len2; d++) {
			if (txt[d] == 'x' && txt[d + 1] == 'x') {
				for (int o = len2 - 1; o > d; o--)
					txt[o + 1] = txt[o];
				txt[d + 1] = 'w';
				len2++;
				collisionX[d + 1] = 1;
				d++;
			}
			else
				if ((txt[d] == txt[d + 1]) && (d % 2 == 0)) {
					for (int o = len2 - 1; o > d; o--)
						txt[o + 1] = txt[o];
					txt[d + 1] = 'x';
					len2++;
					collisionX[d + 1] = 1;
					d++;
				}
				else
					collisionX[d] = 0;
		}
		if (len2 % 2 != 0) {
			if (txt[len2 - 1] == 'x') {
				txt[len2] = 'w';
				collisionX[len2] = 1;
				len2++;
			}
			else {
				txt[len2] = 'x';
				collisionX[len2] = 1;
				len2++;
			}
		}


		wchar_t* ResText = new wchar_t[len2 + 25];
		while (k < len2)
		{
			for (int l = 0; l < 5; l++)
				for (int m = 0; m < 5; m++)
				{
					if (txt[k] == 'j') {
						ind_x1 = 2;
						ind_y1 = 3;

					}
					else if (txt[k] == Resh[l][m])
					{
						ind_x1 = l;
						ind_y1 = m;

					}
					if (txt[k + 1] == 'j') {
						ind_x1 = 2;
						ind_y1 = 3;


					}
					else if (txt[k + 1] == Resh[l][m])
					{
						ind_x2 = l;
						ind_y2 = m;

					}


				}
			// Если буквы находятся в одной строке
			if (ind_x1 == ind_x2)
			{
				if (ind_y1 == 4)
				{
					if (txt[k] == 'j')
						collisionIJ[i] = 1;
					else collisionIJ[i] = 0;
					i++;
					if (txt[k + 1] == 'j')
						collisionIJ[i] = 1;
					else collisionIJ[i] = 0;
					i++;
					ResText[k] = Resh[ind_x1][0];
					ResText[k + 1] = Resh[ind_x2][ind_y2 + 1];
				}
				else
					if (ind_y2 == 4)
					{
						if (txt[k] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						if (txt[k + 1] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						ResText[k] = Resh[ind_x1][ind_y1 + 1];
						ResText[k + 1] = Resh[ind_x2][0];
					}
					else
					{
						if (txt[k] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						if (txt[k + 1] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						ResText[k] = Resh[ind_x1][ind_y1 + 1];
						ResText[k + 1] = Resh[ind_x2][ind_y2 + 1];
					}
			}
			// Если буквы находятся в одном столбце
			if (ind_y1 == ind_y2)
			{
				if (ind_x1 == 4)
				{
					if (txt[k] == 'j')
						collisionIJ[i] = 1;
					else collisionIJ[i] = 0;
					i++;
					if (txt[k + 1] == 'j')
						collisionIJ[i] = 1;
					else collisionIJ[i] = 0;
					i++;
					ResText[k] = Resh[0][ind_y1];
					ResText[k + 1] = Resh[ind_x2 + 1][ind_y2];
				}
				else
					if (ind_x2 == 4)
					{
						if (txt[k] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						if (txt[k + 1] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						ResText[k] = Resh[ind_x1 + 1][ind_y1];
						ResText[k + 1] = Resh[0][ind_y2];
					}
					else
					{
						if (txt[k] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						if (txt[k + 1] == 'j')
							collisionIJ[i] = 1;
						else collisionIJ[i] = 0;
						i++;
						ResText[k] = Resh[ind_x1 + 1][ind_y1];
						ResText[k + 1] = Resh[ind_x2 + 1][ind_y2];
					}
			}

			// Если буквы находятся в разных строках и разных столбцах
			if ((ind_x1 != ind_x2) && (ind_y1 != ind_y2))
			{
				if (txt[k] == 'j')
					collisionIJ[i] = 1;
				else collisionIJ[i] = 0;
				i++;
				if (txt[k + 1] == 'j') {
					collisionIJ[i] = 1;
				}
				else collisionIJ[i] = 0;
				i++;
				ResText[k] = Resh[ind_x1][ind_y2];
				ResText[k + 1] = Resh[ind_x2][ind_y1];
			}
			res = res + ResText[k];
			res = res + ResText[k + 1];
			k = k + 2;

		}


		if (res == nullptr)
			MessageBox::Show(this, "Текст введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			BoxOutput->Text = res;
		return 0;
	}

}

void MyForm::Decrypt_Playfair() {
	char str[30] = { 'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };//abcdefghiklmnopqrstuvwxyz
	System::String^ res = "";
	System::String^ key1 = BoxKey->Text;
	System::String^ key = "";
	int lentext12 = key1->Length;
	for (int i = 0; i < lentext12; i++)
	{
		if (key1[i] >= 'a' && key1[i] <= 'z' || key1[i] >= 'A' && key1[i] <= 'Z')
			int pio = 0;
		else {
			key1 = key1->Remove(i, 1);
			lentext12--;
			i--;
		}
	}
	if (key1 == "")
		MessageBox::Show(this, "Ключ введен неверно", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		wchar_t* txt2 = new wchar_t[lentext12 + 25];
		for (int d = 0; d < lentext12; d++) {
			txt2[d] = key1[d];
		}
		for (int d = 0; d < lentext12; d++) {
			if (txt2[d] >= 'A' && txt2[d] <= 'Z')
				txt2[d] = txt2[d] - 'A' + 'a';
		}

		int fg = 0, flag1 = 0;
		int lenta = lentext12;
		for (int d = 0; d < lentext12; d++)
		{
			for (int oi = 0; oi < fg; oi++)
				if (key[oi] == txt2[d])
				{
					flag1 = 1;

				}
			if (flag1 != 1)
			{
				key = key + txt2[d];
				fg++;

			}
			else
				lenta = lenta - 1;
			flag1 = 0;
		}


		System::String^ plainText1 = BoxInput->Text;
		int lentext1 = plainText1->Length;
		for (int i = 0; i < lentext1; i++)
		{
			if (plainText1[i] >= 'a' && plainText1[i] <= 'z' || plainText1[i] >= 'A' && plainText1[i] <= 'Z')
				int pio = 0;
			else
			{
				plainText1 = plainText1->Remove(i, 1);
				lentext1--;
				i--;
			}
		}
		System::String^ plainText = "";
		wchar_t* txt0 = new wchar_t[lentext1 + 25];
		for (int d = 0; d < lentext1; d++) {
			txt0[d] = plainText1[d];
		}
		for (int d = 0; d < lentext1; d++) {
			if (txt0[d] >= 'A' && txt0[d] <= 'Z')
				txt0[d] = txt0[d] - 'А' + 'а';
			plainText = plainText + txt0[d];
		}
		int ind_x1 = 0;
		int ind_y1 = 0;
		int ind_x2 = 0;
		int ind_y2 = 0;
		wchar_t f = 'j';
		wchar_t Resh[30][30];

		/*char A[30][30] = { {'c','r','y','p','t'},{'o','g','a','h','b'}, {'d','e','f','i','k'},{'l','m','n','q','s'}, {'u','v','w','x','z'} };*/
		int length = 25;
		for (int i = 0; i < lenta; i++)
			for (int j = 0; j < length; j++)
				if (key[i] == str[j])
				{
					for (int per = j; per < length; per++)
						str[per] = str[per + 1];
					length--;
					j--;
				}

		int p = 0, l = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (p < lenta) {
					Resh[i][j] = key[p];
					p++;
				}
				else {
					Resh[i][j] = str[l];
					l++;
				}
		int k = 0;
		wchar_t* ResText = new wchar_t[lentext1 + 25];
		wchar_t* txt = new wchar_t[lentext1 + 25];
		int i = 0;
		for (int d = 0; d < lentext1; d++)
			txt[d] = plainText[d];
		while (k < lentext1)
		{
			for (int n = 0; n < 5; n++)
				for (int o = 0; o < 5; o++)
				{
					if (txt[k] == 'j') {
						ind_x1 = 3;
						ind_y1 = 2;
					}
					if (txt[k + 1] == 'j') {
						ind_x1 = 3;
						ind_y1 = 2;
					}
					if (txt[k] == Resh[n][o])
					{
						ind_x1 = n;
						ind_y1 = o;
					}
					if (txt[k + 1] == Resh[n][o])
					{
						ind_x2 = n;
						ind_y2 = o;
					}
				}
			// Если буквы находятся в одной строке
			if (ind_x1 == ind_x2)
			{
				if (ind_y1 == 0)
				{
					ResText[k] = Resh[ind_x1][4];
					ResText[k + 1] = Resh[ind_x2][ind_y2 - 1];
					if (ResText[k] == 'i' && collisionIJ[i] == 1) {
						ResText[k] = 'j';
					}
					if (ResText[k + 1] == 'i' && collisionIJ[i] == 1) {
						ResText[k + 1] = 'j';
					}
					i = i + 2;
				}
				else
					if (ind_y2 == 0)
					{
						ResText[k] = Resh[ind_x1][ind_y1 - 1];
						ResText[k + 1] = Resh[ind_x2][4];
						if (ResText[k] == 'i' && collisionIJ[i] == 1) {
							ResText[k] = 'j';
						}
						if (ResText[k + 1] == 'i' && collisionIJ[i] == 1) {
							ResText[k + 1] = 'j';
						}
						i = i + 2;
					}
					else
					{
						ResText[k] = Resh[ind_x1][ind_y1 - 1];
						ResText[k + 1] = Resh[ind_x2][ind_y2 - 1];
						if (ResText[k] == 'i' && collisionIJ[i] == 1) {
							ResText[k] = 'j';
						}
						if (ResText[k + 1] == 'i' && collisionIJ[i] == 1) {
							ResText[k + 1] = 'j';
						}
						i = i + 2;
					}
			}
			// Если буквы находятся в одном столбце
			if (ind_y1 == ind_y2)
			{
				if (ind_x1 == 0)
				{
					ResText[k] = Resh[4][ind_y1];
					ResText[k + 1] = Resh[ind_x2 - 1][ind_y2];
					if (ResText[k] == 'i' && collisionIJ[i] == 1) {
						ResText[k] = 'j';
					}
					if (ResText[k + 1] == 'i' && collisionIJ[i] == 1) {
						ResText[k + 1] = 'j';
					}
					i = i + 2;
				}
				else
					if (ind_x2 == 0)
					{
						ResText[k] = Resh[ind_x1 - 1][ind_y1];
						ResText[k + 1] = Resh[4][ind_y2];
						if (ResText[k] == 'i' && collisionIJ[i] == 1) {
							ResText[k] = 'j';
						}
						if (ResText[k + 1] == 'i' && collisionIJ[i] == 1) {
							ResText[k + 1] = 'j';
						}
						i = i + 2;
					}
					else
					{
						ResText[k] = Resh[ind_x1 - 1][ind_y1];
						ResText[k + 1] = Resh[ind_x2 - 1][ind_y2];
						if (ResText[k] == 'i' && collisionIJ[i] == 1) {
							ResText[k] = 'j';
						}
						if (ResText[k + 1] == 'i' && collisionIJ[i] == 1) {
							ResText[k + 1] = 'j';
						}
						i = i + 2;
					}
			}
			// Если буквы находятся в разных строках и разных столбцах
			if ((ind_x1 != ind_x2) && (ind_y1 != ind_y2))
			{
				ResText[k] = Resh[ind_x1][ind_y2];
				ResText[k + 1] = Resh[ind_x2][ind_y1];
				if (ResText[k] == 'i' && collisionIJ[i] == 1)
					ResText[k] = 'j';

				if (ResText[k + 1] == 'i' && collisionIJ[i] == 1) {
					ResText[k + 1] = 'j';
				}
				i = i + 2;
			}
			if (collisionX[k] != 1)
				res = res + ResText[k];
			if (collisionX[k + 1] != 1)
				res = res + ResText[k + 1];

			k = k + 2;
		}

		if (res == "")
			MessageBox::Show(this, "Текст введен неверно!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			BoxOutput->Text = res;
	}
		
}
		


private: System::Void Decrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	if (BoxInput->Text == "")
		MessageBox::Show(this, "Текст не введен!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else
		if (BoxKey->Text == "")
			MessageBox::Show(this, "Ключ не введен!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			{
				if (RailwayFance->Checked) {
					if (BoxKey->Text == "0")
						MessageBox::Show(this, "Ключ должен быть больше нуля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					else
						Decrypt_fance();
				}
				if (Vigner->Checked) {
					Decrypt_Vigner();
				}
				if (Playfair->Checked) {
					Decrypt_Playfair();
				}
			}
}

private: System::Void Encrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	if(BoxInput->Text == "")
		MessageBox::Show(this, "Текст не введен!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else
		if (BoxKey->Text == "")
			MessageBox::Show(this, "Ключ не введен!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			{
				if (RailwayFance->Checked) {
					if (BoxKey->Text == "0")
						MessageBox::Show(this, "Ключ должен быть больше нуля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					else
						Encrypt_fance();
				}
				if (Vigner->Checked) {
					Encrypt_Vigner(BoxInput->Text);
				}
				if (Playfair->Checked) {
					Encrypt_Playfair();
				}
			}
	

}

	   private: System::Void Vigner_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		  
		   BoxInput->Text = "";
		   BoxOutput->Text = "";
		   BoxKey->Text = "";
		 
		   BoxKey->Visible = true;
		   label1->Visible = true;
	   }
private: System::Void Playfair_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	BoxInput->Text = "";
	BoxOutput->Text = "";
	BoxKey->Text = "";
}
private: System::Void RailwayFance_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	BoxInput->Text = "";
	BoxOutput->Text = "";
	BoxKey->Text = "";
	BoxKey->Visible = true;
	label1->Visible = true;

}
private: System::Void File_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ FileName = "";
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->RestoreDirectory = true;
if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
	FileName = openFileDialog1->FileName;
	try {
		StreamReader^ file = File::OpenText(FileName);
	
		 BoxInput->Text = file->ReadToEnd();
		 file->Close();
	 
	}catch(Exception ^ e){
		MessageBox::Show(this, "ошибка");
	}
	
}


}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (RailwayFance->Checked) {
		StreamWriter^ f = gcnew StreamWriter("E:\\TI\\TI_lab1\\RailwayFance.txt");
		f->Write(BoxOutput->Text);
		BoxInput->Text = "";
		BoxOutput->Text = "";
		f->Close();
		MessageBox::Show(this, "Файл успешно сохранен", "соощение", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	if (Vigner->Checked) {
		StreamWriter^ f = gcnew StreamWriter("E:\\TI\\TI_lab1\\Vigener.txt");
		f->Write(BoxOutput->Text);
		BoxInput->Text = "";
		BoxOutput->Text = "";
		f->Close();
		MessageBox::Show(this, "Файл успешно сохранен", "соощение", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	if (Playfair->Checked) {
		StreamWriter^ f = gcnew StreamWriter("E:\\TI\\TI_lab1\\Playfair.txt");
		f->Write(BoxOutput->Text);
		BoxInput->Text = "";
		BoxOutput->Text = "";
		f->Close();
		MessageBox::Show(this, "Файл успешно сохранен", "соощение", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}


private: System::Void Playfair_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	BoxOutput->Text = "";
	
}
private: System::Void BoxKey_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	BoxOutput->Text = "";
}
private: System::Void BoxInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	BoxOutput->Text = "";
}
};
}

