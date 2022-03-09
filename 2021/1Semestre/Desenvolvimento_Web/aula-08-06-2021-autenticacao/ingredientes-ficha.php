<?php
	$acao = @$_POST['acao'];
	$cod_ingrediente = @$_POST['cod_ingrediente'];

	if( $acao != 'alterar' and $acao != 'incluir' )
	{
		echo '<script language="javascritp">
					document.location = "index.php?modulo=ingredientes&erro=Ação inválida !!!";
			  </script>
			 ';
	}


	if( $acao == 'alterar' )
	{
		// buscar os dados do registro a ser alterado

		$sql = " select * from ingredientes where cod_ingrediente = '$cod_ingrediente' ";

		$r = $pdo->query($sql);

		$dados = $r->fetch(PDO::FETCH_ASSOC);

		// se conseguiu obter o registro
		if( $dados )
		{
			$descricao       = $dados['descricao'];
			$valor_unitario  = floatBR($dados['valor_unitario']);    
			$cod_unidade     = $dados['cod_unidade'];    
		}
		else
		{
			echo '<script language="javascritp">
						document.location = "index.php?modulo=ingredientes&erro=Registro não encontrado para alteração !!!";
				  </script>
				 ';
		}

	} // se estiver alterando
	else
	{
		$descricao        = "";
		$valor_unitario   = "0";
		$cod_unidade      = "";

	} // se estiver incluindo


?>

<script type="text/javascript">
	
	$(document).ready(function(){

		//-------------------------------------------------------------
		$("div[id*=erro]").css("color", "#f00");

		//-------------------------------------------------------------
		$("#btcancelar").click(function(){
			document.location="index.php?modulo=ingredientes";
		});

		//-------------------------------------------------------------
		$("#fcad").submit(function(){

			var erros = 0;

			$("div[id*=erro]").html("");

			$("#descricao").val(  $.trim($("#descricao").val() ) );
			if( $("#descricao").val() == "" )
			{
				$("#div_error_descricao").html("O campo Descrição deve ser preenchido !!!");
				erros++;
			}

			if( $("#cod_unidade").val() == "0" )
			{
				$("#div_error_cod_unidade").html("O campo Unidade de Medida deve ser selecionado !!!");
				erros++;
			}

			$("#valor_unitario").val(  $.trim($("#valor_unitario").val() ) );
			if( !numReal( $("#valor_unitario").val()  ) )
			{
				$("#div_error_valor_unitario").html("O campo Valor Unitário deve conter um valor numérico válido. <br>Informe o valor 0 (zero) caso não tenha o valor unitário deste ingrediente  !!!");
				erros++;
			}



			return erros == 0;

		}); // submit de fcad


	}); // read

</script>




	<h2>Cadastro de Ingredientes</h2>

	<form name="fcad" id="fcad" method="post" action="ingredientes-gravar.php">

		<input type="hidden" name="acao" id="acao" value="<?php echo $acao; ?>">
		<input type="hidden" name="cod_ingrediente" id="cod_ingrediente" value="<?= $cod_ingrediente; ?>">

		<p>		
			Descrição:<br>
			<input type="text" name="descricao" id="descricao" maxlength="100" value="<?= $descricao; ?>" size="60">
			<div id="div_error_descricao"></div>
		</p>

		<p>
			Valor Unitário:<br>
			<input type="text" name="valor_unitario" id="valor_unitario" value="<?= $valor_unitario; ?>">
			<div id="div_error_valor_unitario"></div>
		</p>

		<p>
			Unidade de Medida:<br>
			<select name="cod_unidade" id="cod_unidade">
				<option value="0">Selecione uma unidade</option>	

				<?php
					$r = $pdo->query("select * from unidades order by descricao");

					while( $d = $r->fetch(PDO::FETCH_ASSOC) )
					{

						if( $cod_unidade == $d['cod_unidade'] ) 
							$selected = ' selected="selected" ';
						else
							$selected = '';

						echo '<option value="'.$d['cod_unidade'].'"  '.$selected.'  >'.$d['descricao'].' ('.$d['sigla'].')</option>';

					} // while

				?>


			</select>
			<div id="div_error_cod_unidade"></div>
		</p>


		<input type="submit" name="btgravar" id="btgravar" value=" Gravar ">
	
		&nbsp;&nbsp;
	
		<input type="button" name="btcancelar" id="btcancelar" value=" Cancelar ">

	</form>

