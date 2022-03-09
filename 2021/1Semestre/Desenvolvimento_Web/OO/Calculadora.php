<?php

	class Calculadora
	{
		public $A;
		public $B;

		public function GetSoma()
		{
			return $this->A + $this->B;
		}

		public function GetSubtracao()
		{
			return $this->A - $this->B;
		}

		public function GetMultiplicacao()
		{
			return $this->A * $this->B;
		}

		public function GetDivisao()
		{
			if(!($this->B == 0)){
				return $this->A / $this->B;
			}

			return "B = 0, divisão nao sera feita";
		}
	}

?>

