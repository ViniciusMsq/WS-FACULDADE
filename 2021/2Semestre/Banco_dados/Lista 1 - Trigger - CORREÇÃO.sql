
/* Exercicio 4 : IMPLEMENTAR LOG COMPLETO (inclusao, exclusao e alteracao) PARA TABELA DE ALUNOS
	Considerar apenas os campos nome, cpf, valor_mensalidade e cod_curso para efeito de log  
*/

create trigger tr_ins_aluno_log
	on alunos
	for insert
as begin
	declare @nome varchar(100), @cpf char(11), @valor_mensalidade float, @cod_curso int
	declare @evento varchar(500)

	---------------------------------------------------------------------------------------------------------
	select	@nome = nome,
			@cpf = cpf,
			@valor_mensalidade = valor_mensalidade,
			@cod_curso = cod_curso
	from inserted

	---------------------------------------------------------------------------------------------------------
	set @evento = 'INCLUSAO DE ALUNO'
	set @evento = @evento + ' - ' + 'Nome: ' + @nome
	set @evento = @evento + '; '  + 'Cpf: ' + @cpf
	set @evento = @evento + '; '  + 'Mensalidade: ' + cast(@valor_mensalidade as varchar)
	set @evento = @evento + '; '  + 'Curso: ' + (select descricao from cursos where cod_curso = @cod_curso)

	insert into logs (evento, usuario) values (@evento, system_user)

end -- tr_ins_aluno_log



create trigger tr_del_aluno_log
	on alunos
	for delete
as begin
	declare @nome varchar(100), @cpf char(11), @valor_mensalidade float, @cod_curso int
	declare @evento varchar(500)

	---------------------------------------------------------------------------------------------------------
	select	@nome = nome,
			@cpf = cpf,
			@valor_mensalidade = valor_mensalidade,
			@cod_curso = cod_curso
	from deleted

	---------------------------------------------------------------------------------------------------------
	set @evento = 'EXCLUSAO DE ALUNO'
	set @evento = @evento + ' - ' + 'Nome: ' + @nome
	set @evento = @evento + '; '  + 'Cpf: ' + @cpf
	set @evento = @evento + '; '  + 'Mensalidade: ' + cast(@valor_mensalidade as varchar)
	set @evento = @evento + '; '  + 'Curso: ' + (select descricao from cursos where cod_curso = @cod_curso)

	insert into logs (evento, usuario) values (@evento, system_user)


end -- tr_del_aluno_log


alter trigger tr_up_aluno_log
	on alunos
	for update
as begin
	declare @nome varchar(100), @cpf char(11), @valor_mensalidade float, @cod_curso int
	declare @nome_anterior varchar(100), @cpf_anterior char(11), @valor_mensalidade_anterior float, @cod_curso_anterior int
	declare @evento varchar(500)

	---------------------------------------------------------------------------------------------------------
	select	@nome = nome,
			@cpf = cpf,
			@valor_mensalidade = valor_mensalidade,
			@cod_curso = cod_curso
	from inserted

	select	@nome_anterior = nome,
			@cpf_anterior = cpf,
			@valor_mensalidade_anterior = valor_mensalidade,
			@cod_curso_anterior = cod_curso
	from deleted
	---------------------------------------------------------------------------------------------------------
	set @evento = 'ALTERACAO DE ALUNO'

	if @nome != @nome_anterior
	begin
		set @evento = @evento + ' - ' + 'Nome Anterior: ' + @nome_anterior + '; Nome Novo: ' + @nome
	end

	if @cpf != @cpf_anterior
	begin
		set @evento = @evento + ' - ' + 'Cpf Anterior: ' + @cpf_anterior + '; Cpf Novo: ' + @cpf
	end

	if @valor_mensalidade != @valor_mensalidade_anterior
	begin
		set @evento = @evento + ' - ' + 'Mensalidade Anterior: ' + cast(@valor_mensalidade_anterior as varchar) + '; Mensalidade Nova: ' + cast(@valor_mensalidade as varchar)
	end

	if @cod_curso != @cod_curso_anterior
	begin
		set @evento = @evento + ' - ' + 'Curso Anterior: ' + (select descricao from cursos where cod_curso = @cod_curso_anterior) + '; Curso Novo: ' + (select descricao from cursos where cod_curso = @cod_curso)
	end

	insert into logs (evento, usuario) values (@evento, system_user)

end -- tr_ins_aluno_log
