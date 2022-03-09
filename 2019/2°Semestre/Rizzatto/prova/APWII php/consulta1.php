<?php
$con = mysqli_connect("localhost","root","vertrigo","loja");
if (mysqli_connect_errno($con))
{
  echo "Erro: " . mysqli_connect_error();
}
else
{
  $sql = "SELECT * FROM clientes";
  $resultado = mysqli_query($con,$sql);
  echo "<h2>Clientes</h2>";
  while($cliente = mysqli_fetch_array($resultado))
  {
    echo $cliente['codigoCli'] . " " . $cliente['nomeCli'].", " . 
	$cliente['cidadeCli']."<br>";
  }
  mysqli_close($con);
}
?>