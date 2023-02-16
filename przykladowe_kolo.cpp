#include <iostream>

#define ZadanieKol2         // zmiana zadan ;3


#ifdef ZadanieKol1

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA KOL_PRZYKLAD 1 
#include <iostream>

using namespace std;

/* Funkcja dla zadania z bloku 3 - kolowkium przykładowe:
 * Jej zadaniem jest wyznaczyć rozstęp, czyli różnicę między najwiekszym i najmniejsyzm
 * elementem zbioru liczb rzeczywistych - wynik pownien być zawsze nieujmeny.
 * Funkcja powinna przyjmować tablicę liczb rzeczywistych i zwrcać wartość rozstępu - liczba rzeczywista)
 */

double rozstep(double* dane, const int ROZMIAR, double& mini, double& maxi, int& blad)  // zmina double'a na int'a
{
    /* Deklaracja zmiennych pomocniczych (inicjalizujemy je pierwszymi wartosciami ze zbioru): */

    double najmniejsza = dane[0], najwieksza = dane[ROZMIAR];  // zmina na double, prz najmniejszej zmina na dane[0]

    /* W pętli szukamy jednoczesnie najwiekszej i najmniejszej liczby: */
    for (int i = 0; i < ROZMIAR; i++)  // zmina double'a na int'a  oraz zmina <= na <
    {
        if (najwieksza < dane[i]) najwieksza = dane[i];  // blad w if zamiast zmiennej najwieksza byla najmniejsza
        if (najmniejsza > dane[i]) najmniejsza = dane[i];
    }

    mini = najmniejsza;
    maxi = najwieksza;

    if (dane == nullptr || ROZMIAR < 0)
    {
        blad = 1;
    }

    /* Zwracamy rożnicę między najwiekszą a najmniejszą wartością: */
    return najmniejsza - najwieksza;
}

/* Polecnie 3: rozbuduj interfejs funkcji tak, aby w funkjci main mozna było odebrać, nie
 * tylko rozstęp, ale także wartości: najmniejszej i największej. Funkcja także powinna
 * zwracać programowo (przez referencję) informację o błędzie, jesli przekazany adres tablicy
 * bedzie == nullptr lub ROZMIAR tablicy będzie ujemny.
 */


 /* Użyj poprawionej funkcji w main zgodnie z jej przeznaczeniem. Samodzielnie przygotuj
  * dane do pokazania jej działania. Program powienien tak wyświetalć dane, aby dało się
  * łatwo sprawdzic poprawność działania funkcji.
  */

int main()
{
    const size_t ROZMIAR = 5;
    double dane[] = { 5.6,7.2,9.9,1.2,13.3 };

    double mini = 0;
    double maxi = 0;

    int blad = 0;

    double wynik = rozstep(dane, ROZMIAR, mini, maxi, blad);

    if (blad == 1)
    {
        cout << "Blad!!! Adres tablicy jest == nullptr lub ROZMIAR tablicy jest ujemny" << endl;
    }
    else
    {

        cout << "Rozstep wynosi: " << wynik << endl;
        cout << "Wartosc najmniejsza wynosi: " << mini << endl;
        cout << "Wartosc najwieksza wynosi: " << maxi << endl;
    }
}


#endif

#ifdef ZadanieKol2

// TU UMIEŚĆ KOD ROZWIAZANIA ZADANIA KOL_PRZYKLAD 2
#include <iostream>
#include <cmath>

/* Funkcje dla zadania z bloku 4 - kolowkium przykładowe:
*  Jej zadaniem jest wyznaczyć położenie miejsca zerowego funkcji w zadanym zakresie.
*  Algorytm działa w założeniu, że we wskazanym zakresie funkcja ma tylko jedno
*  miejsce zerowe. Na granicach zakresu funkjca powinna przyjmować wartości
*  o przeciwnych znakach. Kolejne kroki podane są w ciele funkcji.
*/

struct Dane
{
    double xp;
    double xk;
    double a;
    double b;
    int n;
    double eps;
    int x;
};

struct Wyniki
{
    double xs;
    double fxs;
    double roznica;
    bool potwierdzenie;
};

void wpiszDane(Dane& p, double xp, double xk, double a, double b, int n, double eps, int x)
{
    p.xp = xp;
    p.xk = xk;
    p.a = a;
    p.b = b;
    p.n = n;
    p.eps = eps;
    p.x = x;
}

