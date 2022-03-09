<?php

    include_once("Classe_pai.php");

    class Classe_filha extends Classe_pai{

        public function mostrar_multiplicacao(){
            echo "Nunca serão, contra tudo e contra todos! ♠Vai Corinthians♠";
            
            return parent::mostrar_multiplicacao();

        }
    }
?>