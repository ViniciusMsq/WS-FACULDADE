<?php

class BD
{
	public $pdo;

	function __construct()
	{
		try 
		{	
			$this->pdo = new PDO("mysql:host=localhost;dbname=baseteste2021","root","vertrigo"); 
		
		} catch(PDOException $e)
		{
			die('Não foi possível realizar a conexão com o Banco de Dados!!!');
			
			// a função die apresenta uma msg e interrompe o script. Possui o mesmo efeito que um echo acompanhado de um exit
			//echo 'Não foi possível realizar a conexão com o Banco de Dados!!!';
			//exit;
		}		
	} // construct

} // class Bd

