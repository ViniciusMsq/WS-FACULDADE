#include <iostream>
using namespace std;

int main(){
	
	int i, j,t , aux;
	
	cout<<"Informe a matriz quadrada : ";
	cin>>t;
	   
	int ma[t][t];
	   
	for(i=0; i<t; i++){
	   	for(j=0;j<t;j++){
	   		cout<<"Informe o valor da linha "<<(i+1)<<" e coluna "<<(j+1)<<": ";
			cin>>ma[i][j];
		}
	}
	for(i=0; i<t; i++){
	   	for(j=0;j<t;j++){
	   		cout<<" "<<ma[i][j];
		}
		cout<<"\n";
	}
	
}
