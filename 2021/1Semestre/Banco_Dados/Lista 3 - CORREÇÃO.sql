-- EXERCÍCIOS SQL – LISTA 3  Agrupamentos - CORREÇÃO--------------------------------------------------------------------------------

/*1.	Listar as unidades de medidas existentes na tabela produto, sem repetições */

-- com distinct 
select distinct unidade
from produto

-- ou com group by
select unidade
from produto
group by unidade


/* 2.	Listar a unidade de medida e o número de produtos relacionados a cada unidade.*/
select unidade, count(*) as produtos_relacionados
from produto
group by unidade


/*3.	Listar a soma geral do valor total (qde * valor) de todas as notas fiscais*/
select sum(qde * valor) as valor_total
from itens_pedido

/*4.	Listar nome do cliente, a data da nota fiscal e o valor total de cada nota (qde * valor), 
ordenado por nome do cliente e em seguida pela data */
select	cl.nome,
		n.data,
		sum(i.qde * i.valor) as vl_total
		
from	cliente as cl 
		inner join nota_fiscal as n on (cl.cod_cli = n.cod_cli)
		inner join itens_pedido i on (n.num_nota = i.num_nota)

group by cl.nome, n.data
order by cl.nome, n.data

/*5.	Listar a descrição do produto, valor total vendido (qde*valor) por ordem 
crescente da descrição do produto*/
select	p.descricao as desc_produto,
		sum(i.qde * i.valor) as vl_total_vendido

from	produto p 
		inner join itens_pedido i on (p.cod_produto = i.cod_produto)
group by p.descricao 
order by desc_produto

/*6.	Idem ao exercício anterior, só que listar apenas os produtos com valor total 
vendido (qde * valor ) superior a R$ 50,00.*/

select	p.descricao as desc_produto,
		sum(i.qde * i.valor) as vl_total_vendido

from	produto p 
		inner join itens_pedido i on (p.cod_produto = i.cod_produto)
group by p.descricao 
having sum(i.qde * i.valor) > 50
order by desc_produto

/*6.1	Idem ao exercício 5, só que listar apenas os produtos com unidade de 
medida igual a kg*/
select	p.descricao as desc_produto,
		sum(i.qde * i.valor) as vl_total_vendido

from	produto p 
		inner join itens_pedido i on (p.cod_produto = i.cod_produto)
where unidade = 'kg'
group by p.descricao 
order by desc_produto

/*6.2 - a batalha final: Idem ao exercício 5, só que listar apenas os produtos
 com unidade de medida igual kg e o valor total vendido inferior a 50 */

select	p.descricao as desc_produto,
		sum(i.qde * i.valor) as vl_total_vendido

from	produto p 
		inner join itens_pedido i on (p.cod_produto = i.cod_produto)
where unidade = 'kg' 
group by p.descricao 
having sum(i.qde * i.valor) < 50
order by desc_produto

/*7.	Listar o número e data de apenas as notas fiscais cujo valor total (qde * valor) 
ultrapassou R$ 100,00.*/

select	n.num_nota,
		n.data,
		sum(i.qde * i.valor) vl_total

from	nota_fiscal n 
		inner join itens_pedido i on (n.num_nota = i.num_nota)

group by n.num_nota, n.data
having sum(i.qde * i.valor) > 100

/*	8. Listar a descrição do produto, a média do valor unitário vendido, o menor e maior
valor unitário, e total de vezes que o produto foi vendido, a quantidade total vendida
e para quantos clientes diferentes foi vendido. */
select	p.descricao,
		avg(i.valor) as media_vl_unitario,
		min(i.valor) as menor_vl,
		max(i.valor) as maior_vl,
		count(*) as total_notas_em_que_apareceu,
		sum(i.qde) as quantidade_total_vendida,
		count(distinct n.cod_cli) as total_clientes_que_compraram
from	produto p 
		inner join itens_pedido i on (p.cod_produto = i.cod_produto)
		inner join nota_fiscal n on (n.num_nota = i.num_nota)
group by p.descricao
order by p.descricao




		







