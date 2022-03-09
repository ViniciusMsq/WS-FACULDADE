#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	float n1, n2 , n3, n4;
	
	cout<<"Digite um numero: ";
	cin>>n1;
	cout<<"Digite outro numero: ";
	cin>>n2;
	cout<<"Digite outro numero: ";
	cin>>n3;
	cout<<"Digite outro numero: ";
	cin>>n4;
	
	cout<<"Resultados: ";
	cout<<"\n N1+N2: "<<n1+n2<<" -N1xN2: "<<n1*n2;
	cout<<"\n N1+N3: "<<n1+n3<<" -N1xN3: "<<n1*n3;
	cout<<"\n N1+N4: "<<n1+n4<<" -N1xN4: "<<n1*n4;
	cout<<"\n N2+N3: "<<n2+n3<<" -N2xN3: "<<n2*n3;
	cout<<"\n N2+N4: "<<n2+n4<<" -N2xN4: "<<n1*n4;
	cout<<"\n N3+N4: "<<n3+n4<<" -N3xN4: "<<n3*n4;
	
	return 0;
}
