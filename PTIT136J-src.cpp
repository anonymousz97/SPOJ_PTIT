#include <iostream>
#include <string>
using namespace std;
string s[6];
long res;

long dem(long x, long is, long ie, long js, long je)
{
	long d = 0;
	char a = char (x + 64);
	for (long i = is; i <= ie; i++)
	  for (long j = js; j <= je; j++)
	    if (s[i][j] != a) d++;
	return d;	
}

long demDoc(long a, long b, long c)
{
	long d = dem(a, 0, 5, 0, 2) + dem(b, 0, 5, 3, 5) + dem(c, 0, 5, 6, 8);
	return d;	
}

long demNgang(long a, long b, long c)
{
	long d = dem(a, 0, 1, 0, 8) + dem(b, 2, 3, 0, 8) + dem(c, 4, 5, 0, 8);
	return d;
}

long dmin(long a, long b)
{
	if (a > b) return b;
	return a;
}

main()
{
	res = 54;
	for (long i = 0; i < 6; i++) cin >> s[i];
	for (long i = 1; i <= 26; i++)
	  for (long j = 1; j <= 26; j++)
	  {
	  	if (i == j) continue;
	  	for (long k = 1; k <= 26; k++)
	  	{
	  		if (j == k) continue;
	  		long d = dmin(demNgang(i, j, k), demDoc(i, j, k));
	  		if (d < res) res = d;
	  	}
	  }
	cout << res;
}