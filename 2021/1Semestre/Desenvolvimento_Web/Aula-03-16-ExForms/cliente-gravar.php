
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Resultados</title>
    <link rel="stylesheet" type="text/css" href="gravar-cliente.css">
</head>
<body>
    <h1>Resultados</h1>
    <div id="caixa">
        <div id="principal"> 
            <?php
                echo "<br><strong>Codigo cliente:</strong> " . $_POST["cod_cliente"]. "<br>";
                echo "<br><strong>data:</strong> " . $_POST["data_cadastro"]. "<br>";
                echo "<br><strong>nome:</strong> " . $_POST["nome"]. "<br>";
                echo "<br><strong>e-mail:</strong> " . $_POST["email"]. "<br>";
                echo "<br><strong>codigo cidade:</strong> " . $_POST["cod_cidade"]. "<br>";
                echo "<br><strong>Pessoa:</strong> " . $_POST["pf_pj"]. "<br>";
                echo "<br><strong>filhos:</strong> " . $_POST["numero_filhos"]. "<br>";
                echo "<br><strong>renda:</strong> " . $_POST["renda_familiar"]. "<br>";
                echo "<br><strong>observações:</strong> " . $_POST["obs"]. "<br>";
                echo "<br><strong>senha:</strong> " . $_POST["senha"]. "<br>";
                echo "<br><strong>termos:</strong> " . $_POST["termos"]. "<br>";
            ?>
        </div>
    </div>
</body>
</html>