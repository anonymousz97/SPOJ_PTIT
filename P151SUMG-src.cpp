#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int t, m, n, l;
string a, b, s;
int d[100];

main()
{
	cin >> m >> n;
	cin >> a >> b;
	cin >> t;
	s = "";
	for (int i = m - 1; i >= 0; i--) s = s + a[i];
	s += b;
	l = m + n;
	s = "*" + s + "*";
	
	for (int i = 1; i <= l; i++)
	  if (i <= m) d[i] = 1;
		else d[i] = 2;
	
	while (t--)
	{
		int i = 1;
		while (i <= l)
		{
			if (d[i] == 1 && d[i + 1] == 2)
			{
				swap(s[i], s[i + 1]);
				swap(d[i], d[i + 1]);
				i += 2;
			}
			else i++;
		}
	}
	s.erase(0, 1);
	s.erase(l, 1);
	cout << s;
}