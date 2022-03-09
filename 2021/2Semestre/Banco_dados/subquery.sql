/*2. Listar todas as cidades que n�o possuem funcion�rios relacionados utilizando 
subquery junto com o perador IN */
SELECT * 
FROM cidades c
WHERE c.cod_cidade not in (select distinct isnull(cod_cidade, 0) from FUNCIONARIOS);

/*3. Listar todas as cidades que possuem funcion�rios relacionados utilizando subquery 
junto com o perador IN*/
SELECT * 
FROM cidades c
WHERE c.cod_cidade in (select distinct isnull(cod_cidade, 0) from FUNCIONARIOS);


/*4. Listar todas as cidades que n�o possuem funcion�rios relacionados utilizando 
subquery junto com o perador EXISTS*/
SELECT * 
FROM cidades c
WHERE not exists (select * from FUNCIONARIOS  f where c.Cod_cidade = f.Cod_cidade);

/*5. Listar todas as cidades que possuem funcion�rios relacionados utilizando subquery 
junto com o perador EXISTS*/
SELECT * 
FROM cidades c
WHERE exists (select * from FUNCIONARIOS  f where c.Cod_cidade = f.Cod_cidade);

/*6. Listar todos os cargos que est�o relacionados com funcion�rios utilizando uma 
subquery que retorne o resultado de um count(*) */
SELECT *
FROM cargos  c
WHERE (select COUNT(*) from FUNCIONARIOS  f where f.Cod_cargo = c.cod_cargo) > 0;

/*7. Listar o nome do funcion�rio, cargo e sal�rio utilizando a cl�usula where */
SELECT  f.Nome 'Nome', 
		c.descricao  'Cargo', 
		c.salario 'Salario'
FROM FUNCIONARIOS  f, 
	 cargos c
WHERE f.Cod_cargo = c.cod_cargo;

/*8. Listar o nome do funcion�rio, cargo e sal�rio utilizando a cl�usula inner join */
SELECT  f.Nome  'Nome', 
		c.descricao  'Cargo', 
		c.salario  'Salario'
FROM FUNCIONARIOS  f 
	 INNER JOIN cargos  c ON (f.Cod_cargo = c.cod_cargo);

/*9. Listar o nome do funcion�rio, cargo e sal�rio utilizando subquery*/
SELECT  f.Nome  'Nome',
		(select descricao from cargos  c where c.cod_cargo = f.cod_cargo)  'Cargo',
		(select salario from cargos  c where c.cod_cargo = f.cod_cargo)  'Salario'
FROM FUNCIONARIOS  f

/*10. Apagar as cidades que n�o est�o relacionadas com funcion�rios */
DELETE FROM cidades
WHERE not exists (select * from FUNCIONARIOS  f where f.Cod_cidade = cidades.Cod_cidade);