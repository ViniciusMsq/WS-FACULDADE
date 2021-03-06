USE [comercial_sp_2021]
GO
/****** Object:  StoredProcedure [dbo].[SP_ADD_CIDADE]    Script Date: 30/08/2021 20:40:18 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_ADD_CIDADE] 

@NOME VARCHAR(50),
@UF   VARCHAR(2),
@CEP  VARCHAR(9)

AS
 IF NOT EXISTS (SELECT * FROM cidades C WHERE C.nome = @NOME and C.uf = @UF)
	BEGIN
		INSERT INTO cidades (nome, uf, cep_padrao) values (@NOME, @UF, @CEP);
		PRINT ('REGISTRO INSERIDO COM SUCESSO');
		RETURN 1;
	END
 ELSE
	BEGIN
		PRINT ('JÁ EXISTE ESSE REGISTRO');
		RETURN 0;
	END