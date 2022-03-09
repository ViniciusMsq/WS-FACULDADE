<!DOCTYPE html>
<html>
<head>
	<title>POO em PHP : Introdução</title>
</head>
<body>
	<h2>POO em PHP : Introdução</h2>

	<?php

		include_once("Classe_soma.php");

		$A = new Classe_soma();
		$A->x = 7;
		$A->y = 13;

		echo 'A soma é ' . $A->GetSoma();

		$A->imprimir_soma();

	?>

</body>
</html>