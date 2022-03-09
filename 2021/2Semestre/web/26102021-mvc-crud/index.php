<?php
session_start();

// ROTEADOR -------------------------------------------------------

$modulo = isset($_GET["modulo"]) ? $_GET["modulo"] : "home";
$acao = isset($_GET["acao"]) ? $_GET["acao"] : "index";

include_once("lib/funcoes.php");

// AUTOLOAD  -------------------------------------------------------
include_once("autoload.php");

use \Controller\HomeController;
use \Controller\AutenticarController;
use \Controller\LogoutController;

use \Controller\CidadesController;
use \Controller\UnidadesController;
//use \Controller\IngredientesController;
use \Controller\ClientesController;


// ROTEADOR -------------------------------------------------------
if( strtolower($modulo) == 'home' ) {

	$ctrl = new HomeController();

	switch(strtolower($acao) ) {
	    case "index" : 
	    $ctrl->Index();
	    break;
	}

} // if modulo Home

//----------------------------------------------------------------
elseif( strtolower($modulo) == 'autenticar' ) {

	$ctrl = new AutenticarController();
	$ctrl->Autenticar();

}

//----------------------------------------------------------------
elseif( strtolower($modulo) == 'logout' ) {

	$ctrl = new LogoutController();
	$ctrl->Logout();

}

//----------------------------------------------------------------
elseif( strtolower($modulo) == 'cidades' ) {

	$ctrl = new CidadesController();

	switch( strtolower($acao) )  {
	    case "listar" : 
	    	$ctrl->Listar();
	    	break;

	    case "excluir" : 
	    	$ctrl->Excluir(@$_GET['cod_cidade']);
	    	break;

	    case "incluindo" : 
	    	$ctrl->Formulario('');
	    	break;

	    case "incluir" : 
	    	$ctrl->Incluir();
	    	break;

	    case "alterando" : 
	    	$ctrl->Formulario(@$_GET['cod_cidade']);
	    	break;

	    case "alterar" : 
	    	$ctrl->Alterar();
	    	break;

	    default: 
	    	$ctrl->Listar();
	    	break;
	}

} // if modulo cidades
//----------------------------------------------------------------
elseif( strtolower($modulo) == 'unidades' ) {

	$ctrl = new UnidadesController();

	switch( strtolower($acao) )  {
	    case "listar" : 
	    	$ctrl->Listar();
	    	break;

	    case "excluir" : 
	    	$ctrl->Excluir(@$_GET['cod_unidade']);
	    	break;

	    case "incluindo" : 
	    	$ctrl->Formulario('');
	    	break;

	    case "incluir" : 
	    	$ctrl->Incluir();
	    	break;

	    case "alterando" : 
	    	$ctrl->Formulario(@$_GET['cod_unidade']);
	    	break;

	    case "alterar" : 
	    	$ctrl->Alterar();
	    	break;

	    default: 
	    	$ctrl->Listar();
	    	break;
	}

} // if modulo unidades
//----------------------------------------------------------------
elseif( strtolower($modulo) == 'clientes' ) {

	$ctrl = new ClientesController();

	switch( strtolower($acao) )  {
	    case "listar" : 
	    	$ctrl->Listar("");
	    	break;

	    case "excluir" : 
	    	$ctrl->Excluir(@$_GET['cod_cliente']);
	    	break;

	    case "incluindo" : 
	    	$ctrl->Formulario('');
	    	break;

	    case "incluir" : 
	    	$ctrl->Incluir();
	    	break;

	    case "alterando" : 
	    	$ctrl->Formulario(@$_GET['cod_cliente']);
	    	break;

	    case "alterar" : 
	    	$ctrl->Alterar();
	    	break;

	    case "ver-duplic" : 
	    	$ctrl->VerDuplicidade($_POST);
	    	break;

	    default: 
	    	$ctrl->Listar("");
	    	break;
	}

} // if modulo clientes

/*
//----------------------------------------------------------------
elseif( strtolower($modulo) == 'ingredientes' ) {

	$ctrl = new IngredientesController();

	switch( strtolower($acao) )  {
	    case "listar" : 
	    	$ctrl->Listar();
	    break;

	    case "excluir" : 
	    	$ctrl->Excluir(@$_GET['cod_ingrediente']);
	    break;

	    case "incluindo" : 
	    	$ctrl->Formulario('');
	    break;

	    case "incluir" : 
	    	$ctrl->Incluir();
	    break;

	    case "alterando" : 
	    	$ctrl->Formulario(@$_GET['cod_ingrediente']);
	    break;

	    case "alterar" : 
	    	$ctrl->Alterar();
	    break;

	    default: 
	    	$ctrl->Listar();
	    break;
	}

} // if modulo cidades
*/
//----------------------------------------------------------------
else 
{

	$ctrl = new HomeController();
	$ctrl->Index();

}

