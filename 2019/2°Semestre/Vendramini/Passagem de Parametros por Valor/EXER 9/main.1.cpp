#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void dados(char a[],char b[],int c[])
{	
	char x='s';
	int i=0;
	
	while (x=='s')
	{
	
	cout<<"Digite o seu nome: ";
	cin>>a[i];
	cout<<"\n";
	
	cout<<"Você é do sexo é F ou M : ";
	cin>>b[i];
	cout<<"\n";
	
	cout<<"Digite a sua nota: ";
	cin>>*c[i];
	cout<<"\n";
	
	i++;
	
	cout<<"Deseja Cadastrar novo Aluno: S ou N";
	cin>>x;
	cout<<"\n\n";
}

}

void calculos (char x[], char y[], int z[])
	{
		int maior=0, pos=0, mediaM=0, i=0, mulh=0, cont=0;
		
		for (i=0; i<20; i++)
		{
			if (z[i] > maior)
			{
				maior = z[i];
				pos = i;
				
			}
		}		
			cout<<"A maior nota é: "<< maior<<"\n";
			
			if (y[pos]== 'm'|| y[pos] == 'M' )
			{
				cout<<"A maior nota é do sexo: Masculino" <<"\n";
			}
			else
			{
				cout<<"A maior nota é do sexo: Feminino" <<"\n";
			}
		
		// Calculando a Media das Mulheres	
		
		for (i=0; i<20; i++)
		{
			if( y[i] == 'F' || y[i] =='f')
			{
				mulh = mulh+z[i];
				cont++;
				
				
			}
			
		}
			mediaM = mulh/cont;
			
			cout<<"Media das Mulheres é : "<<mediaM;
	}

int main(int argc, char** argv) 
{
	char nom[20], sex[20];
	int nota[20];
	
	dados(nom,sex,nota);
	cout<<nota[1];
	calculos(nom,sex,nota);
	return 0;
}
