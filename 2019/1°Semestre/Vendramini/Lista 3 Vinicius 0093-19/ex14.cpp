#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	float x;
	
	cout<<"Digite um valor para X";
	cin>>x;
	
	if(x>1){
		cout<<sqrt(x+1);
	}
	else if(x == 1){
		cout<<"1";
	}
	else{
		cout<<x+100;
	}
	
	return 0;
}
