#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	int* ptr = &n;
	cin >> *ptr;
	cout << n;
}