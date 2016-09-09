#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	vector<int> tickets;

	while (cin.good()) {
		cout << "Enter raffle ticket number to play " <<
		"(Press CTRL-D to begin raffle): ";
		cin >> n;
		tickets.push_back(n);
	}
	srand(time(0));
	cout << "The winner is ticket number: " <<
	tickets[rand() % tickets.size()] << endl;
	return 0;
}
