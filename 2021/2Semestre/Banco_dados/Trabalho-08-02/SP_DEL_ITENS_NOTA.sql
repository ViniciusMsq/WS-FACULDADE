USE [comercial_sp_2021]
GO
/****** Object:  StoredProcedure [dbo].[SP_DEL_ITENS_NOTA]    Script Date: 30/08/2021 20:38:11 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_DEL_ITENS_NOTA]

@NUM_NOTA		INT,
@COD_PRODUTO	INT,
@QDE			FLOAT

AS
BEGIN
	DELETE FROM itens_nota WHERE num_nota = @NUM_NOTA AND cod_produto =  @COD_PRODUTO;
	PRINT ('REGISTRO DELETADO COM SUCESSO');

	SELECT @QDE = (SELECT qde FROM itens_nota WHERE num_nota = @NUM_NOTA AND cod_produto =  @COD_PRODUTO)

	UPDATE produtos SET qde_estoque = qde_estoque + @QDE WHERE cod_produto = @COD_PRODUTO;

	PRINT ('ESTOQUE ALTERADO COM SUCESSO');
	RETURN 1;
END