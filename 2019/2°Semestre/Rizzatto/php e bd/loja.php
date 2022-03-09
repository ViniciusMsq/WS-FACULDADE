<?php
$con = mysql_connect();

if(mysql_connect_errno($con)){
	echo "erro ao conectar com a base de dados";
	mysqli_connect_error();
}
mysql_close($con);
echo "conexão encerra";
?>