/* Considerando que seu código na tabela cliente seja 13, altere sua data de nascimento e salário */

update clientes set data_nascimento='27/04/2000', salario = 10000.23
where cod_cliente = 13;

/*Liste os ingredientes com valor unitário entre R$ 20 ,13 e R$ 100,28, cuja descrição possua a palavra Bacon, 
ordenando pela descrição do ingrediente em ordem decrescente */

select * from ingredientes
where valor_unitario > 20.13 and valor_unitario < 100.28 and descricao like '%Bacon%'
order by descricao desc


/*Considerando que a cidade em que mora tenha o código 52, insira-se na tabela cliente preenchendo todos os campos */

select * from clientes
insert into cidades(nome, uf,cep_padrao)values('Tupi Paulista', 'SP', '17930000')

insert into clientes(nome, cpf, rg, endereco, bairro, cod_cidade, cep, telefone, celular, email, data_nascimento, salario)
values('Vinicius mesquini', '99999999900', '99999999999', 'Rua osvaldo cruz', 'centro', 52, '17930000', '125478548', '123654789', 'ddd@gmail.com', '27/04/2000', 500.25)

/* Ainda considerando que seu código na tabela cliente seja 13, exclua-se desta tabela */
delete from clientes
where cod_cliente = 13



/* Liste a descrição do prato e o valor unitário MÉDIO dos pratos encomendados */

select * from pratos
select * from itens_encomenda

select prt.descricao, AVG(ite.valor_unitario) as 'valor medio'
from pratos prt, itens_encomenda ite
where prt.cod_prato = ite.cod_prato
group by prt.descricao


select prt.descricao, AVG(ite.valor_unitario) as 'valor medio'
from pratos prt, itens_encomenda ite
group by prt.descricao




select p.descricao as 'DESCRICAO PRATOS', AVG(i.valor_unitario) as 'VALOR MEDIO' 
    from pratos p INNER JOIN itens_encomenda i ON( p.cod_prato = i.cod_prato )
    group by p.descricao;

insert into pratos(descricao, valor_unitario) values ('Misto Quente com Ovo', 10.70);
insert into pratos(descricao, valor_unitario) values ('Misto Quente com bacon', 25.50);
insert into pratos(descricao, valor_unitario) values ('Misto Quente com salada', 50.40);
insert into pratos(descricao, valor_unitario) values ('Misto Quente com cebola', 2.50);
insert into pratos (descricao, valor_unitario) values ('Pizza de Calabresa', 53.78);
insert into pratos (descricao, valor_unitario) values ('Feijoada', 108);
