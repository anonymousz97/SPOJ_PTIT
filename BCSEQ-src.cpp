#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string s;
long n, a, b, res;
main()
{
	cin >> s;
	n = s.length();
	a = 0;
	b = 0;
	res = 0;
	for (long i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			a--;
			b--;
		}
		else
		if (s[i] == 'R')
		{
			a++;
			b++;
		}
		else
		{
			a++;
			b--;
		}
		if (fabs(a) > res) res = fabs(a);
		if (fabs(b) > res) res = fabs(b);
	}
	cout << res;
}