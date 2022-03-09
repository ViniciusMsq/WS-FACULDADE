// FatorialFibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Fatorial(int n) {
    if (n > 1) {
        return n * Fatorial(n - 1);
    }
    else {
        return 1;
    }
}
int Febonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return Febonacci(n - 1) + Febonacci(n - 2);
    }
}

int main()
{
    int n;
    cout<< "numero: ";
    cin >> n;
    cout<<"\n\nresultado: "<< Fatorial(n);

    cout << "\n\nEscolha o indice de febonacci: ";
    cin >> n;
    cout << "\n\nResultado: " << Febonacci(n);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
