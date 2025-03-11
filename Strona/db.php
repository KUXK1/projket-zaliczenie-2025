<?php
$host = '127.0.0.1';
$db = 'project_2024';
$user = 'root'; // Ustaw właściwą nazwę użytkownika bazy danych
$pass = '';     // Ustaw hasło użytkownika bazy danych

try {
    $pdo = new PDO("mysql:host=$host;dbname=$db", $user, $pass);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die("Błąd połączenia z bazą danych: " . $e->getMessage());
}
?>
