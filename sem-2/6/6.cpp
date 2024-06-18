#include <iostream>
#include <cstring>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	char S[255];
	cin.getline(S, 255);
	int dlinstr = strlen(S);
	int nachslovo = 0;
	S[dlinstr] = ' ';
	for (int i = 0; i < dlinstr + 1; i++) {
		if (S[i] == ' ') {
			for (int k = nachslovo; k < i - 1; k++) {
				for (int j = k + 1; j < i; j++) {
					if (S[j] < S[k]) {
						char temp = S[j];
						S[j] = S[k];
						S[k] = temp;
					}
				}
			}
			nachslovo = i + 1;
		}
		if (S[i] == ' ' && S[i + 1] == ' ') {
			nachslovo = i + 1;
		}
	}
	for (int i = 0; i < dlinstr; i++) {
		cout << S[i];
	}
	return 0;
}