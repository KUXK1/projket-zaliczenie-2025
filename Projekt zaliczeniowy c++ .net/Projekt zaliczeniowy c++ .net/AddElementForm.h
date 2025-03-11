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
	/// Podsumowanie informacji o AddElementForm
	/// </summary>
	public ref class AddElementForm : public System::Windows::Forms::Form
	{
	public:
		AddElementForm(void)
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
		~AddElementForm()
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

	private: System::Windows::Forms::Button^ Add_confirm;
	private: System::Windows::Forms::ComboBox^ Type_combo;
	private: System::Windows::Forms::ComboBox^ Producent_combo;
	private: System::Windows::Forms::ComboBox^ Mount_combo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ Id_num;
	private: System::Windows::Forms::TextBox^ Quantity;
	private: System::Windows::Forms::TextBox^ O1;
	private: System::Windows::Forms::TextBox^ O2;
	private: System::Windows::Forms::TextBox^ O3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ Quantity_label;
	private: System::Windows::Forms::Label^ O_1;
	private: System::Windows::Forms::Label^ O_2;
	private: System::Windows::Forms::Label^ O_3;
	protected:

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
			this->Add_confirm = (gcnew System::Windows::Forms::Button());
			this->Type_combo = (gcnew System::Windows::Forms::ComboBox());
			this->Producent_combo = (gcnew System::Windows::Forms::ComboBox());
			this->Mount_combo = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Id_num = (gcnew System::Windows::Forms::TextBox());
			this->Quantity = (gcnew System::Windows::Forms::TextBox());
			this->O1 = (gcnew System::Windows::Forms::TextBox());
			this->O2 = (gcnew System::Windows::Forms::TextBox());
			this->O3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Quantity_label = (gcnew System::Windows::Forms::Label());
			this->O_1 = (gcnew System::Windows::Forms::Label());
			this->O_2 = (gcnew System::Windows::Forms::Label());
			this->O_3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Add_confirm
			// 
			this->Add_confirm->Location = System::Drawing::Point(142, 415);
			this->Add_confirm->Name = L"Add_confirm";
			this->Add_confirm->Size = System::Drawing::Size(75, 23);
			this->Add_confirm->TabIndex = 0;
			this->Add_confirm->Text = L"Add";
			this->Add_confirm->UseVisualStyleBackColor = true;
			this->Add_confirm->Click += gcnew System::EventHandler(this, &AddElementForm::Add_confirm_Click);
			// 
			// Type_combo
			// 
			this->Type_combo->FormattingEnabled = true;
			this->Type_combo->Location = System::Drawing::Point(142, 15);
			this->Type_combo->Name = L"Type_combo";
			this->Type_combo->Size = System::Drawing::Size(121, 21);
			this->Type_combo->TabIndex = 1;
			this->Type_combo->SelectedIndexChanged += gcnew System::EventHandler(this, &AddElementForm::Type_combo_SelectedIndexChanged);
			// 
			// Producent_combo
			// 
			this->Producent_combo->FormattingEnabled = true;
			this->Producent_combo->Location = System::Drawing::Point(142, 42);
			this->Producent_combo->Name = L"Producent_combo";
			this->Producent_combo->Size = System::Drawing::Size(121, 21);
			this->Producent_combo->TabIndex = 2;
			// 
			// Mount_combo
			// 
			this->Mount_combo->FormattingEnabled = true;
			this->Mount_combo->Location = System::Drawing::Point(142, 69);
			this->Mount_combo->Name = L"Mount_combo";
			this->Mount_combo->Size = System::Drawing::Size(121, 21);
			this->Mount_combo->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Type:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Producent";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Mount_type";
			// 
			// Id_num
			// 
			this->Id_num->Location = System::Drawing::Point(142, 96);
			this->Id_num->Name = L"Id_num";
			this->Id_num->Size = System::Drawing::Size(100, 20);
			this->Id_num->TabIndex = 7;
			// 
			// Quantity
			// 
			this->Quantity->Location = System::Drawing::Point(142, 122);
			this->Quantity->Name = L"Quantity";
			this->Quantity->Size = System::Drawing::Size(100, 20);
			this->Quantity->TabIndex = 8;
			// 
			// O1
			// 
			this->O1->Location = System::Drawing::Point(142, 151);
			this->O1->Name = L"O1";
			this->O1->Size = System::Drawing::Size(100, 20);
			this->O1->TabIndex = 9;
			// 
			// O2
			// 
			this->O2->Location = System::Drawing::Point(142, 177);
			this->O2->Name = L"O2";
			this->O2->Size = System::Drawing::Size(100, 20);
			this->O2->TabIndex = 10;
			// 
			// O3
			// 
			this->O3->Location = System::Drawing::Point(142, 203);
			this->O3->Name = L"O3";
			this->O3->Size = System::Drawing::Size(100, 20);
			this->O3->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Id number";
			// 
			// Quantity_label
			// 
			this->Quantity_label->AutoSize = true;
			this->Quantity_label->Location = System::Drawing::Point(13, 131);
			this->Quantity_label->Name = L"Quantity_label";
			this->Quantity_label->Size = System::Drawing::Size(46, 13);
			this->Quantity_label->TabIndex = 13;
			this->Quantity_label->Text = L"Quantity";
			// 
			// O_1
			// 
			this->O_1->AutoSize = true;
			this->O_1->Location = System::Drawing::Point(13, 158);
			this->O_1->Name = L"O_1";
			this->O_1->Size = System::Drawing::Size(35, 13);
			this->O_1->TabIndex = 14;
			this->O_1->Text = L"label5";
			// 
			// O_2
			// 
			this->O_2->AutoSize = true;
			this->O_2->Location = System::Drawing::Point(13, 185);
			this->O_2->Name = L"O_2";
			this->O_2->Size = System::Drawing::Size(35, 13);
			this->O_2->TabIndex = 15;
			this->O_2->Text = L"label5";
			this->O_2->Click += gcnew System::EventHandler(this, &AddElementForm::O_2_Click);
			// 
			// O_3
			// 
			this->O_3->AutoSize = true;
			this->O_3->Location = System::Drawing::Point(13, 212);
			this->O_3->Name = L"O_3";
			this->O_3->Size = System::Drawing::Size(35, 13);
			this->O_3->TabIndex = 16;
			this->O_3->Text = L"label5";
			// 
			// AddElementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(398, 489);
			this->Controls->Add(this->O_3);
			this->Controls->Add(this->O_2);
			this->Controls->Add(this->O_1);
			this->Controls->Add(this->Quantity_label);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->O3);
			this->Controls->Add(this->O2);
			this->Controls->Add(this->O1);
			this->Controls->Add(this->Quantity);
			this->Controls->Add(this->Id_num);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Mount_combo);
			this->Controls->Add(this->Producent_combo);
			this->Controls->Add(this->Type_combo);
			this->Controls->Add(this->Add_confirm);
			this->Name = L"AddElementForm";
			this->Text = L"AddElementForm";
			this->Load += gcnew System::EventHandler(this, &AddElementForm::AddElementForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddElementForm_Load(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void Add_confirm_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (Type_combo->SelectedItem->ToString() != "None" && Producent_combo->SelectedItem->ToString() != "None") {
				String^ idNum = Id_num->Text;
				String^ typeName = Type_combo->SelectedItem->ToString();
				String^ producentName = Producent_combo->SelectedItem->ToString();
				String^ mountName = Mount_combo->SelectedItem->ToString();
				int quantity = Int32::Parse(Quantity->Text);
				float optional1 = String::IsNullOrEmpty(O1->Text) ? 0.0f : Single::Parse(O1->Text);
				float optional2 = String::IsNullOrEmpty(O2->Text) ? 0.0f : Single::Parse(O2->Text);
				float optional3 = String::IsNullOrEmpty(O3->Text) ? 0.0f : Single::Parse(O3->Text);

				AddElementToDatabase(idNum, typeName, producentName, mountName, quantity, optional1, optional2, optional3);

				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			}
			else {
				MessageBox::Show("Proszê wybraæ typ i producenta!", "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Wyst¹pi³ b³¹d: " + ex->Message, "B³¹d", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	private: System::Void O_2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Type_combo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedType = Type_combo->SelectedItem->ToString();

		O_1->Visible = false;
		O_2->Visible = false;
		O_3->Visible = false;
		O1->Visible = false;
		O2->Visible = false;
		O3->Visible = false;

		if (selectedType == "Resistor")
		{
			O_1->Text = "Resistance (Ohms)";
			O_2->Text = "Power Rating (Watts)";
			O_3->Visible = false; 
			O1->Visible = true;
			O2->Visible = true;

			O_1->Visible = true;
			O_2->Visible = true;
		}
		else if (selectedType == "Diode")
		{
			O_1->Text = "Voltage (Volts)";
			O_2->Text = "Current (Amps)";
			O_3->Visible = false; 
			O1->Visible = true;
			O2->Visible = true;

			O_1->Visible = true;
			O_2->Visible = true;
		}
		else if (selectedType == "Capacitor")
		{
			O_1->Text = "Capacitance (Farads)";
			O_2->Text = "Voltage (Volts)";
			O_3->Visible = false; 
			O1->Visible = true;
			O2->Visible = true;

			O_1->Visible = true;
			O_2->Visible = true;
		}
		else if (selectedType == "Inductor")
		{
			O_1->Text = "Inductance (Henries)";
			O_2->Text = "Resistance (Ohms)";
			O_3->Visible = false;
			O1->Visible = true;
			O2->Visible = true;

			O_1->Visible = true;
			O_2->Visible = true;
		}
		else if (selectedType == "Crystal_Oscillator")
		{
			O_1->Text = "Frequency (Hz)";
			O_2->Visible = false;
			O_3->Visible = false;
			O1->Visible = true;

			O_1->Visible = true;
		}
		else if (selectedType == "Microcontroller")
		{
			O_1->Text = "RAM (KB)";
			O_2->Text = "Flash Memory (KB)";
			O_3->Text = "Supply Voltage (Volts)";
			O1->Visible = true;
			O2->Visible = true;
			O3->Visible = true;

			O_1->Visible = true;
			O_2->Visible = true;
			O_3->Visible = true;
		}
		else
		{
			O_1->Visible = false;
			O_2->Visible = false;
			O_3->Visible = false;
			O1->Visible = false;
			O2->Visible = false;
			O3->Visible = false;
		}
	}
};
}
