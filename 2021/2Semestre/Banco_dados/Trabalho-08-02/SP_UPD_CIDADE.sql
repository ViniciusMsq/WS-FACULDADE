USE [comercial_sp_2021]
GO
/****** Object:  StoredProcedure [dbo].[SP_UPD_CIDADE]    Script Date: 30/08/2021 20:26:01 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_UPD_CIDADE]

@COD_CIDADE INT,
@NOME VARCHAR(50),
@UF   VARCHAR(2),
@CEP  VARCHAR(9)

AS
IF EXISTS(SELECT * FROM cidades WHERE cod_cidade = @COD_CIDADE)

	IF NOT EXISTS (SELECT * FROM cidades C WHERE C.nome = @NOME AND C.uf = @UF AND cod_cidade <> @COD_CIDADE)
		BEGIN
			UPDATE cidades SET nome = @NOME, uf = @UF, cep_padrao = @CEP WHERE cod_cidade = @COD_CIDADE;
			PRINT ('REGISTRO ATUALIZADO COM SUCESSO');
			RETURN 1;
		END
	ELSE
		BEGIN
			PRINT ('JÁ EXISTE ESSE REGISTRO');
			RETURN 0;
		END
ELSE
	PRINT ('CODIGO INVALIDO')
	RETURN 0;

EXEC SP_UPD_CIDADE 4, 'TUPI PTA', 'SP', '124512 '