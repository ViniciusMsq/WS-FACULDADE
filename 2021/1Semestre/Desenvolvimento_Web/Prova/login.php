<html>
<head>
	<meta charset="UTF-8">
	<title>Login</title>

    <link rel="stylesheet" type="text/css" href="login.css">
	
	<script type="text/javascript" src="jquery-3.6.0.min.js"></script>
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

				//login
				if( $.trim( $('#login').val() ) == "" )
				{
					$("#erro_login").html("O campo login deve ser preenchido");
					$('#login').focus();
					erros++;
				}

				//Senha
				if( $.trim($('#senha').val()).length < 4 )
				{
					$('#erro_senha').html('A senha deve conter no mínimo 4 dígitos');
					$('#senha').focus();
					erros++;
				}
				return erros == 0;

			});
		});

	</script>
</head>

<body>

	<div id="formulario">
		

		<form name="form1" id="form1" action="autenticar.php" method="post">
			<i><h1 id="titulo">Formulario de Login</h1></i>
			Login: <br>
			<input type="text"  name="login" id="login" maxlength="40" size="30" value="" />
			<div id="erro_login"></div>
			<br>		
			
			Senha: <br />
			<input type="password" name="senha" id="senha" value="" maxlength="12" width="30" />
			<div id="erro_senha"></div>
			
			<br>
			
			<input type="submit" name="btenviar" id="btenviar" value=" Sign in " />

		</form>
	</div>



</body>
</html>
