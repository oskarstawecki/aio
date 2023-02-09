#include <iostream>
#include <cmath>
#include <math.h>
#include <time.h>

#define Blok4


using namespace std;

#ifdef Blok1

int main() {
	int count,evcount=0,min=5,max=0,sum=0;
	double z,x;

	setlocale(LC_ALL, "");
	do {
		cout << "Podaj liczbę :";
		cin >> count;
		if (count < 0) {
			cout << "Błąd ! Nieprawidłowa liczba !";
		}
		sum += count;
		evcount++;
		if (count > max) {
			max = count;
		}
		if(count < min) {
			min = count;
		}
	
	} while (sum <= 10 || sum % 3 != 0);

	z = (double(evcount) * pow(double(min), 3.14)) + pow(double(max), (1 / 4));
	cout.precision(4);

	cout << "X: " << min << endl;
	cout << "Y: " << max << endl;
	cout << "Suma :" << sum << endl;
	cout << "Z= " << z << endl;


}

#endif

#ifdef Blok2

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));
	const int ROZMIAR = 10, ROZMIARRAND = 6;
	double oceny[ROZMIAR] = {};
	double tabrand[ROZMIARRAND] = { 2.0,3.0,3.5,4.0,4.5,5.0 };
	//wypełnianie
	for (int i = 0; i < 10; i++) {
		int j = rand() % 6;
		oceny[i] = tabrand[j];
	}
	//wyświetlanie
	cout << "Oceny = { ";
	for (int i = 0; i < 10; i++) {
		cout << " " << double(oceny[i]);
		if (i < 9) {
			cout << ",";
		}
	}
	cout << "}" << endl;
	//widok wypełnienie
	double* widok[ROZMIAR] = {};
	for (int i = 0; i < ROZMIAR; i++) {
		widok[i] = &oceny[i];
	}
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < ROZMIAR; j++) {
			if (*widok[i] < *widok[j]) {
				swap(widok[i], widok[j]);
			}
		}
	}
	//widok wyświetlenie
	cout << "Widok = { ";
	for (int i = 0; i <ROZMIAR; i++) {
		cout << " " << *widok[i];
		if (i < 9) {
			cout << " |";
		}
	}
	cout << " }" << endl;
}
#endif

#ifdef Blok3

/*
   Rolą funkcji jest odwrócić kolejność cyfr w podanej licznie naturalnej, która nie jest wielokrotnością
   liczby 10.
*/
int reverseInt(int x)
{

	int reversedInt = 0;
	int temp = x;
	bool firstLoop = true;

	/* Zadany argument będziemy przetwarzać tak długo,
	   aż wyciągniemy z niego wszystkie cyfry */

	while (x != 0) // usunięto niepotrzebny ) oraz ; (blokował on funkcję)
	{
	/* Pobierz cyfrę jedności z zadanej liczby */
	int pop = x % 10;

	/* Zakładamy, że nie powinno się odwracać liczb z zerem na koncu,
	   bo następuje utrata informacji */

	if (firstLoop == true and pop == 0)
		return 0;
		firstLoop = false; // dodano ;, aby dalszy kod się wykonywał
	
		/* Skracamy "x" o jedną cyfrę i zapisujemy wynik w "x" */
		x = x / 10; // dodano x=, aby przypisać dane do x
	
	/* To co zostało obliczone do tej pory przesuwamy na jedno miejsce w prawo
	   następnie dodajemy ostatnio zapamiętaną liczbę */
	reversedInt = (reversedInt * 10) + pop; // poprawiono literówkę
	}
	if (reversedInt < 0) {
		cout << "Błąd ! Liczba jest ujemna." << endl;
	}
	else if (temp % 10 == 0) {
		cout << "Błąd ! Liczba kończy się 0" << endl;
	}
	else {
		cout << "OK ! Liczba jest zgodna z kryteriami." << endl;
	}
	return reversedInt;


}

/* 3) Funkjca powinna zwracać dodatkową informację o liczbie znalezionych cyfr wejsciowej oraz zgłaszać
	  do kontekstu zewnętrznego poprawność jej wykonania. Funkcja powinna zgłaszać błąd jesli
	  wejściowa liczba jest ujemna, lub gdy 0 pojawia się jako ostatnia jej cyfra, np:
	  1234506 -> OK, ale już 123450 -> Błąd!
	  Dostosuj kod w main do zmian. */

int main() {
	setlocale(LC_ALL, ""); 
	
	cout << "Odwrotnoscia 4 jest " << reverseInt(4) << endl; // zmieniono znak z >> na <<
	cout << "Odwrotnoscia 123 jest " << reverseInt(123) << endl;
	cout << "Odwrotnoscia 208478933 jest " << reverseInt(208478933) << endl;
	cout << "Odwrotnoscia -73634 jest " << reverseInt(-73634) << endl;

	return 0;
}

#endif

