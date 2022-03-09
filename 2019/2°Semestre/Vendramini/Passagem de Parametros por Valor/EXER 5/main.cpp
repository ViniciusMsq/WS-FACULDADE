#include <iostream>

using namespace std;

 void por_ref(int x, int y, int *w)
{
 	
 	 *w= x + y;
 	
}
 
 int por_valor(int x, int y)
 {
 	int soma;
 	soma= x + y;
 	
 	
 	return soma;
 }

int main(int argc, char** argv) 
{
	int z,x,y;
	x=20; y=10;
	
	//1ª Soma  por referencia.
	//z=por_valor(x, y);
	
	//2ª Soma por retorn.
	por_ref( x, y, &z);
	
	cout<<"Soma: "<<z<<"\n";
	cout<<"x: "<<x<<"\n";
	cout<<"y: "<<y<<"\n";
	
	
	return 0;
}
