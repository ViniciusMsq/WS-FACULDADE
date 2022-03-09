#include <iostream>
using namespace std;
int ler_numero (int vet2[], int *z)
{
	int a,i;
	system ("cls");
	do
	{
		cout<<"\n Digite o "<<i<<"° valor: ";
		cin>>vet2[i];
		i++;
		cout<<"\n Digite 1 para continuar ou 0 para parar: ";
		cin>>a;
		*z=i;
	}while (a!=0);
}
int maximo_minimo (int vet2[],int *ma,int *mi,int z)
{
	int i;
	for (i=0;i<z;i++)
	{
      if (vet2[i]>*ma)
      {
   	    *ma=vet2[i];
      }
      if (vet2[i]<*mi)
      {
   	   *mi=vet2[i];
      }
  }
   
}
int main ()
{
	setlocale (LC_ALL, "Portuguese");
	int maximo=0,minimo=1000,cont;
	int vet[1000];
	ler_numero (vet,&cont);
	maximo_minimo(vet,&maximo,&minimo,cont);
	cout<<"\n O valor maximo é: "<<maximo;
	cout<<"\n O valor mínimo é: "<<minimo;
}

