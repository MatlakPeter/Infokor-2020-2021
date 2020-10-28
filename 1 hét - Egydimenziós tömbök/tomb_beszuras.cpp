//Szurjunk be egy 10-es a 2 poziciora.

#include <iostream>

using namespace std;

int main()
{
    int tomb[5] = {2, 4, 13, 6};
    int hossz = 4;

	//noveljuk a tomb hosszat
    hossz++;
	
	//atpakoljuk az elemeket
    for (int i = hossz - 1; i > 2; i--) {
        tomb[i] = tomb[i - 1];
    }

	//a kert poziciora beszurjuk az erteket
    tomb[2] = 10;

	//kiiratjuk a tombot
    for (int i = 0; i < hossz; i++) {
        cout << tomb[i] << " ";
    }

    return 0;
}
