ALTER PROCEDURE SP_ADD_ALUNOS

@NOME VARCHAR(100),
@CPF CHAR(11),
@DATA_MATRI DATETIME,
@COD_CURSO INT,
@VALOR_MENSAL FLOAT

AS
BEGIN

	IF @NOME <> '' OR @NOME <> NULL
		BEGIN
			IF EXISTS(SELECT * FROM DBO.cursos C WHERE C.cod_curso = @COD_CURSO)
				BEGIN
					IF NOT EXISTS (SELECT * FROM DBO.alunos A WHERE A.cpf = @CPF)
						BEGIN
							INSERT INTO dbo.alunos(nome, cpf, valor_mensalidade, data_matricula, cod_curso, media_geral)
											VALUES(@NOME, @CPF, @VALOR_MENSAL, @DATA_MATRI, @COD_CURSO, 0)
						END;
					ELSE
						BEGIN
							SELECT 'CPF JA EXISTE' ERRO
						END;
				END;
			ELSE
				BEGIN
					SELECT 'CURSO INVALIDO' ERRO
				END;
		END;
	ELSE
		BEGIN
			SELECT 'NOME INVALIDO' ERRO
		END;
END;