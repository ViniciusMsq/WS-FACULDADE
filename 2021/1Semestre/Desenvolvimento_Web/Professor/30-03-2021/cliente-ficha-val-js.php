<!DOCTYPE html>
<html>
<head>
	<title>Sistema de Gestão Comercial</title>


<script type="text/javascript" src="_js/funcoes.js"></script>

<script type="text/javascript">

//----------------------------------------------------------------------------------	
function enviar()
{
	// validando os campos 

	/**/
	if( document.getElementById('nome').value.trim() == "" )
	{
		alert("O campo nome deve ser preenchido !!!");
		document.getElementById('nome').focus();

		return; // interrompe a execução da função 
	}
	/**/

	var nomes;

	// a função split separa a string utilizada (campo nome) sempre que encontrar um caracter
	// separador, no caso o espaço ' ', e retorna em forma de um vetor
	// o trim retira os espaços em branco antes e depois da string
	nomes = document.getElementById('nome').value.trim().split(' ');

	/*
	// a propriedade length informa a quantidade de elementos de um vetor, 
	// ou a quantidade de caracteres de uma string
	alert( 'Total de elementos do vetor nomes: ' + nomes.length ); 

	for(i=0; i<nomes.length; i++)
	{
		alert(nomes[i]);
	}
	*/

	if( nomes.length < 2 )
	{
		alert("O campo nome deve ser composto por nome e pelo menos um sobrenome !!!");
		document.getElementById('nome').focus();

		return; // interrompe a execução da função 
	}


	if( document.getElementById('cod_cidade').value == "0" )
	{
		alert("A cidade do cliente deve ser selecionada !!!");
		document.getElementById('cod_cidade').focus();
		
		return; // interrompe a execução da função 
	}

	// checkbox
	if( !document.getElementById('aceito_os_termos').checked  )
	{
		if( !confirm("Você não marcou a opção de aceite dos termos, deseja realmente continuar ???") )
		{
			return;
		}
	}

	// radio
	if( !document.getElementById("tipo_cliente1").checked && !document.getElementById("tipo_cliente2").checked )
	{
		alert('Você deve selecionar o tipo de cliente !');
		return;
	}

	if( !verificaData(document.getElementById('data_cadastro').value ) )
	{
		alert('A data de cadastro precisa ser uma data válida !!!');		
		document.getElementById('data_cadastro').focus();
		return;
	}

	if( !numInteiro(document.getElementById('numero_filhos').value) )
	{
		alert('O número de filhos, deve ser um número válido !');
		document.getElementById('numero_filhos').focus();
		return;
	}

	if( document.getElementById('numero_filhos').value < 0 )
	{
		alert('O número de filhos não pode ser negativo !');
		document.getElementById('numero_filhos').focus();
		return;
	}

	if( !numReal(document.getElementById('renda_familiar').value) )
	{
		alert('A renda familiar deve ser um número válido !');
		document.getElementById('renda_familiar').focus();
		return;
	}

	if( document.getElementById('renda_familiar').value < 0 )
	{
		alert('A renda familiar não pode ser negativa !');
		document.getElementById('renda_familiar').focus();
		return;
	}	

	if( document.getElementById('observacoes').value.trim() == "" )
	{
		alert('Preecha algo nas observações !!!');
		document.getElementById('observacoes').focus();
		return;	
	}

	if( !ValidaEmail(document.getElementById('email').value) )
	{
		alert('O campo email é inválido !!!');
		document.getElementById('email').focus();
		return;
	}


	if( document.getElementById('senha').value.trim().length < 6 )
	{
		alert('A senha deve conter no mínimo 6 dígitos !!!');
		document.getElementById('senha').focus();
		return;	
	}

	document.getElementById('fcad').submit();


} // function enviar()
//----------------------------------------------------------------------------------	


</script>


</head>

<body>

	<h2>CADASTRO DE CLIENTE</h2>

	<form name="fcad" id="fcad" action="cliente-gravar.php" method="post">

		<input type="hidden" name="cod_cliente" id="cod_cliente" value="0">

		Nome:<br>
		<input type="text" name="nome" id="nome" maxlength="100" size="60" value="">

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

		<p></p>

		<label>
		<input type="checkbox" name="aceito_os_termos" id="aceito_os_termos" value="1">
		Aceito os Termos do Contrato
		</label> 

		<p></p>

		<label>
		<input type="radio" name="tipo_cliente" id="tipo_cliente1" value="1"> Pessoa Física
		</label>

		<label>
		<input type="radio" name="tipo_cliente" id="tipo_cliente2" value="2"> Pessoa Jurídica
		</label>

		<p></p>

		Data de Cadastro:<br>
		<input type="text" name="data_cadastro" id="data_cadastro" value="" maxlength="10">

		<p></p>

		N&uacute;mero de Filhos:<br>
		<input type="text" name="numero_filhos" id="numero_filhos" value="">

		<p></p>

		Renda Familiar:<br>
		<input type="text" name="renda_familiar" id="renda_familiar" value="">

		<p></p>

		Observa&ccedil;&otilde;es:<br>
		<textarea name="observacoes" id="observacoes" maxlength="255" rows="5" cols="60"></textarea>

		<p></p>

		E-mail:<br>
		<input type="text" name="email" id="email" maxlength="100" size="60" value="">

		<p></p>

		Senha: (Informe uma senha com no mínimo 6 dígitos)<br>
		<input type="password" name="senha" id="senha" maxlength="10" value="">

		<p>&nbsp;</p>

		<!--
			<input type="submit" name="btenviar" id="btenviar" value=" Gravar ">
		-->

		<input type="button" name="btenviar2" id="btenviar2" value=" Gravar " onclick="enviar();">


	</form>


</body>
</html>