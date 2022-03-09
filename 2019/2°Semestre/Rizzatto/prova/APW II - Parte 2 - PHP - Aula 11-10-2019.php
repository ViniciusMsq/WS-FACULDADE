<?php
// Criando uma conexão com o bando de dados
$con = mysqli_connect("localhost","root","vertrigo","loja");
// Checando a conexão
if (mysqli_connect_errno($con)){
echo "Erro ao conectar com a base de dados: ".mysqli_connect_error();
}else{
echo "Conexão Aberta e com o Banco de Dados disponível<br>";
}
mysqli_close($con);
echo "Conexão Encerra com o Banco de Dados disponível";
?>