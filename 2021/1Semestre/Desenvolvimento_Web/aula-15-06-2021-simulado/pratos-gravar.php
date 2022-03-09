<?php
	session_start();

	include_once("funcoes.php");

	verificar_autenticacao();

	include_once("bd.php");

	// Fazendo a conexão com o Banco de Dados	
	$meu_BD = new BD();	
	
	$pdo = $meu_BD->pdo;

	$acao = @$_POST['acao'];
	$cod_prato = @$_POST['cod_prato'];

	//--------------------------------------------------------------------
	if( $acao == 'incluir' or $acao == 'alterar' )
	{
		$descricao = $_POST['descricao'];
		$valor_unitario   = $_POST['valor_unitario'];
		$cod_categoria   = $_POST['cod_categoria'];
	}

	//--------------------------------------------------------------------
	if( $acao == 'incluir' )
	{
		$sql = " insert into pratos (descricao, valor_unitario, cod_categoria) values (:descricao, :valor_unitario, :cod_categoria) ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":descricao" , $descricao );
		$cmd->bindValue(":valor_unitario"   , $valor_unitario );
		$cmd->bindValue(":cod_categoria"   , $cod_categoria );


	} // incluir
	else
	//--------------------------------------------------------------------
	if( $acao == 'alterar' )
	{
		$sql = " update pratos set
					descricao = :descricao,
					valor_unitario   = :valor_unitario,
					cod_categoria   = :cod_categoria
				 where cod_prato = :cod_prato
			   ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":cod_prato", $cod_prato );
		$cmd->bindValue(":descricao"      , $descricao );
		$cmd->bindValue(":valor_unitario"   	 , $valor_unitario );
		$cmd->bindValue(":cod_categoria"   	 , $cod_categoria );


	} // alterar
	else
	//--------------------------------------------------------------------
	if( $acao == 'excluir' )
	{
		// fazendo a integridade referencial: clientes
		$result = $pdo->query("select count(*) as total from itens_encomenda where cod_prato = '$cod_prato' ");
		$dados = $result->fetch(PDO::FETCH_ASSOC);

		if( $dados['total'] > 0)
		{
			header("Location: index.php?modulo=pratos&erro=Não é possível excluir esta prato porque possui clientes relacionados !!!");
			exit;
		}

		// fazendo a integridade referencial: clientes
		$result = $pdo->query("select count(*) as total from composicao where cod_prato = '$cod_prato' ");
		$dados = $result->fetch(PDO::FETCH_ASSOC);

		if( $dados['total'] > 0)
		{
			header("Location: index.php?modulo=pratos&erro=Não é possível excluir esta prato porque possui fornecedores relacionados !!!");
			exit;
		}


		$sql = " delete from pratos where cod_prato = :cod_prato ";

		$cmd = $pdo->prepare($sql);

		$cmd->bindValue(":cod_prato", $cod_prato );

	} // excluir
	else
	{
		echo '<script language="javascript">
					document.location = "index.php?modulo=pratos&erro=Ação inválida !!!";
			  </script>
			 ';
	}


	// se conseguiu executar o comando sql sem erros
	if( $cmd->execute() )
	{
		echo '<script language="javascript">
					document.location = "index.php?modulo=pratos";
			  </script>
			 ';
	}
	else
	{
		echo '<script language="javascript">
					document.location = "index.php?modulo=pratos&erro=Não foi possível gravar as informações, houve algum erro na transação com o Banco de Dados!!!";
			  </script>
			 ';
	}

?>