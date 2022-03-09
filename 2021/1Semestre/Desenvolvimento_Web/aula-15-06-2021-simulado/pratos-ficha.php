<?php

	$acao = @$_POST['acao'];
	$cod_prato = @$_POST['cod_prato'];

	if( $acao != 'alterar' and $acao != 'incluir' )
	{
		echo '<script language="javascritp">
					document.location = "index.php?modulo=pratos&erro=Ação inválida !!!";
			  </script>
			 ';
	}


	if( $acao == 'alterar' )
	{
		// buscar os dados do registro a ser alterado

		$sql = " select * from pratos where cod_prato = '$cod_prato' ";

		$r = $pdo->query($sql);

		$dados = $r->fetch(PDO::FETCH_ASSOC);

		// se conseguiu obter o registro
		if( $dados )
		{
			$descricao = $dados['descricao'];
			$valor_unitario   = $dados['valor_unitario'];
			$cod_categoria   = $dados['cod_categoria'];

		}
		else
		{
			echo '<script language="javascritp">
						document.location = "index.php?modulo=pratos&erro=prato não encontrada para alteração !!!";
				  </script>
				 ';
		}

	} // se estiver alterando
	else
	{
		$descricao = "";
		$valor_unitario	  = "";
		$cod_categoria = ""; 
	} // se estiver incluindo


?>

<script type="text/javascript">
	
	$(document).ready(function(){

		//-------------------------------------------------------------
		$("div[id*=erro]").css("color", "#f00");

		//-------------------------------------------------------------
		$("#btcancelar").click(function(){
			document.location="index.php?modulo=pratos";
		});

		//-------------------------------------------------------------
		$("#fcad").submit(function(){

			var erros = 0;

			$("div[id*=erro]").html("");

			$("#descricao").val(  $.trim($("#descricao").val() ) );
			$("#valor_unitario").val(  $.trim($("#valor_unitario").val() ) );
			$("#cod_categoria").val(  $.trim($("#cod_categoria").val() ) );


			if( $("#descricao").val() == "" )
			{
				$("#div_error_descricao").html("O campo descricao deve ser preenchido !!!");
				erros++;
			}

			if( $("#valor_unitario").val() == "" )
			{
				$("#div_error_valor_unitario").html("O campo Valor unitario deve ser preenchido !!!");
				erros++;
			}

			if( $("#cod_categoria").val() == "" )
			{
				$("#div_error_cod_categoria").html("O campo cod_categoria deve ser preenchido !!!");
				erros++;
			}

			return erros == 0;

		}); // submit de fcad


	}); // read

</script>


	<h2>Cadastro de pratos</h2>

	<form name="fcad" id="fcad" method="post" action="pratos-gravar.php">

		<input type="hidden" name="acao" id="acao" value="<?php echo $acao; ?>">
		<input type="hidden" name="cod_prato" id="cod_prato" value="<?= $cod_prato; ?>">

		<p>		
			descricao da prato:<br>
			<input type="text" name="descricao" id="descricao" maxlength="100" value="<?= $descricao; ?>" size="60">
			<div id="div_error_descricao"></div>
		</p>

		<p>		
			Valor unitario:<br>
			<input type="text" name="valor_unitario" id="valor_unitario" maxlength="2" value="<?= $valor_unitario; ?>" size="20">
			<div id="div_error_valor_unitario"></div>
		</p>
		<!-- <p>		
			codigo categoria:<br>
			<input type="text" name="cod_categoria" id="cod_categoria" maxlength="2" value="<?= $cod_categoria; ?>" size="20">
			<div id="div_error_cod_categoria"></div>
		</p> -->
		<p>
			Categoria:<br>
			<select name="cod_categoria" id="cod_categoria">
				<option value="0">Selecione uma categoria</option>	

				<?php
					$r = $pdo->query("select * from categorias order by descricao");

					while( $d = $r->fetch(PDO::FETCH_ASSOC) )
					{

						if( $categoria == $d['cod_categoria'] ) 
							$selected = ' selected="selected" ';
						else
							$selected = '';

						echo '<option value="'.$d['cod_categoria'].'"  '.$selected.'  >'.$d['descricao'].'</option>';

					} // while

				?>


			</select>
			<div id="erro_categoria"></div>
		</p>

		<input type="submit" name="btgravar" id="btgravar" value=" Gravar ">
		&nbsp;&nbsp;
		<input type="button" name="btcancelar" id="btcancelar" value=" Cancelar ">

	</form>

