<?php

class Classe_data
{
	private $semana;
	private $mes;
	private $data;
	
	//-------------------------------------------------------------------------
	function __construct()
	{
		if( func_num_args() == 3 )
		{
			$this->data = mktime(0, 0, 0, func_get_arg(1), func_get_arg(0), func_get_arg(2) );
		}
		else
		{
			$this->data = time();
		}
		
		$this->semana[0] = 'Domingo';
		$this->semana[1] = 'Segunda-Feira';
		$this->semana[2] = 'Ter&ccedil;a-Feira';
		$this->semana[3] = 'Quarta-Feira';
		$this->semana[4] = 'Quinta-Feira';
		$this->semana[5] = 'Sexta-Feira';
		$this->semana[6] = 'Sab&aacute;do';

		$this->mes[1] = 'Janeiro';
		$this->mes[2] = 'Fevereiro';
		$this->mes[3] = 'Mar&ccedil;o';
		$this->mes[4] = 'Abril';
		$this->mes[5] = 'Maio';
		$this->mes[6] = 'Junho';
		$this->mes[7] = 'Julho';
		$this->mes[8] = 'Agosto';
		$this->mes[9] = 'Setembro';
		$this->mes[10] = 'Outubro';
		$this->mes[11] = 'Novembro';
		$this->mes[12] = 'Dezembro';
		
	} // construtor...

	//-------------------------------------------------------------------------
	public function nome_do_mes()
	{
		return $this->mes[(int)date('m',$this->data)];
	}

	//-------------------------------------------------------------------------
	public function nome_do_dia()
	{
		return $this->semana[date('w',$this->data)];
	}
	
	//-------------------------------------------------------------------------
	public function dia()
	{
		return date('j',$this->data);
	}

	//-------------------------------------------------------------------------
	public function ano()
	{
		return date('Y',$this->data);
	}
	
	//-------------------------------------------------------------------------
	public function data_por_extenso()
	{
		return $this->nome_do_dia() . ', ' . $this->dia() . ' de ' . $this->nome_do_mes() . ' de ' . $this->ano();
	}

	//-------------------------------------------------------------------------
	public function calendario()
	{

		if( func_num_args() == 2 )
		{
			$mes = func_get_arg(0);
			$ano = func_get_arg(1);
		}
		else
		{
			$mes = (int)date('m', $this->data);
			$ano = (int)date('Y', $this->data);
		}



		$mes_original = $mes;
		$i = 1;

		$data = mktime(0, 0, 0, $mes, $i, $ano  );

		echo '<table width="50%">';

		echo '<tr bgcolor="#c2c2c2"><td colspan="2" align="center">';
		echo '<b>' . strtoupper($this->mes[$mes]) ;
		echo ' DE ' . $ano . '</b></td></tr>';

		while( $mes_original == $mes )
		{	
			//echo date('d/m/Y', $data) . '<br>';

			echo '<tr bgcolor="#e8e8e8">';

			if( date('w', $data) == 0 or date('w', $data) == 6)
			{
				$cor = '#f00';
			}
			else
			{
				$cor = '#e8e8e8';
			}

			echo '<td align="center" bgcolor="'.$cor.'">' . date('d', $data) . '</td>';
			echo '<td align="left" bgcolor="'.$cor.'">' . $this->semana[date('w', $data)] . '</td>';

			echo '</tr>';


			$i++;
			$data = mktime(0, 0, 0, $mes, $i, $ano  );

			$mes = (int)date('m', $data);

		} // while( $mes_original == $mes )


		echo '</table>';
		


	} // calendario()


} // Classe_data

?>
