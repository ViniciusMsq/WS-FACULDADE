<?php

    class Classe_pai{

        protected int $A, $B;

        function __construct(int $a, int $b){
            $this->A = $a;
            $this->B = $b;
        }

        public function mostrar_multiplicacao(){
            $mult = ($this->A * $this->B);
            
            return $mult;
        }

        public function preecher_dados(int $a, int $b){
            $this->A = $a;
            $this->B = $b;
        }
    }
?>