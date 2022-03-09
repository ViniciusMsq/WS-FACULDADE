<!DOCTYPE html>
<html>
<head>
	<title>Testando Heranças</title>

<?php
	include_once("Classe_filha.php");

?>

</head>
<body>
	<h2>Testando Heranças</h2>

	<?php

		$F = new Classe_filha();

		$F->mensagem();



	?>


</body>
</html>