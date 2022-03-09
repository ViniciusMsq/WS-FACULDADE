#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	
	int n1, n2, n3;
	float res;
	
	cout<<"Digite a nota 1: ";
	cin>>n1;
	printf("Digite a nota 2: ");
	scanf("%u",&n2);
	cout<<"Ditgite a nota 3: ";
	cin>>n3;
	
	res = (n1+n2+n3)/3;
	
	cout<<"MEDIA: ";
	
	if(res>=8 && res<=10){
		cout<<"A";
	}
	else if(res>=7 && res<8){
		cout<<"B";
	}
	else if(res>=6 && res<7){
		cout<<"C";
	}
	else if(res>=5 && res<6){
		cout<<"D";
	}
	else if(res>=0 && res<5){
		cout<<"R";
	}
	else{
		cout<<"'se e o bixao memo em'";
	}
	
	
	
	
	
	
	
	return 0;
}
