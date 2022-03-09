<?php

class Classe_pai
{

	public    $A = 1;
	private   $B = 2;
	protected $C = 3;

	public function mensagem()
	{
		echo '<p>Esta é uma frase gerada na classe Pai !!!</p>';

		echo 'O valor da propriedade A é: ' .     $this->A;
		echo '<br>O valor da propriedade B é: ' . $this->B;
		echo '<br>O valor da propriedade C é: ' . $this->C;
	}

} // Classe_pai


?>