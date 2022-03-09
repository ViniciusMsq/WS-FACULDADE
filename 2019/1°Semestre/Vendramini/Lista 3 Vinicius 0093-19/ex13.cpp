#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int x;
	
	cout<<"Informe o valor de X: ";
	cin>>x;
	
	if(x>0){
		cout<<"resultado: "<<x-1;
	}
	else if(x<0){
		cout<<"resultado: "<<x+1;
	}
	else{
		cout<<"resultado: "<<1;
	}
	
	return 0;
}
