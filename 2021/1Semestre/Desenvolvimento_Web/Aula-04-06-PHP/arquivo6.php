<?php
    $s = 0;
    $c = 1;
    $i = 2;
    while($c<=100){
        $s += $i;
        $i += 2;
        $c++;
    }

    echo "valor total é $s";
?>