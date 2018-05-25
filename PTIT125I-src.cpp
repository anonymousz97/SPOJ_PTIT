#include <iostream>
#include <string>
using namespace std;
const int nmax = 500005;
int n, k, p, d[nmax], st[nmax], t, l;
int vt;
string s;

void Process()
{
	for (int i = 1; i <= l; i++)
	{
		int x = s[i] - '0';
		while (x > st[t] && k > 0)
		{
			if (k < d[t])
			{
				d[t] -= k;
				k = 0;
			}
			else
			if (k == d[t])
			{
				k = 0;
				t--;
			}
			else k -= d[t--];
		}
		if (!k)
		{
			vt = i;
			break;
		}
		else
		if (x == st[t]) d[t]++;
		else
		{
			st[++t] = x;
			d[t] = 1;
		}
	}
}

void Output()
{
	if (!k)
	{
		for (int i = 1; i <= t; i++)
		  for (int j = 1; j <= d[i]; j++) cout << st[i];
		for (int i = vt; i <= l; i++) cout << s[i];
		return;
	}
	while (k > 0)
	{
		if (d[t] > k)
		{
		  d[t] -= k;
		  k = 0;
		}
		else
		if (d[t] == k)
		{
			t--;
			k = 0;
		}
		else k -= d[t--];
	}
	for (int i = 1; i <= t; i++)
		  for (int j = 1; j <= d[i]; j++) cout << st[i];
}

main()
{
	cin >> n >> k >> s;
	l = s.length();
	s = "*" + s;
	t = 0;
	st[0] = 10;
	Process();
	Output();
}