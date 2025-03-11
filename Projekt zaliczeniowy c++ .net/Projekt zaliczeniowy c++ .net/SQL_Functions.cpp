#include "SQL_Functions.h"
#include "Elements.h"
using namespace System::Data; // DataTable, DataRow
using namespace System::Windows::Forms; // DataGrid
using namespace MySql::Data::MySqlClient;
using namespace System::Net::Mail; // MailMessage, Attachment, SmtpClient
using namespace System::Drawing; // Bitmap, Graphics, Color
using namespace System::IO; // File, FileInfo
// Funkcja ³¹cz¹ca z baz¹ danych
MySqlConnection^ GetConnection()
{
    String^ server = "localhost";
    String^ username = "root";
    String^ password = "";
    String^ database = "project_2024";

    MySqlConnection^ connection = gcnew MySqlConnection(
        "Server=" + server + ";User ID=" + username + ";Password=" + password + ";Database=" + database + ";"
    );

    connection->Open();
    return connection;
}

// Funkcja wykonuj¹ca zapytanie SQL
static MySqlDataReader^ ExecuteQuery(MySqlConnection^ connection, String^ query)
{
    MySqlCommand^ command = gcnew MySqlCommand(query, connection);
    return command->ExecuteReader();
}
// Funkcja zapelniajaca liste producentow;
List<String^>^ Load_Producents(List<String^>^ list)
{
    String^ query = "SELECT * FROM elements_producents";
    List<String^>^ producents = gcnew List<String^>();
    MySqlConnection^ connection = GetConnection();

    try {
        producents->Add("None");
        MySqlDataReader^ reader = ExecuteQuery(connection, query);
        while (reader->Read()) {
            producents->Add(reader["producent_name"]->ToString());
        }
    }
    catch (Exception^ e) {
        Console::WriteLine("B³¹d: " + e->Message);
    }
    finally {
        connection->Close();
    }

    return producents;
}
// Funkcja zapelniajaca liste typow;
List<String^>^ Load_Types(List<String^>^ list)
{
    String^ query = "SELECT name FROM elements_types";
    List<String^>^ producents = gcnew List<String^>();
    MySqlConnection^ connection = GetConnection();

    try {
        producents->Add("None");
        MySqlDataReader^ reader = ExecuteQuery(connection, query);
        while (reader->Read()) {
            producents->Add(reader["name"]->ToString());
        }
    }
    catch (Exception^ e) {
        Console::WriteLine("B³¹d: " + e->Message);
    }
    finally {
        connection->Close();
    }

    return producents;
}
List<String^>^ Load_Mount(List<String^>^ list)
{
    String^ query = "SELECT elements_mounts.Mout_type FROM `elements_mounts`";
    List<String^>^ producents = gcnew List<String^>();
    MySqlConnection^ connection = GetConnection();

    try {
        MySqlDataReader^ reader = ExecuteQuery(connection, query);
        while (reader->Read()) {
            producents->Add(reader["Mout_type"]->ToString());
        }
    }
    catch (Exception^ e) {
        Console::WriteLine("B³¹d: " + e->Message);
    }
    finally {
        connection->Close();
    }

    return producents;
}

