#include <iostream>
#include <cstring>
using namespace std;
void numbertranslation(char S[50], long int desdrob, int linelen) {
	long long int chislit = 0;
	int entovoe;
	int nullcounter = 0;
	for (int i = 0; i < desdrob; i++) {
		if (S[i] == '0' && i != 0) {
			nullcounter += 1;
		}
		entovoe = S[i] - '0';
		chislit += entovoe * pow(10, linelen - 2 - i);
	}
	for (int i = desdrob + 1; i < linelen; i++) {
		if (S[i] == '0') {
			nullcounter += 1;
		}
		entovoe = S[i] - '0';
		chislit += entovoe * pow(10, linelen - i - 1);
	}
	if (nullcounter > 0) {
		chislit = chislit / pow(10, nullcounter);
	}
	cout << chislit;
	cout << '/';
	cout << '1';
	for (int i = 0; i < linelen - desdrob - 1 - nullcounter; i++) {
		cout << '0';
	}
}
void numbertranslation(char S[], int obdrob, int linelen) {
	long long int chislit = 0;
	long long int znamen = 0;
	int a;
	for (int i = 0; i < obdrob; i++) {
		a = S[i] - '0';
		chislit += a * pow(10, linelen - (linelen - obdrob) - 1 - i);
	}
	for (int i = obdrob + 1; i < linelen; i++) {
		a = S[i] - '0';
		znamen += a * pow(10, linelen - i - 1);
	}
	chislit = chislit * pow(10, linelen);
	double otvet = chislit / znamen;
	otvet = otvet / pow(10, linelen);
	cout << (otvet);
}
int main() {
	char S[50];
	long int desdrob;
	int obdrob;
	cin.getline(S, 50);
	int linelen = strlen(S);
	for (int i = 0; i < 50; i++) {
		if (S[i] == '/') {
			obdrob = i;
			numbertranslation(S, obdrob, linelen);
		}
		if (S[i] == '.' || S[i] == ',') {
			desdrob = i;
			numbertranslation(S, desdrob, linelen);
		}
	}
	return 0;
}
/*
1)
123.123
123123/1000
2)
0.125412
125412/1000000
3)
12421.1230
12421123/1000
4)
125/123
1.01626
5)
60/100
0.6
*/