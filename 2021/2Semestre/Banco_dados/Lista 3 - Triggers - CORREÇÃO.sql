create table cidades (
	cod_cidade  int not null identity(1,1) primary key,
	nome varchar(100) not null ,
	uf char(2),
	cep_padrao char(8)
);

create table clientes (
	cod_cliente  int not null identity(1,1) primary key,
	nome varchar(100) not null ,
	cpf char(11),
	Telefone varchar(20),
	endereco varchar(100),
	cod_cidade int foreign key references cidades (cod_cidade),
	CEP char(8),
	Valor_devido float
);

create table categorias (
	cod_categoria int not null identity(1,1) primary key,
	descricao varchar(100) not null ,
	Valor float,
	Dias_pra_devolver smallint
);

create table filmes (
	cod_filme int not null identity(1,1) primary key,
	titulo varchar(100) not null ,
	Cod_categoria int foreign key references categorias (cod_categoria)
);

create table Locacoes (
	Cod_locacao int not null identity(1,1) primary key,
	Cod_cliente int foreign key references clientes (cod_cliente),
	Cod_filme int foreign key references filmes (cod_filme),
	Valor_locacao float,
	Data_locacao datetime,
	Data_a_devolver datetime,
	Devolvido smallint default 0 not null,-- (0 ou 1) default 0 not null
	Data_devolucao datetime,
	Multa float,
	Pago smallint not null  default 0 , -- (0 ou 1)
	Data_pagto datetime,
	Valor_pago float
);


-- Exercicio 1 : 
/*
a) Quando uma locacao e inserida, sao informados apenas os seguintes 
campos (cod_cliente, cod_filme, data_locacao), os campos (valor_locacao, data_a_devolver) 
deverao ser calculados automaticamente atraves das informacaes da tabela categorias. 
Ainda nesta insercao, o campo valor_devido da tabela clientes devera ser atualizado;
*/

create trigger tr_ins_loc
	on locacoes
	for insert
as begin
	
	declare @cod_cliente int, @cod_filme int, @data_locacao datetime
	declare @cod_locacao int
	declare @valor_locacao float, @data_a_devolver  datetime
	declare @cod_categoria int, @valor_locacao float, @dias_pra_devolver int
	
	select	@cod_cliente=cod_cliente, 
			@cod_filme=cod_filme, 
			@data_locacao=data_locacao,
			@cod_locacao = cod_locacao
	from INSERTED
	
	set @cod_categoria = (select cod_categoria from filmes where cod_filme = @cod_filme)
	
	select	@valor_locacao = valor, 
			@dias_pra_devolver = dias_pra_devolver 
	from categorias
	where cod_categoria = @cod_categoria
	
	set @data_a_devolver = @data_locacao + @dias_pra_devolver
	
	-- atualizando locacoes
	update locacoes set
		data_a_devolver = @data_a_devolver,
		valor_locacao = @valor_locacao
	where cod_locacao = @cod_locacao
	
	-- atualizando clientes
	update clientes set
		valor_devido = isnull(valor_devido,0) + @valor_locacao
	where cod_cliente = @cod_cliente
	
end -- tr_ins_loc

/*
b) Quando um filme for devolvido, são atualizados os campos (devolvido e data_devolucao). 
O campo multa devera ser calculado automaticamente sendo que para cada dia de atraso, R$ 2,00
sao cobrados. O campo valor_devido da tabela clientes tambem devera ser atualizado.
*/
create trigger tr_item_b
	on locacoes
	for update
as begin

	declare @dev_antes smallint, @dev_depois smallint
	declare @data_devolucao datetime, @data_a_devolver datetime
	declare @dias_atraso smallint, @multa float
	declare @cod_locacao int, @cod_cliente int

	-- valores antes da altera��o
	select	@dev_antes = devolvido, 
			@cod_locacao = Cod_locacao, 
			@cod_cliente = cod_cliente
	from DELETED

	-- valores ap�s a altera��o
	select	@dev_depois = devolvido, 
			@data_devolucao = Data_devolucao, 
			@data_a_devolver = data_a_devolver 
	from INSERTED

	-- verificando se realmente nesta comando de update da tab. locacoes, o objeto est� sendo devolvido
	if @dev_antes = 0 and @dev_depois = 1
	begin
		set @dias_atraso = datediff(day,@data_a_devolver, @data_devolucao)

		if @dias_atraso > 0 
		begin

			set @multa = 2 * @dias_atraso

			update locacoes set multa = @multa 
			where cod_locacao = @cod_locacao

			update clientes set valor_devido = valor_devido + @multa 
			where cod_cliente = @cod_cliente

		end -- se o "Andr�" devolveu em atraso

	end -- se o "kara" est� devolvendo
	
