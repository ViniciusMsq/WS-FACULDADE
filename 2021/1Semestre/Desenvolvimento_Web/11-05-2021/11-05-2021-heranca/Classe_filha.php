<?php
	
include_once("Classe_pai.php");

class Classe_filha extends Classe_pai
{	
	//-----------------------------------------------------------------------------------
	function __construct()
	{
		$this->A = 100;
		$this->B = 200;
		$this->C = 300;
	}

	//-----------------------------------------------------------------------------------
	public function mensagem()
	{
		echo '<p>Este é o método mensagem da classe pai reescrito na classe filha !!!</p>';

		echo '<p>A seguir o método mensagem original da classe pai é chamado !!!</p>';

		parent::mensagem();

	}

} // Classe_filha

?>