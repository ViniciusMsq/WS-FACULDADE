CREATE TABLE FORNECEDORES(
	COD_FORCEDOR INT IDENTITY(1,1) PRIMARY KEY,
	RAZAO_SOCIAL VARCHAR(100),
	COD_CIDADE INT,
	CONSTRAINT FK_COD_CIDADE FOREIGN KEY (COD_CIDADE) REFERENCES CIDADES(COD_CIDADE)
)