end -- tr_item_b

/*
c) Quando o cliente pagar uma loca��o, s�o atualizados os campos pago, data_pagto e valor_pago.
O campo valor_devido da tabela cliente deve ser subtra�do do valor_pago em locacoes.
*/
create trigger tr_item_c
	on locacoes
	for update
as begin

	declare @pago_antes smallint, @pago_depois smallint
	declare @valor_pago float, @cod_cliente int

	select	@pago_antes = pago, 
			@cod_cliente = cod_cliente
	from DELETED

	select	@pago_depois = pago, 
			@valor_pago = valor_pago
	from INSERTED

	-- se a loca��o est� sendo paga
	if @pago_antes = 0 and @pago_depois = 1
	begin

		update clientes set valor_devido = valor_devido - @valor_pago
		where cod_cliente = @cod_cliente

	end -- se o "kara" est� pagando

end -- tr_item_c

/*
d) Quando um registro de loca��o � exclu�do, o campo valor_devido da tabela clientes deve ser
alterado. Note que isso s� � feito quando o campo pago tiver o valor 0.
*/

create trigger tr_item_d
	on locacoes
	for delete
as begin
	
	declare @pago smallint, @cod_cliente int, @valor_locacao float, @multa float

	select	@pago = pago, 
			@cod_cliente = cod_cliente, 
			@valor_locacao = valor_locacao, 
			@multa = multa
	from DELETED

	if @pago = 0
	begin

		update clientes set valor_devido = valor_devido - (@valor_locacao + @multa)
		where cod_cliente = @cod_cliente

	end 

end -- tr_item_d


-- EXERC�CIO 2:
/*2.	Fa�a um Stored Procedure para incluir registros na tabela clientes. 
Quando o CEP n�o for informado, o CEP do cliente deve ser preenchido com o CEP padr�o da
tabela cidades. 
A inclus�o de um cliente n�o pode ser realizada com os campos CPF ou nome em brancos. 
N�o pode haver dois clientes com o mesmo CPF. 
Observa��o: Retorne mensagens para informar se a inclus�o foi realizada com sucesso ou n�o, 
e neste caso o porqu�.
*/
create procedure sp_ins_cliente
	@nome varchar(100) ,
	@cpf char(11),
	@Telefone varchar(20),
	@endereco varchar(100),
	@cod_cidade int ,
	@CEP char(8),
	@Valor_devido float
as begin

	if @cep is null or @cep = ''
	begin
		set @cep = (select cep_padrao from cidades where cod_cidade = @cod_cidade)
	end	
	
	if @nome = '' or @cpf = ''
	begin
		select 0 as retorno, 'O nome e o cpf devem ser preenchidos !' as msg
		return;	
	end
	
	begin transaction -- inicia uma transa��o com o BD e bloqueia para outros acessos
	
		if not exists (select * from clientes where cpf = @cpf)
		begin
	
			insert into clientes (nome, cpf, telefone, endereco, cod_cidade, cep, valor_devido)
			values (@nome, @cpf, @telefone, @endereco, @cod_cidade, @cep, @valor_devido)
	
			select 1 as retorno, 'Cliente cadastrado!' as msg
		end
		else begin
			select 0 as retorno, 'J� h� um cliente com este cpf !' as msg
		end

	commit -- confirma a transa��o e libera o BD 

end -- sp_ins_cliente

/* EXERC�CIO 3 - EXTRA ----------------------------------------------
Fazer um gatilho de inclus�o na tabela categorias, de forma que, se a descri��o da
categoria estiver nula ou em branco, a descri��o dever� ser preenchida com a palavra 
"Categoria" concatenada com o c�digo dela.

Exemplo: Sendo o �ltimo auto-incremento da tabela categorias, o c�digo 38, se uma
categoria for inclu�da sem descri��o, a categoria dever� ter a descri��o igual a:

Categoria 39
*/

create trigger tr_ex3
	on categorias
	for insert
as begin

	declare @descricao varchar(100), @cod_categoria int

	select	@descricao = descricao, 
			@cod_categoria = cod_categoria
	from inserted

	if @descricao = '' or @descricao is null 
	begin
		set @descricao = 'Categoria ' + cast(@cod_categoria as varchar)

		update categorias set
			descricao = @descricao
		where cod_categoria = @cod_categoria
			
	end
end -- tr_ex3




