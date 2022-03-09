#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {

	int cont = 0, hor=0, min=0, seg=0;
	float mi = 0.0,gr = 0.0;
	
	cout<<"Digite a massa do material em gramas: ";
	cin>>mi;
	gr = mi;
	while(gr >= 0.5){
		
		cont += +50;
		gr = gr/2;  
	}
	
	seg = cont%60;
	min = (cont/60)%60;
	hor =  (cont/60)/60;
	cout<<cont;
	cout<<"\nHoras: "<<hor;
	cout<<"\nMinutos: "<<min;
	cout<<"\nSegundos: "<<seg;

	return 0;
}
