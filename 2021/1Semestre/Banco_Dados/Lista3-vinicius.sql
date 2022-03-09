/* 1. Listar as unidades de medidas existentes na tabela produto, sem repetições */
	
select Unidade
from produto
group by Unidade
/*------------------*/

/*2. Listar a unidade de medida e o número de produtos relacionados a cada unidade. */ 
	
select Unidade AS 'UNIDADE DE MEDIDA', COUNT(*) as 'NUMERO DE PRODUTOS'
from produto
group by Unidade
/*------------------*/

/*3. Listar a soma geral do valor total (qde * valor) de todas as notas fiscais */
	
select SUM(i.Qde * i.Valor) as 'VALOR TOTAL' 
from itens_pedido i
/*------------------*/

/*4. Listar nome do cliente, a data da nota fiscal e o valor total de cada nota (qde * valor),
ordenado por nome do cliente e em seguida nº da nota. */
	
select c.Nome, n.Data, n.Num_nota, SUM(i.Qde * i.Valor) as 'Valor Total' 
from cliente c
	INNER JOIN nota_fiscal n ON( c.Cod_cli = n.Cod_cli)
	INNER JOIN itens_pedido i ON( n.Num_nota = i.Num_nota)
group by c.Nome, n.Data, n.Num_nota
order by c.Nome, n.Num_nota
/*------------------*/

/*5. Listar a descrição do produto, valor total vendido (qde*valor) por ordem crescente da 
descrição do produto. */
	
select p.Descricao, SUM(i.Qde * i.Valor) as 'Valor Total Vendido'
from produto p 
	INNER JOIN itens_pedido i ON(p.Cod_produto = i.Cod_produto)
group by p.Descricao
order by p.Descricao asc
/*------------------*/
	
/*6. Idem ao exercício anterior, só que listar apenas os produtos com valor total vendido 
(qde * valor ) superior a R$ 50,00. */
	
select p.Descricao, SUM(i.Qde * i.Valor) as 'Valor Total Vendido'
from produto p 
	INNER JOIN itens_pedido i ON(p.Cod_produto = i.Cod_produto)
group by p.Descricao
having SUM(i.Qde * i.Valor) > 50
order by p.Descricao asc
/*------------------*/

/*7. Listar o número e data de apenas as notas fiscais cujo valor total (qde * valor) 
ultrapassou R$ 100,00.*/
	
select n.Num_nota, N.Data, SUM(i.Qde * i.Valor) as 'Valor Total Vendido'
from nota_fiscal n 
	INNER JOIN itens_pedido i ON(n.Num_nota = i.Num_nota)
group by n.Num_nota, N.Data
having SUM(i.Qde * i.Valor) > 100
/*------------------*/
