BD I - CC - LISTA 2
CORRE��O

/*
1.	Listar o nome do cliente, o n�mero da nota fiscal e a data ordenado pelo 
nome do cliente e em seguida pela data. (fa�a com where e depois com inner join)
*/

-- where
select	cl.nome, 
		n.num_nota, 
		n.data
from cliente cl, nota_fiscal n

where cl.cod_cli = n.cod_cli

order by cl.nome, n.data

-- inner join
select	cl.nome, 
		n.num_nota, 
		n.data

from cliente cl		
	 inner join nota_fiscal n on (cl.cod_cli = n.cod_cli)

order by cl.nome, n.data


/*
2.	Listar o nome, endere�o, cidade e uf dos clientes residentes no estado de SP. 
(fa�a com where e depois com inner join)
*/

-- where
select	cl.nome,	
		cl.endereco,
		ci.nome as cidade,
		ci.uf

from	cliente as cl, cidades as ci

where	cl.cod_cidade = ci.cod_cidade and ci.uf = 'sp'

order by cl.nome

-- inner join
select	cl.nome,	
		cl.endereco,
		ci.nome as cidade,
		ci.uf

from	cliente as cl
		inner join cidades as ci on (cl.cod_cidade = ci.cod_cidade)

where	 ci.uf = 'sp'

order by cl.nome

/*
3. Listar a descri��o do produto, sua unidade, o n�mero da nota, a qde vendida, o valor e o
valor total (qde * valor) de cada item da nota, ordenado pela descri��o do produto em
ordem crescente. (fa�a com where e depois com inner join)
*/

-- vers�o where
select	p.descricao,
		p.unidade,
		i.num_nota,
		i.qde,
		i.valor,
		i.qde * i.valor
from	produto as p, itens_pedido i
where	p.cod_produto = i.cod_produto
order by p.descricao

-- vers�o inner join - a revanche
select	p.descricao,
		p.unidade,
		i.num_nota,
		i.qde,
		i.valor,
		i.qde * i.valor
from	produto as p
		inner join itens_pedido i on (p.cod_produto = i.cod_produto)
order by p.descricao


/*
4. Idem ao anterior, s� que deve ser listadas apenas as notas ficais entre 01/04/2000 e
15/04/2000. (fa�a com where e depois com inner join)
*/
-- vers�o where
select	p.descricao,
		p.unidade,
		i.num_nota,
		i.qde,
		i.valor,
		i.qde * i.valor

from	produto as p, itens_pedido i, nota_fiscal as n

where	p.cod_produto = i.cod_produto and 
		n.num_nota = i.num_nota and 
		n.data between '01/04/2000' and '15/04/2000'

order by p.descricao

-- vers�o inner join - guerra infinita
select	p.descricao,
		p.unidade,
		i.num_nota,
		i.qde,
		i.valor,
		i.qde * i.valor

from	produto as p
		inner join itens_pedido i on (p.cod_produto = i.cod_produto)
		inner join nota_fiscal as n on (n.num_nota = i.num_nota)

where	 n.data between '01/04/2000' and '15/04/2000'

order by p.descricao

/*
5.	Listar o nome do cliente, a cidade onde mora, o n�mero e data da nota fiscal. 
(fa�a com where e depois com inner join). 
Ordene pela data da nota, num. da nota e depois pelo cliente.
*/

-- where
select	cl.nome,	
		ci.nome as cidade,
		ci.uf,
		n.num_nota,
		n.data

from	cliente as cl, cidades as ci, nota_fiscal n

where	cl.cod_cidade = ci.cod_cidade and 
		cl.cod_cli = n.cod_cli

order by n.data, n.num_nota, cl.nome

-- inner join
select	cl.nome,	
		ci.nome as cidade,
		ci.uf,
		n.num_nota,
		n.data

from	cliente as cl
		inner join cidades as ci on (cl.cod_cidade = ci.cod_cidade)
		inner join nota_fiscal n on (cl.cod_cli = n.cod_cli)

order by n.data, n.num_nota, cl.nome

/*
6. Listar o nome do cliente, a cidade onde mora, o n�mero e data da nota fiscal, por�m
apenas dos clientes do estado de s�o Paulo e nota fiscal lan�ada a partir de agosto de
2000. Ordene pela data da nota, num. da nota e depois pelo cliente. (fa�a com where e
depois com inner join)
*/

