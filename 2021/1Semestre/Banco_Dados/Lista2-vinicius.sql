/* 1. Listar o nome do cliente, o número da nota fiscal e a data ordenado pelo nome do
cliente e em seguida pela data. (faça com where e depois com inner join)*/
	
--Where
select cl.Nome as 'CLIENTE', n.Num_nota as 'NUMERO NOTA', n.Data as 'DATA NOTA' 
from cliente cl, nota_fiscal n 
where cl.Cod_cli = n.Cod_cli
order by cl.Nome, n.Data;

--Inner join
select cl.Nome as 'CLIENTE', n.Num_nota as 'NUMERO NOTA', n.Data as 'DATA NOTA' 
from cliente cl INNER JOIN nota_fiscal n ON(cl.Cod_cli = n.Cod_cli)
order by cl.Nome, n.Data;
/*------------------*/

/* 2. Listar o nome, endereço, cidade e uf dos clientes residentes no estado de SP. (faça com
where e depois com inner join)*/
	
--Where
select cl.Nome as 'CLIENTE', cl.Endereco as 'ENDEREÇO', ci.Nome as 'CIDADE', ci.uf as 'UF' 
from cidades ci, cliente cl 
where ci.Cod_cidade = cl.Cod_cidade and uf = 'SP';
	
--Inner join
select cl.Nome as 'CLIENTE', cl.Endereco as 'ENDEREÇO', ci.Nome as 'CIDADE', ci.uf as 'UF' 
from cidades ci INNER JOIN cliente cl ON(ci.Cod_cidade = cl.Cod_cidade)
where uf = 'SP';
/*------------------*/

/* 3. Listar a descrição do produto, sua unidade, o número da nota, a qde vendida, o valor e o
valor total (qde * valor) de cada item da nota, ordenado pela descrição do produto em
ordem crescente. (faça com where e depois com inner join)*/

--Where
select * from produto 
select * from nota_fiscal
select * from itens_pedido
	
Select p.Descricao, p.Unidade, n.Num_nota, it.Qde, p.Valor_Unitario, it.Valor as 'Valor Total'
from itens_pedido it, produto p, nota_fiscal n
where it.Cod_produto = p.Cod_produto and it.Num_nota = n.Num_nota
order by p.Descricao asc

--Inner join
Select p.Descricao, p.Unidade, n.Num_nota, it.Qde, p.Valor_Unitario, it.Valor as 'Valor Total'
from itens_pedido it
	INNER JOIN produto p ON(it.Cod_produto = p.Cod_produto) 
	INNER JOIN nota_fiscal n ON(it.Num_nota = n.Num_nota)
order by p.Descricao asc
/*------------------*/

/* 4. Idem ao anterior, só que deve ser listadas apenas as notas ficais entre 01/04/2000 e
15/04/2000. (faça com where e depois com inner join) */

--Where
Select p.Descricao, p.Unidade, n.Num_nota, it.Qde, p.Valor_Unitario, it.Valor as 'Valor Total', n.Data
from itens_pedido it, produto p, nota_fiscal n
where it.Cod_produto = p.Cod_produto and it.Num_nota = n.Num_nota and ( Data >= '01/04/2000' and Data <= '15/04/2000')
order by p.Descricao asc

--Inner join
Select p.Descricao, p.Unidade, n.Num_nota, it.Qde, p.Valor_Unitario, it.Valor as 'Valor Total', n.Data
from itens_pedido it 
	INNER JOIN produto p ON(it.Cod_produto = p.Cod_produto)
	INNER JOIN nota_fiscal n ON(it.Num_nota = n.Num_nota)
where n.Data >= '01/04/2000' and n.Data <= '15/04/2000'
order by p.Descricao asc
/*------------------*/

/* 5. Listar o nome do cliente, a cidade onde mora, o número e data da nota fiscal. (faça com
where e depois com inner join). Ordene pela data da nota, num. da nota e depois pelo
cliente. */

--Where
Select cl.Nome as 'CLIENTE', ci.Nome as 'CIDADE', n.Num_nota as 'NOTA', n.Data as 'DATA'
from cliente cl, cidades ci, nota_fiscal n
where ci.Cod_cidade = cl.Cod_cidade and cl.Cod_cli = n.Cod_cli
order by n.Data, n.Num_nota, cl.Nome;

--Inner join
Select cl.Nome as 'CLIENTE', ci.Nome as 'CIDADE', n.Num_nota as 'NOTA', n.Data as 'DATA'
from cliente cl 
	INNER JOIN cidades ci ON(ci.Cod_cidade = cl.Cod_cidade)
	INNER JOIN nota_fiscal n ON(cl.Cod_cli = n.Cod_cli)
