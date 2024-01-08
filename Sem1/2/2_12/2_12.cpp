#include <iostream>
using namespace std;
int main() {
	int n, a, max, min;
	cin >> n >> a;
	max = min = a;
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		if (a > max) {
			max = a;
		}
		if (a < min) {
			min = a;
		}
	}
	cout << max << " Max element" << endl;
	cout << min << " Min element" << endl;
	cout << max + min << " Sum elements" << endl;
}