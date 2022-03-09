<?php
	session_start();

	$login = @$_POST['login'];
	$senha = @$_POST['senha'];

	if( $login == 'andre' && $senha = '123' )
	{
		$_SESSION['usuario']['cod_usuario']   = 99;
		$_SESSION['usuario']['login']         = $login;
		$_SESSION['usuario']['nome_completo'] = 'André Mendes';

		header("Location: index.php");

	} 
	else 
	{
		header("Location: index.php?erro=Usuário e/ou senha inválidos!!!");	
	}



?>