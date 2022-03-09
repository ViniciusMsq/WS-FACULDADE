#include <iostream>
using namespace std;
int ler_numero(int vet2[])
{
	int i;
	for (i=0;i<3;i++)
	{
		cout<<"\n Digite o "<<i<<"° valor: ";
		cin>>vet2[i];
	}
}
int maior_menor(int vet2[],int * maior, int * menor)
{
	int i;
   for(i=0;i<3;i++)
   {
      if (vet2[i]>*maior)
      {
   	    *maior=vet2[i];
      }
      if (vet2[i]<*menor)
      {
   	   *menor=vet2[i];
      }
   }
}
int main ()
{
	setlocale (LC_ALL, "Portuguese");
	int funcao,ma=0,me=1000;
	int vet[3],i;
	ler_numero (vet);
	maior_menor (vet,&ma,&me);
	cout<<"\n O maior número é: "<<ma;
	cout<<"\n O menor número é: "<<me;
}
