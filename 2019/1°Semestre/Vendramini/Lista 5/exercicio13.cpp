#include <iostream>

using namespace std;
int main(){
	 int vo[4], vi[4],i, c=3, x;
	 
	 	for(i=0; i<4; i++){
	 	cout<<"Informe os valores: ";
	 	cin>>vo[i];
		}
		for(i=0;i<4;i++){
			vi[i]=vo[c];
			c--;
		}
		for(i=0;i<4;i++){
			if(vi[i]==vo[i]){
				x++;
			}
			else{
				cout<<"vetores nao são iguais";
				break;
			}
		}
		if(x==4){
			cout<<"vetores iguais";
		}	 
	}
