#include <iostream>

using namespace std;

int main(){
	int v1[4], v2[2], v3[2], i, c=0, x=0;
	
	for(i=0; i<4; i++){
		cout<<"informe um numero: ";
		cin>>v1[i];
	}
	
	for(i=0;i<4;i++){
		if(v1[i]%2==0){
			v3[c]= v1[i];
			c++;
		}
		else{
			v2[x]=v1[i];
			x++;
		}
	}
	for(i=0; i<2;i++){
		cout<<"\n "<<v3[i]<<" "<<v2[i];
	}
}
