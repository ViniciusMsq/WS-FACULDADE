#include <iostream>
#include "TABB.h"
#include "funcoes.h"

using namespace std;

//---------------------------------------------------------------------------------
int main(int argc, char** argv) {
	
	TABB arvore;
	TABB::TNo* no;
	int n, op=1;
	
	while(op>0 && op<7){
		system("CLS");
		printf(" 1) Incluir na arvore\n 2) Remover\n 3) Alterar\n 4) Destruir a arvore\n 5) Imprimir a arvore\n 6) Pesquisar\n 7) Sair do sistema\n");
		cout<<"\nDIGITE A OPCAO: ";
		cin>>op;
		
		if(op>0 && op<7){
			system("CLS");
			switch(op){
				case 1: cout<<"INSERIR NO\n ";
						cout<<"Digite o numero a inserir: ";
						int x;
						cin>>x;
						arvore.InserirNo( arvore.Raiz, x );
					break;
				case 2: cout<<"REMOVER NO\n ";
						cout<<"Digite o numero a remover: ";
						cin>>x;
						arvore.Remover(x);
					break;
				case 3: cout<<"ALTERAR NO\n ";
						cout<<"Digite o numero a remover: ";
						cin>>x;
						arvore.Remover(x);
						cout<<"Digite o numero a inserir: ";
						cin>>x;
						arvore.InserirNo( arvore.Raiz, x );
					break;
				case 4: cout<<"DELETANDO ARVORE\n";
						
						while(!arvore.IsEmpty()){
							
							arvore.Remover(arvore.GetRaiz()->dado);
						}
					break;
				case 5: cout<<"ARVORE\n";
						arvore.print_elementos_da_arvore( arvore.GetRaiz() );
						system("PAUSE");
					break;
				case 6: cout<<"PESQUISAR\n ";
						int pesquisa;	
						cout << "\n\nInfome um numero a pesquisa: ";
						cin >> pesquisa;
						
						TABB::TNo* aux;
						aux = arvore.LocalizarNo( arvore.Raiz, pesquisa);
						
							
						if( aux != NULL )
						{
							cout << "\n\nVALOR ENCONTRADO !!!\n\n";
						}
						else
						{
							cout << "\n\nValor NAO encontrado !!!\n\n";
						}
						system("PAUSE");
					break;
				case 7:
					break;
			}
		}	
	}
	
	system("PAUSE");
	


	cout << "\n\n";
	
	return 0;
	
} // main()
