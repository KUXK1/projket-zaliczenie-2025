<?php
include 'db.php';
session_start();

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['register'])) {
        $email = $_POST['email'];
        $password = md5($_POST['password']);

        $stmt = $pdo->prepare("INSERT INTO users (email, password) VALUES (?, ?)");
        if ($stmt->execute([$email, $password])) {
            echo "<div class='success-message'>Rejestracja udana! Możesz się teraz zalogować.</div>";
        } else {
            echo "<div class='error-message'>Błąd rejestracji.</div>";
        }
    }

    if (isset($_POST['login'])) {
        $email = $_POST['email'];
        $password = md5($_POST['password']);

        $stmt = $pdo->prepare("SELECT * FROM users WHERE email = ? AND password = ?");
        $stmt->execute([$email, $password]);
        $user = $stmt->fetch();

        if ($user) {
            $_SESSION['user_id'] = $user['user_id'];
            header("Location: dashboard.php");
        } else {
            echo "<div class='error-message'>Nieprawidłowe dane logowania.</div>";
        }
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Logowanie</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="login-container">
        <h2>Logowanie</h2>
        <form method="POST">
            <input type="email" name="email" placeholder="Email" required>
            <input type="password" name="password" placeholder="Hasło" required>
            <button type="submit" name="login">Zaloguj się</button>
        </form>

        <h2>Rejestracja</h2>
        <form method="POST">
            <input type="email" name="email" placeholder="Email" required>
            <input type="password" name="password" placeholder="Hasło" required>
            <button type="submit" name="register">Zarejestruj się</button>
        </form>
    </div>
</body>
</html>
