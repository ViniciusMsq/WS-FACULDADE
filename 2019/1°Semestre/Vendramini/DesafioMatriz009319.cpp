#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
	
	int i, j, LinhaA, ColunA, LinhaB, ColunB, x;
	cout<<"Quantidade de linha De A: ";
	cin>>LinhaA;
	cout<<"Quantidade de coluna de A: ";
	cin>>ColunA;
	cout<<"Quantidade de linha De B: ";
	cin>>LinhaB;
	cout<<"Quantidade de coluna de B: ";
	cin>>ColunB;
	
	float MA[LinhaA][ColunA], MB[LinhaB][ColunB], MC[LinhaA][ColunB], a=0;
	
	if(ColunA==LinhaB){
		for(i=0; i<LinhaA; i++){
			for(j=0; j<ColunA; j++){
				 printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da Matriz A: ", i+1, 167, j+1, 167);
				 cin>>MA[i][j];
			}	
		}
		for(i=0; i<LinhaB; i++){
			for(j=0; j<ColunB; j++){
				 printf("\n\n Informe o valor da %d%c Linha e da %d%c Coluna da Matriz B: ", i+1, 167, j+1, 167);
				 cin>>MB[i][j];
			}	
		}
		
		cout<<"\n";
		cout<<"Matriz A: \n";
		for(i=0; i<LinhaA; i++){
			for(j=0; j<ColunA; j++){
				 cout<<" "<<MA[i][j];
			}
			cout<<"\n";	
		}
		cout<<"\n";
		cout<<"Matriz B: \n";
		for(i=0; i<LinhaB; i++){
			for(j=0; j<ColunB; j++){
				cout<<" "<<MB[i][j];
			}
			cout<<"\n";	
		}
		for(i=0; i<LinhaA; i++){
        	for(j=0; j<ColunB; j++){
                MC[i][j]=0;
                for(x=0; x<LinhaB; x++){
                 a += MA[i][x] * MB[x][j];
                }
                 MC[i][j]=a;
                 a=0;
            }
        }
        
        cout<<"\n\n";
        cout<<"Matriz C: \n";
        for(i=0; i<LinhaA; i++){
        	for(j=0; j<ColunB; j++){
        		cout<<" "<<MC[i][j];
			}
			cout<<"\n";
		}
        
		
	}
	else{
		cout<<"\nNão é possivel Multiplicar";
	}
	
	return 0;
}
