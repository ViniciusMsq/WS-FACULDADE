<?php
	//header('Content-Type: text/html; charset=utf-8');
	header('Content-Type: text/html; charset=iso-8859-1');

	include_once("bd.php");

	// Fazendo a conexão com o Banco de Dados	
	$meu_BD = new BD();	
	
	$pdo = $meu_BD->pdo;


?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<!-- <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" /> -->
<title>PDO : INTRODUÇÃO</title>
</head>

<body>

<H2>CADASTRO DE CIDADES</H2>

<form name="fcad" id="fcad" action="cidades-gravar.php" method="post">

	<input type="hidden" name="acao" id="acao" value="incluir">

	Nome:<br>
	<input type="text" name="nome" id="nome" size="60" maxlength="100" value="">

	<p></p>
	Unidade Federal:<br>
	<input type="text" name="uf" id="uf" size="30" maxlength="2" value="">

	<p></p>
	<input type="submit" name="btgravar" id="btgravar" value="  Gravar  ">

</form>

<p></p>
<h5>Cidades Cadastradas</h5>

<?php
		
	// Listando registros a partir de um select
	
	$r = $pdo->query("select * from cidades order by nome");
	
	while( $dados = $r->fetch(PDO::FETCH_ASSOC) )
	{
		echo $dados['cod_cidade'] . ' - ' . $dados['nome'] . '/' . $dados['uf'] . '<br>';	
	} 


?>

</body>
</html>











