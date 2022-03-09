<html>
<head>
	<title>Cadastro</title>

</head>

<body>
<p><b>ESTE &Eacute; MEU SEGUNDO CADASTRO EM HTML</b> </p>

<form name="form1" id="form1" action="gravar.php" method="post">

	Nome: <br>
	<input type="text"  name="nome" id="nome" maxlength="100" size="80" value="" />

	<p>		
	Op&ccedil;&otilde;es de r&aacute;dio:<br />
	<label>
	<input type="radio" name="opcrad" id="opcrad1" value="1" /> 
	Op&ccedil;&atilde;o 1 <br />
	</label>

	<label>
	<input type="radio" name="opcrad" id="opcrad2" value="2" /> 
	Op&ccedil;&atilde;o 2 <br />
	</label>

	<label>
	<input type="radio" name="opcrad" id="opcrad3" value="3" /> 
	Op&ccedil;&atilde;o 3 <br />
	</label>
	
	<p>
	Op&ccedil;&otilde;es de checkbox:<br />
	<label>
	<input type="checkbox" name="check1" id="check1" value="1" />
	Check 1 <br />
	</label>

	<label>
	<input type="checkbox" name="check2" id="check3" value="2"  />
	Check 2 <br />
	</label>

	<label>
	<input type="checkbox" name="check3" id="check3" value="3"  />
	Check 3 <br />
	</label>


	<p>
	
	Idade:  <br>
	<input type="text" name="idade" id="idade" size="10" value="" />
	<p>
	
	Sal&aacute;rio:  <br>
	<input type="text" name="salario" id="salario" size="10" value="" />
	<p>
	
	CPF:  <br>
	<input type="text" name="cpf" id="cpf" size="20" value="" />
	<p>

	Data de Nascimento:  <br>
	<input type="text" name="dt_nascimento" id="dt_nascimento" size="10" value="" />
	<p>
	

	<p>
	Informa&ccedil;&otilde;es em caixa combinada (combobox): 
	<select name="combo1" id="combo1" >
		<option value="0"  selected="selected"> Selecione -----</option>
		<option value="100"> Cem </option>
		<option value="100000"> Cem Mil</option>
		<option value="100000000"> Um milh&atilde;o </option>
	</select>
	
	<p>
	&Aacute;rea de Texto: <br />
	<textarea name="obs" id="obs" rows="4" cols="60"></textarea>
	
	<p>
	Campo Senha: <br />
	<input type="password" name="senha" id="senha" value="" maxlength="10" width="30" />
	
	<p>
	
	<input type="submit" name="btenviar" id="btenviar" value=" Gravar " />
	&nbsp;&nbsp;&nbsp;&nbsp;
	<input type="reset" name="btlimpar" id="btlimpar" value=" Limpar " />



</form>




</body>
</html>
