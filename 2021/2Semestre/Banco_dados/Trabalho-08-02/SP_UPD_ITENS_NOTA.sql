USE [comercial_sp_2021]
GO
/****** Object:  StoredProcedure [dbo].[SP_UPD_ITENS_NOTA]    Script Date: 30/08/2021 20:32:33 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_UPD_ITENS_NOTA]

@NUM_NOTA		INT,
@COD_PRODUTO	INT,
@QDE			FLOAT,
@VALOR_UNITARIO	FLOAT

AS
DECLARE @QDE_NOVA INT;

IF EXISTS(SELECT * FROM itens_nota WHERE num_nota = @NUM_NOTA AND cod_produto = @COD_PRODUTO)
	BEGIN
		SELECT @QDE_NOVA = ((SELECT qde FROM itens_nota WHERE num_nota = @NUM_NOTA AND cod_produto = @COD_PRODUTO) - @QDE)

		IF @QDE_NOVA + (SELECT qde_estoque FROM produtos WHERE cod_produto = @COD_PRODUTO) >= 0
			BEGIN

				UPDATE itens_nota SET qde = @QDE, valor_unitario = @VALOR_UNITARIO WHERE num_nota = @NUM_NOTA AND cod_produto = @COD_PRODUTO;
				PRINT ('REGISTRO ATUALIZADO COM SUCESSO');

				UPDATE produtos SET qde_estoque += @QDE_NOVA WHERE cod_produto = @COD_PRODUTO;
				PRINT ('ESTOQUE ATUALIZADO')

				RETURN 1;
			END
		ELSE
			BEGIN
				PRINT('NÃO EXISTE ESSA QUANTIDADE A MAIS EM ESTOQUE')
				RETURN 0;
			END
	END
ELSE
	PRINT ('CODIGO INVALIDO');
	RETURN 0;
