-- drop database baseteste;

create database baseteste2021;

use baseteste2021;

create table cidades (
	cod_cidade int not null auto_increment primary key,
	nome varchar(100) not null,
	uf char(2) not null
);

insert into cidades values (1,'Adamantina','SP');
insert into cidades values (2,'Lucelia','SP');
insert into cidades values (3,'Inubia Paulista','SP');
insert into cidades values (4,'Osvaldo Cruz','SP');
insert into cidades values (5,'Londrina','PR');
insert into cidades values (6,'Maringa','PR');
insert into cidades values (7,'Curitiba','PR');
insert into cidades values (8,'Belo Horizonte','MG');
insert into cidades values (9,'Uberlandia','MG');
insert into cidades values (10,'Salmourão','SP');


create table carros_marcas (
	cod_marca int not null auto_increment primary key,
	descricao varchar(100) not null,
	origem varchar(20) not null
);

create table carros_modelos (
	cod_modelo int not null auto_increment primary key,
	descricao varchar(100) not null,
	cod_marca int not null,
	constraint fk_marca_modelo foreign key (cod_marca) references carros_marcas (cod_marca)
);

insert into carros_marcas values (1,'Volkswagen', 'Alemanha');
insert into carros_marcas values (2,'Ford', 'Inglaterra');
insert into carros_marcas values (3,'Fiat', 'Itália');
insert into carros_marcas values (4,'Toyota', 'Japão');

insert into carros_modelos values (1,'Fusca',1);
insert into carros_modelos values (2,'Brasilia',1);
insert into carros_modelos values (3,'Parati',1);
insert into carros_modelos values (4,'Passati',1);

insert into carros_modelos values (5,'Belina',2);
insert into carros_modelos values (6,'Dell Rey',2);
insert into carros_modelos values (7,'Corcel',2);

insert into carros_modelos values (8,'147',3);
insert into carros_modelos values (9,'Uno',3);

insert into carros_modelos values (10,'Corolla',4);
insert into carros_modelos values (11,'Hillux',1);

create table carros (
	cod_carro int not null auto_increment primary key,
	cod_modelo int not null,
	placa char(7) not null,
	ano_modelo smallint,
	ano_fabricacao smallint,
	cor varchar(50),	
	descricao_detalhada varchar(100) not null,
	constraint fk_carro_modelo foreign key (cod_modelo) references carros_modelos (cod_modelo)
);

