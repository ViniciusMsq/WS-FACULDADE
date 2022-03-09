<?php
	include_once("bd.php");

	// Fazendo a conexão com o Banco de Dados	
	$meu_BD = new BD();	
	
	$pdo = $meu_BD->pdo;

	$acao = @$_POST['acao'];
	$cod_cidade = @$_POST['cod_cidade'];

	//--------------------------------------------------------------------
	if( $acao == 'incluir' or $acao == 'alterar' )
	{
		$nome = $_POST['nome'];
		$uf   = $_POST['uf'];
	}

	//--------------------------------------------------------------------
	if( $acao == 'incluir' )
	{
		$sql = " insert into cidades (nome, uf) values (:nome, :uf) ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":nome" , $nome );
		$cmd->bindValue(":uf"   , $uf );


	} // incluir
	else
	//--------------------------------------------------------------------
	if( $acao == 'alterar' )
	{
		$sql = " update cidades set
					nome = :nome,
					uf   = :uf
				 where cod_cidade = :cod_cidade
			   ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":cod_cidade", $cod_cidade );
		$cmd->bindValue(":nome"      , $nome );
		$cmd->bindValue(":uf"   	 , $uf );


	} // alterar
	else
	//--------------------------------------------------------------------
	if( $acao == 'excluir' )
	{
		$sql = " delete from cidades where cod_cidade = :cod_cidade ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":cod_cidade", $cod_cidade );

	} // excluir
	else
	{
		echo '<script language="javascript">
					document.location = "cidades.php?erro=Ação inválida !!!";
			  </script>
			 ';
	}


	// se conseguiu executar o comando sql sem erros
	if( $cmd->execute() )
	{
		echo '<script language="javascript">
					document.location = "cidades.php";
			  </script>
			 ';
	}
	else
	{
		echo '<script language="javascript">
					document.location = "cidades.php?erro=Não foi possível gravar as informações, houve algum erro na transação com o Banco de Dados!!!";
			  </script>
			 ';
	}

?>