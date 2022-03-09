#include <iostream>

using namespace std;
int main(){
	
	int v1[2], v2[2], v3[4], i, c=0, x=0;
	
	for(i=0; i<2; i++){
		cout<<"informe um numero: ";
		cin>>v1[i];
		cout<<"Informe outro numero: ";
		cin>>v2[i];
	}
	
	for(i=0;i<4;i++){
		if(i%2==0){
			v3[i]= v1[c];
			c++;
		}
		else{
			v3[i]=v2[x];
			x++;
		}
		cout<<" "<<v3[i];
	}
	
}
