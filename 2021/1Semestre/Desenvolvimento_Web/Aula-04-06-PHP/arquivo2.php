<?php
    //outras formas de criação de vetor
    $vet = array('Janeiro', 'Fevereiro', 'Março');

    //com chaves definidas
    $vet2 = array('1' => 'Janeiro', '2' =>'Fevereiro', '3' => 'Março');

    foreach($vet as $chave => $valor){
        echo "<br>$chave = $valor ";
    }
    echo "<br>";
    foreach($vet2 as $chave => $valor){
        echo "<br>$chave = $valor ";
    }
?>