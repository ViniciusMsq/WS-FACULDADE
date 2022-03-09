<?php
    $salario = 1800.45;

    if( $salario < 2000){
        $salario = $salario * 1.25;
        echo "O novo salario é ". number_format($salario,2,',','.');
    }

    echo "<br><br>";

    $x = 8;
    if($x%2==0){
        echo "$x contem numero par";
    }else{
        echo "$x contem numero impar";
    }

    echo "<br><br>";

    $x = 3;
    $y = 10;

    if($x>$y){
        echo "$x é maior que $y";
    }elseif($x<$y){
        echo "$x é menor que $y";
    }else{
        echo "$x é igual a $y";
    }

    echo "<br><br>";

    $dia_semana = date('w');

    switch($dia_semana){
        case 0:
            echo "Domingo";
            break;
        case 1:
            echo "Segunda";
            break;
        case 2:
            echo "Terça";
            break;
        case 3:
            echo "Quarta";
            break;
        case 4:
            echo "Quinta";
            break;
        case 5:
            echo "Sexta";
            break;
        case 6:
            echo "Sabado";
            break;
        default:
            echo "Dia errado meu truta";
            break;
    }

?>