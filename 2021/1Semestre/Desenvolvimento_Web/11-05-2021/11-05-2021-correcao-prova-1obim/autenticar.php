<!DOCTYPE html>
<html>
<head>
	<title>Autenticar</title>
</head>
<body>
	<h2>Autenticando...</h2>

	<?php

		$login = $_POST['login'];
		$senha = $_POST['senha'];

		if( $login == "UNIFAI" and $senha == "2021" )
		{
			echo '<p style="color:#00f;">Usuário autenticado...</p>';			
		}
		else
		{
			echo '<p style="color:#f00;">Usuário e/ou senha inválidos...</p>';			
		}



	?>

</body>
</html>