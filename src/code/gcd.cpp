#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int n;

	if (a < b) {
		n = a;
	} else {
		n = b;
	}
	while (n > 1) {
		if (a % n == 0 and b % n == 0) {
			return n;
		}
		--n;
	}
	return 1;
}

int main()
{
	int n, m;

	cout << "Enter an integer: ";
	cin >> n;
	cout << "Enter another integer: ";
	cin >> m;
	cout << "The greatest common divisor is: " <<
	gcd(n, m) << endl;
}
