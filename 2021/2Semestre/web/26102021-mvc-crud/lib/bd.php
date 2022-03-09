<?php

namespace Lib;

use \PDO; // necessário para autoload da classe PDO

class BD
{
	public $pdo;

	function __construct()
	{
		try 
		{	
			$this->pdo = new PDO("mysql:host=localhost;dbname=restaurante2021","root","vertrigo"); 
		
		} catch(PDOException $e)
		{
			die('Não foi possível realizar a conexão com o Banco de Dados!!!');
		}		
	} // construct

} // class Bd

