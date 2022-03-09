<!DOCTYPE html>
<html>
<head>
	<title>Sistema de Gestão Comercial</title>


<script type="text/javascript" src="_js/jquery-3.6.0.min.js"></script>

<script type="text/javascript" src="_js/funcoes.js"></script>

<script type="text/javascript">

//----------------------------------------------------------------------------------	

/*************************

function pronto()
{
	alert('Hello World jQuery !!!');
}

// programando um evento chamado ready, o qual significa que será executado
// quando todo conteúdo da página estiver carregado e pronto
// Obs: a função pronto() foi passada como parâmetro sem os parênteses, porque
//	    não estamos chamando a função e sim atribuindo ela a um evento do javascript,
//	    no caso o evento ready do objeto document

$(document).ready( pronto );

/*************************/

$(document).ready( function(){

	//alert('Hello World jQuery !!!');

	// alterando a cor da font de todos os div para msg de erro
	$("div[id*=erro_]").css("color","#f00");



	// capturando o evento submit do formulário fcad
	$("#fcad").submit( function(){

		// se retornar false, não submete, se retornar true, submete o formulário

		// Limpar todas as mensagens de erro
		$("div[id*=erro_]").html("");

		var erros = 0;

		if( $.trim( $('#nome').val() ) == "" )
		{
			$("#erro_nome").html("O campo nome deve ser preenchido !!!");
			$('#nome').focus();
			erros++;
		}

		var nomes;
		nomes = $.trim($('#nome').val()).split(' ');

		if( nomes.length < 2 )
		{
			$("#erro_nome").html("O campo nome deve ser composto por nome e pelo menos um sobrenome !!!");
			$('#nome').focus();

			erros++;
		}		

		if( $('#cod_cidade').val() == "0" )
		{
			$("#erro_cod_cidade").html("A cidade do cliente deve ser selecionada !!!");
			$('#cod_cidade').focus();
			
			erros++;
		}

		// checkbox
		if( !$("#aceito_os_termos").prop('checked') )
		{
			$("#erro_aceito_os_termos").html("*** Falta o aceite dos termos !!!");

			if( !confirm("Você não marcou a opção de aceite dos termos, deseja realmente continuar ???") )
			{
				erros++;
			}
		}

		// radio
		if( $("[name=tipo_cliente]:checked").length == 0  )
		{
			$("#erro_tipo_cliente").html('Você deve selecionar o tipo de cliente !');
			erros++;
		}
		
		if( !verificaData($('#data_cadastro').val() ) )
		{
			$("#erro_data_cadastro").html('A data de cadastro precisa ser uma data válida !!!');		
			$('#data_cadastro').focus();
			erros++;
		}

		if( !numInteiro($('#numero_filhos').val()) )
		{
			$('#erro_numero_filhos').html('O número de filhos, deve ser um número válido !');
			$('#data_numero_filhos').focus();
			erros++;
		}

		if( $('#numero_filhos').val() < 0 )
		{
			$('#erro_numero_filhos').html('O número de filhos não pode ser negativo !');
			$('#data_numero_filhos').focus();
			erros++;
		}

		if( !numReal($('#renda_familiar').val()) )
		{
			$('#erro_renda_familiar').html('A renda familiar deve ser um número válido !');
			$('#data_renda_familiar').focus();
			erros++;
		}

		if( $('#renda_familiar').val() < 0 )
		{
			$('#erro_renda_familiar').html('A renda familiar não pode ser negativa !');
			$('#data_renda_familiar').focus();
			erros++;
		}	

		if( $.trim($('#observacoes').val()) == "" )
		{
			$('#erro_observacoes').html('Preecha algo nas observações !!!');
			$('#data_observacoes').focus();
			erros++;
		}

		if( !ValidaEmail($('#email').val()) )
		{
			$('#erro_email').html('O campo email é inválido !!!');
			$('#data_email').focus();
			erros++;
		}

		if( $.trim($('#senha').val()).length < 6 )
		{
			$('#erro_senha').html('A senha deve conter no mínimo 6 dígitos !!!');
			$('#data_senha').focus();
			erros++;
		}



		//if( erros == 0 ) return true; else return false;
		return erros == 0;

		

	}); /// $("#fcad").submit( function(){...



}); // ready()



</script>


</head>

<body>

	<h2>CADASTRO DE CLIENTE</h2>

	<form name="fcad" id="fcad" action="cliente-gravar.php" method="post">

		<input type="hidden" name="cod_cliente" id="cod_cliente" value="0">

		Nome:<br>
		<input type="text" name="nome" id="nome" maxlength="100" size="60" value="">
		<div id="erro_nome"></div>

		<p></p>

		Cidade:<br>
		<select name="cod_cidade" id="cod_cidade">
			<option value="0" selected="selected">Selecione uma cidade</option>	
			<option value="52">Adamantina</option>
			<option value="3">Luc&eacute;lia</option>
			<option value="76">Fl&oacute;rida Paulista</option>
			<option value="88">In&uacute;bia Paulista</option>
			<option value="107">Pacaembu</option>
		</select>
		<div id="erro_cod_cidade"></div>

		<p></p>

		<label>
		<input type="checkbox" name="aceito_os_termos" id="aceito_os_termos" value="1">
		Aceito os Termos do Contrato
		</label> 
		<div id="erro_aceito_os_termos"></div>

		<p></p>

		<label>
		<input type="radio" name="tipo_cliente" id="tipo_cliente1" value="1"> Pessoa Física
		</label>

		<label>
		<input type="radio" name="tipo_cliente" id="tipo_cliente2" value="2"> Pessoa Jurídica
		</label>

		<div id="erro_tipo_cliente"></div>

		<p></p>

		Data de Cadastro:<br>
		<input type="text" name="data_cadastro" id="data_cadastro" value="" maxlength="10">
		<div id="erro_data_cadastro"></div>

		<p></p>

		N&uacute;mero de Filhos:<br>
		<input type="text" name="numero_filhos" id="numero_filhos" value="">
		<div id="erro_numero_filhos"></div>

		<p></p>

		Renda Familiar:<br>
		<input type="text" name="renda_familiar" id="renda_familiar" value="">
		<div id="erro_renda_familiar"></div>

		<p></p>

		Observa&ccedil;&otilde;es:<br>
		<textarea name="observacoes" id="observacoes" maxlength="255" rows="5" cols="60"></textarea>
		<div id="erro_observacoes"></div>

		<p></p>

		E-mail:<br>
		<input type="text" name="email" id="email" maxlength="100" size="60" value="">
		<div id="erro_email"></div>

		<p></p>

		Senha: (Informe uma senha com no mínimo 6 dígitos)<br>
		<input type="password" name="senha" id="senha" maxlength="10" value="">
		<div id="erro_senha"></div>

		<p>&nbsp;</p>

		<input type="submit" name="btenviar" id="btenviar" value=" Gravar ">

		<!--
			<input type="button" name="btenviar2" id="btenviar2" value=" Gravar " onclick="enviar();">
		-->
	
	</form>


</body>
</html>