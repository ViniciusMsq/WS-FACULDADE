#include <iostream>

using namespace std;

//---------------------------------------------------------------------------------------------
class THello
{
	private:   // Propriedades e m�todos que s� podem ser acessados dentro da classe.
			   // Ou seja, os objetos n�o possuem acesso a estes elementos.
			   // No caso de alguma outra classe herdar esta classe, estes elementos n�o estar�o
			   // presentes nesta nova classe.
		
		int x; 
				
	protected: // Propriedades e m�todos que s� podem ser acessados dentro da classe. {SEMELHANTE A PRIVATE}
			   // No caso de alguma outra classe herdar esta classe, ESTE ELEMENTOS EST�O PRESENTES NA NOVA CLASSE				
			   // Entretanto, estes elementos na nova classe ser�o considerados Privados.
			   
		int y;
		
	public:	   // Propriedades e m�todos que S�O VIS�VEIS dentro da classe e PELOS OBJETOS tamb�m.
		 	   // No caso de heran�a, estes elementos tamb�m estar�o presentes.
		
		int z;
		
		void mensagem();
		THello();  // M�todo construtor: � executado automaticamente quando a classe � instanciada em um objeto
		~THello(); // M�todo DEstrutor: � executado automaticamente quando o objeto da classe � retirado ou 

}; // class THello

//---------------------------------------------------------------------------------------------
// Implementa��o dos m�todos da classe THello

	//-----------------------------------------------------------
	void THello::mensagem()
	{
		x = 10;
		y = 11;
		z = 12;
					
		cout << "\n\nHello World POO !!!!";
		
		cout << "\nO valor da propriedade x e: " << x;
		cout << "\nO valor da propriedade y e: " << y;
		cout << "\nO valor da propriedade z e: " << z;
		
		cout << "\n\n\n";
		
		
	} // void mensagem()
	
	//-----------------------------------------------------------
	THello::THello() // M�todo construtor: � executado automaticamente quando a classe � instanciada em um objeto
	{
		cout << "\n\nINICIANDO A CLASSE\n\n";
		
	} // construtor

	//-----------------------------------------------------------
	THello::~THello() // M�todo DEstrutor: � executado automaticamente quando o objeto da classe � retirado ou 
			  //				   destruido da mem�ria		
	{
		cout << "\n\nDESTRUINDO O OBJEDO DA CLASSE, OU SEJA, RETIRANDO ESTE OBJETO DA MEMORIA\n\n";
		
	} // DEstrutor

	//-----------------------------------------------------------


//---------------------------------------------------------------------------------------------
int main(int argc, char** argv) 
{

	if( 1 == 1 )
	{
		THello hteste;
		int x;
	}
		
	// x hteste n�o existe neste ponto porque foi declarado dentro de um bloco de comandos 
	
	THello h; // Declarando o objeto h da classe THello
	
	//h.x = 1; // ERRADO: porque x � privado, sendo assim, n�o pode ser acessado pelo objeto h
	
	//h.y = 2; // ERRADO: porque y � protegido, sendo assim, n�o pode ser acessado pelo objeto h
	
	h.z = 3; // z pode ser acessado pelo objeto h porque � p�blico
	
	h.mensagem();
	
	return 0;
	
} // FIM DO PROGRAMA




