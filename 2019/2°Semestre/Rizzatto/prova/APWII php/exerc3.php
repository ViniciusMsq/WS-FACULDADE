<?php
  echo "Aplicação Web para mostrar os números primos de 0 a 50"."<br>";
  echo "<br>";
  echo "<br>";
  for($i=1;$i<=50;$i+=2)     // Falta o 2 que é primo
  {
	  for($j=2;$j<=$i-1;$i++)
	  {
		  $resto = $i%$j; 
	      if($resto == 0) 
             break;	
	  }		
	  if($resto != 0)
		  echo $i."<br>";
  }	  
?>