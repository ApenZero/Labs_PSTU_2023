#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float a, b;
	float sum = 0;
	float* ptr1;
	float* ptr2;
	cin >> a >> b;
	ptr1 = &a;
	ptr2 = &b;
	sum = *ptr1 + *ptr2;
	cout << sum;
}