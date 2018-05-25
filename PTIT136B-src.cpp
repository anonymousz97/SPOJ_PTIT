#include <iostream>
#include <string>
using namespace std;

string s[100], x;
long r, c, a, b;
main()
{
	cin >> r >> c;
	for (long i = 0; i < r; i++)
	{
		cin >> x;
		s[i] = x;
		for (long j = c - 1; j >= 0; j--) s[i] += x[j];
	}
	long k = r;
	for (long i = r; i < 2 * r; i++)
	{
		k--;
		s[i] = s[k];
	}
	cin >> a >> b;
	a--; b--;
	if (s[a][b] == '.') s[a][b] = '#';
	else s[a][b] = '.';
	for (long i = 0; i < 2 * r - 1; i++) cout << s[i] << endl;
	cout << s[2 * r - 1];
}