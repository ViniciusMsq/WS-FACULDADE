USE COMERCIAL_2021;

/*17.	Listar o total de clientes que moram em Adamantina*/
select count(*) as total_de_clientes
from cliente
where cod_cidade = 1

/*18.	Contar o número de notas fiscais lançadas no período entre 
agosto de 2000 e dezembro de 2000.*/

select count(*) as notas
from nota_fiscal
where data between '01/08/2000' and '31/12/2000'

-- versão 2 : o retorno
select count(*) as notas
from nota_fiscal
where data >= '01/08/2000' and data <= '31/12/2000'

-- versão 3 : o futuro
select count(*) as notas
from nota_fiscal
where year(data) = 2000 and month(data) between 8 and 12


/*19.	Somar o campo valor da tabela itens_pedido*/

select sum(valor) as soma_valor
from itens_pedido

/*20.	Somar o campo valor da tabela itens_pedido, contar o total de registros, 
somar a multiplicação dos campos qde * valor e apresentar a média do campo qde.*/

select	sum(valor) as soma_valor,
		count(*) as total_de_registros,
		sum(qde * valor) as soma_valor_total,
		avg(qde) as media_qde		
from itens_pedido


/*21.	Idem ao anterior, só que apenas dos pedidos com quantidade superior a 1*/
select	sum(valor) as soma_valor,
		count(*) as total_de_registros,
		sum(qde * valor) as soma_valor_total,
		avg(qde) as media_qde		
from itens_pedido
where qde > 1

/*22. Idem ao exercício 20, só que, deve-se acrescentar o total de notas fiscais
envolvidas */

select	sum(valor) as soma_valor,
		count(*) as total_de_registros,
		sum(qde * valor) as soma_valor_total,
		avg(qde) as media_qde,
		
		count(distinct num_nota) as total_de_notas
				
from itens_pedido






