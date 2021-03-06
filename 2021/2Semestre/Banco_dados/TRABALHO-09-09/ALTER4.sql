USE [comercial_sp_2021]
GO
/****** Object:  StoredProcedure [dbo].[SP_ADD_ITENS_NOTA]    Script Date: 09/09/2021 14:12:10 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_ADD_ITENS_NOTA]

@NUM_NOTA		INT,
@COD_PRODUTO	VARCHAR(100),
@QDE			FLOAT,
@VALOR_UNITARIO	FLOAT

AS

IF NOT EXISTS (SELECT * FROM itens_nota I WHERE I.num_nota = @NUM_NOTA AND I.cod_produto = @COD_PRODUTO)
	IF (SELECT qde_estoque FROM produtos WHERE cod_produto = @COD_PRODUTO) >= @QDE
		BEGIN
			INSERT INTO itens_nota(num_nota, cod_produto, qde, valor_unitario) values (@NUM_NOTA, @COD_PRODUTO, @QDE, @VALOR_UNITARIO);
			PRINT ('REGISTRO INSERIDO COM SUCESSO');

			UPDATE produtos SET qde_estoque = qde_estoque - @QDE WHERE cod_produto = @COD_PRODUTO;

			PRINT ('ESTOQUE ALTERADO COM SUCESSO');
			RETURN 1;
		END
	ELSE
		BEGIN
			PRINT ('PRODUTO INDISPONIVEL');
			RETURN 0;
	END
 ELSE
	BEGIN
		PRINT ('JÁ EXISTE ESSE REGISTRO');
		RETURN 0;
	END