<!DOCTYPE html>
<html>
<head>
	<title>Sistema de Gestão Comercial</title>
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

		Senha:<br>
		<input type="password" name="senha" id="senha" maxlength="10" value="">

		<p>&nbsp;</p>

		<input type="submit" name="btenviar" id="btenviar" value=" Gravar ">



	</form>


</body>
</html>