#pragma once
#include "Elements.h"
#include "SQL_Functions.h"
#include "AddElementForm.h"
#include "DeleteElementForm.h"
#include "EditElementForm.h"
#include "OrdersMenu.h"

namespace Projektzaliczeniowycnet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		// Deklaracja dynamicznej tablicy (listy) przechowuj¹cej obiekty String^
		List<String^>^ Producents;
		List<String^>^ Types;
		array<Elements^>^ elementsArray;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ComboBox^ Filtr_by_type;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ Filtr_by_prod;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Add_form_button;
	private: System::Windows::Forms::TextBox^ Search;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ Remove_form_button;
	private: System::Windows::Forms::Button^ Edit_form_button;
	private: System::Windows::Forms::Button^ Orders;

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Filtr_by_type = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Filtr_by_prod = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Add_form_button = (gcnew System::Windows::Forms::Button());
			this->Search = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Remove_form_button = (gcnew System::Windows::Forms::Button());
			this->Edit_form_button = (gcnew System::Windows::Forms::Button());
			this->Orders = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 23);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(844, 568);
			this->dataGridView1->TabIndex = 1;
			// 
			// Filtr_by_type
			// 
			this->Filtr_by_type->FormattingEnabled = true;
			this->Filtr_by_type->Location = System::Drawing::Point(987, 40);
			this->Filtr_by_type->Name = L"Filtr_by_type";
			this->Filtr_by_type->Size = System::Drawing::Size(121, 21);
			this->Filtr_by_type->TabIndex = 3;
			this->Filtr_by_type->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Filtr_by_type_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(887, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Filtr by type:";
			// 
			// Filtr_by_prod
			// 
			this->Filtr_by_prod->FormattingEnabled = true;
			this->Filtr_by_prod->Location = System::Drawing::Point(987, 67);
			this->Filtr_by_prod->Name = L"Filtr_by_prod";
			this->Filtr_by_prod->Size = System::Drawing::Size(121, 21);
			this->Filtr_by_prod->TabIndex = 5;
			this->Filtr_by_prod->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Filtr_by_prod_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(887, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Filtr by producent:";
			// 
			// Add_form_button
			// 
			this->Add_form_button->Location = System::Drawing::Point(890, 242);
			this->Add_form_button->Name = L"Add_form_button";
			this->Add_form_button->Size = System::Drawing::Size(218, 23);
			this->Add_form_button->TabIndex = 7;
			this->Add_form_button->Text = L"Add component";
			this->Add_form_button->UseVisualStyleBackColor = true;
			this->Add_form_button->Click += gcnew System::EventHandler(this, &MyForm::Add_form_button_Click);
			// 
			// Search
			// 
			this->Search->Location = System::Drawing::Point(987, 95);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(100, 20);
			this->Search->TabIndex = 8;
			this->Search->TextChanged += gcnew System::EventHandler(this, &MyForm::Search_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(890, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Search by id num:";
			// 
			// Remove_form_button
			// 
			this->Remove_form_button->Location = System::Drawing::Point(890, 300);
			this->Remove_form_button->Name = L"Remove_form_button";
			this->Remove_form_button->Size = System::Drawing::Size(218, 23);
			this->Remove_form_button->TabIndex = 10;
			this->Remove_form_button->Text = L"Remove component";
			this->Remove_form_button->UseVisualStyleBackColor = true;
			this->Remove_form_button->Click += gcnew System::EventHandler(this, &MyForm::Remove_form_button_Click);
			// 
			// Edit_form_button
			// 
			this->Edit_form_button->Location = System::Drawing::Point(890, 271);
			this->Edit_form_button->Name = L"Edit_form_button";
			this->Edit_form_button->Size = System::Drawing::Size(218, 23);
			this->Edit_form_button->TabIndex = 11;
			this->Edit_form_button->Text = L"Edit component";
			this->Edit_form_button->UseVisualStyleBackColor = true;
			this->Edit_form_button->Click += gcnew System::EventHandler(this, &MyForm::Edit_form_button_Click);
			// 
			// Orders
			// 
			this->Orders->Location = System::Drawing::Point(890, 330);
			this->Orders->Name = L"Orders";
			this->Orders->Size = System::Drawing::Size(218, 23);
			this->Orders->TabIndex = 12;
			this->Orders->Text = L"Orders";
			this->Orders->UseVisualStyleBackColor = true;
			this->Orders->Click += gcnew System::EventHandler(this, &MyForm::Orders_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1146, 623);
			this->Controls->Add(this->Orders);
			this->Controls->Add(this->Edit_form_button);
			this->Controls->Add(this->Remove_form_button);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Search);
			this->Controls->Add(this->Add_form_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Filtr_by_prod);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Filtr_by_type);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"w";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Producents = gcnew List<String^>();
		Producents = Load_Producents(Producents);
		Types = gcnew List<String^>();
		Types = Load_Types(Types);

		elementsArray = gcnew array<Elements^>(20000);
		elementsArray = LoadElementsFromDatabase(elementsArray);

		Filtr_by_prod->Items->AddRange(Producents->ToArray());
		Filtr_by_prod->SelectedIndex = 0;
		Filtr_by_type->Items->AddRange(Types->ToArray());
		Filtr_by_type->SelectedIndex = 0;

		dataGridView1->ReadOnly = true;
		PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
	}

	private: System::Void Filtr_by_type_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Filtr_by_type->SelectedItem != nullptr && Filtr_by_prod->SelectedItem != nullptr) {
			PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
		}
	}

	private: System::Void Filtr_by_prod_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (Filtr_by_type->SelectedItem != nullptr && Filtr_by_prod->SelectedItem != nullptr) {
			PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
		}
	}

	private: System::Void Add_form_button_Click(System::Object^ sender, System::EventArgs^ e) {
		AddElementForm^ addForm = gcnew AddElementForm();
		if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			elementsArray = LoadElementsFromDatabase(elementsArray);
			PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
		}
	}

	private: System::Void Search_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
	}

	private: System::Void Remove_form_button_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteElementForm^ addForm = gcnew DeleteElementForm();
		if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			elementsArray = LoadElementsFromDatabase(elementsArray);
			PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
		}
	}

	private: System::Void Orders_Click(System::Object^ sender, System::EventArgs^ e) {
		OrdersMenu^ addForm = gcnew OrdersMenu();

		if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			elementsArray = LoadElementsFromDatabase(elementsArray);
			PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
		}
	}



	private: System::Void Edit_form_button_Click(System::Object^ sender, System::EventArgs^ e) {
		EditElementForm^ addForm = gcnew EditElementForm();
		if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			elementsArray = LoadElementsFromDatabase(elementsArray);
			PopulateDataGrid(dataGridView1, elementsArray, Filtr_by_type->SelectedItem->ToString(), Filtr_by_prod->SelectedItem->ToString(), Search->Text);
		}
	}
	};
}
