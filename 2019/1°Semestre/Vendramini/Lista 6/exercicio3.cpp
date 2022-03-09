#include <iostream>

using namespace std; 
 
int main(){
	int i, j, ma[3][3], sl, sc;
	
	for(i=0;i<3;i++){
		
		for(j=0;j<3;j++){
			cout<<"Informe o valor da linha "<<(i+1)<<" e coluna "<<(j+1)<<": ";
			cin>>ma[i][j];
		}
	}
	for(i=0;i<3;i++){
		sl=0;
		for(j=0;j<3;j++){
			cout<<"  "<<ma[i][j];
			sl+=ma[i][j];
			
		}
		cout<<" | "<<sl;
		cout<<"\n";
	}
	cout<<"-----------";
	cout<<"\n";
	
	for(j=0;j<3;j++){
		sc=0;
		for(i=0;i<3;i++){
			sc+=ma[i][j];
		}
		cout<<" "<<sc;
	}	
 	
}
