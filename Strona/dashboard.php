<?php
include 'db.php';
session_start();
if (!isset($_SESSION['user_id'])) {
    header("Location: index.php");
    exit;
}

if (!isset($_SESSION['cart'])) {
    $_SESSION['cart'] = [];
}

// Koszyk
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['add_to_cart'])) {
    $component_id = $_POST['component_id'];
    $quantity = (int) $_POST['quantity'];

    if (isset($_SESSION['cart'][$component_id])) {
        $_SESSION['cart'][$component_id] += $quantity;
    } else {
        $_SESSION['cart'][$component_id] = $quantity;
    }
}

// Lista
$search = isset($_GET['search']) ? $_GET['search'] : "";
$stmt = $pdo->prepare("SELECT e.*, p.producent_name, m.Mout_type, t.Name as type_name 
                      FROM elements e
                      JOIN elements_producents p ON e.Producent_id = p.Id_producent
                      JOIN elements_mounts m ON e.Mount_type = m.ID
                      JOIN elements_types t ON e.Element_type = t.Id_type
                      WHERE e.Id_num LIKE ? OR p.producent_name LIKE ? OR t.Name LIKE ?");
$stmt->execute(["%$search%", "%$search%", "%$search%"]);
$components = $stmt->fetchAll();
?>

<!DOCTYPE html>
<html>
<head>
    <title>Lista komponentów</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h2>Lista komponentów</h2>

        <form method="GET" class="search-form">
            <input type="text" name="search" placeholder="Szukaj komponentu..." value="<?= htmlspecialchars($search) ?>">
            <button type="submit">Szukaj</button>
        </form>

        <table class="component-table">
            <tr>
                <th>ID</th>
                <th>Producent</th>
                <th>Typ</th>
                <th>Montaż</th>
                <th>Ilość</th>
                <th>Parametry</th>
                <th>Dodaj do koszyka</th>
            </tr>
            <?php foreach ($components as $component): ?>
                <tr>
                    <td><?= htmlspecialchars($component['Id_num']) ?></td>
                    <td><?= htmlspecialchars($component['producent_name']) ?></td>
                    <td><?= htmlspecialchars($component['type_name']) ?></td>
                    <td><?= htmlspecialchars($component['Mout_type']) ?></td>
                    <td><?= htmlspecialchars($component['Quantity']) ?></td>
                    <td><?= getComponentDetails($component) ?></td>
                    <td>
                        <form method="POST" class="cart-form">
                            <input type="hidden" name="component_id" value="<?= $component['Id_num'] ?>">
                            <input type="number" name="quantity" min="1" max="<?= $component['Quantity'] ?>" required>
                            <button type="submit" name="add_to_cart">Dodaj</button>
                        </form>
                    </td>
                </tr>
            <?php endforeach; ?>
        </table>

        <a href="cart.php" class="cart-link">Przejdź do koszyka</a>
    </div>
</body>
</html>

<?php
function getComponentDetails($component) {
    switch ($component['Element_type']) {
        case 1:
            return "Rezystancja: {$component['Optional1']} Ω, Moc: {$component['Optional2']} W";
        case 2:
            return "Pojemność: {$component['Optional1']} F, Napięcie: {$component['Optional2']} V";
        case 3:
            return "Częstotliwość: {$component['Optional1']} Hz";
        case 4:
            return "Indukcyjność: {$component['Optional1']} H, Rezystancja: {$component['Optional2']} Ω";
        case 5:
            return "RAM: {$component['Optional1']} KB, Flash: {$component['Optional2']} KB, Napięcie: {$component['Optional3']} V";
        case 6:
            return "Napięcie: {$component['Optional1']} V, Prąd: {$component['Optional2']} A";
        default:
            return "Brak danych";
    }
}
?>
