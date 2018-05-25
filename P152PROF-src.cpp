#include <iostream>
#include <algorithm>
using namespace std;
int m, s, rmin[105], rmax[105];

int Process()
{
	// tim Max	
	int x = s, n = 0;
	while (x > 9)
	{
		n++;
		rmax[n] = 9;
		x -= 9;
		if (n > m) return 0;
	}
	if ((n == m) && (x != 0)) return 0;
	if (m - n == 1)
	{
		n++;
		rmax[n] = x;
	}	
	else
	{
		n++;
		rmax[n] = x;
		while (n < m)
		{
			n++;
			rmax[n] = 0;
		}
	}
	
	// tim Min
	x = s; n = 0;
	while (x > 9)
	{
		n++;
		rmin[n] = 9;
		x -= 9;
		if (n > m) return 0;
	}
	if ((n == m) && (x != 0)) return 0;
	if (m - n == 1)
	{
		n++;
		rmin[n] = x;
		if (!x) swap(rmin[n], rmin[n - 1]); 
	}
	else
	{
		if (x == 0)
		{
			for (int i = n; i < m; i++) rmin[i] = 0;
			rmin[m] = 9;
		}
		else
		{
			rmin[n + 1] = x - 1;
			for (int i = n + 2; i < m; i++) rmin[i] = 0;
			rmin[m] = 1;
		}
	}
	return 1;
	
}

int main()
{
	cin >> m >> s;
	if ((m != 1) && (s == 0))
	{
		cout << "-1 -1";
		return 0;
	}
	if (!Process()) cout << "-1 -1";
	else
	{
		for (int i = m; i > 0; i--) cout << rmin[i];
		cout << " ";
		for (int i = 1; i <= m; i++) cout << rmax[i];
	}
}
