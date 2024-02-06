#include "Wybor.h"
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;


/*
* Uwaga: Zadania kod rozwiazania zaania umieszczać pomiędzy #ifdef a #endif.
*/

#ifdef Kol_1

int main()
{
	srand(time(0));
	int x1, x2, y1, y2;
	cout << "Podaj punkty (x1,y1,x2,y2) : " << endl;
	cin >> x1; cin >> y1; cin >> x2; cin >> y2;
	double d = 0;
	double x = pow((x2 - x1), 2);
	double y = pow((y2 - y1), 2);
	d = sqrt(x + y);
	char* ptr, * ptrend;
	cout << "d = " << setprecision(2) << d << endl;

	char T[3][2] = {}, rnd[6] = { '*', '&', '$', '#', '@', '!' }, znak;

	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 2; j++) {
			znak = rnd[rand() % 6];
			T[i][j] = znak;
		}
	}

	cout << "Tablica : " << endl;
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 2; j++) {
			cout << T[i][j] << " | ";
		}
		cout << endl;
	}

	cout << " Parzyste wiersze : " << endl;
	for (size_t i = 0; i < 3; i++) {
		if ((i + 1) % 2 == 0) {
			ptr = &T[i][0];
			ptrend = &T[i][2 - 1];

			cout << "w." << i + 1 << "\t";

			while (ptr != ptrend + 1) {
				cout << *ptr << "\t";
				ptr++;
			}
			cout << endl;
		}
	}
}

#endif