List<String^>^ Load_IDsByType(List<String^>^ list, String^ elementType)
{
    // Po³¹czenie z baz¹ danych
    MySqlConnection^ connection = GetConnection();

    // Tworzymy zapytanie SQL, które pobierze id_num dla wskazanego typu elementu
    String^ query = "SELECT e.Id_num FROM elements e INNER JOIN elements_types t ON e.Element_type = t.Id_type WHERE t.Name = '" + elementType + "'";

    // Wykonaj zapytanie
    MySqlDataReader^ reader = ExecuteQuery(connection, query);
    list->Clear();
    // Zczytujemy dane z bazy
    while (reader->Read())
    {
        String^ idNum = reader["Id_num"]->ToString();
        list->Add(idNum); // Dodajemy id_num do listy
    }

    // Zamykamy po³¹czenie
    reader->Close();
    connection->Close();

    // Zwracamy wype³nion¹ listê
    return list;
}
// Funkcja zapelniajaca liste komponentów;
void PopulateDataGrid(DataGridView^ dataGridView, array<Elements^>^ elementsArray, String^ By_type, String^ By_Prod, String^ By_IDPattern)
{
    DataSet^ dataSet = gcnew DataSet();
    DataTable^ dataTable = gcnew DataTable("ElementsTable");

    dataTable->Columns->Add("Type", String::typeid);
    dataTable->Columns->Add("ID Number", String::typeid);
    dataTable->Columns->Add("Producent", String::typeid);
    dataTable->Columns->Add("Mount Type", String::typeid);
    dataTable->Columns->Add("Quantity", String::typeid);
    dataTable->Columns->Add("Parameter 1", String::typeid);
    dataTable->Columns->Add("Parameter 2", String::typeid);
    dataTable->Columns->Add("Parameter 3", String::typeid);

    // Iteracja po tablicy elementów
    for each (Elements ^ elem in elementsArray)
    {
        if (elem != nullptr) // Sprawdzenie, czy element nie jest nullptr
        {
            // Sprawdzenie typu, producenta oraz wzorca ID (jak LIKE)
            if ((elem->ToStringArray()[0] == By_type || By_type == "None") &&
                (elem->ToStringArray()[2] == By_Prod || By_Prod == "None"))
            {
                // Porównanie ID z wzorcem - u¿ywamy Contains do "LIKE"
                if (By_IDPattern == "None" || elem->ToStringArray()[1]->ToLower()->Contains(By_IDPattern->ToLower()))
                {
                    dataTable->Rows->Add(elem->ToStringArray());
                }
            }
        }
    }

    dataSet->Tables->Add(dataTable);

    // Przypisanie DataSource
    dataGridView->DataSource = dataSet;
    dataGridView->DataMember = "ElementsTable";
}

array<Elements^>^ LoadElementsFromDatabase(array<Elements^>^ elementsArray)
{
    // Po³¹cz z baz¹ danych
    MySqlConnection^ connection = GetConnection();

    // Zapytanie SQL do pobierania danych z tabeli elements i powi¹zanych tabel
    String^ query = R"(
        SELECT 
            e.ID AS ElementID,
            e.Id_num AS ElementNumber,
            p.producent_name AS Producent,
            m.Mout_type AS MountType,
            e.Quantity,
            e.Optional1,
            e.Optional2,
            e.Optional3,
            t.Name AS ElementType
        FROM 
            elements e
        INNER JOIN 
            elements_producents p ON e.Producent_id = p.Id_producent
        INNER JOIN 
            elements_mounts m ON e.Mount_type = m.ID
        INNER JOIN 
            elements_types t ON e.Element_type = t.Id_type
    )";

    // Wykonaj zapytanie SQL
    MySqlDataReader^ reader = ExecuteQuery(connection, query);

    // Indeks do wstawiania elementów do tablicy
    int index = 0;

    // Przetwarzanie wyników
    while (reader->Read() && index < elementsArray->Length)
    {
        String^ id_num = reader["ElementNumber"]->ToString();
        String^ producent = reader["Producent"]->ToString();
        String^ mount_type = reader["MountType"]->ToString();
        String^ element_type = reader["ElementType"]->ToString();
        int quantity = Convert::ToInt32(reader["Quantity"]);
        float optional1 = reader["Optional1"] != DBNull::Value ? Convert::ToSingle(reader["Optional1"]) : 0.0f;
        float optional2 = reader["Optional2"] != DBNull::Value ? Convert::ToSingle(reader["Optional2"]) : 0.0f;
        float optional3 = reader["Optional3"] != DBNull::Value ? Convert::ToSingle(reader["Optional3"]) : 0.0f;

        // Tworzenie obiektów w zale¿noœci od typu elementu
        if (element_type == "Resistor")
        {
            elementsArray[index] = gcnew Resistor(id_num, producent, mount_type, quantity, optional1, optional2);
        }
        else if (element_type == "Capacitor")
        {
            elementsArray[index] = gcnew Capacitor(id_num, producent, mount_type, quantity, optional1, optional2);
        }
        else if (element_type == "Crystal_Oscillator")
        {
            elementsArray[index] = gcnew Crystal_Oscillator(id_num, producent, mount_type, quantity, optional1);
        }
        else if (element_type == "Inductor")
        {
            elementsArray[index] = gcnew Inductor(id_num, producent, mount_type, quantity, optional1, optional2);
        }
        else if (element_type == "Microcontroller")
        {
            elementsArray[index] = gcnew Microcontroller(id_num, producent, mount_type, quantity, (int)optional1, (int)optional2, optional3);
        }
        else if (element_type == "Diode")
        {
            elementsArray[index] = gcnew Diode(id_num, producent, mount_type, quantity, optional1, optional2);
        }

        // Zwiêksz indeks
        index++;
    }

    // Zamknij po³¹czenie
    reader->Close();
    connection->Close();

    // Zwróæ uzupe³nion¹ tablicê
    return elementsArray;
}



