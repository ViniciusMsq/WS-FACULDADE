<?php
$con = mysqli_connect("localhost","root","vertrigo","loja");
if (mysqli_connect_errno($con))
{
  echo "Erro: " . mysqli_connect_error();
}
else
{
  $sql = "SELECT * FROM produtos";
  $resultado = mysqli_query($con,$sql);
  echo "<h2>Produtos</h2>";
  while($produto = mysqli_fetch_array($resultado))
  {
    echo $produto['codigoProd'] . " " . $produto['descricaoProd'].", " . 
	$produto['precoProd']."<br>";
  }
  mysqli_close($con);
}
?>