-- vers�o where : o in�cio da saga 
select	cl.nome,
		rtrim(ci.nome) + '-' + ci.uf as cidade,
		n.num_nota,
		n.data

from	cliente as cl, cidades as ci, nota_fiscal n

where	cl.cod_cidade = ci.cod_cidade and n.cod_cli = cl.cod_cli
		and ci.uf = 'sp'
		and n.data >= '01/08/2000'

order by n.data, n.num_nota, cl.Nome

-- vers�o inner join : a saga continua
select	cl.nome,
		rtrim(ci.nome) + '-' + ci.uf as cidade,
		n.num_nota,
		n.data

from	cliente as cl
		inner join cidades as ci on (cl.cod_cidade = ci.cod_cidade)
		inner join nota_fiscal n on (n.cod_cli = cl.cod_cli)

where	ci.uf = 'sp'
		and n.data >= '01/08/2000'

order by n.data, n.num_nota, cl.Nome


/*
7. Listar a descri��o do produdo, qde vendida, independentemente se o produto foi
vendido ou n�o. (utilize left e depois right)
*/
-- vers�o left
select	p.descricao,
		i.qde
from produto p left outer join itens_pedido i on (p.cod_produto = i.cod_produto)

-- vers�o rigth : abonan�a
select	p.descricao,
		i.qde
from  itens_pedido i right outer join produto p on (p.cod_produto = i.cod_produto)

/*
8.	Listar o nome do cliente, o n�mero da nota fiscal, 
independentemente se o cliente possui nota ou n�o. 
(utilize left e depois rigth)
*/

-- left
select	cl.nome, 
		n.num_nota		

from cliente cl		
	 left join nota_fiscal n on (cl.cod_cli = n.cod_cli)

order by cl.nome

-- right
select	cl.nome, 
		n.num_nota		

from	nota_fiscal n 
		right join cliente cl on (cl.cod_cli = n.cod_cli)

order by cl.nome


/*
9. Listar o nome da cidade, nome do cliente, numero e data da nota fiscal, descri��o do
produto, qde vendida, valor unit�rio vendido, e valor total vendido (qde * valor). (fa�a
com where e depois com inner join)
*/

-- vers�o where : o desafio
select	ci.nome as cidade,
		ci.uf as 'Unidade_Federal',
		cl.nome as nome_cliente,
		n.num_nota,
		n.data,
		p.descricao as produto,
		i.qde as qde_vendida,
		i.valor as valor_unitario,
		i.qde * i.valor as valor_total

from	cidades ci, cliente cl, nota_fiscal n, itens_pedido i, produto as p

where	ci.cod_cidade = cl.cod_cidade and
		cl.cod_cli = n.cod_cli and
		n.num_nota = i.num_nota and
		i.cod_produto = p.cod_produto

order by nome_cliente

-- vers�o inner join : o tremor
select	ci.nome as cidade,
		ci.uf as 'Unidade_Federal',
		cl.nome as nome_cliente,
		n.num_nota,
		n.data,
		p.descricao as produto,
		i.qde as qde_vendida,
		i.valor as valor_unitario,
		i.qde * i.valor as valor_total

from	cidades ci
		inner join cliente cl       on (ci.cod_cidade = cl.cod_cidade)
		inner join nota_fiscal n	on (cl.cod_cli = n.cod_cli)
		inner join itens_pedido i	on (n.num_nota = i.num_nota)
		inner join produto as p		on (i.cod_produto = p.cod_produto)

order by nome_cliente

/*
9.1 Idem ao anterior, por�m, os clientes que n�o possuem cidade relacionada devem ser listados 
e as notas fiscais sem itens tamb�m 
*/

-- vers�o inner join : o desafio
select	ci.nome as cidade,
		ci.uf as 'Unidade_Federal',
		cl.nome as nome_cliente,
		n.num_nota,
		n.data,
		p.descricao as produto,
		i.qde as qde_vendida,
		i.valor as valor_unitario,
		i.qde * i.valor as valor_total

from	cidades ci
		right join cliente cl       on (ci.cod_cidade = cl.cod_cidade)
		inner join nota_fiscal n	on (cl.cod_cli = n.cod_cli)
		left join itens_pedido i	on (n.num_nota = i.num_nota)
		left join produto as p		on (i.cod_produto = p.cod_produto)

order by nome_cliente

