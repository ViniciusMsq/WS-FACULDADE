#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
int main(int argc, char** argv) {
	float x, r1, r2;
	
	cout<<"De um valor para X: ";
	cin>>x;
	
	r1 = 2*x+1;
	r2 = (x*x*x)- 2*(x*x)+x-1;
	
	cout<<"O resultado de (a) é: "<<r1;
	cout<<"\nO resultado de (b) é: "<<r2;
	
	
	return 0;
}
