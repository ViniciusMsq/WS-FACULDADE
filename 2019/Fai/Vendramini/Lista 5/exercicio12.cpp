#include <iostream>

using namespace std;
int main(){
	int v1[2], v2[2], v3[2], i, c=0, x=0;
	
	for(i=0; i<2; i++){
		cout<<"informe um numero: ";
		cin>>v1[i];
		cout<<"Informe outro numero: ";
		cin>>v2[i];
	}
	
	for(i=0;i<2;i++){
			v3[i]= v1[i]*v2[i];
			

		cout<<" "<<v3[i];
	}
}
