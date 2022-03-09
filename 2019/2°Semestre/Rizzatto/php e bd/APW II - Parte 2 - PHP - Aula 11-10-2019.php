<?php
// Criando uma conexão com o bando de dados
$con = mysqli_connect("localhost","root","","loja");
// Checando a conexão
if (mysqli_connect_errno($con)){
	echo "Erro ao conectar com a base de dados: ".mysqli_connect_error();
}else{

	$sql = " SELECT * FROM clientes";
	$resultado = mysqli_query($con,$sql);
	echo "<h2>Clientes</h2>";
	while($clientes = mysqli_fetch_array($resultado)){
		echo $clientes ['codigoCli'] , 	" " , $cliente['nomeCli'], ", " , $cliente['cidadeCli'],"<br>";
	}
}
mysqli_close($con);
?>