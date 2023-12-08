#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;


int wys_menu(){
	cout << "wybierz rozmiar planysz" << endl;
	cout << "1 - mały rozmiar [5 , 5] " << endl;
	cout << "2 - mały rozmiar [8 , 8] " << endl;
	cout << "3 - mały rozmiar [10 , 10] " << endl;
	cout << "4 - wyjscie z orogramu" << endl;
	int menu_wybor;
	cin >> menu_wybor;
	switch (menu_wybor) {
		case 1:{
			return 5;
		}
		case 2: {
			return 8;
		}
		case 3: {
			return 10;
		}
		case 4: {
			exit(0);
		}
	}
}

int gen_atom(int rozmiar_tab) {
	switch (rozmiar_tab) {
		case 5: {
			return 3;
			}
		case 8: {
			return 5;
		}
		case 10: {
			return 8;
		}
	}
}

bool** gen_tab(int rozmiar_tab) {		/*użytkownuk podaj wilekośc tabeli*/
	bool** tab = new bool* [rozmiar_tab];
	for (int i = 0; i < rozmiar_tab; i++) {
		tab[i] = new bool[rozmiar_tab];
		for (int j = 0; j < rozmiar_tab; j++) {
			tab[i][j] = false;
		}
	}
	return tab;
}

/*
int gen_tab1(const int tab3) {
	for (int i = 0; i < 6; i++) {
		tab3[i] = 1;
		for (int j = 0; j < 6; j++) {
			tab3[i][j] = 2;
		}
	}
}
*/

/*
int** gen_tab2(int roz_tab) {
	int k = 1;
	int n = 2;
	int** tab1 = new int* [roz_tab];
	for (int x = 0; x < roz_tab; x++) {
		tab1[x] = new int [k];
		for (int y = 0; y < roz_tab; y++) {
			tab1[x][y] = n;
		}
	}
	return tab1;
}

void print1(int **tab1, int rozmiar_tab) {
	for (int i = 0; i < rozmiar_tab; i++) {
		for (int j = 0; j < rozmiar_tab; j++) {
			cout << tab1[i][j];
		}
		cout << endl;

	}
}
*/
bool** losowanie(bool** tab, int rozmiar_tab ,int ilosc_atom) {
	srand(time(NULL));
	for (int i = 0; i < ilosc_atom; i++) {
		int a = rand() % rozmiar_tab;
		int b = rand() % rozmiar_tab;
		/*
		for (int i = 0; i < rozmiar_tab; i++) {
			if (tab[i][0]) {
				int a = false;
			}
		for (int i = 0; i < rozmiar_tab; i++) {
				if (tab[i][10]) {
					int a = false;
				}
		for (int j = 0; j < rozmiar_tab; j++) {
			if (tab[0][j]) {
				int b = false;
				}
			}
		}
		for (int j = 0; j < rozmiar_tab; j++) {
			if (tab[10][j]) {
				int b = false;
			}
		}
	}*/
		tab[a][b] = true;
	}
	return tab;
}

void print(bool** tab,int rozmiar_tab) {
	for (int i = 0; i < rozmiar_tab; i++) {
		for (int j = 0; j < rozmiar_tab; j++) {
			cout << tab[i][j];
		}
		cout << endl;

	}
}

void pentla_gry(bool** tab,int rozmiar_tab) {
	int x = 0;
	int y = 0;
	char key;
	print(tab, rozmiar_tab);
	while (true) {
		//print(tab, rozmiar_tab);
		cin >> key;
		key = toupper(key);
		while (key != 'w' and key != 's' and key != 'd' and key != 'a' and key != 'p' and key != 'k' and key != 'q') {
			cin >> key;
			key = toupper(key); //wszytkie opce do wilekich liter
		}
		switch (key) {
			case 'w': {
				y--;
				cout << tab[x][y] << endl;
				break;
			}
			case 's': {
				y++;
				cout << tab[x][y] << endl;
				break;
			}
			case 'd': {
				x++;
				cout << tab[x][y] << endl;
				break;
			}
			case 'a': {
				x--;
				cout << tab[x][y] << endl;
				break;
			}
			case 'k': {
				print(tab,rozmiar_tab);
				//cout << "uzystkane punkty " << int punkty << endl;
				exit(0);
				break;
			}
			case 'p': {
				print(tab, rozmiar_tab);
				return;
				break;
			}
			case 'q': {
				return;

			}
		
			}
		system("CLS");
	}
}

//void klawisze(int rozmiar_tab) {
	/*if (rozmiar_tab = 5) {
		cout << "w ,s , a , d - poruszanie sie po tablicy" << endl;
		cout << "q - wyjscie do menu" << endl;
		cout << "u - cofnij ruch" << endl;
		cout << "r - powtorz ruch" << endl;
		cout << "o - przypuszczalne ustawienie atomu" << endl;
		cout << "p - umożliwa wyswitlenie rozwiazania" << endl;
		cout << "h - pomoc" << endl;
	}
}*/

void laserLBok(int kol , bool** tab , int rozmiar_tab) {
		for (int i = 0; i < rozmiar_tab; i++) {
			for (int j = kol; j < rozmiar_tab; j++) {
				if (*tab[i] == true) {
					cout << "cel trafiony" << endl;
				}
				else {
					cout << "pudło" << endl;
				}
			}
		}
}

void laserRBok(int kol, bool** tab, int rozmiar_tab) {
	for (int i = 10; i > rozmiar_tab; i--) {
		for (int j = kol; j < rozmiar_tab; j++) {
			if (*tab[i] == true) {
				cout << "cel trafiony" << endl;
			}
			else {
				cout << "pudło" << endl;
			}
		}
	}
}

void laserGora(int kol, bool** tab, int rozmiar_tab) {
	for (int i = kol; i < rozmiar_tab; i++) {
		for (int j = 0; j < rozmiar_tab; j++) {
			if (*tab[i] == true) {
				cout << "cel trafiony" << endl;
			}
			else {
				cout << "pudło" << endl;
			}
		}
	}
}

void laserDol(int kol, bool** tab, int rozmiar_tab) {
	for (int i = kol; i < rozmiar_tab; i++) {
		for (int j = 10; j > rozmiar_tab; j--) {
			if (*tab[i] == true) {
				cout << "cel trafiony" << endl;
			}
			else {
				cout << "pudło" << endl;
			}
		}
	}
}

int main() {
	while (true) {
		//int tab3[6][6];
		int rozmiar_tab = wys_menu();
		int roz_tab = rozmiar_tab + 1;
		int ilosc_atom = gen_atom(roz_tab);
		bool** tab = gen_tab(rozmiar_tab);
		//int **tab1 = gen_tab2(roz_tab);
		//print1(tab1, roz_tab);
		losowanie(tab, rozmiar_tab, ilosc_atom);
		//klawisze(rozmiar_tab);
		cout << "ktora kolumne chcesz szukac " << endl;
		int kol;
		cin >> kol;
		pentla_gry(tab, rozmiar_tab);
		delete tab;
	}
}
