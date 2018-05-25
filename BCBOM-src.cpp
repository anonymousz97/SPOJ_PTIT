#include <iostream>
#include <string>
using namespace std;
string s[102];
long m, n, d;
long x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
long y[8] = {0, -1, -1, -1, 0, 1, 1, 1};
main()
{
	cin >> m >> n;
	while (m != 0)
	{
	
	for (long i = 1; i <= m; i++)
	{
		cin >> s[i];
		s[i] = "." + s[i] + ".";
	}
	s[0] = "";
	s[m + 1] = "";
	for (long j = 0; j <= n + 1; j++)
	{
		s[0] += ".";
		s[m + 1] += ".";
	}
	for (long i = 1; i <= m; i++)
	  for (long j = 1; j <= n; j++)
	    if (s[i][j] == '.')
	    {
	    	d = 0;
	    	for (long k = 0; k < 8; k++)
	    	{
	    		long u = i + x[k], v = j + y[k];
	    		if (s[u][v] == '*' ) d++;
	    		s[i][j] = char (d + 48);
	    	}
	    }
	for (long i = 1; i <= m; i++)
	{
		for (long j = 1; j <= n; j++) cout << s[i][j];
		cout << endl;
	}
	cin >> m >> n;
	}
}