//Keressuk meg a 10-es elem indexet es irassuk ki.

#include <iostream>

using namespace std;

int main()
{

    //int tomb[5] = {1, 2, 10, 24, 3};

    int tomb[5];

	//feltoltjuk a tombot ertekekkel
    tomb[0] = 1;
    tomb[1] = 2;
    tomb[2] = 10;
    tomb[3] = 24;
    tomb[4] = 3;

    int index;

    /*for (int i = 0; i < 5; i++) {
        if (tomb[i] == 10) {
            index = i;
        }
    }*/

    bool megvan = false;
    int i = 0;

    while (i <= 4 && !megvan) {
        if (tomb[i] == 10) {
            index = i;
            megvan = true;
        }
        i++;
    }


    cout << "10-es elem indexe/pozicioja: " << index << endl;

    return 0;
}
