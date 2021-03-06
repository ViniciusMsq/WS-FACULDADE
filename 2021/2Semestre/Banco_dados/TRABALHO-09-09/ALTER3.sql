USE [comercial_sp_2021]
GO
/****** Object:  StoredProcedure [dbo].[SP_DEL_NOTA_FISCAL]    Script Date: 09/09/2021 14:26:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[SP_DEL_NOTA_FISCAL]

@NUM_NOTA INT

AS

declare cursor_itens cursor for 
	select i.cod_produto from itens_nota i where i.num_nota = @NUM_NOTA

declare @cod_produto int
IF EXISTS(SELECT * FROM nota_fiscal WHERE num_nota = @NUM_NOTA)
	BEGIN
		IF EXISTS (SELECT * FROM itens_nota WHERE num_nota = @NUM_NOTA)
					BEGIN				
						open cursor_itens

						fetch next from cursor_itens
							into @cod_produto

						while @@FETCH_STATUS = 0 -- enquanto não chegar ao fim do cursor
						begin
					
							EXEC SP_DEL_ITENS_NOTA @NUM_NOTA, @cod_produto

							fetch next from cursor_itens
								into @cod_produto
	
						end -- while....
					END
			-- fechar o cursor
				close cursor_itens

				-- retirar o cursor da memória
				deallocate cursor_itens
				DELETE FROM nota_fiscal WHERE num_nota = @NUM_NOTA
				PRINT ('REGISTRO DELETADO COM SUCESSO');
				RETURN 1;
	END
ELSE
	BEGIN
		PRINT ('NÃO EXISTE NUM NOTA');
	END

