<!DOCTYPE html>
<html>
<head>
	<title>POO em PHP : Introdução</title>
</head>
<body>
	<h2>POO em PHP : Introdução</h2>

    <?php

        include_once("Calculadora.php");

        $obj = new Calculadora();
        $obj->A=10;
        $obj->B=0;

        echo "<br>Soma: " . $obj->GetSoma();
        echo "<br>Subtração: " . $obj->GetSubtracao();
        echo "<br>Multiplicação: " . $obj->GetMultiplicacao();
        echo "<br>Divisão: " . $obj->GetDivisao();

    ?>
</body>
</html>