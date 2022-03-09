<!DOCTYPE html>
<html>
<head>
	<title>Gravando...</title>
</head>
<body>

	<h3>Gravando os dados...</h3>

	<?php
		/*
		echo "Cod_cliente: " . $_POST['cod_cliente'] . '<br>';
		echo "Nome: " . $_POST['nome'] . '<br>';
		echo "cod_cidade: " . $_POST['cod_cidade'] . '<br>';
		*/

		foreach($_POST as $chave => $valor)
		{
			echo $chave . ': <b>' . $valor . '</b><br>';
		}



	?>



</body>
</html>