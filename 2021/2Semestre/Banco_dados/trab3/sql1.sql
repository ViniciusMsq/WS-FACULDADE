CREATE PROCEDURE SP_ADD_CLIENTES
@NOME VARCHAR(100),
@CPF CHAR(11),
@TELEFONE VARCHAR(20),
@ENDERECO VARCHAR(100),
@COD_CIDADE INT,
@CEP CHAR(8),
@VALOR_DEVIDO FLOAT

AS 
BEGIN
SET @NOME = LTRIM(RTRIM(@NOME))
SET @CPF = LTRIM(RTRIM(@CPF))
SET @TELEFONE = LTRIM(RTRIM(@TELEFONE))
SET @COD_CIDADE = LTRIM(RTRIM(@COD_CIDADE))
SET @CEP = LTRIM(RTRIM(@CEP))
SET @VALOR_DEVIDO = LTRIM(RTRIM(@VALOR_DEVIDO))

IF @NOME = '' OR @CPF = '' OR @NOME IS NULL OR @CPF IS NULL
BEGIN
	PRINT('OS CAMPOS NOME E CPF NAO PODEM ESTAR EM BRANCOS! ')
END
IF NOT EXISTS (SELECT * FROM CLIENTES WHERE NOME = @NOME AND CPF = @CPF)
BEGIN
	IF @CEP = '' OR @CEP IS NULL
	BEGIN
		INSERT INTO CLIENTES (NOME,CPF,TELEFONE,COD_CIDADE,CEP,VALOR_DEVIDO)
		VALUES(@NOME, @CPF, @TELEFONE, @COD_CIDADE, '17800000', @VALOR_DEVIDO)
	END
	ELSE BEGIN
		INSERT INTO CLIENTES (NOME,CPF,TELEFONE,COD_CIDADE,CEP,VALOR_DEVIDO)
		VALUES(@NOME, @CPF, @TELEFONE, @COD_CIDADE, @CEP, @VALOR_DEVIDO)
	END
		PRINT('INCLUIDO COM SUCESSO! ')
END
ELSE BEGIN
	PRINT('ESTE CLIENTE JA ESTA CADASTRADO! ')
END
END
