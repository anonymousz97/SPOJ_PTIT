#include <iostream>
#include <string>
using namespace std;
long t, n, m, k;
string ti[31], teo[31];
long x[5001], y[5001];
long res;
long teoTruot;

long play(string s[], long x, long y, long &turn, long &tank, long num)
{
	if (tank == 0)
	{
		turn *= -1;
		if (num == 1) teoTruot = 1;
		return 0;
	}
	if (s[y][x] == '#')
	{
		s[y][x] = '_';
		tank--;
		if (tank == 0)
		{
			turn *= -1;
			if (num == 1) teoTruot = 1;
		}	
	}
	else
	{
		turn *= -1;
		if (num == 1) teoTruot = 1;
	}
}

long dem(string s[])
{
	long d = 0;
	for (long i = m - 1; i >= 0; i--)
	  for (long j = 0; j < n; j++)
	    if (s[i][j] == '#') d++;
	return d;
}

void xuli()
{
	res = -2;
	long d1 = dem(ti), d2 = dem(teo);
	long turn = 1;
	for (long i = 1; i <= k; i++)
	{
		if (turn == 1) play(teo, x[i], y[i], turn, d2, 2);
		else 
		{
			teoTruot = 0;
			play(ti, x[i], y[i], turn, d1, 1);
			if (teoTruot)
			{
			
				if ((d1 == 0) && (d2 != 0))
				{
					res = 1;
					break;
				}
				else if ((d1 != 0) && (d2 == 0))
				{
					res = -1;
					break;
				}
			}
		}
		if ((d1 == d2) && (d2 == 0))
		{
			res = 0;
			break;
		}
	}
	if (res = -2)
	{
		if (d1 * d2 != 0) res = 0; 
		if ((d1 == d2) && (d2 == 0)) res = 0;
		if ((d1 == 0) && (d2 > 0)) res = 1;
		if ((d1 > 0) && (d2 == 0)) res = -1;
	}
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n >> m >> k;
		for (long i = m - 1; i >= 0; i--) cin >> ti[i];
		for (long i = m - 1; i >= 0; i--) cin >> teo[i];
		for (long i = 1; i <= k; i++) cin >> x[i] >> y[i];
		xuli();
		if (res == -1) cout << "player one wins";
		if (res == 0) cout << "draw";
		if (res == 1) cout << "player two wins";
		cout << endl;
	}
}