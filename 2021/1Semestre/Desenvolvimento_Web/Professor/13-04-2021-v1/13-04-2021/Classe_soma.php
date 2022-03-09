<?php

class Classe_soma
{
	public $x;
	public $y;

	public function imprimir_soma()
	{
		echo "<p>A soma de $this->x com $this->y é ". ($this->x + $this->y) ."</p>";
	}

	public function GetSoma()
	{
		return $this->x + $this->y;
	}

} // class Classe_soma()


?>

