<!DOCTYPE html>
<html>
<head>
	<title>Autenticar</title>
	<link rel="stylesheet" type="text/css" href="Autenticar.css">

</head>
<body>

<h1>Verificação</h1>
    <div id="caixa">
        <div id="principal"> 
            <?php
               // strtoupper -> conversão para maiusculo, verificando caso seja digitado em minusculo
				if(strtoupper ($_POST['login'])=='UNIFAI' && $_POST['senha']=='2021'){
					echo " Usuario autenticado com sucesso &nbsp &nbsp &nbsp";
				}else{
					echo " Usuario e/ou senha invalidos &nbsp &nbsp &nbsp";
				}
            ?>
        </div>
    </div>



</body>
</html>