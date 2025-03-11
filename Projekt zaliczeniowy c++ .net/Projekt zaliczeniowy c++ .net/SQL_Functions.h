#pragma once
#include "Elements.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Windows::Forms;

List<String^>^ Load_Producents(List<String^>^ list);
List<String^>^ Load_Types(List<String^>^ list);
List<String^>^ Load_Mount(List<String^>^ list);
List<String^>^ Load_IDsByType(List<String^>^ list, String^ elementType);
List<String^>^ Load_Orders(bool x);
void PopulateDataGrid(DataGridView^ dataGridView, array<Elements^>^ elementsArray, String^ By_type, String^ By_Prod, String^ By_IDPattern);
array<Elements^>^ LoadElementsFromDatabase(array<Elements^>^ elementsArray);
void AddElementToDatabase(
    String^ idNum,
    String^ typeName,
    String^ producentName,
    String^ mountName,
    int quantity,
    float optional1,
    float optional2,
    float optional3
);
void DeleteElementFromDatabase(String^ idNum);
void UpdateElementDetails(String^ elementType, String^ idNum, ComboBox^ mountCombo, ComboBox^ producentCombo, TextBox^ quantityBox, TextBox^ optional1Box, TextBox^ optional2Box, TextBox^ optional3Box);
void UpdateElementInDatabase(String^ idNum, String^ producentName, String^ mountName, int quantity, float optional1, float optional2, float optional3);
void MarkOrderAsShippedAndUpdateStock(ComboBox^ comboBox, DataGridView^ dataGrid);
void Load_OrderDetails(Label^ label, DataGridView^ dataGridView, ComboBox^ comboBox);
void SendOrderConfirmationWithAttachment(DataGridView^ dataGridView, Label^ orderLabel);


