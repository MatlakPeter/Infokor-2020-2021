//Toroljuk a 2. indexen levo erteket.

#include <iostream>

using namespace std;

int main()
{
    int tomb[5] = {2, 45, 3, 6};
	
	//eltaroljuk a tomb hosszat
    int hossz = 4;

	//atkoltoztetjuk az elemeket
    for (int i = 2; i < hossz; i++) {
        tomb[i] = tomb[i + 1];
    }

	//csokkentjuk a hosszat a tombnek
    hossz--;

	//kiirjuk a tombot
    for (int i = 0; i < hossz; i++) {
        cout << tomb[i] << " ";
    }

    return 0;
}
