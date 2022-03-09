#include <iostream>

using namespace std;

//---------------------------------------------------------------------------------------------
class THello
{
	private:   // Propriedades e métodos que só podem ser acessados dentro da classe.
			   // Ou seja, os objetos não possuem acesso a estes elementos.
			   // No caso de alguma outra classe herdar esta classe, estes elementos não estarão
			   // presentes nesta nova classe.
		
		int x; 
				
	protected: // Propriedades e métodos que só podem ser acessados dentro da classe. {SEMELHANTE A PRIVATE}
			   // No caso de alguma outra classe herdar esta classe, ESTE ELEMENTOS ESTÃO PRESENTES NA NOVA CLASSE				
			   // Entretanto, estes elementos na nova classe serão considerados Privados.
			   
		int y;
		
	public:	   // Propriedades e métodos que SÃO VISÍVEIS dentro da classe e PELOS OBJETOS também.
		 	   // No caso de herança, estes elementos também estarão presentes.
		
		int z;
		
		void mensagem();
		THello();  // Método construtor: É executado automaticamente quando a classe é instanciada em um objeto
		~THello(); // Método DEstrutor: É executado automaticamente quando o objeto da classe é retirado ou 

}; // class THello

//---------------------------------------------------------------------------------------------
// Implementação dos métodos da classe THello

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
	THello::THello() // Método construtor: É executado automaticamente quando a classe é instanciada em um objeto
	{
		cout << "\n\nINICIANDO A CLASSE\n\n";
		
	} // construtor

	//-----------------------------------------------------------
	THello::~THello() // Método DEstrutor: É executado automaticamente quando o objeto da classe é retirado ou 
			  //				   destruido da memória		
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
		
	// x hteste não existe neste ponto porque foi declarado dentro de um bloco de comandos 
	
	THello h; // Declarando o objeto h da classe THello
	
	//h.x = 1; // ERRADO: porque x é privado, sendo assim, não pode ser acessado pelo objeto h
	
	//h.y = 2; // ERRADO: porque y é protegido, sendo assim, não pode ser acessado pelo objeto h
	
	h.z = 3; // z pode ser acessado pelo objeto h porque é público
	
	h.mensagem();
	
	return 0;
	
} // FIM DO PROGRAMA




