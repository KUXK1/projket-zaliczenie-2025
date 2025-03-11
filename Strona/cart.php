<?php
include 'db.php';
session_start();

if (!isset($_SESSION['user_id'])) {
    header("Location: index.php");
    exit;
}

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['place_order'])) {
    $user_id = $_SESSION['user_id'];

    $stmt = $pdo->prepare("INSERT INTO orders (user_id) VALUES (?)");
    $stmt->execute([$user_id]);
    $order_id = $pdo->lastInsertId();

    foreach ($_SESSION['cart'] as $component_id => $quantity) {
        $stmt = $pdo->prepare("INSERT INTO order_items (order_id, component_id_num, quantity) VALUES (?, ?, ?)");
        $stmt->execute([$order_id, $component_id, $quantity]);
    }

    $_SESSION['cart'] = [];
    header("Location: thank_you.php");
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Koszyk</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h2>Twój koszyk</h2>
        <?php if (!empty($_SESSION['cart'])): ?>
            <table class="cart-table">
                <tr>
                    <th>ID komponentu</th>
                    <th>Ilość</th>
                </tr>
                <?php foreach ($_SESSION['cart'] as $component_id => $quantity): ?>
                    <tr>
                        <td><?= htmlspecialchars($component_id) ?></td>
                        <td><?= htmlspecialchars($quantity) ?></td>
                    </tr>
                <?php endforeach; ?>
            </table>
            <form method="POST">
                <button type="submit" name="place_order" class="btn-order">Zamów</button>
            </form>
        <?php else: ?>
            <p class="empty-cart">Koszyk jest pusty.</p>
        <?php endif; ?>

        <a href="dashboard.php" class="back-link">Powrót do listy komponentów</a>
    </div>
</body>
</html>
