<?php
	header('Content-Type: text/html; charset=iso-8859-1');
	//header('Content-Type: text/html; charset=utf-8');

	include_once("bd.php");

	// Fazendo a conexão com o Banco de Dados	
	$meu_BD = new BD();	
	
	$pdo = $meu_BD->pdo;
	
	/* EXEMPLO 1 
	if( $_POST['acao'] == 'incluir' )
	{
		$nome = $_POST['nome'];
		$uf = $_POST['uf'];

		$sql = " insert into cidades (nome, uf)	values ('$nome', '$uf') ";	
	
		$cmd = $pdo->prepare($sql);

		if( $cmd->execute() )
		{
			// redirecionando
			echo "<script language='javascript'>
					document.location='cidades.php';
				</script>";	
		}
		else
		{
			echo 'Não foi possível gravar os dados...!';
			echo '<p>Erro:</p>';
			print_r($cmd->errorInfo());
		}
				
	} // inclusão
	/* */
	
	/* EXEMPLO 2 
	if( $_POST['acao'] == 'incluir' )
	{
		$nome = $_POST['nome'];
		$uf = $_POST['uf'];

		$sql = " insert into cidades (nome, uf)	values (?, ?) ";

		$cmd = $pdo->prepare($sql);

		// preenchendo os parâmetros "?"
		$cmd->bindValue(1,$nome);
		$cmd->bindValue(2,$uf);

		if( $cmd->execute() )
		{
			// redirecionando
			echo "<script language='javascript'>
					document.location='cidades.php';
				</script>";	
		}
		else
		{
			echo 'Não foi possível gravar os dados...!';
			echo '<p>Erro:</p>';
			print_r($cmd->errorInfo());
		}

				
	} // inclusão
	/**/	
	
	/* EXEMPLO 3 */
	if( $_POST['acao'] == 'incluir' )
	{

		$nome = $_POST['nome'];
		$uf   = $_POST['uf'];

		$sql = " insert into cidades (nome, uf)	values (:nome, :uf) ";

		$cmd = $pdo->prepare($sql);

		// preenchendo os parâmetros 
		$cmd->bindValue(":nome" , $nome);
		$cmd->bindValue(":uf"	, $uf);

		if( $cmd->execute() )
		{
			// redirecionando
			echo "<script language='javascript'>
					document.location='cidades.php';
				</script>";	
		}
		else
		{
			echo 'Não foi possível gravar os dados...!';
			echo '<p>Erro:</p>';
			print_r($cmd->errorInfo());
		}
				
	} // inclusão
	/**/	
		

?>