#include <iostream>
#include <string>
using namespace std;
long s[1001][1001];
long n, m;
long a[1001], f[1001];

void up(long &x, long &y, long k)
{
	long d = 1;
	while (d <= k)
	{
		s[x][y] = 1;
		d++;
		x++;
		y++;
	}
}

void down(long &x, long &y, long k)
{
	long d = 1;
	while (d <= k)
	{
		s[x][y] = 2;
		x--;
		y++;
		d++;
	}
}
main()
{
	cin >> n;
	for (long i = 1; i <= n; i++) cin >> a[i];
	long k = -1;
	f[1] = a[1];
	for (long i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + k * (a[i] - 1);
		k = - k;
	}
	//for (long i = 1; i <= n; i++) cout << f[i] << " ";
	long x = 10000000, y;
	for (long i = 1; i <= n; i++)
	  if (f[i] < x) x = f[i];
	m = -1000000;
	for (long i = 1; i <= n; i++)
	  if (f[i] > m) m = f[i];
	if (x < 1) m += (1 - x);
	long sum = 0;
	for (long i = 1; i <= n; i++) sum += a[i];
	for (long i = 0; i <= m; i++)
	 for (long j = 0; j <= sum; j++) s[i][j] = 0;
	if (x < 1) x = 1 + (1 - x); else x = 1;
	//cout << x;
	y = 1;
	
	//cout << x << " " << y << "  " << m << " " << sum;
	
	for (long i = 1; i <= n; i++)
	{
	  if (i % 2 != 0) 
	  {
	  		up(x, y, a[i]);
	  		x--;
	  }
	  else 
	  {
	  		down(x, y, a[i]);
	  		x++;
	  }
	  //cout << x << " " << y << endl;
	}
	for (long i = m; i >= 1; i--)
	{
		for (long j = 1; j <= sum; j++)
		  if (s[i][j] == 1) cout << "/";
		  else if (s[i][j] == 2) cout << "\\";
		  else cout << " ";
		cout << endl;
	}
}