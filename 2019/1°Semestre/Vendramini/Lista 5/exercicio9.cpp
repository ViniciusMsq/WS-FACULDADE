#include <iostream>

using namespace std;

int main(){
	int V1[9],V2[9],V3[9],VR[9],i, x=10;
	
	for(i=0;i<9;i++){
		x++;
		V1[i]=x;
		V2[i]=x+10;
		V3[i]=x+20;
		cout<<" "<<V1[i];
		
		cout<<" "<<V2[i];
		
		cout<<" "<<V3[i];
		cout<<"\n";
	}
	
	for(i=0;i<9;i++){
		if(i<=2){
			VR[i]=V1[i];
		}
		else if(i>2 && i<=5){
			VR[i]=V2[i];
		}
		else{
			VR[i]=V3[i];
		}
		
		cout<<" "<<VR[i];
	}
}
