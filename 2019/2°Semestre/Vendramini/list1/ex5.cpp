#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
//Funções declaradas:
int retS(int x, int y);
int retP(int x, int y, int *z2);
//------------------------------------
int main(int argc, char** argv) {
	int z,z2, x, y;
	
	cout<<"informe o valor de x: ";
	cin>>x;
	cout<<"Informe o valor de y: ";
	cin>>y;
	
	z= retS(x,y);
	retP(x,y, &z2);
	
	cout<<"z: "<<z;
	cout<<"\nz2: "<<z2;
	return 0;
}
//Funões-------------------------------
int retS(int x, int y){
		return(x+y);
}
int retP(int x, int y, int *z2){
	*z2 = x+y;
}
