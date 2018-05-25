#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
string s1, s2, s;
int d1, d2, t;
string res;
main()
{
	cin >> t;
	s1 = ""; d1 = 0;
	s2 = ""; d2 = 0;
	while (t--)
	{
		cin >> s;
		if (s1 == "") s1 = s;
		if (s != s1) s2 = s;
		if (s == s1) d1++;
		else d2++;
	}
	if (d1 > d2) res = s1; else res = s2;
	cout << res;
}