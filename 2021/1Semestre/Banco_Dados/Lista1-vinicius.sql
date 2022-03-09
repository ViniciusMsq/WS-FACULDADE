/* 1. Listar o nome e endereço de todos os clientes cadastrados ordenados em ordem
crescente alfabética pelo nome*/

select nome, endereco from cliente
order by nome asc;

/*------------------*/

/* 2. Idem ao anterior só que listando todos os campos e não apenas o nome e endereço*/

select * from cliente
order by nome asc;

/*------------------*/

/* 3. Listar nome e ENDEREÇO de todos os clientes residentes na cidade de código 1*/

select Nome, Endereco from cliente
where cod_cidade = 1;

/*------------------*/

/* 4. Listar a descrição, o valor e a unidade dos produtos ordenado pela unidade em ordem
decrescente e em seguida pela descrição em ordem crescente*/

select descricao, valor_unitario, unidade from produto
order by unidade desc, descricao asc
/*------------------*/

/* 5. Listar os números de notas fiscais CUJA data está entre 01/04/2000 e 15/04/2000.*/

select num_nota from nota_fiscal
where data >= '01/04/2000' and data <= '15/04/2000'
/*------------------*/

/* 6. Contar o número de notas fiscais lançadas no período 01/04/2000 e 15/04/2000.*/

select COUNT(*) as 'Contagem' from nota_fiscal
where data >= '01/04/2000' and data <= '15/04/2000'
/*------------------*/

/* 7. Listar o nome dos clientes com código igual a 3 ou 7*/

select nome from cliente
where cod_cli = 3 or cod_cli = 7
/*------------------*/

/* 8. Listar o nome dos clientes com código 1, 3 ou 7, utilizando o operador IN*/

select nome from cliente
where cod_cli in (1,3,7)
/*------------------*/

/* 9. Listar os produtos com valor unitário entre 2 e 20 reais*/

select * from produto
where valor_unitario >= 2 and valor_unitario <= 20;
/*------------------*/

/* 10. Listar todos os campos da tabela ITENS_PEDIDO ordenados 
pelo número da nota e em seguida pelo código do produto, 
incluindo na listagem o valor total (qde * valor)*/

select num_nota, cod_produto, qde, valor, qde * valor as 'Valor total' from itens_pedido 
order by num_nota, cod_produto;
/*------------------*/

/* 11. Listar o nome e endereço dos clientes que contenham a letra o em seu nome, ordenados*/

select nome, endereco from cliente
where nome like '%o%' 
order by nome;
/*------------------*/

/* 12. Listar o nome e endereço dos clientes que possuem a combinação de letras dol em seu
nome e que moram em adamantina, ordenados pelo campo nome*/

select nome, endereco from cliente
where nome like '%dol%' and cod_cidade = 1
order by nome
/*------------------*/

/* 13. Listar o nome e endereço dos clientes que NÃO possuem a combinação de letras
dol em seu nome, ordenados pelo campo nome */

select nome, endereco from cliente
where not nome like '%dol%' and cod_cidade = 1
order by nome
/*------------------*/


/* 14. Listar os clientes que começam com a letra F*/

select * from cliente
where nome like 'F%'
/*------------------*/

/* 15. Listar os produtos que terminam com a letra r em sua descrição e que possuem unidade
de medida kg*/

select * from produto
where descricao like '%r' and unidade = 'kg'
/*------------------*/

/* 16. Listar o total de clientes*/

select COUNT(*) as total from cliente
/*------------------*/

/* 17. Listar o total de clientes que moram em Adamantina*/

select COUNT(*) as total from cliente
where cod_cidade = 1
/*------------------*/

/* 18. Contar o número de notas fiscais lançadas no período entre agosto de 2000 e dezembro
de 2000.*/

select COUNT(*) as total from nota_fiscal
where data >= '01/08/2000' and data <= '31/12/2000' 
/*------------------*/

/* 19. Somar o campo valor da tabela itens_pedido.*/

select SUM(valor) as total from itens_pedido
/*------------------*/

/*20. Somar o campo valor da tabela itens_pedido, contar o total de registros, somar a
multiplicação dos campos qde * valor e apresentar a média do campo qde.*/

select	SUM(valor) as 'total valor', 
		COUNT(*) as 'total registros', 
		SUM(qde*valor) as 'total qde * valor', 
		AVG(qde) as media 
		
		from itens_pedido
/*------------------*/

/* 21. Idem ao anterior, só que apenas dos pedidos com quantidade superior a 1*/

select	SUM(valor) as 'total valor', 
		COUNT(*) as 'total registros', 
		SUM(qde*valor) as 'total qde * valor', 
		AVG(qde) as media 
		
		from itens_pedido
		where qde > 1
/*------------------*/
