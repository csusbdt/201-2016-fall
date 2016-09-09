#include <iostream>
using namespace std;


/* Returns true if n is a prime integer.
 * A prime integer is only evenly divisible by 
 * 1 and itself.
 */
bool is_prime(int n)
{
	int i;

	/* We stop after n/2 since any integer greater 
	 * than half of n is not a factor of n.
	 */
	for (i = 2; i <= n / 2; ++i) {
		/* n modulo i is zero if i is a factor of n */
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

/* Calculates the next prime integer after n */
int next_prime(int n)
{
	/* Keep incrementing n until it is a prime integer */
	do {
		++n;
	} while (not is_prime(n));
	return n;
}

int main()
{
	int n;

	cout << "Enter an integer: ";
	cin >> n;
	cout << "The next prime integer after " << n <<
	" is " << next_prime(n) << endl;
	return 0;
}
