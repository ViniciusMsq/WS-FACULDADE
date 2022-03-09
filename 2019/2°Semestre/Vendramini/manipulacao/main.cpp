#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	fstream arquivo;
	char opc='s';
	string nome,linha;
	
	arquivo.open("teste.txt",ios::out|ios::app);
	
	while((opc=='s')or(opc=='S')){
		cout<<"Digite um nome: ";
		cin>>nome;
		arquivo<<nome<<"\n";
		cout<<"digitar outro?[s/n]";
		cin>>opc;
		system("CLS");
	}
	arquivo.close();
	
	arquivo.open("teste.txt",ios::out);
	
	cout<<"nomes digitados"<<endl;
	if(arquivo.is_open()){
		while(getline(arquivo,linha)){
			cout<<linha<<endl;
		}
		arquivo.close();
	}
	else{
		cout<<"não foi possivel ler"<<endl;
	}
	
	return 0;
}
