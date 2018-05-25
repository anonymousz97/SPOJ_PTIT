#include <iostream>
#include <string>
using namespace std;
int n;
main()
{
	cin >> n;
	for (int i = 1; i <= n/2; i++)
	{
		for (int j = 1; j <= n/2 - i + 1; j++) cout << "*";
		for (int j = 1; j <= 2 * i - 1; j++) cout << "D";
		for (int j = 1; j <= n/2 - i + 1; j++) cout << "*";
		cout << endl;
	}
	for (int i = 1; i <= n; i++) cout << "D";
	cout << endl;
	for (int i = n/2; i > 0; i--)
	{
		for (int j = 1; j <= n/2 - i + 1; j++) cout << "*";
		for (int j = 1; j <= 2 * i - 1; j++) cout << "D";
		for (int j = 1; j <= n/2 - i + 1; j++) cout << "*";
		cout << endl;
	}
}
