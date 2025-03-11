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
	/// Podsumowanie informacji o OrdersMenu
	/// </summary>
	public ref class OrdersMenu : public System::Windows::Forms::Form
	{
	public:
		OrdersMenu(void)
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
		~OrdersMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		List<String^>^ Shipped;
		List<String^>^ NaShipped;
		bool isChangingSelection = false;
	private: System::Windows::Forms::ComboBox^ orders_shipped;
	private: System::Windows::Forms::ComboBox^ pending_orders;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ Order;
	private: System::Windows::Forms::Label^ Order_info;
	private: System::Windows::Forms::Button^ Accept_button;


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
			this->orders_shipped = (gcnew System::Windows::Forms::ComboBox());
			this->pending_orders = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Order = (gcnew System::Windows::Forms::DataGridView());
			this->Order_info = (gcnew System::Windows::Forms::Label());
			this->Accept_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Order))->BeginInit();
			this->SuspendLayout();
			// 
			// orders_shipped
			// 
			this->orders_shipped->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->orders_shipped->FormattingEnabled = true;
			this->orders_shipped->Location = System::Drawing::Point(180, 533);
			this->orders_shipped->Name = L"orders_shipped";
			this->orders_shipped->Size = System::Drawing::Size(235, 21);
			this->orders_shipped->TabIndex = 0;
			this->orders_shipped->SelectedIndexChanged += gcnew System::EventHandler(this, &OrdersMenu::orders_shipped_SelectedIndexChanged);
			// 
			// pending_orders
			// 
			this->pending_orders->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->pending_orders->FormattingEnabled = true;
			this->pending_orders->Location = System::Drawing::Point(180, 561);
			this->pending_orders->Name = L"pending_orders";
			this->pending_orders->Size = System::Drawing::Size(235, 21);
			this->pending_orders->TabIndex = 1;
			this->pending_orders->SelectedIndexChanged += gcnew System::EventHandler(this, &OrdersMenu::pending_orders_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(125, 541);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Shipped:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(128, 568);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Pending:";
			// 
			// Order
			// 
			this->Order->AllowUserToAddRows = false;
			this->Order->AllowUserToDeleteRows = false;
			this->Order->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Order->Location = System::Drawing::Point(12, 119);
			this->Order->Name = L"Order";
			this->Order->ReadOnly = true;
			this->Order->Size = System::Drawing::Size(465, 401);
			this->Order->TabIndex = 4;
			this->Order->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &OrdersMenu::dataGridView1_CellContentClick);
			// 
			// Order_info
			// 
			this->Order_info->AutoSize = true;
			this->Order_info->Location = System::Drawing::Point(12, 28);
			this->Order_info->Name = L"Order_info";
			this->Order_info->Size = System::Drawing::Size(0, 13);
			this->Order_info->TabIndex = 5;
			this->Order_info->Click += gcnew System::EventHandler(this, &OrdersMenu::Order_info_Click);
			// 
			// Accept_button
			// 
			this->Accept_button->Location = System::Drawing::Point(12, 541);
			this->Accept_button->Name = L"Accept_button";
			this->Accept_button->Size = System::Drawing::Size(75, 23);
			this->Accept_button->TabIndex = 6;
			this->Accept_button->Text = L"Send";
			this->Accept_button->UseVisualStyleBackColor = true;
			this->Accept_button->Click += gcnew System::EventHandler(this, &OrdersMenu::Accept_button_Click);
			// 
			// OrdersMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 633);
			this->Controls->Add(this->Accept_button);
			this->Controls->Add(this->Order_info);
			this->Controls->Add(this->Order);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pending_orders);
			this->Controls->Add(this->orders_shipped);
			this->Name = L"OrdersMenu";
			this->Text = L"OrdersMenu";
			this->Load += gcnew System::EventHandler(this, &OrdersMenu::OrdersMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Order))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void OrdersMenu_Load(System::Object^ sender, System::EventArgs^ e) {
	Shipped = Load_Orders(true);
	NaShipped = Load_Orders(false);

	pending_orders->Items->AddRange(NaShipped->ToArray());
	

	orders_shipped->Items->AddRange(Shipped->ToArray());
	Accept_button->Visible = false;
	
}
private: System::Void Order_info_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void pending_orders_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isChangingSelection) return;
	isChangingSelection = true;
	Load_OrderDetails(Order_info, Order, pending_orders);
	orders_shipped->SelectedIndex = -1;
	isChangingSelection = false;
	Accept_button->Visible = true;
}
private: System::Void Accept_button_Click(System::Object^ sender, System::EventArgs^ e) {
	MarkOrderAsShippedAndUpdateStock(pending_orders, Order);
	SendOrderConfirmationWithAttachment(Order, Order_info);
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
}
private: System::Void orders_shipped_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isChangingSelection) return;
	isChangingSelection = true;
	Load_OrderDetails(Order_info, Order, orders_shipped);
	pending_orders->SelectedIndex = -1;
	isChangingSelection = false;
	Accept_button->Visible = false;
}
};
}