void AddElementToDatabase(
    String^ idNum,
    String^ typeName,
    String^ producentName,
    String^ mountName,
    int quantity,
    float optional1,
    float optional2,
    float optional3
) {
    try {
        MySqlConnection^ connection = GetConnection();

        String^ getProducentIdQuery = "SELECT Id_producent FROM elements_producents WHERE producent_name = @ProducentName";
        String^ getTypeIdQuery = "SELECT Id_type FROM elements_types WHERE Name = @TypeName";
        String^ getMountIdQuery = "SELECT ID FROM elements_mounts WHERE Mout_type = @MountName";

        MySqlCommand^ getProducentIdCmd = gcnew MySqlCommand(getProducentIdQuery, connection);
        getProducentIdCmd->Parameters->AddWithValue("@ProducentName", producentName);
        int producentId = Convert::ToInt32(getProducentIdCmd->ExecuteScalar());

        MySqlCommand^ getTypeIdCmd = gcnew MySqlCommand(getTypeIdQuery, connection);
        getTypeIdCmd->Parameters->AddWithValue("@TypeName", typeName);
        int typeId = Convert::ToInt32(getTypeIdCmd->ExecuteScalar());

        MySqlCommand^ getMountIdCmd = gcnew MySqlCommand(getMountIdQuery, connection);
        getMountIdCmd->Parameters->AddWithValue("@MountName", mountName);
        int mountId = Convert::ToInt32(getMountIdCmd->ExecuteScalar());

        String^ insertQuery = "INSERT INTO elements (Id_num, Producent_id, Mount_type, Quantity, Optional1, Optional2, Optional3, Element_type) " "VALUES (@IdNum, @ProducentId, @MountId, @Quantity, @Optional1, @Optional2, @Optional3, @TypeId) ""ON DUPLICATE KEY UPDATE " "Quantity = Quantity + @Quantity";

        MySqlCommand^ insertCmd = gcnew MySqlCommand(insertQuery, connection);
        insertCmd->Parameters->AddWithValue("@IdNum", idNum);
        insertCmd->Parameters->AddWithValue("@ProducentId", producentId);
        insertCmd->Parameters->AddWithValue("@MountId", mountId);
        insertCmd->Parameters->AddWithValue("@Quantity", quantity);
        insertCmd->Parameters->AddWithValue("@Optional1", optional1);
        insertCmd->Parameters->AddWithValue("@Optional2", optional2);
        insertCmd->Parameters->AddWithValue("@Optional3", optional3);
        insertCmd->Parameters->AddWithValue("@TypeId", typeId);

        insertCmd->ExecuteNonQuery();

        connection->Close();
        MessageBox::Show("Element zosta³ dodady do bazy danych.");
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Wyst¹pi³ b³¹d podczas dodawania elementu: " + ex->Message);
    }
}

