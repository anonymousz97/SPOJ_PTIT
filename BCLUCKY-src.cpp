#include <iostream>
#include <string>
using namespace std;

long thaoTac(string s[], long n, long m)
{
	long a[21];
	long lock[21], xh[21];
	for (long i = 1; i <= n; i++)
	{
		lock[i] = 0;
		xh[i] = 0;
	}
	long item, pos;
	for (long i = 1; i <= m; i++)
	{
		cin >> item >> pos;
		lock[pos] = 1;
		xh[item] = 1;
		a[pos] = item;
	}
	long t = 0, st[40];
	for (long i = 1; i <= n; i++)
	  if (!lock[i])
	  {
	  	t++;
	  	st[t] = i;
	  }
	long p = 0;
	for (long i = 1; i <= n; i++)
	  if (!xh[i])
	  {
	  	p++;
	  	a[st[p]] = i;
	  }
	for (long i = 1; i <= n; i++) cout << s[a[i]] << " ";
	cout << endl;
}
main()
{
	long t;
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		long n, m;
		string s[21];
		cin >> n >> m;
		for (long i = 1; i <= n; i++) cin >> s[i];
		thaoTac(s, n, m);
	}
}