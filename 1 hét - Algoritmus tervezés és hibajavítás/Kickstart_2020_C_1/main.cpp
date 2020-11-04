#include <iostream>

using namespace std;

// Ötlet
// Jó lenne, ha mindig tudnánk, melyik számnak kellene
// következnie ahhoz, hogy folytatni tudjunk a már megkezdett
// k-leszámolást (countdownt)/hogy egy újat tudjunk kezdeni.
// Jelöljük ezt a számot keresettSzam-mal.
//
// 1. eset: Ha soron következő eleme a sorozatnak megegyezik a
// keresettSzammal, akkor folytatjuk a már megkezdett
// k-leszámolást.
// 1.a. eset: Ha ez a leszámolás befejeződik ezzel az új elemmel,
// akkor legközelebb a k értéket keressük,
// hogy egy új k-leszámolást kezdhessünk.
// 1.b. eset: Ha nem fejeződött még be az a leszámolás,
// amit elkezdtünk, akkor a következő lépésben az
// eggyel kisebb számot, azaz (keresettSzám-1)-et várjuk.
//
// 2. eset: Ha a soron következő eleme a sorozatnak nem egyezik meg
// keresettSzámmal, akkor nem tudjuk folytatni a leszámolást.
// 2.a. eset: Ha a jelenlegi elem egyenlő k-val, akkor ez az elem
// el is kezdhet egy újabb leszámolást, a keresettSzám pedig k-1 lesz.
// 2.b. eset: Ha a jelenlegi elem sem k-val, sem a keresettSzammal
// nem egyenlő, akkor nem tudunk új leszámolást kezdeni, várnunk kell
// addig, amíg megjelenik a k szám valahol. Így a keresettSzám legyen k.
//

int main()
{
    int tesztDb, elemDb, k, elem;
    cin >> tesztDb;
    int keresettSzam, countdownDb;
    for (int t = 1; t <= tesztDb; t++){
        cin >> elemDb >> k;
        keresettSzam = k;
        countdownDb = 0;
        for(int i = 1; i <= elemDb; i++){
            cin >> elem;
            if (elem == keresettSzam){
                keresettSzam--;
                if (keresettSzam == 0) {
                    countdownDb++;
                    keresettSzam=k;
                }
            }
            else if (elem == k){
                keresettSzam = k-1;
            }
            else keresettSzam = k;
        }
        cout << "Case #" << t << ": " << countdownDb << endl;
    }
    return 0;
}
