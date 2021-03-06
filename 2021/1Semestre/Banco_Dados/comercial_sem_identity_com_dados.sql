USE MASTER
GO


--DROP DATABASE COMERCIAL_2021
GO

CREATE DATABASE COMERCIAL_2021
GO

USE COMERCIAL_2021
GO
/****** Object:  Table [dbo].[cidades]    Script Date: 04/27/2012 16:15:43 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[cidades](
	[Cod_cidade] [int] NOT NULL,
	[Nome] [varchar](100) NULL,
	[uf] [char](2) NULL,
 CONSTRAINT [PK_cidades] PRIMARY KEY CLUSTERED 
(
	[Cod_cidade] ASC
) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[produto]    Script Date: 04/27/2012 16:15:43 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[produto](
	[Cod_produto] [int] NOT NULL,
	[Descricao] [varchar](100) NULL,
	[Unidade] [char](10) NULL,
	[Valor_Unitario] [float] NULL,
 CONSTRAINT [PK_produto] PRIMARY KEY CLUSTERED 
(
	[Cod_produto] ASC
) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[cliente]    Script Date: 04/27/2012 16:15:43 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[cliente](
	[Cod_cli] [int] NOT NULL,
	[Nome] [varchar](100) NULL,
	[Endereco] [varchar](150) NULL,
	[Cod_cidade] [int] NULL,
	[data_nascimento] [datetime] NULL,
	[data_cadastro] [datetime] NULL default getdate(),
 CONSTRAINT [PK_cliente] PRIMARY KEY CLUSTERED 
(
	[Cod_cli] ASC
) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[nota_fiscal]    Script Date: 04/27/2012 16:15:43 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[nota_fiscal](
	[Num_nota] [int] NOT NULL,
	[Cod_cli] [int] NULL,
	[Data] [datetime] NULL,
 CONSTRAINT [PK_nota_fiscal] PRIMARY KEY CLUSTERED 
(
	[Num_nota] ASC
) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[itens_pedido]    Script Date: 04/27/2012 16:15:43 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[itens_pedido](
	[Num_nota] [int] NOT NULL,
	[Cod_produto] [int] NOT NULL,
	[Qde] [float] NULL,
	[Valor] [float] NULL,
 CONSTRAINT [PK_itens_pedido] PRIMARY KEY CLUSTERED 
(
	[Num_nota] ASC,
	[Cod_produto] ASC
) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  ForeignKey [FK_cliente_cidades]    Script Date: 04/27/2012 16:15:43 ******/
ALTER TABLE [dbo].[cliente]  WITH NOCHECK ADD  CONSTRAINT [FK_cliente_cidades] FOREIGN KEY([Cod_cidade])
REFERENCES [dbo].[cidades] ([Cod_cidade])
GO
ALTER TABLE [dbo].[cliente] CHECK CONSTRAINT [FK_cliente_cidades]
GO
/****** Object:  ForeignKey [FK_itens_pedido_nota_fiscal]    Script Date: 04/27/2012 16:15:43 ******/
ALTER TABLE [dbo].[itens_pedido]  WITH NOCHECK ADD  CONSTRAINT [FK_itens_pedido_nota_fiscal] FOREIGN KEY([Num_nota])
REFERENCES [dbo].[nota_fiscal] ([Num_nota])
GO
ALTER TABLE [dbo].[itens_pedido] CHECK CONSTRAINT [FK_itens_pedido_nota_fiscal]
GO
/****** Object:  ForeignKey [FK_itens_pedido_produto]    Script Date: 04/27/2012 16:15:43 ******/
ALTER TABLE [dbo].[itens_pedido]  WITH NOCHECK ADD  CONSTRAINT [FK_itens_pedido_produto] FOREIGN KEY([Cod_produto])
REFERENCES [dbo].[produto] ([Cod_produto])
GO
ALTER TABLE [dbo].[itens_pedido] CHECK CONSTRAINT [FK_itens_pedido_produto]
GO
/****** Object:  ForeignKey [FK_nota_fiscal_cliente]    Script Date: 04/27/2012 16:15:43 ******/
ALTER TABLE [dbo].[nota_fiscal]  WITH NOCHECK ADD  CONSTRAINT [FK_nota_fiscal_cliente] FOREIGN KEY([Cod_cli])
REFERENCES [dbo].[cliente] ([Cod_cli])
GO
ALTER TABLE [dbo].[nota_fiscal] CHECK CONSTRAINT [FK_nota_fiscal_cliente]
GO

--- produto ---

insert into produto values ('1','Queijo  ',      'Kg ',2.3   );
insert into produto values ('2','Chocolate',  'BAR',1.4   );
insert into produto values ('3','Vinho  ',      'L  ',15.68 );
insert into produto values ('4','Linho  ',      'M  ',1.05  );
insert into produto values ('5','Açúcar  ',      'Kg ',1.23  );
insert into produto values ('6','Linha  ',      'M  ',1.5   );
insert into produto values ('7','Papel  ',      'M  ',1.05  );


--- cidades ---
insert into cidades values ('1','Adamantina    ','SP');
insert into cidades values ('2','Tupã       ',        'SP');
insert into cidades values ('3','Curitiba      ','PR');
insert into cidades values ('4','Belo Horizonte','MG');


--- cliente ---

insert into cliente  (cod_cli, nome, cod_cidade, endereco, data_nascimento) values (1,'Ana ',  1,'Rua 17, n. 19','01-02-1990');
insert into cliente  (cod_cli, nome, cod_cidade, endereco, data_nascimento) values (2,'Flávio ',  1,'Av. Pres. Vargas, 10','25-08-1989');
insert into cliente  (cod_cli, nome, cod_cidade, endereco, data_nascimento) values (3,'Jorge ',  1,'Rua Itabira, 123','13-09-1988');
insert into cliente  (cod_cli, nome, cod_cidade, endereco, data_nascimento) values (4,'Lúcia ',  2,'Largo da Lapa 27 sobrado','15-04-1995');
insert into cliente  (cod_cli, nome, cod_cidade, endereco, data_nascimento) values (5,'Maurício',  3,'Rua Lopes 789','21-06-1994');
insert into cliente  (cod_cli, nome, cod_cidade, endereco, data_nascimento) values (6,'Rodolfo ',  3,'Av. Beira Mar 1256','17-03-1980');
insert into cliente  (cod_cli, nome, cod_cidade, endereco, data_nascimento) values (7,'Gisele ',  4,'Av. Rio Branco 778','01-02-1976');


--- nota_fiscal ---
insert into nota_fiscal values (871,5,'10/08/2000');
insert into nota_fiscal values (872,1,'05/12/2000');
insert into nota_fiscal values (873,7,'01/10/2000');
insert into nota_fiscal values (874,3,'13/04/2000');
insert into nota_fiscal values (875,2,'17/02/2000');
insert into nota_fiscal values (687,5,'23/09/2000');
insert into nota_fiscal values (787,4,'28/09/2000');


--- itens_pedido ---
insert into itens_pedido values (871,1,2,4.6  );
insert into itens_pedido values (871,2,1,1.4  );
insert into itens_pedido values (873,1,4,9.2  );
insert into itens_pedido values (873,5,1,1.23 );
insert into itens_pedido values (873,3,2,31.36);
insert into itens_pedido values (687,6,1,1.5  );

insert into produto values (8,'Paçoca','kg',7.5);
insert into produto values (9,'Mussarela Perdigão','Kg',132);
insert into produto values (10,'Vinho Goes','L',12);
insert into produto values (11,'Vodka','L',58);
insert into produto values (12,'Vinho Goes','L',12);
