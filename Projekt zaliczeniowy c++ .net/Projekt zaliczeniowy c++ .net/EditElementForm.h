#pragma once
#include "SQL_Functions.h"

namespace Projektzaliczeniowycnet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o EditElementForm
	/// </summary>
	public ref class EditElementForm : public System::Windows::Forms::Form
	{
	public:
		EditElementForm(void)
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
		~EditElementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		List<String^>^ Producents;
		List<String^>^ Types;
		List<String^>^ Mounts;
		List<String^>^ IDs;
	private: System::Windows::Forms::Button^ Edit_button;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ O1;
	private: System::Windows::Forms::Label^ O2;
	private: System::Windows::Forms::Label^ O3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ Type_combo;
	private: System::Windows::Forms::ComboBox^ Id_combo;
	private: System::Windows::Forms::ComboBox^ Mount_combo;
	private: System::Windows::Forms::TextBox^ Quantity_box;
	private: System::Windows::Forms::TextBox^ O1_box;
	private: System::Windows::Forms::TextBox^ O2_box;
	private: System::Windows::Forms::TextBox^ O3_box;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ Producent_combo;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Edit_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->O1 = (gcnew System::Windows::Forms::Label());
			this->O2 = (gcnew System::Windows::Forms::Label());
			this->O3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Type_combo = (gcnew System::Windows::Forms::ComboBox());
			this->Id_combo = (gcnew System::Windows::Forms::ComboBox());
			this->Mount_combo = (gcnew System::Windows::Forms::ComboBox());
			this->Quantity_box = (gcnew System::Windows::Forms::TextBox());
			this->O1_box = (gcnew System::Windows::Forms::TextBox());
			this->O2_box = (gcnew System::Windows::Forms::TextBox());
			this->O3_box = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Producent_combo = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// Edit_button
			// 
			this->Edit_button->Location = System::Drawing::Point(104, 254);
			this->Edit_button->Name = L"Edit_button";
			this->Edit_button->Size = System::Drawing::Size(75, 23);
			this->Edit_button->TabIndex = 0;
			this->Edit_button->Text = L"Edit";
			this->Edit_button->UseVisualStyleBackColor = true;
			this->Edit_button->Click += gcnew System::EventHandler(this, &EditElementForm::Edit_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Type:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Id num:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 134);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Quantity:";
			// 
			// O1
			// 
			this->O1->AutoSize = true;
			this->O1->Location = System::Drawing::Point(15, 161);
			this->O1->Name = L"O1";
			this->O1->Size = System::Drawing::Size(35, 13);
			this->O1->TabIndex = 4;
			this->O1->Text = L"label4";
			// 
			// O2
			// 
			this->O2->AutoSize = true;
			this->O2->Location = System::Drawing::Point(15, 188);
			this->O2->Name = L"O2";
			this->O2->Size = System::Drawing::Size(35, 13);
			this->O2->TabIndex = 5;
			this->O2->Text = L"label4";
			// 
			// O3
			// 
			this->O3->AutoSize = true;
			this->O3->Location = System::Drawing::Point(15, 215);
			this->O3->Name = L"O3";
			this->O3->Size = System::Drawing::Size(35, 13);
			this->O3->TabIndex = 6;
			this->O3->Text = L"label4";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Mount:";
			// 
			// Type_combo
			// 
			this->Type_combo->FormattingEnabled = true;
			this->Type_combo->Location = System::Drawing::Point(149, 13);
			this->Type_combo->Name = L"Type_combo";
			this->Type_combo->Size = System::Drawing::Size(121, 21);
			this->Type_combo->TabIndex = 8;
			this->Type_combo->SelectedIndexChanged += gcnew System::EventHandler(this, &EditElementForm::Type_combo_SelectedIndexChanged);
			// 
			// Id_combo
			// 
			this->Id_combo->FormattingEnabled = true;
			this->Id_combo->Location = System::Drawing::Point(149, 40);
			this->Id_combo->Name = L"Id_combo";
			this->Id_combo->Size = System::Drawing::Size(121, 21);
			this->Id_combo->TabIndex = 9;
			this->Id_combo->SelectedIndexChanged += gcnew System::EventHandler(this, &EditElementForm::Id_combo_SelectedIndexChanged);
			// 
			// Mount_combo
			// 
			this->Mount_combo->FormattingEnabled = true;
			this->Mount_combo->Location = System::Drawing::Point(149, 68);
			this->Mount_combo->Name = L"Mount_combo";
			this->Mount_combo->Size = System::Drawing::Size(121, 21);
			this->Mount_combo->TabIndex = 10;
			
			// 
			// Quantity_box
			// 
			this->Quantity_box->Location = System::Drawing::Point(149, 127);
			this->Quantity_box->Name = L"Quantity_box";
			this->Quantity_box->Size = System::Drawing::Size(100, 20);
			this->Quantity_box->TabIndex = 11;
			
			// 
			// O1_box
			// 
			this->O1_box->Location = System::Drawing::Point(149, 154);
			this->O1_box->Name = L"O1_box";
			this->O1_box->Size = System::Drawing::Size(100, 20);
			this->O1_box->TabIndex = 12;
			
			// 
			// O2_box
			// 
			this->O2_box->Location = System::Drawing::Point(149, 181);
			this->O2_box->Name = L"O2_box";
			this->O2_box->Size = System::Drawing::Size(100, 20);
			this->O2_box->TabIndex = 13;
			
			// 
			// O3_box
			// 
			this->O3_box->Location = System::Drawing::Point(149, 208);
			this->O3_box->Name = L"O3_box";
			this->O3_box->Size = System::Drawing::Size(100, 20);
			this->O3_box->TabIndex = 14;
			
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 104);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"label5";
			// 
			// Producent_combo
			// 
			this->Producent_combo->FormattingEnabled = true;
			this->Producent_combo->Location = System::Drawing::Point(149, 96);
			this->Producent_combo->Name = L"Producent_combo";
			this->Producent_combo->Size = System::Drawing::Size(121, 21);
			this->Producent_combo->TabIndex = 16;
			
			// 
			// EditElementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 336);
			this->Controls->Add(this->Producent_combo);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->O3_box);
			this->Controls->Add(this->O2_box);
			this->Controls->Add(this->O1_box);
			this->Controls->Add(this->Quantity_box);
			this->Controls->Add(this->Mount_combo);
			this->Controls->Add(this->Id_combo);
			this->Controls->Add(this->Type_combo);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->O3);
			this->Controls->Add(this->O2);
			this->Controls->Add(this->O1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Edit_button);
			this->Name = L"EditElementForm";
			this->Text = L"EditElementForm";
			this->Load += gcnew System::EventHandler(this, &EditElementForm::EditElementForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void EditElementForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Producents = gcnew List<String^>();
		Producents = Load_Producents(Producents);

		Types = gcnew List<String^>();
		Types = Load_Types(Types);

		Mounts = gcnew List<String^>();
		Mounts = Load_Mount(Mounts);

		Producent_combo->Items->AddRange(Producents->ToArray());
		Producent_combo->SelectedIndex = 0;

		Type_combo->Items->AddRange(Types->ToArray());
		Type_combo->SelectedIndex = 0;

		Mount_combo->Items->AddRange(Mounts->ToArray());
		Mount_combo->SelectedIndex = 0;

	}
	private: System::Void Edit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedId = Id_combo->SelectedItem->ToString();
		if (String::IsNullOrEmpty(selectedId))
		{
			MessageBox::Show("Proszê wybraæ ID elementu do edytowania.");
			return;
		}

		try
		{
			// Sprawdzamy, czy u¿ytkownik wprowadzi³ zmiany w formularzu
			String^ newProducent = Producent_combo->SelectedItem->ToString();
			String^ newMount = Mount_combo->SelectedItem->ToString();
			int newQuantity = Convert::ToInt32(Quantity_box->Text);
			float newOptional1 = Convert::ToSingle(O1_box->Text);
			float newOptional2 = Convert::ToSingle(O2_box->Text);
			float newOptional3 = Convert::ToSingle(O3_box->Text);

			UpdateElementInDatabase(selectedId, newProducent, newMount, newQuantity, newOptional1, newOptional2, newOptional3);

			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close(); // Zamykamy okno po zapisaniu zmian
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("B³¹d podczas edytowania elementu: " + ex->Message);
		}

	}
	private: System::Void Type_combo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedType = Type_combo->SelectedItem->ToString();

		label2->Visible = false;
		Id_combo->Visible = false;
		label3->Visible = false;
		Mount_combo->Visible = false;
		label4->Visible = false;
		Quantity_box->Visible = false;
		Producent_combo->Visible = false;
		label5->Visible = false;
		O1->Visible = false;
		O1_box->Visible = false;
		O2->Visible = false;
		O2_box->Visible = false;
		O3->Visible = false;
		O3_box->Visible = false;

		if (selectedType == "Resistor") {
			label2->Visible = true;
			Id_combo->Visible = true;
			label3->Visible = true;
			Mount_combo->Visible = true;
			label4->Visible = true;
			Quantity_box->Visible = true;
			Producent_combo->Visible = true;
			label5->Visible = true;

			O1->Text = "Resistance (Ohms)";
			O2->Text = "Power Rating (Watts)";
			O1->Visible = true;
			O1_box->Visible = true;
			O2->Visible = true;
			O2_box->Visible = true;
		}
		else if (selectedType == "Diode") {
			label2->Visible = true;
			Id_combo->Visible = true;
			label3->Visible = true;
			Mount_combo->Visible = true;
			label4->Visible = true;
			Quantity_box->Visible = true;
			Producent_combo->Visible = true;
			label5->Visible = true;

			O1->Text = "Voltage (Volts)";
			O2->Text = "Current (Amps)";
			O1->Visible = true;
			O1_box->Visible = true;
			O2->Visible = true;
			O2_box->Visible = true;
		}
		else if (selectedType == "Capacitor") {
			label2->Visible = true;
			Id_combo->Visible = true;
			label3->Visible = true;
			Mount_combo->Visible = true;
			label4->Visible = true;
			Quantity_box->Visible = true;
			Producent_combo->Visible = true;
			label5->Visible = true;

			O1->Text = "Capacitance (Farads)";
			O2->Text = "Voltage (Volts)";
			O1->Visible = true;
			O1_box->Visible = true;
			O2->Visible = true;
			O2_box->Visible = true;
		}
		else if (selectedType == "Inductor") {
			label2->Visible = true;
			Id_combo->Visible = true;
			label3->Visible = true;
			Mount_combo->Visible = true;
			label4->Visible = true;
			Quantity_box->Visible = true;
			Producent_combo->Visible = true;
			label5->Visible = true;

			O1->Text = "Inductance (Henries)";
			O2->Text = "Resistance (Ohms)";
			O1->Visible = true;
			O1_box->Visible = true;
			O2->Visible = true;
			O2_box->Visible = true;
		}
		else if (selectedType == "Crystal_Oscillator") {
			label2->Visible = true;
			Id_combo->Visible = true;
			label3->Visible = true;
			Mount_combo->Visible = true;
			label4->Visible = true;
			Quantity_box->Visible = true;
			Producent_combo->Visible = true;
			label5->Visible = true;

			O1->Text = "Frequency (Hz)";
			O1->Visible = true;
			O1_box->Visible = true;
		}
		else if (selectedType == "Microcontroller") {
			label2->Visible = true;
			Id_combo->Visible = true;
			label3->Visible = true;
			Mount_combo->Visible = true;
			label4->Visible = true;
			Quantity_box->Visible = true;
			Producent_combo->Visible = true;
			label5->Visible = true;

			O1->Text = "RAM (KB)";
			O2->Text = "Flash Memory (KB)";
			O3->Text = "Supply Voltage (Volts)";
			O1->Visible = true;
			O1_box->Visible = true;
			O2->Visible = true;
			O2_box->Visible = true;
			O3->Visible = true;
			O3_box->Visible = true;
		}
		IDs = gcnew List<String^>();
		IDs = Load_IDsByType(IDs, Type_combo->SelectedItem->ToString());
		Id_combo->Items->Clear();
		Id_combo->Items->AddRange(IDs->ToArray());
		if (IDs == nullptr)
		{
			Id_combo->SelectedIndex = 0;
		}
	}
private: System::Void Id_combo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Za³ó¿my, ¿e masz ComboBoxy i TextBoxy w formularzu
	String^ selectedElementType = Type_combo->SelectedItem->ToString();
	String^ selectedIdNum = Id_combo->SelectedItem->ToString();

	// Wywo³anie funkcji do uzupe³nienia szczegó³ów elementu
	UpdateElementDetails(selectedElementType, selectedIdNum, Mount_combo, Producent_combo, Quantity_box, O1_box, O2_box, O3_box);
}
};
}
