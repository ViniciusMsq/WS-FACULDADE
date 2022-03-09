#include <iostream>

using namespace std;


	void P(int x, int y, int*z)
	{
		*z= x + y + *z;
		cout<< x <<" "<< y <<" "<< *z <<"\n";
	}
	
	int main()
	{
		int a, b, c;
		a=5; b=8; c=3;
		
		P(a, b, &c); // x recebe (a=5)  Y recebe (b=8)  Z aponta para (c=3)  que a soma da função P de x=5 + y=8 + z=3 torna  (z=16) z aponta para c portanto o valor de c foi modificado e passa a valer 16 como z
		P(7, a + b + c, &a); //  x recebe (7) Y recebe a=5+b=8+c=16=(29) z aponta para (a=5) que a soma da função P de x=7 + y=29 + z=5 torna(z=41) z aponta para a portanto o valor de a foi modificado e passa a valer 41 como z
		P(a * b, a / b, &c);// x recebe a=41 * b=8 =(328) y recebe a=41/b=8 = (5) z recebe (16) que a soma da função P de x=328 + y=5 + z=16 torna (z=349) z aponta para c portanto o valor de c foi modificado e passa a valer 349 como z
	
		return 0;

	}
	
	
