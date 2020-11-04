#include <iostream>

using namespace std;

#define MAX_NO_BUSSES 1000
// Ez a sor egy konstanst definial
// Amit "define"-nal deklaralunk, az egy macro, azaz
// tulajdonkeppen barhol megjelenik a kodban a neve
// (MAX_NO_BUSSES ebben az esetben), meg a forditas
// elott ki lesz cserelve a szovegben az ertekere (1000-re).
// Ez nem egy valtozo, nem lehet megvaltoztatni utolag az erteket,
// csak egy szoveges helyettesitoje az 1000-nek ebben az esetben.
// Azert hasznaljuk, hogy olvashatobb legyen a kod, es konnyebb
// legyen megvaltoztatni a konstanst, ha szukseges (pl. ha
// megvaltoznak a problema kovetelmenyei mert holnaptol 1500 busz
// kozlekedik, nem kell mindnehol kicsereljuk a szamot, csak ennek
// a macronak csereljuk ki az erteket, de a kodban ugyanugy
// hasznalhatjuk tovabbra is a nevet).

// Otlet
// Azt konnyen lathatjuk, hogy ha az i. busz X_i_ naponta jar, akkor
// az olyan napokon jar, amelyek szama oszthato X_i_-vel.
// Azt is lathatjuk, hogy ha tudjuk hogy az i. busszal az N_i_. napon
// fog utazni Bucket, akkor az i+1. busszal a legkorabbi olyan
// N_i+1_ szamu napon erdemes utaznia, amelyre N_i+1+ >= N_i_
// es N_i+1_ oszthato X_i+1_-gyel.
// Eszrevetel:
// Ha N_i_ oszthato X_i+1_-gyel, akkor mar meg is van a kovetkezo busz napja.
// Egyebkent pedig nem kell az osszes napot kiprobalnunk amig megtalaljuk
// a megfelelot, hiszen ha N_i_-nek az X_i+1_-gyel valo osztasi maradeka
// r < X_i+1_, akkor, N_i+1_ = N_i_ + (X_i+1_ - r).
//
// Tehat ha eldontjuk, melyik napon indul el Bucket az utjara
// a legelso busszal, akkor kesobb minden buszra meg tudjuk hatarozni,
// melyik a legkorabbi nap, amin utazhat vele, es igy meg tudjuk hatarozni,
// hogy Bucketnek sikerul-e befejeznie az utjat a hataridoig (maxNap).
// A kerdes tehat az, hogyan kell kivalasztani az 1. napot.
//
// Az elso tesztcsomagban a maxNap erteke maximum 100, igy gyakorlatilag
// kiprobalhatunk minden kezdonapot 1 es 100 kozott. Ez 100 kulonbozo
// probalkozast jelent. Mindegyikre ki kell szamolnunk, hogy melyik busszal
// hanyadik napon fog utazni a fenti eszrevetel alapjan, leellenorizzuk, hogy
// befejezi-e az utjat maxNapig es a legkesobbi (legnagyobb) napot valasztjuk,
// amire ez teljesul.
// A fenti logika alapjan belathatjuk, hogy ha egy N_i_ napon indulva megerkezik
// a hataridoig, akkor barmely korabbi napon indulva is megerkezik (pl. a kezdo
// buszt leszamitva utazhat minden busszal azon a napon, amelyiken akkor utazott
// volna, ha N_i_ napon indult volna). Tehat kereshetjuk a legkesobbi ilyen napot
// forditott sorrendben, 100-tol indulva 1 fele.
//
// A problema az, hogy a masodik tesztcsomagban a maxNap erteke maximum 10^12 = 10e12,
// ami olyan nagy szam, hogy nem fer be egy intbe. 10^12 eset kiprobalasa nem fer be
// az idobe, tul lassu az algoritmus, uj strategiara van szuksegunk.
// Egy megoldas lenne a binaris kereses, amihez nem kell semmi uj otlet
// a fentihez kepest,  de ugy tudom, meg nem tanultatok. Kesobb majd
// megbeszeljuk egyutt, de most nezzuk egy kevesbe "technikas" megoldast:
// Az indulas napjat nem tudjuk meghatarozni anelkul, hogy tudnank mikor utazik a
// kesobbi buszokkal, de forditva mukodik a dolog: a celt, hogy a leheto legkesobb
// induljon el Bucket az 1. busszal, biztosan nem lehetetleniti el az, ha minden
// busszal az utolsotol szamolva a leheto legkesobb utazik. Az utsolo busszal
// egy olyan, leheto legkesobbi N_buszDb_ napon kell utaznia, amelyik maxNap elott
// van(vagy aznap), es a szama oszthato X_buszDb_-bal.
// Mikor ezt meghataroztuk, haosnlo keppen megfogalmazhatjuk,
// hogy a buszDb-1. busszal a legkesobbi olyan napon erdemes utaznia, amelyik
// N_buszDb_ elott van(vagy vele egyenlo), es szama oszhato X_buszDb-1_gyel.
// Igy haladhatunk visszafele az 1. buszig (mintha egy matematikai indukciot
// vezetnenk le), amellyel egy olyan napon utazhat, ami
// a 2. busz napja elott van(van vele azonos) es oszthato X_1_-gyel.
// Ha a kesobbi buszokat meghataroztuk mar, akkor az i. busz napjat mar konnyu tehat
// meghatarozni ez alapjan. Gyakorlatilag minden i. busz-nap par meghatarozasa
// utan ujrafogalmazhatnank a feladatot ugy, hogy i-1 busszal kell utaznia
// Bucketnek ugy, hogy legkesobb N_i_ napra megerkezzen.
// Ezert a kodban nem tarolom, hogy melyik busszal melyik napon utazik,
// csupan csokkentem a maxNap-ot, a legkesobbi erkezes datumat, es ugy tekintem,
// hogy csak az elso i-1 buszt kell figyelembe vennem.
// A fenti keplethez hasonloan tovabba elmondhatjuk, hogy ha N_i+1_ oszthato X_i_-vel,
// akkor az i. busszal is utazhat N_i+1_ napon, egyebkent peddig annyival kell
// csokkentenunk a napot, hogy oszthato legyen X_i_vel, tehat le kell vonnunk
// X_i_-vel valo osztasi maradekat.
// A lenti kod ezt az otletet koveti. Lathatjuk, hogy nehany eszrevetel utan a kod
// a beolvasason kivul tulajdonkeppen csak 3 sor :)


int main()
{
    int tesztDb;
    cin >> tesztDb;
    int buszDb;
    long long x[MAX_NO_BUSSES+1];
    long long maxNap;

    for (int t = 1; t <= tesztDb; t++) {
        cin >> buszDb >> maxNap;
        for (int i = 1; i <= buszDb; i++) {
            cin >> x[i];
        }
        for (int i = buszDb; i >= 1; i--) {
           maxNap -= maxNap % x[i];
           //maxNap ezen a ponton az a nap, amelyen
           // az i. busszal utazik. A korabbi buszokkal
           // tehat legkesobb maxNapig meg kell erkeznie.
        }
        cout << "Case #" << t <<": " << maxNap << endl;
    }
    return 0;
}
