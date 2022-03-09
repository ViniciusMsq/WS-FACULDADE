<!DOCTYPE html>
<html>
<head>
	<title>PDO : Inicio</title>
</head>
<body>
<h3>PDO : HELLO WORLD!!!</h3>

<?php

	// Efetuando a conexão com o banco de dados

	// PDO(string de conexão, usuário do bd, senha)

	$pdo = new PDO("mysql:host=localhost;dbname=baseteste2021","root","vertrigo"); 

	// Método 1 -------------------------------------------------------------------
	echo "<h4>LISTANDO : EXEMPLO 1</h4>";
	
	$r = $pdo->query("select * from cidades order by nome");

	/*
	$dados = $r->fetch(PDO::FETCH_OBJ);

	// se o fetch retornou verdadeiro, significa que conseguiu obter um registro da consulta
	// senão, se fetch retornou falso, significa que chegou ao fim da consulta
	if( $dados ) 
	{
		echo 'Código da cidade: ' . $dados->cod_cidade;
		echo '<br>Nome da cidade: ' . $dados->nome;
		echo '<br>UF da cidade: ' . $dados->uf;
	}

	$dados = $r->fetch(PDO::FETCH_OBJ);
	if( $dados ) 
	{
		echo '<br>Código da cidade: ' . $dados->cod_cidade;
		echo '<br>Nome da cidade: ' . $dados->nome;
		echo '<br>UF da cidade: ' . $dados->uf;
	}

	$dados = $r->fetch(PDO::FETCH_OBJ);
	if( $dados ) 
	{
		echo '<br>Código da cidade: ' . $dados->cod_cidade;
		echo '<br>Nome da cidade: ' . $dados->nome;
		echo '<br>UF da cidade: ' . $dados->uf;
	}

	$dados = $r->fetch(PDO::FETCH_OBJ);
	if( $dados ) 
	{
		echo '<br>Código da cidade: ' . $dados->cod_cidade;
		echo '<br>Nome da cidade: ' . $dados->nome;
		echo '<br>UF da cidade: ' . $dados->uf;
	}
	*/

	/*
	$dados = $r->fetch(PDO::FETCH_OBJ);

	while( $dados ) 
	{
		echo '<br>' . $dados->cod_cidade . ' - ' . $dados->nome . '/' . $dados->uf; 

		$dados = $r->fetch(PDO::FETCH_OBJ);
	}
	*/

	while( $dados = $r->fetch(PDO::FETCH_OBJ) ) 
	{
		echo '<br>' . $dados->cod_cidade . ' - ' . $dados->nome . '/' . $dados->uf; 		
	}


	// Método 2 -------------------------------------------------------------------
	echo "<h4>LISTANDO : EXEMPLO 2</h4>";
	
	$r = $pdo->prepare("select * from cidades order by nome");		
	$r->execute();
	
	// Observação1: O método prepare executa tanto select quanto
	// insert, update, delete, procedimentos armazenados e funções
	
	// Observação2: O método query, só executa select
	
	while( $dados = $r->fetch(PDO::FETCH_OBJ) )
	{
		echo $dados->cod_cidade . ' - ' . $dados->nome . '/' . $dados->uf . '<br>';	
	}





	// Método 3 -------------------------------------------------------------------
	echo "<h4>LISTANDO : EXEMPLO 3</h4>";
	
	$r = $pdo->query("select * from cidades order by nome");
		
	// Observação: Nesse método, é retornado para dados
	// um vetor, e não um objeto

	while( $dados = $r->fetch(PDO::FETCH_ASSOC) )
	{
		echo $dados['cod_cidade'] . ' - ' . $dados['nome'] . '/' . $dados['uf'] . '<br>';	
	} 
	

	// Método 4 -------------------------------------------------------------------
	echo "<h4>LISTANDO : EXEMPLO 4</h4>";
	
	$r = $pdo->query("select * from cidades order by nome");
		
	// Observação: Nesse método, é retornado para a linha
	// um vetor com as chaves duplicadas. Índice numerico e 
	// indice associativo
	
	while( $dados = $r->fetch(PDO::FETCH_BOTH) )
	{
		echo $dados['cod_cidade'] . ' - ' . $dados['nome'] . '/' . $dados['uf'] . '<br>';	
		echo $dados[0] . ' - ' . $dados[1] . '/' . $dados[2] . '<br>';	
	} 


?>	


</body>
</html>