void wpiszDaneW(Wyniki& p, double xs, double fxs, double roznica, bool potwierdzenie)
{
    p.xs = xs;
    p.fxs = fxs;
    p.roznica = roznica;
    p.potwierdzenie = potwierdzenie;
}

double funkcja(Dane* dane, double x)
/* a i b to parametry funkcji liniowej, x to jej argument */
{
    return dane->a * x + dane->b;
}
//double miejsceZerowe(double xp, double xk, double a, double b, int n, bool& powodzenie, int x, double eps, double& fxs, double& roznica)
double miejsceZerowe(Dane* dane, Wyniki* wyniki)
{
    /*UWAGA:  f(x) uzyskujemy przez wywołanie: funkcja(a,b,x) */
    /* 0. sprawdź czy xk > xp i f(xk) ma różny znak od f(xp) jesli
     * którykolwiek z tych warunków nie jest spełniony - zakończ funkcję
     * z sygnalizacją błędu (arg. powdzenie równy false).
     */

     /* Powtarzaj n razy: */
        /* Wyznacz środek przedziału <xp, xk> jako xs.*/
        /* Sparwdź czy f(xp) i f(xs) mają różne znaki: */
           /* jeśli TAK to zastąp xk przez xs.*/
           /* jeśli NIE to zastąp xp przez xs.*/
     /* zwróć ostatnie xs (funkcja musi sygnalizować powodzenie równe true) */

    double fx = funkcja(dane, dane->x);
    double fxk = funkcja(dane, dane->xk);
    double fxp = funkcja(dane, dane->xp);

    double xs_prev;

    //cout << fxk << endl << fxp << endl;
    //cout << dane->xk << endl << dane->xp << endl;

    if ((dane->xk > dane->xp) && (fxk * fxp < 0))
    {
        xs_prev = dane->xk;
        for (int i = 0; i < dane->n; i++)
        {
            wyniki->xs = (dane->xp + dane->xk) / 2;
            wyniki->fxs = funkcja(dane, wyniki->xs);
            wyniki->roznica;
            wyniki->roznica = fabs(wyniki->xs - xs_prev);
            if (wyniki->roznica < dane->eps)
            {
                break;
            }
            xs_prev = wyniki->xs;
            if (fxp * wyniki->fxs < 0)
            {
                dane->xk = wyniki->xs;
            }
            else
            {
                dane->xp = wyniki->xs;
            }
        }
        wyniki->fxs = funkcja(dane, wyniki->xs);
        return wyniki->xs;
        wyniki->potwierdzenie = true;
    }
    else
    {
        wyniki->potwierdzenie = false;
        return 0;
    }
}

/* Polecenie 2: Zmodyfikuj kod programu tak, aby agorytm kończył się jeśli różnica pomiędzy
 * dwoma kolejnymi oszacowaniami wyniku (xs) jest mniejsza od zadenego eps.
 * Zmodyfikuj tak interfejs funkcji, aby można było zadać eps, oraz zwrócić wartość f(xs) i różnicę
 * w oszacowaniach (wartość sparwdzaną w nowym kryterium zbieżności).
 */

 /* Polecenie 3: Zmodyfikuj tak interfejs funkcji, aby wszytskie dane wejściowe przekazywać
    za pomocą struktury, oraz wszystkie wyniki odbierać w postaci struktury. Napisz funkcje
    do wypełniania struktury wejściwem treścią i do wyświetlania struktury wyjściowej na ekranie.
  */

using namespace std;

int main()
{
    /* main dla zadania z bloku 4*/
    bool czyOK = true;
    //double a = 2.0, b = 1.0, poczatek = -5.0, koniec = 5.0;
    // int liczbaIteracji = 10;
    //double eps = 0.01;

    //double fxs;
    //double roznica;

    Dane dane;
    Wyniki wyniki;

    wpiszDane(dane, -5.0, 5.0, 2.0, 1.0, 10, 0.01, 1);

    double wynik = miejsceZerowe(&dane, &wyniki);
    if (czyOK)
    {
        cout << "Miejsce zerowe funkjci y = " << dane.a << " x + " << dane.b << " w : " << wynik
            << endl;
        cout << "Wartosc f(xs): " << wyniki.fxs << endl;
        cout << "Roznica w oszacowaniach : " << wyniki.roznica << endl;
    }
    else
    {
        cout << "Bledne dane!\n";
    }
}



#endif

