#include <iostream>
#include <algorithm>

using namespace std;

// link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56

int main()
{
    int tesztDb;
    cin >> tesztDb;
    int hazDb, osszeg, elkoltve = 0;
    int ar[100];
    for (int t = 1; t <= tesztDb; t++) {
        cin >> hazDb >> osszeg;
        for (int i = 1; i <= hazDb; i++) {
            cin >> ar[i];
        }
        sort(ar, ar+hazDb);
        int hazIndex = 1;
        while (hazIndex <= hazDb && elkoltve + ar[hazIndex] <= osszeg) {
            hazIndex++;
            elkoltve+=ar[hazIndex];
        }
        cout << "Case #" << t << ": " << hazIndex<< endl;
    }
    return 0;
}
