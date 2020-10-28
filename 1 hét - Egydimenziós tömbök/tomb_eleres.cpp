//Deklaráljunk egy 10 elemű tömböt.
//Inicializáljuk úgy, hogy minden elem értéke legyen a saját indexének kétszerese. 
//Írassuk ki, milyen érték szerepel a 0., 5. és 9. indexen.

#include <iostream>

using namespace std;

int main()
{
	
	//deklaracio es inicializacio egyszerre
    //int tomb[10] = {0, 2, 4, 6, 8, }

    //deklaraljuk a tombot
    int tomb[10];

    //inicializaljuk a tombot
    for (int i = 0; i <= 9; i++) {
        tomb[i] = i * 2;
    }

    cout << tomb[0] << endl;
    cout << tomb[5] << endl;
    cout << tomb[9] << endl;

    return 0;
}
