<?php
 $con = mysqli_connect("localhost","root","vertrigo","loja");
 if (mysqli_connect_errno($con))
 {
  echo "Erro: " . mysqli_connect_error();
 }
 else
 {
   $sql = "INSERT INTO produtos VALUES('$_POST[codigoP]',
                                       '$_POST[descricaoP]',
									   '$_POST[precoP]',
									   '$_POST[dataVP]',
									   '$_POST[estoqueP]')";
   if(mysqli_query($con,$sql))
   {
    echo "Produto inserido com sucesso!!!";
   }
   else
   {
    echo "Erro: ".mysqli_error($con);
   }
   mysqli_close($con);
 }
?>