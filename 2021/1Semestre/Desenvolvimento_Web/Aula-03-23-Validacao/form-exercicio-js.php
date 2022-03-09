<html>
<head>
	<title>Cadastro</title>
	<script type="text/javascript" src="funcoes.js"></script>

	<script>
		function enviar(){
			
			//nome
			var nome = document.getElementById('nome').value.trim().split(' ');
			if( nome.length < 2 )
			{
				alert("O campo nome deve ter pelo menos um sobrenome");
				document.getElementById('nome').focus();

				return;
			}

			//radio
			if( !document.getElementById("opcrad1").checked && !document.getElementById("opcrad2").checked && !document.getElementById("opcrad3").checked)
			{
				alert('Você deve selecionar um tipo radio !');
				return;
			}

			//cheackbox
			if( !document.getElementById('check1').checked && !document.getElementById('check2').checked && !document.getElementById('check3').checked)
			{
				alert("selecione algum check")
				return;
			}

			//idade
			if( !numInteiro(document.getElementById('idade').value) )
			{
				alert('Idade inválida !');
				document.getElementById('idade').focus();
				return;
			}

			if( document.getElementById('idade').value < 18 )
			{
				alert('Deve ser maior de 18');
				document.getElementById('idade').focus();
				return;
			}

			//salario
			if( !numReal(document.getElementById('salario').value) )
			{
				alert('O salario deve ser um número válido !');
				document.getElementById('salario').focus();
				return;
			}

			if( document.getElementById('salario').value < 1000 )
			{
				alert('O salario não pode ser menor que 1000 !');
				document.getElementById('salario').focus();
				return;
			}
			
			//cpf
			if(!validaCPF(document.getElementById('cpf').value)){
				alert('cpf invalido')
				return;
			}

			//data
			if( !verificaData(document.getElementById('dt_nascimento').value ) )
			{
				alert('A data de nascimento invalida');		
				document.getElementById('dt_nascimento').focus();
				return;
			}

			//combobox
			if( document.getElementById('combo1').value == "0" )
			{
				alert("Combobox nao selecionado");
				document.getElementById('combo1').focus();
				
				return;
			}

			//caixa de texto
			if( document.getElementById('obs').value.trim() == "" )
			{
				alert('Preecha a area de texto');
				document.getElementById('obs').focus();
				return;	
			}

			//senha
			if( document.getElementById('senha').value.trim().length < 8 )
			{
				alert('A senha deve conter no mínimo 8 dígitos');
				document.getElementById('senha').focus();
				return;	
			}
			if( document.getElementById('senha2').value != document.getElementById('senha').value )
			{
				alert('A senha deve ser igual');
				document.getElementById('senha2').focus();
				return;	
			}

			document.getElementById('form1').submit();

		}
	</script>
	
</head>

<body>
<p><b>ESTE &Eacute; MEU SEGUNDO CADASTRO EM HTML</b> </p>

<form name="form1" id="form1" action="cadastro-unifai.php" method="post">

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
	<input type="checkbox" name="check2" id="check2" value="2"  />
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
	<input type="password" name="senha" id="senha" value="" maxlength="10" width="30" /><br>
	Confirme a senha Senha: <br />
	<input type="password" name="senha2" id="senha2" value="" maxlength="10" width="30" />
	
	<p>
	
	<input type="button" name="btenviar" id="btenviar" value=" Gravar " onclick="enviar();" />
	&nbsp;&nbsp;&nbsp;&nbsp;
	<input type="reset" name="btlimpar" id="btlimpar" value=" Limpar " />



</form>




</body>
</html>
