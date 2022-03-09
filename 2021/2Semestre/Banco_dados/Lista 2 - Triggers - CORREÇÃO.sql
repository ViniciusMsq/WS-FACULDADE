create table clientes (
	cod_cliente  int not null identity(1,1) primary key,
	nome varchar(100) not null ,
	cpf char(11)
);

create table vendedores (
	cod_vendedor  int not null identity(1,1) primary key,
	nome varchar(100) not null,
	percentual_comissao float ,
	valor_comissao float 
);

create table vendas (
	cod_venda  int not null identity(1,1) primary key,
	cod_vendedor int not null foreign key references vendedores (cod_vendedor),
	data datetime not null ,
	descricao varchar(200) not null ,
	percentual_comissao float not null,
	valor float not null 
);

create table audidorias (
	cod_auditoria  int not null identity(1,1) primary key,
	data_hora datetime not null default getdate(),
	usuario varchar(50) not null,
	evento text not null
);

-- Exercicio 2 

-- Gatilho de Inclusao -------------------------------------------------------------------
create trigger tr_venda_ins
	on vendas
	for insert
as begin

	declare @percentual_comissao float, @cod_vendedor int
	declare @valor float, @valor_comissao float
	
	set @cod_vendedor = (select cod_vendedor from INSERTED)

	-- Obter o percentual_comissao da tabela vendedor 
	set @percentual_comissao = (select percentual_comissao from vendedores where cod_vendedor = @cod_vendedor)
	
	-- Calcular o valor da comissao com base no percentual obtido anteriormente 
	set @valor = (select valor from INSERTED) -- valor da venda
	set @valor_comissao = (@percentual_comissao/100) * @valor
	
	-- Acumular na tabela vendedores o valor calculado neste gatilho, 
	-- com o valor de comissao la armazenado 	
	update vendedores 
		set valor_comissao = valor_comissao + @valor_comissao 
	where cod_vendedor = @cod_vendedor
	
	-- Gravar na tabela vendas o percentual obtido anteriormente 	
	update vendas set
		percentual_comissao = @percentual_comissao
	where cod_venda = (select cod_venda from INSERTED)

end -- tr_venda_ins

-- Gatilho de EXCLUSAO -------------------------------------------------------------------
create trigger tr_venda_DEL
	on vendas
	for delete
as begin
	
	declare @pc float, @valor float, @vc float, @cod_vendedor int

	select	@pc = percentual_comissao,
			@valor = valor,
			@cod_vendedor = cod_vendedor
	from DELETED

	-- Calcular o valor de comissao com base nos valores excluidos da tabela venda (perc. e valor) 
	set @vc = @pc/100 * @valor	
	
	-- Subtrair este valor do campo valor_comissao da tabela vendedores 	
	update vendedores set
		valor_comissao = valor_comissao - @vc
	where cod_vendedor = @cod_vendedor

end -- tr_venda_del

-- Gatilho de ALTERACAO  -------------------------------------------------------------------
create trigger tr_venda_UP
	on vendas
	for update
as begin

	declare @pc float, @vv float, @vc float, @cod_vendedor int

	-- valores antes da alteracao
	select @pc=percentual_comissao, @vv=valor, @cod_vendedor=cod_vendedor from DELETED

	-- Se percentual de comissao ou valor da venda foi(ram) alterado(s), entao: 
	if (update(percentual_comissao) AND @pc is not null and @pc > 0) -- se houve alteracao no % de comissao
		or update(valor) -- se houve alteracao no valor da venda
	begin
		-- Calcular o valor de comissao com base nos valores antes da alteracao da tabela vendas (perc. e valor) 
		set @vc = @pc/100 * @vv		
				
		-- Subtrair este valor do campo valor_comissao da tabela vendedores 
		update vendedores set valor_comissao = valor_comissao - @vc 
		where cod_vendedor = @cod_vendedor
		
		-- Calcular o valor de comissao com base nos novos valores da tabela vendas (perc. e valor) 
		select @pc=percentual_comissao, @vv=valor from INSERTED
	
		set @vc = @pc/100 * @vv		
				
		-- Acrescentar no campo valor_comissao o valor calculado no passo anterior 
		update vendedores set valor_comissao = valor_comissao + @vc 
		where cod_vendedor = @cod_vendedor		
		
	end -- se alterou o % ou valor
end -- tr_venda_UP
