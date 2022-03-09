<?php

class Classe_teste
{

	function __construct()
	{
		echo '<p style="color:#00f;">Instanciando a classe teste...</p>';
	}

	function __destruct()
	{
		echo '<p style="color:#f00;">Objeto eliminado da memória...</p>';	
	}


} // class Classe_teste

?>
