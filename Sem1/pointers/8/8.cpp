#include <iostream>
#include <string>
using namespace std;
int main() {
	string s, a, b;
	cin >> s >> a >> b;
	int mini = 0;
	int big = 0;
	int ot = 0;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		string sim = s.substr(i, 1);
		if (sim == a) {
			big++;
		}
		else if (sim == b) {
			mini++;
		}
		else {
			ot++;
		}
	}
	cout << big << endl << mini << endl << ot << endl << s.length();

}