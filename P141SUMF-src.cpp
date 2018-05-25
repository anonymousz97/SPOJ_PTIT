#include <iostream>
#include <string>
using namespace std;
string s[100];
long m, n, t;

void xuli(long x, long y)
{
	long stop = 0;
	while (not stop)
	{
		if (s[x + 1][y] == 'X')
		{
			stop = 1;
			s[x][y] = 'O';
			continue;
		}
		if (s[x + 1][y] == '.') x++;
		if (s[x + 1][y] == 'O')
		{
			if ((s[x][y - 1] == '.') && (s[x + 1][y - 1] == '.')) y--;
			else  if ((s[x][y + 1] == '.') && (s[x + 1][y + 1] == '.')) y++;
			else
			{
				s[x][y] = 'O';
				stop = 1;
				continue;
			}
		}
	}
}
main()
{
	cin >> m >> n;
	for (long i = 1; i <= m; i++)
	{
		cin >> s[i];
		s[i] = "O" + s[i] + "O";
	} 
	s[m + 1] = "";
	for (long j = 0; j <= n + 1; j++) s[m + 1] += "X";
	//______________________________________________________
	
	cin >> t;
	long y;
	for (long q = 1; q <= t; q++)
	{
		cin >> y;
		xuli(1, y);
	}
	for (long i = 1; i <= m; i++)
	{
		for (long j = 1; j <= n; j++) cout << s[i][j];
		cout << endl;
	}
}