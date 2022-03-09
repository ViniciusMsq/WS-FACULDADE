CREATE TRIGGER TR_DEL_MOVTO
ON MOVIMENTACAO
FOR DELETE
AS 
BEGIN
	DECLARE @COD_CLIENTE INT, @TIPO_MOVTO CHAR(1), @VALOR FLOAT
	
	SELECT  @COD_CLIENTE = COD_CLIENTE,
			@TIPO_MOVTO = TIPO_MOVTO,
			@VALOR = ISNULL(VALOR,0)
		FROM DELETED

	IF @TIPO_MOVTO = 'C' OR @TIPO_MOVTO = 'c'
		BEGIN
			UPDATE CLIENTES 
				SET SALDO = SALDO - @VALOR 
			WHERE COD_CLIENTE = @COD_CLIENTE
		END
	IF @TIPO_MOVTO = 'D' OR @TIPO_MOVTO = 'd'
		BEGIN
			UPDATE CLIENTES 
				SET SALDO = SALDO + @VALOR 
			WHERE COD_CLIENTE = @COD_CLIENTE
		END
END