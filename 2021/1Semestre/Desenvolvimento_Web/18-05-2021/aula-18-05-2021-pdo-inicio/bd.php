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
			die('N�o foi poss�vel realizar a conex�o com o Banco de Dados!!!');
			
			// a fun��o die apresenta uma msg e interrompe o script. Possui o mesmo efeito que um echo acompanhado de um exit
			//echo 'N�o foi poss�vel realizar a conex�o com o Banco de Dados!!!';
			//exit;
		}		
	} // construct

} // class Bd

