#include <iostream>
using namespace std;
long n, t[100];
long f[100][1300][1300];
long s;

long initF()
{
	for (long i = 0; i <= n; i++)
	  for (long j = 0; j <= s; j++)
	    for (long k = 0; k <= s; k++) f[i][j][k] = 0;
	for (long i = 1; i <= n; i++)
	{
		f[i][t[i]][0] = 1;
		f[i][0][t[i]] = 1;
		f[i][0][0] = 1;
	}
}

long xuli()
{
	long d = 0;
	for (long i = 1; i <= n; i++)
	{
		d += t[i];
		for (long j = 0; j <= s; j++)
		  for (long k = 0; k <= s; k++)
		  {
		  	if (f[i - 1][j][k]) f[i][j][k] = 1;
		  	else
		  	if ((j >= t[i]) && (f[i - 1][j - t[i]][k])) f[i][j][k] = 1;
		 	else
		  	if ((k >= t[i]) && (f[i - 1][j][k - t[i]])) f[i][j][k] = 1;
		  }
	}
}

long mx(long a, long b, long c)
{
	long res = a;
	if (res < b) res = b;
	if (res < c) res = c;
	return res;
}

long result()
{
	long res = s;
	for (long j = 0; j <= s; j++)
	  for (long k =  0; k <= s; k++)
	    if (f[n][j][k] == 1)
		{
			long d = mx(j, k, s - j - k);
			if (d < res) res = d;
		}	
	return res;
}

main()
{
	while ((cin >> n) && (n != 0))
	{
		s = 0;
		for (long i = 1; i <= n; i++)
		{
			cin >> t[i];
			s += t[i];
		}
		initF();
		xuli();
		cout << result() << endl;
	}
}