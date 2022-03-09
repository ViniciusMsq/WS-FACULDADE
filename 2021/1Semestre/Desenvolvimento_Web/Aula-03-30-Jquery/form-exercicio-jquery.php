<html>
<head>
	<meta charset="UTF-8">
	<title>Cadastro</title>

	<script type="text/javascript" src="jquery-3.6.0.min.js"></script>
	<script type="text/javascript" src="funcoes.js"></script>

	<script type="text/javascript">
		$(document).ready( function(){

		//alert('Hello World jQuery !!!');

		// alterando a cor da font de todos os div para msg de erro
			$("div[id*=erro_]").css("color","#f00");

		// capturando o evento submit do formulário fcad
			$("#form1").submit( function(){
				// se retornar false, não submete, se retornar true, submete o formulário

				// Limpar todas as mensagens de erro
				$("div[id*=erro_]").html("");

				var erros = 0;

				//nome
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

				//radio
				if( $("[name=opcrad]:checked").length == 0  )
				{
					$("#erro_opcrad").html('Você deve selecionar um "radio" !');
					erros++;
				}

				//checkbox
				if( !$("#check1").prop('checked') && !$("#check2").prop('checked') && !$("#check3").prop('checked') )
				{
					$("#erro_check1").html("Marque um checkbox");
					erros++;		
				}
				
				//Idade
				if( !numInteiro($('#idade').val()))
				{
					$('#erro_idade').html('A idade deve ser um número válido');
					$('#idade').focus();
					erros++;
				}
				if( $('#idade').val() < 18 )
				{
					$('#erro_idade').html('A idade não pode ser menor que 18 !');
					$('#idade').focus();
					erros++;
				}

				//Salario
				if( !numReal($('#salario').val()) )
				{
					$('#erro_salario').html('O Salario deve ser um número válido !');
					$('#salario').focus();
					erros++;
				}
				if( $('#salario').val() < 1000 )
				{
					$('#erro_salario').html('O Salario não pode ser inferior a 1000,00 reais !');
					$('#salario').focus();
					erros++;
				}

				//CPF
				if(!validaCPF($('#cpf').val())){
					$("#erro_cpf").html('CPF invalido');		
					$('#cpf').focus();
					erros++;
				}

				//Data
				if( !verificaData($('#dt_nascimento').val() ) )
				{
					$("#erro_dt_nascimento").html('A data de nascimento tem que ser valida');		
					$('#ddt_nascimento').focus();
					erros++;
				}

				//ComboBox
				if( $('#combo1').val() == "0" )
				{
					$("#erro_combo1").html("Selecione algo no comboBox");
					$('#combo1').focus();
					
					erros++;
				}

				//Textarea
				if( $.trim($('#obs').val()) == "" )
				{
					$('#erro_obs').html('Preecha algo nas observações');
					$('#obs').focus();
					erros++;
				}

				//Senha
				if( $.trim($('#senha').val()).length < 8 )
				{
					$('#erro_senha').html('A senha deve conter no mínimo 8 dígitos');
					$('#senha').focus();
					erros++;
				}
				if( $.trim($('#senha2').val()) != $.trim($('#senha').val()) )
				{
					$('#erro_senha2').html('A senha deve ser igual');
					$('#senha2').focus();
					erros++;
				}
				//if( erros == 0 ) return true; else return false;
				return erros == 0;

				

			}); /// $("#fcad").submit( function(){...
		});

	</script>
</head>

<body>
<p><b>ESTE &Eacute; MEU SEGUNDO CADASTRO EM HTML</b> </p>

<form name="form1" id="form1" action="gravar.php" method="post">

	Nome: <br>
	<input type="text"  name="nome" id="nome" maxlength="100" size="80" value="" />
	<div id="erro_nome"></div>
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
	<div id="erro_opcrad"></div>
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
	<div id="erro_check1"></div>
	<p>
	
	Idade:  <br>
	<input type="text" name="idade" id="idade" size="10" value="" />
	<div id="erro_idade"></div>

	<p>
	
	Sal&aacute;rio:  <br>
	<input type="text" name="salario" id="salario" size="10" value="" />
	<div id="erro_salario"></div>

	<p>
	
	CPF:  <br>
	<input type="text" name="cpf" id="cpf" size="20" value="" />
	<div id="erro_cpf"></div>
	<p>

	Data de Nascimento:  <br>
	<input type="text" name="dt_nascimento" id="dt_nascimento" size="10" value="" />
	<div id="erro_dt_nascimento"></div>
	<p>
	

	<p>
	Informa&ccedil;&otilde;es em caixa combinada (combobox): 
	<select name="combo1" id="combo1" >
		<option value="0"  selected="selected"> Selecione -----</option>
		<option value="100"> Cem </option>
		<option value="100000"> Cem Mil</option>
		<option value="100000000"> Um milh&atilde;o </option>
	</select>
	<div id="erro_combo1"></div>
	<p>
	&Aacute;rea de Texto: <br />
	<textarea name="obs" id="obs" rows="4" cols="60"></textarea>
	<div id="erro_obs"></div>
	<p>
	Campo Senha: <br />
	<input type="password" name="senha" id="senha" value="" maxlength="10" width="30" />
	<div id="erro_senha"></div>
	
	<p>
	<p>
	Confirmação de Senha: <br />
	<input type="password" name="senha2" id="senha2" value="" maxlength="10" width="30" />
	<div id="erro_senha2"></div>
	
	<p>
	
	<input type="submit" name="btenviar" id="btenviar" value=" Gravar " />
	&nbsp;&nbsp;&nbsp;&nbsp;
	<input type="reset" name="btlimpar" id="btlimpar" value=" Limpar " />



</form>




</body>
</html>
