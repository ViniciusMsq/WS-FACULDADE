<?php
	const EXEMPLO2 = "Exemplo de constante";
	const pi = 3.141592;
	$vetor = array(0, 1, 2, 3);
	
	function F()
	{
		static $num = 100;
		return $num--;
	}
	

	for($i=1; $i<=100; $i++);
	echo " ".F();
    echo "<br>".EXEMPLO2; 
	echo "<br><br><br>".pi;
	echo "<br><br><br>";
	for($cont=1; $cont<=3; $cont++) 
    {
		echo " ".$vetor[$cont]." ".$cont;	
	}	
	
	$resto = 5%2;
	echo "<br><br><br>resto = ".$resto;
?>
