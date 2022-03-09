#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int dividendo, divisor = 1;
	float s=0;
	
	for(dividendo = 1; dividendo<=99;dividendo += 2){
		
		s += dividendo/divisor;
		
		cout<<"\n"<<dividendo<<"/"<<divisor;
		
		divisor++;
	}
	
	cout<<"\n\n"<<s;
	
	
	return 0;
}
