#include <iostream>
#include <string>
using namespace std;
long n, t, res;
string s[101];

long lcs(string a, string b)
{
	long f[31][31];
	long m = a.length(), n = b.length();
	a = "#" + a; b = "#" + b;
	for (long i = 0; i <= m; i++)
	  for (long j = 0; j <= n; j++) f[i][j] = 0;
	for (long i = 1; i <= m; i++)
	  for (long j = 1; j <= n; j++)
	    if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
		else
			{
				f[i][j] = f[i - 1][j];
				if (f[i][j] < f[i][j - 1]) f[i][j] = f[i][j - 1];
			}	
	return f[m][n];
}
main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n; 
		res = 0;
		for (long i = 1; i <= n; i++) cin >> s[i];
		for (long i = 1; i <= n - 1; i++)
		  for (long j = i + 1; j <= n; j++)
		  {
		  	long d = lcs(s[i], s[j]);
		  	if (d > res) res = d;
		  }
		cout << res << endl;
	}
}