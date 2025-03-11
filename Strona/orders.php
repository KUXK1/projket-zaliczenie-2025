<?php
include 'db.php';
session_start();

if (!isset($_SESSION['user_id'])) {
    header("Location: index.php");
    exit;
}

$user_id = $_SESSION['user_id'];
$orders = $pdo->prepare("SELECT * FROM orders WHERE user_id = ?");
$orders->execute([$user_id]);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Twoje zamówienia</title>
</head>
<body>
    <h2>Twoje zamówienia:</h2>
    <ul>
        <?php while ($order = $orders->fetch()): ?>
            <li>Zamówienie #<?= $order['order_id'] ?> - Data: <?= $order['order_date'] ?></li>
        <?php endwhile; ?>
    </ul>

    <h3><a href="dashboard.php">Powrót do panelu</a></h3>
</body>
</html>
