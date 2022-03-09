<!DOCTYPE html>
<html>
<head>
	<title>Testando o Construct e Destruct</title>

<?php
	include_once("Classe_teste.php");

function teste()
{
	$obj = new Classe_teste();
	echo '<p>Dentro da função teste</p>';
}

?>


</head>
<body>

	<?php teste(); ?>

	<h2>Testando o Construct e Destruct</h2>

	<?php

		$A = new Classe_teste();

		echo '<p>Frase entre as instancias de A e B</p>';

		$B = new Classe_teste();

		// Eliminando o objeto B da memória
		unset($B);

		echo '<p>Frase após a eliminação de B</p>';

	?>



</body>
</html>