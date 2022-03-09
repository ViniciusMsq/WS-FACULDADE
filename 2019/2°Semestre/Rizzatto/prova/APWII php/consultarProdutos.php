<?php
 
 $con = mysqli_connect("localhost","root","vertrigo","loja");
 
 if (mysqli_connect_errno($con))
 {
  echo "Erro: " . mysqli_connect_error();
 }
 else
 {
   $sql = "SELECT * FROM produtos WHERE codigoProd = " . $_POST[codigoP] . ";";
   if($result = $con->query($sql))
   {  
    $prod = $result->fetch_object();
    echo '<p>Código: '. $prod->codigoProd ;
    echo '<br/> Descrição: '. $prod->descricaoProd;
    echo '<br />Preço: '. $prod->precoProd;
    echo '<br />Data de validade:'. $prod->dataValidadeProd;
	echo '<br />Data de validade:'. $prod->estoqueProd;
    echo '</p>';
   }
   else
   {
    echo "Erro: ".mysqli_error($con);
   }
   mysqli_close($con);
 }
?>