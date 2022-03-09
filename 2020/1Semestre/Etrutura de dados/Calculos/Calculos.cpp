// Calculos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale.h>
using namespace std;

int Potencia(int n, int e) {
    if (e == 0) {
        return 1;
    }
    else {
        return n*Potencia(n, e-1);
    }
}
int SomaN(int n) {
    if (n > 0) {
        return n - 1 + SomaN(n - 1);
    }
    else {
        return 0;
    }
}
 int SomaP(int n) {
     n = n-1;
    if (n > 0) {
        return n*2 + (SomaP(n));
    }
    else {
        return 0;
    }
}
int main()
{
    setlocale(LC_ALL, "");
    int n, e;
    cout << "néç: ";
    cin >> n;
    cout << "\ne ";
    cin >> e;
    cout << "\n\nres: " << Potencia(n, e);
    cout << "\n\nInforme os n nat: ";
    cin >> n;
    cout << "\nres " << SomaN(n);
    cout << "\n\nInforme os n par: ";
    cin >> n;
    cout << "\nres " << SomaP(n);

    cout<<"\n\n";
    system("PAUSE");
    return 0;
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
