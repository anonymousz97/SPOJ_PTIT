#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
long test, t, n, st[2000];
string s;

long tinh(char c)
{
	return min(c - 'A','Z' - c + 1);
}

long ketQua(string s)
{
	n = s.length();
	s = "s" + s;
	long res = 0;
	for (long i = 1; i <= n; i++) res += tinh(s[i]);
	t = 0;
	for (long i = 1; i <= n; i++)
	  if (s[i] != 'A')
	  {
	  	t++;
	  	st[t] = i;
	  }
	if (t == 0) return 0;
	if (t == 1) return res + min(st[t] - 1, n - st[t] + 1);
	long d = min(st[t] - 1, n - st[1] + 1);
	for (long i = 1; i <= t - 1; i++) d = min(d, 2 * (st[i] - 1) + n - st[i + 1] + 1);
	for (long i = 2; i <= t; i++) d = min(d, 2 * (n - st[i] + 1) + st[i - 1] - 1);
	return res + d;
	
}
main()
{
	cin >> test;
	while (test--)
	{
		cin >> s;
		cout << ketQua(s) << endl;
	}
}
