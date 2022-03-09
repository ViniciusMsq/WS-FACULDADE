USE [comercial_sp_2021]
GO
/****** Object:  StoredProcedure [dbo].[SP_ADD_NOTA_FISCAL]    Script Date: 30/08/2021 20:39:40 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_ADD_NOTA_FISCAL]

@COD_CLIENTE	INT,
@DATA			DATE

AS

BEGIN
	INSERT INTO nota_fiscal(cod_cliente, data) values(@COD_CLIENTE, @DATA);
	PRINT ('REGISTRO INSERIDO COM SUCESSO');
	RETURN 1;
END