#include <iostream>

using namespace std;

int main()
{
    // magas - a jelenlegi pont magassaga
    // magas1 - az elozo pont magassaga
    // magas2 - a 2-vel korabbi pont magassaga
    int tesztDb, pontDb, magas2, magas1, magas, csucsDb;
    cin >> tesztDb;
    for (int t = 1; t <= tesztDb; t++) {
        cin >> pontDb;
        csucsDb = 0;
        cin >> magas2;
        cin >> magas1;
        int i = 1;
        for (; i <= pontDb; i++) {
            cin >> magas;
            if (magas1 >= magas2 && magas1 >= magas) {
                csucsDb++;
            }
        }
        cout << "Case #" << t << ": " << csucsDb << endl;
    }
    return 0;
}
