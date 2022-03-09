<?php
    //Matriz
    $matriz[1][1] = 'A';
    $matriz[1][2] = 'B';
    
    $matriz[2][1] = 'C';
    $matriz[2][2] = 'D';

    $matriz[3][1] = 'E';
    $matriz[3][2] = 'F';

    for($i=1; $i<=3; $i++){
        for($j=1; $j<=2; $j++){
            echo $matriz[$i][$j] . ' ; ';
        }
        echo"<br>";
    }

    echo"<br><br> ";

    foreach($matriz as $linha){
        foreach($linha as $valor){
            echo $valor . ' ; ';
        }
        echo"<br>";
    }

?>