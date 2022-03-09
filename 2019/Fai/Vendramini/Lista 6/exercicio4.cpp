#include <iostream>

using namespace std;

int main(){
	   int i, j, l, c, aux;
	   
	   cout<<"Informe a quantidade de linhas : ";
	   cin>>l;
	   cout<<"Informe a quantidade de colunas : ";
	   cin>>c;
	   
	   int ma[l][c];
	   
	   for(i=0; i<l; i++){
	   		for(j=0;j<c;j++){
	   			cout<<"Informe o valor da linha "<<(i+1)<<" e coluna "<<(j+1)<<": ";
				cin>>ma[i][j];
			}
	   }
	   for(i=0; i<l; i++){
	   		for(j=0;j<c;j++){
	   			cout<<" "<<ma[i][j];
			}
			cout<<"\n";
	   }
	   cout<<"\nTransposta-----------\n";
	   for(j=0; j<c;j++){
	   		for(i=0;i<l;i++){
	   			cout<<" "<<ma[i][j];
			   }
			   cout<<"\n";
	   }
}
