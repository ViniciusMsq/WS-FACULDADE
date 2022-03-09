#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int cod;
	float prod, result, pjuros;
	
	printf("Qual o valor do produto: ");
	cin>>prod;
	cout<<"1   a vista em dinheiro ou cheque ganha 10% de desconto";
	cout<<"\n2   a vista no cartão de credito ganha 5% de desconto";
	cout<<"\n3   em duas vezes, preco normal sem juros";
	cout<<"\n4   em tres vezes, preco normal mais juros de 10%";
	
	cout<<"\nEscolha uma das formas de pagamento: ";
	cin>>cod;
	
	if ( cod == 1 ) {
		
		result = prod - (prod * 0.10);

		cout<<"\nO VALOR SERA: "<<result<<" REAIS";
	}  
	else if ( cod == 2 ) {
		
		result = prod - (prod * 0.05);
		
		cout<<"\nO VALOR SERA: "<<result<<" REAIS";
	} 
	else if ( cod == 3 ) {
		
		result = prod / 2;
		
		cout<<"\nO VALOR SERA 2 VEZES DE "<<result<<" REAIS = "<<result*2<<" REAIS";
	}  
	else if ( cod == 4 ) {
		
		pjuros = prod + (prod * 0.10);
		
		result = pjuros / 3;

		cout<<"\nO VALOR SERA 3 VEZES DE "<<result<<" REAIS = "<<result*3<<" REAIS";
	}                 
	else{
		
		cout<<"Codigo Invalido";
	}              
	
	return 0;
}










