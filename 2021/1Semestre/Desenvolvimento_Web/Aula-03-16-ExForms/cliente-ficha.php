<!DOCTYPE html>
<html lang="pt-br">
<head>
    <link rel="stylesheet" type="text/css" href="ficha-cliente.css">
    <meta charset="UTF-8">
    <title>Exercicio de formulario</title>
    <script type="text/javascript">

        //----------------------------------------------------------------------------------	
        function enviar()
        {
            console.log("ola");
            // validando os campos 

            if( document.getElementById('nome').value == "" )
            {
                alert("O campo nome deve ser preenchido !!!");
                document.getElementById('nome').focus();

                return; // interrompe a execução da função 
            }

            if( document.getElementById('cod_cidade').value == "0" )
            {
                alert("A cidade do cliente deve ser selecionada !!!");
                document.getElementById('cod_cidade').focus();
                
                return; // interrompe a execução da função 
            }

            document.getElementById('form1').submit();


        } // enviar()

    </script>
</head>
<body>
    <div id="formulario">
        <u><h1 id="titulo">Formulario</h1></u>
        
        <form name="form1" id="form1" action="cliente-gravar.php" method="post">
            
            <input type="hidden" name="cod_cliente" value="1">
            
            Data de cadastro <input type="datetime-local" id="data_cadastro" name="data_cadastro" value="2021-03-13T23:10" min="2021-03-016T00:00" max="2021-03-16T00:00">
            <br><br>
            Nome:<br> <input type="text" name="nome" id="nome" maxlength="100" size="50">
            <br><br>
            e-mail:<br> <input type="text" name="email">
            <br><br>
            cidade:<br>
                <select name="cod_cidade" id="cod_cidade">
                    <option value="0">Selecione uma cidade</option>
                    <option value="3500105">Adamantina</option>
                    <option value="3534807">Ouro verde</option>
                    <option value="3555109">Tupi Paulista</option>
                </select>
            <br><br>
            Pessoa:<br> <input type="radio" name="pf_pj" id="pf" value="fisica" checked="checked"/>Fisica
                    <input type="radio" name="pf_pj" id="pj" value="juridica"/>juridica
            <br><br>
            <div>
                <div class="caixa">
                    Numero de filhos: <input class="meio"type="text" name="numero_filhos" maxlength="2" size="1"></div>
                <div class="caixa">
                    Renda familiar:<input class="rnd"type="text" name="renda_familiar" size="10">
                </div>
            </div>
            <br><br>
            Observações:<br>
                <textarea name="obs" id="obs" rows="5" cols="50">Insira o texto.</textarea>
            <br><br>
            senha: <input type="password" name="senha">
            <br><br>
            aceito os termos: <input type="checkbox" name="termos" id="termos" value="1">
            <br><br>
            
            <input type=submit value="OK">
            
            <input type="button" name="btenviar2" id="btenviar2" value=" Gravar " onclick='enviar();'>
        </form>
    </div>
</body>
</html>