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

bool** losowanie(bool** tab, int rozmiar_tab ,int ilosc_atom) {
	srand(time(NULL));
	for (int i = 0; i < ilosc_atom; i++) {
		int a = rand() % rozmiar_tab;
		int b = rand() % rozmiar_tab;
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
	while (true) {
		print(tab, rozmiar_tab);
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
			}
			case 'p': {
				print(tab, rozmiar_tab);
				return;
			}
			case 'q': {
				return;
			}
		
			}
		system("CLS");
	}

}

int main() {
	while (true) {
		int rozmiar_tab = wys_menu();
		int ilosc_atom = gen_atom(rozmiar_tab);
		bool** tab = gen_tab(rozmiar_tab);
		losowanie(tab, rozmiar_tab, ilosc_atom);
		pentla_gry(tab, rozmiar_tab);
		delete tab;
	}
}







































/*int main() {
	ifstream myfile("C:\\Users\\kacpe\\Desktop\\a.txt");
	if (myfile) {
		string a;
		myfile >> a;
		cout << a << endl;
		myfile.close();
		
	}
	ofstream plik("C:\\Users\\kacpe\\Desktop\\a.txt");
	if (plik) {
		int n;
		cin >> n;
		plik << n << "\n";
		plik.close();
	}

	return 0;
}
*/