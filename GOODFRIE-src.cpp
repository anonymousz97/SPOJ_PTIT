#include <iostream>
#include <string>
using namespace std;
const long long nmax = 300001;
long long n, k, a[nmax], d[nmax][21];
string s;
main()
{
	cin >> n >> k;
	for (long i = 1; i <= n; i++)
	{
		cin >> s;
		a[i] = s.length();
	}
	for (long i = 1; i <= n; i++) d[i][0] = 0;
	for (long j = 1; j <= 20; j++) d[0][j] = 0;
	for (long j = 1; j <= 20; j++)
	  for (long i = 1; i <= n; i++)
		if (a[i] == j) d[i][j] = d[i - 1][j] + 1;
		else d[i][j] = d[i - 1][j];
	/*for (long i = 0; i <= n; i++)
	{
		for (long j = 1; j <= 20; j++) cout << d[i][j] << " ";
		cout << endl;
	}*/
	long long res = 0;
	for (long i = 1; i <= n; i++)
	{
		long long p = 0;
		if (i - k - 1 > p) p = i - k - 1;
		long long sl = d[i][a[i]] - d[p][a[i]];
		res += sl - 1;
	}
	cout << res;
}