order by n.Data, n.Num_nota, cl.Nome;
/*------------------*/

/* 6. Listar o nome do cliente, a cidade onde mora, o número e data da nota fiscal, porém
apenas dos clientes do estado de são Paulo e nota fiscal lançada a partir de agosto de
2000. Ordene pela data da nota, num. da nota e depois pelo cliente. (faça com where e
depois com inner join) */
	
--Where
Select cl.Nome as 'CLIENTE', ci.Nome as 'CIDADE', n.Num_nota as 'NOTA', n.Data as 'DATA'
from cliente cl, cidades ci, nota_fiscal n
where (ci.Cod_cidade = cl.Cod_cidade and cl.Cod_cli = n.Cod_cli) and (ci.uf = 'SP' and n.Data > '31/08/2000')
order by n.Data, n.Num_nota, cl.Nome;

--Inner join
Select cl.Nome as 'CLIENTE', ci.Nome as 'CIDADE', n.Num_nota as 'NOTA', n.Data as 'DATA'
from cliente cl
	INNER JOIN cidades ci ON(ci.Cod_cidade = cl.Cod_cidade)
	INNER JOIN nota_fiscal n ON(cl.Cod_cli = n.Cod_cli)
where ci.uf = 'SP' and n.Data > '31/08/2000'
order by n.Data, n.Num_nota, cl.Nome;
/*------------------*/

/* 7. Listar a descrição do produdo, qde vendida, independentemente se o produto foi
vendido ou não. (utilize left e depois right) */
	
--LEFT
select p.Descricao as 'DESCRIÇÃO', it.Qde as 'QT VENDIDA' 
from itens_pedido it  LEFT OUTER JOIN produto p ON(it.Cod_produto = p.Cod_produto);

--RIGHT
select p.Descricao as 'DESCRIÇÃO', it.Qde as 'QT VENDIDA' 
from  produto p RIGHT OUTER JOIN itens_pedido it ON(it.Cod_produto = p.Cod_produto);
/*------------------*/

/* 8. Listar o nome do cliente, o número da nota fiscal, independentemente se o cliente
possui nota ou não. (utilize left e depois rigth) */
	
--LEFT
select cl.Nome as 'CLIENTE', n.Num_nota as 'NUMERO NOTA' 
from cliente cl  LEFT OUTER JOIN nota_fiscal n ON(cl.Cod_cli = n.Cod_cli);

--RIGHT
select cl.Nome as 'CLIENTE', n.Num_nota as 'NUMERO NOTA' 
from nota_fiscal n RIGHT OUTER JOIN cliente cl  ON(cl.Cod_cli = n.Cod_cli);
/*------------------*/

/* 9. Listar o nome da cidade, nome do cliente, numero e data da nota fiscal, descrição do
produto, qde vendida, valor unitário vendido, e valor total vendido (qde * valor). (faça
com where e depois com inner join) */

	--Where
Select ci.Nome as 'CIDADE', cl.Nome as 'CLIENTE', n.Num_nota as 'NUMERO NOTA', n.Data as 'DATA', p.Descricao as 'DESCRICAO', it.Qde as 'QT VENDIDA', p.Valor_Unitario as 'VALOR UNITARIO', it.Valor as 'VALOR TOTAL'
from cliente cl, cidades ci, nota_fiscal n, produto p, itens_pedido it
where ci.Cod_cidade = cl.Cod_cidade and 
		cl.Cod_cli = n.Cod_cli and
		n.Num_nota = it.Num_nota and
		it.Cod_produto = p.Cod_produto
order by cl.Nome;

--Inner join
Select ci.Nome as 'CIDADE', cl.Nome as 'CLIENTE', n.Num_nota as 'NUMERO NOTA', n.Data as 'DATA', p.Descricao as 'DESCRICAO', it.Qde as 'QT VENDIDA', p.Valor_Unitario as 'VALOR UNITARIO', it.Valor as 'VALOR TOTAL'
from cidades ci
	INNER JOIN cliente cl  ON(ci.Cod_cidade = cl.Cod_cidade)
	INNER JOIN nota_fiscal n ON(cl.Cod_cli = n.Cod_cli)
	INNER JOIN itens_pedido it ON(it.Num_nota = n.Num_nota)
	INNER JOIN produto p ON(it.Cod_produto = p.Cod_produto)
order by cl.Nome;
/*------------------*/
