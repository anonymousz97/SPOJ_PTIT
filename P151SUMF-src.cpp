#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
string s;
int l, t, d[200010];
main()
{
	cin >> s;
	l = s.length();
	s = "*" + s;
	for (int i = 0; i <= l + 1; i++) d[i] = 0;
	cin >> t;
	int x;
	while (t--)
	{
		cin >> x;
		d[x]++;
		d[l - x + 2]--;
	}
	for (int i = 1; i <= l; i++) d[i] += d[i - 1];
	for (int i = 1; i <= l / 2; i++)
	  if (d[i] % 2 == 1) swap(s[i], s[l - i + 1]);
	s.erase(0, 1);
	cout << s;
}