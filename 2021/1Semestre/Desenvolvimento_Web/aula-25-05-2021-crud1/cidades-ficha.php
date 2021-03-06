<?php
	include_once("bd.php");

	// Fazendo a conexão com o Banco de Dados	
	$meu_BD = new BD();	
	
	$pdo = $meu_BD->pdo;

	$acao = @$_POST['acao'];
	$cod_cidade = @$_POST['cod_cidade'];

	if( $acao != 'alterar' and $acao != 'incluir' )
	{
		echo '<script language="javascritp">
					document.location = "cidades.php?erro=Ação inválida !!!";
			  </script>
			 ';
	}


	if( $acao == 'alterar' )
	{
		// buscar os dados do registro a ser alterado

		$sql = " select * from cidades where cod_cidade = '$cod_cidade' ";

		$r = $pdo->query($sql);

		$dados = $r->fetch(PDO::FETCH_ASSOC);

		// se conseguiu obter o registro
		if( $dados )
		{
			$nome = $dados['nome'];
			$uf   = $dados['uf'];
		}
		else
		{
			echo '<script language="javascritp">
						document.location = "cidades.php?erro=Cidade não encontrada para alteração !!!";
				  </script>
				 ';
		}

	} // se estiver alterando
	else
	{
		$nome = "";
		$uf	  = "";

	} // se estiver incluindo


?>
<!DOCTYPE html>
<html>
<head>
	<title>Sistema de Gestão Comercial</title>



<!-- incluindo a biblioteca jQuery -->
<script type="text/javascript" src="_js/jquery-3.4.1.min.js"></script>

<!-- incluindo a biblioteca de funções gerais -->
<script type="text/javascript" src="_js/funcoes.js"></script>	

<script type="text/javascript">
	
	$(document).ready(function(){

		//-------------------------------------------------------------
		$("div[id*=erro]").css("color", "#f00");

		//-------------------------------------------------------------
		$("#btcancelar").click(function(){
			document.location="cidades.php";
		});

		//-------------------------------------------------------------
		$("#fcad").submit(function(){

			var erros = 0;

			$("div[id*=erro]").html("");

			$("#nome").val(  $.trim($("#nome").val() ) );
			$("#uf").val(  $.trim($("#uf").val() ) );

			if( $("#nome").val() == "" )
			{
				$("#div_error_nome").html("O campo Nome deve ser preenchido !!!");
				erros++;
			}

			if( $("#uf").val() == "" )
			{
				$("#div_error_uf").html("O campo Unidade Federal deve ser preenchido !!!");
				erros++;
			}

			return erros == 0;

		}); // submit de fcad


	}); // read

</script>




</head>
<body>

	<h2>Cadastro de Cidades</h2>

	<form name="fcad" id="fcad" method="post" action="cidades-gravar.php">

		<input type="hidden" name="acao" id="acao" value="<?php echo $acao; ?>">
		<input type="hidden" name="cod_cidade" id="cod_cidade" value="<?= $cod_cidade; ?>">

		<p>		
			Nome da Cidade:<br>
			<input type="text" name="nome" id="nome" maxlength="100" value="<?= $nome; ?>" size="60">
			<div id="div_error_nome"></div>
		</p>

		<p>		
			Unidade Federal:<br>
			<input type="text" name="uf" id="uf" maxlength="2" value="<?= $uf; ?>" size="20">
			<div id="div_error_uf"></div>
		</p>

		<input type="submit" name="btgravar" id="btgravar" value=" Gravar ">
		&nbsp;&nbsp;
		<input type="button" name="btcancelar" id="btcancelar" value=" Cancelar ">

	</form>


</body>
</html>