void DeleteElementFromDatabase(String^ idNum)
{
    try
    {

        MySqlConnection^ connection = GetConnection();

        String^ deleteQuery = "DELETE FROM elements WHERE Id_num = @Id_num";
        MySqlCommand^ command = gcnew MySqlCommand(deleteQuery, connection);

        command->Parameters->AddWithValue("@Id_num", idNum);

        int rowsAffected = command->ExecuteNonQuery(); 

        if (rowsAffected > 0)
        {
            MessageBox::Show("Element zosta³ usuniêty z bazy danych.");
        }
        else
        {
            MessageBox::Show("Nie znaleziono elementu do usuniêcia.");
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("B³¹d podczas usuwania elementu: " + ex->Message);
    }
}

void UpdateElementDetails(String^ elementType, String^ idNum, ComboBox^ mountCombo, ComboBox^ producentCombo, TextBox^ quantityBox, TextBox^ optional1Box, TextBox^ optional2Box, TextBox^ optional3Box)
{
    MySqlConnection^ connection = GetConnection();

    String^ query = "SELECT e.Quantity, e.Optional1, e.Optional2, e.Optional3, "
        "p.producent_name, m.Mout_type "
        "FROM elements e "
        "INNER JOIN elements_producents p ON e.Producent_id = p.Id_producent "
        "INNER JOIN elements_mounts m ON e.Mount_type = m.ID "
        "INNER JOIN elements_types t ON e.Element_type = t.Id_type "
        "WHERE e.Id_num = @IdNum AND t.Name = @ElementType";

    MySqlCommand^ command = gcnew MySqlCommand(query, connection);
    command->Parameters->AddWithValue("@IdNum", idNum);
    command->Parameters->AddWithValue("@ElementType", elementType);

    MySqlDataReader^ reader = command->ExecuteReader();

    if (reader->Read())
    {
        String^ producent = reader["producent_name"]->ToString();
        String^ mount_type = reader["Mout_type"]->ToString();
        int quantity = Convert::ToInt32(reader["Quantity"]);
        float optional1 = reader["Optional1"] != DBNull::Value ? Convert::ToSingle(reader["Optional1"]) : 0.0f;
        float optional2 = reader["Optional2"] != DBNull::Value ? Convert::ToSingle(reader["Optional2"]) : 0.0f;
        float optional3 = reader["Optional3"] != DBNull::Value ? Convert::ToSingle(reader["Optional3"]) : 0.0f;

        producentCombo->SelectedItem = producent; 

        mountCombo->SelectedItem = mount_type; 

        quantityBox->Text = quantity.ToString();

        optional1Box->Text = optional1.ToString();
        optional2Box->Text = optional2.ToString();
        optional3Box->Text = optional3.ToString();
    }

    reader->Close();
    connection->Close();
}


void UpdateElementInDatabase(String^ idNum, String^ producentName, String^ mountName, int quantity, float optional1, float optional2, float optional3)
{
    try
    {
        MySqlConnection^ connection = GetConnection();

        String^ getProducentIdQuery = "SELECT Id_producent FROM elements_producents WHERE producent_name = @ProducentName";
        String^ getMountIdQuery = "SELECT ID FROM elements_mounts WHERE Mout_type = @MountName";

        MySqlCommand^ getProducentIdCmd = gcnew MySqlCommand(getProducentIdQuery, connection);
        getProducentIdCmd->Parameters->AddWithValue("@ProducentName", producentName);
        int producentId = Convert::ToInt32(getProducentIdCmd->ExecuteScalar());

        MySqlCommand^ getMountIdCmd = gcnew MySqlCommand(getMountIdQuery, connection);
        getMountIdCmd->Parameters->AddWithValue("@MountName", mountName);
        int mountId = Convert::ToInt32(getMountIdCmd->ExecuteScalar());

        String^ updateQuery = "UPDATE elements SET Quantity = @Quantity, Optional1 = @Optional1, Optional2 = @Optional2, Optional3 = @Optional3, "
            "Producent_id = @ProducentId, Mount_type = @MountId "
            "WHERE Id_num = @IdNum";

        MySqlCommand^ updateCmd = gcnew MySqlCommand(updateQuery, connection);
        updateCmd->Parameters->AddWithValue("@Quantity", quantity);
        updateCmd->Parameters->AddWithValue("@Optional1", optional1);
        updateCmd->Parameters->AddWithValue("@Optional2", optional2);
        updateCmd->Parameters->AddWithValue("@Optional3", optional3);
        updateCmd->Parameters->AddWithValue("@ProducentId", producentId);
        updateCmd->Parameters->AddWithValue("@MountId", mountId);
        updateCmd->Parameters->AddWithValue("@IdNum", idNum);

        updateCmd->ExecuteNonQuery();

        MessageBox::Show("Zedytowano element");
        connection->Close();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("B³¹d podczas aktualizacji elementu: " + ex->Message);
    }
}
List<String^>^ Load_Orders(bool x)
{
    List<String^>^ ordersList = gcnew List<String^>();
    MySqlConnection^ connection = GetConnection();

    String^ query;
    if (x)
    {
        // Zapytanie dla wys³anych zamówieñ (is_shipped = 1)
        query = "SELECT orders.order_id, users.email FROM `orders` "
            "JOIN `users` ON orders.user_id = users.user_id "
            "WHERE orders.is_shipped = 1";
    }
    else
    {
        // Zapytanie dla niewys³anych zamówieñ (is_shipped = 0)
        query = "SELECT orders.order_id, users.email FROM `orders` "
            "JOIN `users` ON orders.user_id = users.user_id "
            "WHERE orders.is_shipped = 0";
    }

    try {
        MySqlDataReader^ reader = ExecuteQuery(connection, query);
        while (reader->Read()) {
            String^ orderInfo = "Order ID: " + reader["order_id"]->ToString() + ", Email: " + reader["email"]->ToString();
            ordersList->Add(orderInfo);
        }
    }
    catch (Exception^ e) {
        Console::WriteLine("B³¹d: " + e->Message);
    }
    finally {
        connection->Close();
    }

    return ordersList;
}

void Load_OrderDetails(Label^ label, DataGridView^ dataGrid, ComboBox^ comboBox) {
    if (comboBox->SelectedItem == nullptr) {
        label->Text = "No order selected.";
        return;
    }

    // Pobierz ID zamówienia z ComboBox
    String^ selectedOrderId = comboBox->SelectedItem->ToString();
    selectedOrderId = selectedOrderId->Substring(selectedOrderId->IndexOf(":") + 2);
    selectedOrderId = selectedOrderId->Substring(0, selectedOrderId->IndexOf(","));

    MySqlConnection^ connection = GetConnection();

    // Kwerenda dla szczegó³ów zamówienia
    String^ orderDetailsQuery = "SELECT orders.order_id, orders.order_date, users.email, orders.is_shipped "
        "FROM `orders` "
        "JOIN `users` ON orders.user_id = users.user_id "
        "WHERE orders.order_id = " + selectedOrderId;

    // Kwerenda dla elementów zamówienia
    String^ itemsQuery = "SELECT order_items.component_id_num, order_items.quantity, elements.Quantity AS stock_quantity, "
        "elements.Quantity - order_items.quantity AS remaining_stock "
        "FROM `order_items` "
        "LEFT JOIN `elements` ON order_items.component_id_num = elements.Id_num "
        "WHERE order_items.order_id = " + selectedOrderId;

    try {
        // Wyczyszczenie DataGridView
        dataGrid->Columns->Clear();
        dataGrid->Rows->Clear();

        // Wykonaj pierwsz¹ kwerendê (detale zamówienia)
        MySqlDataReader^ reader = ExecuteQuery(connection, orderDetailsQuery);

        bool isShippedOrder = false;

        if (reader->Read()) {
            // Wyœwietl szczegó³y zamówienia w Label
            String^ orderId = reader["order_id"]->ToString();
            String^ orderDate = reader["order_date"]->ToString();
            String^ email = reader["email"]->ToString();
            isShippedOrder = Convert::ToBoolean(reader["is_shipped"]);

            String^ isShipped = isShippedOrder ? "Yes" : "No";

            label->Text = "Order ID: " + orderId +
                "\nDate: " + orderDate +
                "\nClient: " + email +
                "\nShipped: " + isShipped;
        }
        else {
            label->Text = "No data found for the selected order.";
        }

        // Zamknij pierwszy DataReader
        reader->Close();

        // Dodaj kolumny do DataGridView
        dataGrid->Columns->Add("ComponentID", "Component ID");
        dataGrid->Columns->Add("OrderedQuantity", "Ordered Quantity");

        // Wykonaj drug¹ kwerendê (elementy zamówienia)
        reader = ExecuteQuery(connection, itemsQuery);

        // Jeœli zamówienie zosta³o wys³ane, poka¿ tylko zamówion¹ iloœæ
        if (isShippedOrder) {
            // Dodaj wiersze do DataGridView (tylko zamówiona iloœæ)
            while (reader->Read()) {
                String^ componentId = reader["component_id_num"]->ToString();
                String^ orderedQuantity = reader["quantity"]->ToString();

                // Dodaj wiersze do DataGridView (tylko zamówiona iloœæ)
                dataGrid->Rows->Add(componentId, orderedQuantity);
            }
        }
        else {
            // Dodaj kolumny dla iloœci na magazynie i pozosta³ej iloœci
            dataGrid->Columns->Add("StockQuantity", "Stock Quantity");
            dataGrid->Columns->Add("RemainingStock", "Remaining Stock");

            // Dodaj wiersze do DataGridView dla wszystkich informacji
            while (reader->Read()) {
                String^ componentId = reader["component_id_num"]->ToString();
                String^ orderedQuantity = reader["quantity"]->ToString();
                String^ stockQuantity = reader["stock_quantity"]->ToString();
                String^ remainingStock = reader["remaining_stock"]->ToString();

                // Dodaj wiersze do DataGridView
                dataGrid->Rows->Add(componentId, orderedQuantity, stockQuantity, remainingStock);
            }
        }

        // Zamknij drugi DataReader
        reader->Close();
    }
    catch (Exception^ e) {
        label->Text = "Error: " + e->Message;
    }
    finally {
        connection->Close();
    }
}


void MarkOrderAsShippedAndUpdateStock(ComboBox^ comboBox, DataGridView^ dataGrid)
{
    if (comboBox->SelectedItem == nullptr)
    {
        MessageBox::Show("Please select an order.");
        return;
    }

    // Pobierz ID zamówienia z ComboBox
    String^ selectedOrderId = comboBox->SelectedItem->ToString();
    selectedOrderId = selectedOrderId->Substring(selectedOrderId->IndexOf(":") + 2);
    selectedOrderId = selectedOrderId->Substring(0, selectedOrderId->IndexOf(","));

    MySqlConnection^ connection = GetConnection();

    // Ustawienie is_shipped na 1 dla wybranego zamówienia
    String^ updateOrderQuery = "UPDATE orders SET is_shipped = 1 WHERE order_id = @OrderId";
    MySqlCommand^ updateOrderCmd = gcnew MySqlCommand(updateOrderQuery, connection);
    updateOrderCmd->Parameters->AddWithValue("@OrderId", selectedOrderId);

    try
    {
        // Wykonaj zapytanie do zmiany statusu zamówienia na wys³ane
        updateOrderCmd->ExecuteNonQuery();

        // Przetwarzanie szczegó³ów zamówienia z DataGridView
        for (int i = 0; i < dataGrid->Rows->Count; i++)
        {
            String^ componentId = dataGrid->Rows[i]->Cells["ComponentID"]->Value->ToString();
            int orderedQuantity = Convert::ToInt32(dataGrid->Rows[i]->Cells["OrderedQuantity"]->Value);

            // Zapytanie sprawdzaj¹ce stan magazynowy
            String^ checkStockQuery = "SELECT Quantity FROM elements WHERE Id_num = @ComponentId";
            MySqlCommand^ checkStockCmd = gcnew MySqlCommand(checkStockQuery, connection);
            checkStockCmd->Parameters->AddWithValue("@ComponentId", componentId);

            MySqlDataReader^ reader = checkStockCmd->ExecuteReader();

            if (reader->Read())
            {
                int stockQuantity = Convert::ToInt32(reader["Quantity"]);

                // Sprawdzamy, czy w magazynie jest wystarczaj¹ca iloœæ
                if (stockQuantity >= orderedQuantity)
                {
                    // Zaktualizowanie iloœci w magazynie
                    reader->Close(); // Zamkniêcie poprzedniego readera

                    String^ updateStockQuery = "UPDATE elements SET Quantity = Quantity - @OrderedQuantity WHERE Id_num = @ComponentId";
                    MySqlCommand^ updateStockCmd = gcnew MySqlCommand(updateStockQuery, connection);
                    updateStockCmd->Parameters->AddWithValue("@OrderedQuantity", orderedQuantity);
                    updateStockCmd->Parameters->AddWithValue("@ComponentId", componentId);

                    // Wykonaj zapytanie do aktualizacji stanu magazynowego
                    updateStockCmd->ExecuteNonQuery();
                }
                else
                {
                    MessageBox::Show("Not enough stock for component " + componentId + ". Cannot fulfill the order.");
                    return;
                }
            }
            reader->Close();
        }

        connection->Close();
        MessageBox::Show("Order has been marked as shipped, and stock has been updated.");
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error occurred: " + ex->Message);
    }
}

void SendOrderConfirmationWithAttachment(DataGridView^ dataGridView, Label^ orderLabel)
{
    // Wyci¹ganie danych z Label
    String^ labelText = orderLabel->Text;

    // Parsowanie danych z label (np. orderId, email, itd.)
    String^ orderId = labelText->Substring(labelText->IndexOf("ID: ") + 4, labelText->IndexOf("\n") - labelText->IndexOf("ID: ") - 4);
    String^ orderDate = labelText->Substring(labelText->IndexOf("Date: ") + 6, labelText->IndexOf("\n", labelText->IndexOf("Date: ")) - labelText->IndexOf("Date: ") - 6);
    int clientStartPos = labelText->IndexOf("Client: ") + 8;
    int clientEndPos = labelText->IndexOf("\n", clientStartPos);
    String^ email = labelText->Substring(clientStartPos, clientEndPos - clientStartPos);
    

    // Zapisanie DataGridView do obrazu (tylko dwie pierwsze kolumny)
    String^ filePath = "order_" + orderId + ".png";  // Œcie¿ka pliku

    int width = dataGridView->Columns[0]->Width + dataGridView->Columns[1]->Width;
    int height = dataGridView->RowCount * dataGridView->RowTemplate->Height;

    Bitmap^ bitmap = gcnew Bitmap(width, height);
    Graphics^ g = Graphics::FromImage(bitmap);
    g->Clear(Color::White);

    // Rysowanie danych w DataGridView na obrazie
    for (int i = 0; i < dataGridView->RowCount; i++)
    {
        g->DrawString(dataGridView->Rows[i]->Cells[0]->Value->ToString(),
            dataGridView->Font, Brushes::Black, 0, i * dataGridView->RowTemplate->Height);
        g->DrawString(dataGridView->Rows[i]->Cells[1]->Value->ToString(),
            dataGridView->Font, Brushes::Black, dataGridView->Columns[0]->Width, i * dataGridView->RowTemplate->Height);
    }

    // Zapisz bitmapê jako plik .png
    bitmap->Save(filePath, System::Drawing::Imaging::ImageFormat::Png);
    delete g;

    // Wysy³anie e-maila
    MailMessage^ message = gcnew MailMessage();
    message->From = gcnew MailAddress("twoje_adres@gmail.com");  // Twój adres e-mail
    message->To->Add(email);  // Adres odbiorcy

    message->Subject = "Potwierdzenie wysy³ki zamówienia ID: " + orderId;
    message->Body = "Szanowni Pañstwo,\n\n" +
        "Potwierdzamy wysy³kê zamówienia o ID: " + orderId + "\n" +
        "Data zamówienia: " + orderDate + "\n" +
        "Status wysy³ki: " +"wyslana" + "\n\n" +
        "Lista elementów znajduje siê w za³¹czonym pliku obrazu.";

    // Dodanie za³¹cznika
    Attachment^ attachment = gcnew Attachment(filePath);
    message->Attachments->Add(attachment);

    // Konfiguracja SMTP dla Gmaila
    SmtpClient^ smtpClient = gcnew SmtpClient("smtp.gmail.com");
    smtpClient->Port = 587;
    smtpClient->Credentials = gcnew System::Net::NetworkCredential("podhajnymaciejkolo2@gmail.com", "cahn jpcl rsza viim");
    smtpClient->EnableSsl = true;

    try
    {
        smtpClient->Send(message);
        MessageBox::Show("Potwierdzenie zamówienia zosta³o wys³ane.");
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("B³¹d podczas wysy³ania e-maila: " + ex->Message);
    }

    // Usuwamy zapisany plik
}







