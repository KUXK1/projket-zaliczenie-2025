#pragma once
#include "SQL_Functions.h";
namespace Projektzaliczeniowycnet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm1
	/// </summary>
	public ref class DeleteElementForm : public System::Windows::Forms::Form
	{
	public:
		DeleteElementForm(void)
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
		~DeleteElementForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		List<String^>^ Types;
		List<String^>^ IDs;
	private: System::Windows::Forms::Button^ Delete_Ok;
	private: System::Windows::Forms::Label^ Type_combo;
	private: System::Windows::Forms::Label^ Id_combo;
	private: System::Windows::Forms::ComboBox^ Type;
	private: System::Windows::Forms::ComboBox^ Id;
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
			this->Delete_Ok = (gcnew System::Windows::Forms::Button());
			this->Type_combo = (gcnew System::Windows::Forms::Label());
			this->Id_combo = (gcnew System::Windows::Forms::Label());
			this->Type = (gcnew System::Windows::Forms::ComboBox());
			this->Id = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// Delete_Ok
			// 
			this->Delete_Ok->Location = System::Drawing::Point(103, 202);
			this->Delete_Ok->Name = L"Delete_Ok";
			this->Delete_Ok->Size = System::Drawing::Size(75, 23);
			this->Delete_Ok->TabIndex = 0;
			this->Delete_Ok->Text = L"Delete";
			this->Delete_Ok->UseVisualStyleBackColor = true;
			this->Delete_Ok->Click += gcnew System::EventHandler(this, &DeleteElementForm::Delete_Ok_Click);
			// 
			// Type_combo
			// 
			this->Type_combo->AutoSize = true;
			this->Type_combo->Location = System::Drawing::Point(12, 17);
			this->Type_combo->Name = L"Type_combo";
			this->Type_combo->Size = System::Drawing::Size(34, 13);
			this->Type_combo->TabIndex = 1;
			this->Type_combo->Text = L"Type:";
			// 
			// Id_combo
			// 
			this->Id_combo->AutoSize = true;
			this->Id_combo->Location = System::Drawing::Point(12, 45);
			this->Id_combo->Name = L"Id_combo";
			this->Id_combo->Size = System::Drawing::Size(61, 13);
			this->Id_combo->TabIndex = 2;
			this->Id_combo->Text = L"ID Number:";
			// 
			// Type
			// 
			this->Type->FormattingEnabled = true;
			this->Type->Location = System::Drawing::Point(103, 9);
			this->Type->Name = L"Type";
			this->Type->Size = System::Drawing::Size(121, 21);
			this->Type->TabIndex = 3;
			this->Type->SelectedIndexChanged += gcnew System::EventHandler(this, &DeleteElementForm::Type_SelectedIndexChanged);
			// 
			// Id
			// 
			this->Id->FormattingEnabled = true;
			this->Id->Location = System::Drawing::Point(103, 37);
			this->Id->Name = L"Id";
			this->Id->Size = System::Drawing::Size(121, 21);
			this->Id->TabIndex = 4;
			// 
			// DeleteElementForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->Id);
			this->Controls->Add(this->Type);
			this->Controls->Add(this->Id_combo);
			this->Controls->Add(this->Type_combo);
			this->Controls->Add(this->Delete_Ok);
			this->Name = L"DeleteElementForm";
			this->Text = L"DeleteElementForm";
			this->Load += gcnew System::EventHandler(this, &DeleteElementForm::DeleteElementForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Delete_Ok_Click(System::Object^ sender, System::EventArgs^ e) {\
		String^ selectedId = Id->SelectedItem->ToString(); // Pobieramy wybrane ID

		   // Sprawdzamy, czy wybrano jakieœ ID
		   if (String::IsNullOrEmpty(selectedId))
		   {
			   MessageBox::Show("Proszê wybraæ ID elementu do usuniêcia.");
			   return; // Jeœli nie wybrano ID, przerywamy dzia³anie funkcji
		   }

		   try
		   {
			   // Wywo³anie funkcji do usuniêcia elementu z bazy danych
			   DeleteElementFromDatabase(selectedId);

				   this->DialogResult = System::Windows::Forms::DialogResult::OK;
				   this->Close();
		   }
		   catch (Exception^ ex)
		   {
			   MessageBox::Show("B³¹d podczas usuwania elementu: " + ex->Message);
		   }
	}
	private: System::Void DeleteElementForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Types = gcnew List<String^>();
		Types = Load_Types(Types);
		
		Type->Items->AddRange(Types->ToArray());
		Type->SelectedIndex = 0;
		Id->Visible = false;
		Id_combo->Visible = false;

	}
	private: System::Void Type_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		IDs = gcnew List<String^>();
		IDs = Load_IDsByType(IDs, Type->SelectedItem->ToString());
		Id->Items->Clear();
		Id->Items->AddRange(IDs->ToArray());
		if (IDs == nullptr)
		{
			Id->SelectedIndex = 0;
		}
		
		Id->Visible = true;
		Id_combo->Visible = true;
	}
};
}
