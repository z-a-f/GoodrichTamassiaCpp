<?php
echo "This is a " . $_SERVER['SCRIPT_NAME'] ."\n";

session_start();

$_SESSION['name'] = 'Zafar';
?>
