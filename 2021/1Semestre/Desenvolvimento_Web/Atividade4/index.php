<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    
    <title>Atividade 4</title>
    <?php
        include_once("Classe_pai.php");
        include_once("Classe_filha.php");
    ?>
</head>
<body>
    <h2>Atividade 4</h2>

    <?php
        $class_pai = new Classe_pai(5,5);
        $class_filha = new Classe_filha(3,8);

        echo '<h4>PAI - Multiplicação(5*5):  '. $class_pai->mostrar_multiplicacao().'</h4>';
        echo '<h4>PAI - Inserção(7*4)  '. $class_pai->preecher_dados(7,4).'</h4>';
        echo '<h4>PAI - Multiplicação(7*4):  '. $class_pai->mostrar_multiplicacao().'</h4>';

        echo '-------------------------------<br>';

        echo '<h4>Filha - Multiplicação(3*8): '. $class_filha->mostrar_multiplicacao().'</h4>';
    ?>
</body>
</html>