#ifdef Blok4
/*
		double funkcjaMatematyczna(double x)
		{
			return 2 * sin(x) + cos(x);
		}

		 Uwaga oszacowanie całki może wyjść ujemne, gdyż pole funkjci pod osią OX jest odejmowane od pola ponad nią 
		
		double całkowanie(double xp, double xk, int n)
		{
			 Sprawdź warunki: xk > xp i n > 2. Jesli choć jeden nie jest spełniony przerwij funkcję wynikiem 0 
			int h, count = 0, oszacowanie, a, b, p;


			if (xk < xp && n < 2) {
				return 0;
			}
			else {
				 Wyznacz wysokość h trapezow jako odcinek |xp, xk| podzielony przez n 
				 Ustaw wartość oszacowania całki oznaczonej na 0 
				double(h) = (xk - xp) / n;
				oszacowanie = 0;
				 Powtarzaj n razy: 
					 Wyznacz podstawy trapezów dla i-tej itreacji jako wartości całkowanej funkcji w punktach:
					a = xp+i*h i b = xp+(i+1)*h, gdzie i to numer iteracji. 
					 Wylicz pole trapezu jako 0.5*h*(a+b) i dodaj je do oszacowania całki 
			do {
			for (int i = 0; i <= n; i++) {
				a = xp + (i * h);
				b = xp + ((double(i) + 1) * h);
				p = 0.5 * h * (double(a) + double(b));
				oszacowanie += p;
			}
			} while (count >= n);
			}
			 Zwroc oszacowanie całki jako wynik funkjci 
			return oszacowanie;
		}

		int main()
		{
			cout << "Oszacowanie : " << całkowanie(3, 4, 9) << endl;
			cout << "Oszacowanie : " << całkowanie(4, 2, 3) << endl;
			cout << "Oszacowanie : " << całkowanie(-2, 6, 2) << endl;
			cout << "Oszacowanie : " << całkowanie(7, 8, 4) << endl;
			cout << "Oszacowanie : " << całkowanie(11, 1, 8) << endl;
		}
*/		

struct DaneWejsciowe
{
	double xp, xk, n, eps;
};

struct DaneWyjsciowe
{
	double wynikCalki;
};

void pobieranieDanychCalki(DaneWejsciowe& dane)
{
	cout << "Podaj xp , xk , n dla ktorego bedzie dzielona podstawa calki miedzy xp i xk i podaj eps :" << endl;
	cin >> dane.xp;
	cin >> dane.xk;
	cin >> dane.n;
	cin >> dane.eps;
}

void wyswietlanieDanejCalki(DaneWyjsciowe dane)
{
	cout << "Podana calka wynosi:" << dane.wynikCalki << endl;
}

/* Całkowana funkcja: */
double funkcjaMatematyczna(double x)
{
	return 2 * sin(x) + cos(x);
}
/* Uwaga oszacowanie całki może wyjść ujemne, gdyż pole funkjci pod osią OX jest odejmowane od pola ponad nią */

DaneWyjsciowe całkowanie(DaneWejsciowe dane)
{
	DaneWyjsciowe wynik = { 0.0 };
	/* Sprawdź warunki: xk > xp i n > 2. Jesli choć jeden nie jest spełniony przerwij funkcję wynikiem 0 */
	if (dane.xk < dane.xp && dane.n < 2)
	{
		return wynik;
	}
	double wysokoscH = (dane.xp - dane.xk) / (double)dane.n;
	double wartoscOszacowaniaCalkiOznaczonej = 0.0;
	/* Wyznacz wysokość h trapezow jako odcinek |xp, xk| podzielony przez n */
	/* Ustaw wartość oszacowania całki oznaczonej na 0 */
	double tempWartosciOszacowanejCalkiNieoznaczonej = 0.0;
	int i = 0;
	do
	{
		double a = funkcjaMatematyczna(dane.xp + i * wysokoscH), b = funkcjaMatematyczna(dane.xp + (i + 1.0) * wysokoscH); i++;
		double poleTrapezu = 0.5 * wysokoscH * (a + b);
		tempWartosciOszacowanejCalkiNieoznaczonej = wartoscOszacowaniaCalkiOznaczonej;
		wartoscOszacowaniaCalkiOznaczonej += poleTrapezu;
	} while (tempWartosciOszacowanejCalkiNieoznaczonej - wartoscOszacowaniaCalkiOznaczonej > dane.eps);
	wynik.wynikCalki = wartoscOszacowaniaCalkiOznaczonej;
	/* Powtarzaj n razy: */
			/* Wyznacz podstawy trapezów dla i-tej itreacji jako wartości całkowanej funkcji w punktach:
			   a = xp+i*h i b = xp+(i+1)*h, gdzie i to numer iteracji. */
			   /* Wylicz pole trapezu jako 0.5*h*(a+b) i dodaj je do oszacowania całki */

	   /* Zwroc oszacowanie całki jako wynik funkjci */
	return wynik;
}

int main()
{
	DaneWejsciowe  daneWejsciowe;
	pobieranieDanychCalki(daneWejsciowe);
	DaneWyjsciowe daneWyjsciowe = całkowanie(daneWejsciowe);
	wyswietlanieDanejCalki(daneWyjsciowe);
	return 0;
}

#endif


