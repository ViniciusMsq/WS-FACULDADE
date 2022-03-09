/*-----------------------------------------------------------------------------------------
BASE DE DADOS
STORED PROCEDURE LISTA 1 DE EXERCÍCIOS
------------------------------------------------------------------------------------------*/

use master
go

--drop database comercial_sp_2021

create database comercial_sp_2021
go

-- EXERCÍCIO 2 : Criando o projeto físico --------------------------------------------------
use comercial_sp_2021
go


create table cidades (
	cod_cidade int not null identity(1,1),
	nome varchar(100) not null,
	uf char(2) not null,
	cep_padrao char(8),
	constraint pk_cidades primary key clustered (cod_cidade)
);	
	
create table marcas (
	cod_marca int not null identity(1,1),
	descricao varchar(100) not null,
	constraint pk_marcas primary key clustered (cod_marca)
);	
	
	
create table produtos (
	cod_produto int not null identity(1,1),
	descricao varchar(100) not null,
	valor_unitario float,
	unidade char(10),
	cod_marca int,
	qde_estoque float
	constraint pk_produtos primary key clustered (cod_produto)
	constraint fk_produtos_marcas foreign key (cod_marca) references marcas (cod_marca)
);	
	
create table clientes (
	cod_cliente int not null identity(1,1),
	nome varchar(100) not null,
	cpf char(14),
	endereco varchar(100),
	bairro varchar(50),
	cod_cidade int,
	cep char(8),
	telefone varchar(20),
	celular varchar(20),
	data_cadastro datetime default getdate()
	constraint pk_clientes primary key clustered (cod_cliente)
	constraint fk_clientes_cidades foreign key (cod_cidade) references cidades (cod_cidade)
)	
;
create table nota_fiscal (
	num_nota int not null identity(1,1),
	cod_cliente int ,
	data datetime,
	constraint pk_nota_fiscal primary key clustered (num_nota),
	constraint fk_nota_fiscal_clientes foreign key (cod_cliente) references clientes (cod_cliente)
)	
;
create table itens_nota (
	num_nota int not null ,
	cod_produto int not null,
	qde float default 0,
	valor_unitario float default 0,
	constraint pk_itens_nota primary key clustered (num_nota, cod_produto),
	constraint fk_nota_fiscal_itens foreign key (num_nota) references nota_fiscal (num_nota),
	constraint fk_nota_fiscal_produtos foreign key (cod_produto) references produtos (cod_produto)
)	
;

