#include <iostream>
using namespace std;
int main(){
	int VetorA[5], VetorB[5], VetorR[5],i, x=0;
	
	for(i=0;i<5; i++){
		VetorA[i]=x+1;
		VetorB[i]=x;
		x+=2;
		cout<<"\nA: "<<VetorA[i]<<" B: "<<VetorB[i];
	}
	cout<<"\n\n";
	for(i=0;i<5;i++){
		if(i%2==0){
			VetorR[i]=VetorA[i];
		}
		else{
			VetorR[i]=VetorB[i];
		}
		
		cout<<"\nR: "<<VetorR[i];
	}
}
