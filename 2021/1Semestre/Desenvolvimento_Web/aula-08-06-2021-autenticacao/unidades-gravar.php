<?php
	include_once("bd.php");

	// Fazendo a conexão com o Banco de Dados	
	$meu_BD = new BD();	
	
	$pdo = $meu_BD->pdo;

	$acao = @$_POST['acao'];
	$cod_unidade = @$_POST['cod_unidade'];

	//--------------------------------------------------------------------
	if( $acao == 'incluir' )
	{
		$sql = " insert into unidades (descricao, sigla) values (:descricao, :sigla) ";

		$cmd = $pdo->prepare($sql);

	} // incluir
	else
	//--------------------------------------------------------------------
	if( $acao == 'alterar' )
	{
		$sql = " update unidades set
					descricao = :descricao,
					sigla   = :sigla
				 where cod_unidade = :cod_unidade
			   ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":cod_unidade", $cod_unidade );

	} // alterar
	else
	//--------------------------------------------------------------------
	if( $acao == 'excluir' )
	{
		$sql = " delete from unidades where cod_unidade = :cod_unidade ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":cod_unidade", $cod_unidade );

	} // excluir
	else
	{
		echo '<script language="javascript">
					document.location = "index.php?modulo=unidades&erro=Ação inválida !!!";
			  </script>
			 ';
	}

	//--------------------------------------------------------------------
	if( $acao == 'incluir' or $acao == 'alterar' )
	{
		$descricao = $_POST['descricao'];
		$sigla     = $_POST['sigla'];

		$cmd->bindValue(":descricao" , $descricao );
		$cmd->bindValue(":sigla"     , $sigla );
	}


	// se conseguiu executar o comando sql sem erros
	if( $cmd->execute() )
	{
		echo '<script language="javascript">
					document.location = "index.php?modulo=unidades";
			  </script>
			 ';
	}
	else
	{
		echo '<script language="javascript">
					document.location = "index.php?modulo=unidades&erro=Não foi possível gravar as informações, houve algum erro na transação com o Banco de Dados!!!";
			  </script>
			 ';
	}

?>