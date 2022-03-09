<?php
    //vetor
    $vetor1[1] = "one";
    $vetor1[2] = "two";
    $vetor1[3] = 29;
    //vetor sem indice
    $vetor2[] = 40;
    $vetor2[] = 100;
    $vetor2[] = 'teste';

    
    //imprimindo vetor sem saber suas chaves
    foreach($vetor2 as $chave => $valor){
        echo "<br>$chave = $valor ";
    }
    echo "<br>";
    for($i=1; $i<=3; $i++){
        echo "<br>" . $vetor1[$i];
    }

    echo "<br>";

    $cliente['cod_cliente'] = 158;
    $cliente['nome'] = 'Benedito';
    $cliente['telefone'] = '18 777 777';

    echo "Nome.: " . $cliente['nome'];

    echo"<br> <br>foreach<br>";
    foreach($cliente as $valor){
        echo "<br>$valor";
    }
    echo"<br> <br>foreach com chaves<br>";

    foreach($cliente as $chave => $valor){
        echo "<br>$chave = $valor";
    }
?>