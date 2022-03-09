<?php

$con = mysqli_connect("localhost","root","vertrigo","loja";)
if(mysqli_connect_errno($con))
{
	
	echo "Erro: ". mysqli_connect_error();

}else
{
	
	$sql = "Select * From clientes";
	$resultado = mysqli_query($con,$sql);
	echo "<h2>Clientes</h2>"; 
 	
 	while($cliente = myqsli_fetch_array($resultado))
 	{

 		echo $cliente['codigoCli']. "" . $cliente['nomeCli'].",".
 		$cliente['cidadeCli']."<br>";

 	}

 	mysqli_close($con)

}


?>