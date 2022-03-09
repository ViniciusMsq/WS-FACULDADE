<!DOCTYPE html>
<html>
<head>
	<title>Prova 1o Bimestre</title>

	<script type="text/javascript" src="_js/jquery-3.6.0.min.js"></script>

<script type="text/javascript">
	
	$(document).ready(function(){

		$("div[id*=error]").css("color","#f00");

		$("#flogin").submit(function(){

			var erros = 0;

			$("div[id*=error]").html("");

			if( $.trim($("#login").val()) == "" )
			{
				$("#div_error_login").html("O campo login deve ser informado!");
				erros++;
			}


			if( $.trim($("#senha").val()) == "" )
			{
				$("#div_error_senha").html("O campo senha deve ser informado!");
				erros++;
			}

			return erros == 0;

		}) // submit de flogin

	}); // ready

</script>	

</head>
<body>
	<h2>Prova 1o Bimestre</h2>

	<form name="flogin" id="flogin" method="post" action="autenticar.php">

		Login:<br>
		<input type="text" name="login" id="login" value="">
		<div id="div_error_login"></div>

		<p></p>

		Senha:<br>
		<input type="password" name="senha" id="senha" value="">
		<div id="div_error_senha"></div>

		<p></p>
		<input type="submit" name="btenviar" id="btenviar" value=" Acessar ">

	</form>

</body>
</html>