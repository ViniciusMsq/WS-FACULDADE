<!DOCTYPE html>
<html>
<head>
	<title>POO em PHP - Aula 2</title>
<?php
	include_once("Classe_data.php");
?>

</head>
<body>
	<h2>POO em PHP - Aula 2</h2>

	<?php

		$minha_data = new Classe_data();

		echo $minha_data->data_por_extenso();

		echo '<p>';

		$minha_data->calendario(9, 2021);

		$minha_data->calendario();

		echo '</p>';

	?>




</body>
</html>