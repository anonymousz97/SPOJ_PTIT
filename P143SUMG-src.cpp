#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#define fi first
#define se second
using namespace std;
long t, n;
string q[3], s;
typedef pair <long, string> record;
record a[11];
long x['z' + 1], y['z' + 1];

void buildQT()
{
	q[0] = "qwertyuiop";
	q[1] = "asdfghjkl*";
	q[2] = "zxcvbnm***";
	for (long i = 0; i < 3; i++)
	  for (long j = 0; j < 10; j++)
	    if (q[i][j] != '*')
	    {
	    	char t = q[i][j];
	    	x[t] = i;
	    	y[t] = j;
	    }
}

long Count(string a, string b)
{
	long n = a.length();
	long res = 0;
	for (long i = 0; i < n; i++) res += fabs(x[a[i]] - x[b[i]]) + fabs(y[a[i]] - y[b[i]]);
	return res;
}

main()
{
	buildQT();
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s >> n;
		for (long i = 1; i <= n; i++)
		{
			cin >> a[i].se;
			a[i].fi = Count(a[i].se, s);
		}
		sort(a + 1, a + 1 + n);
		for (long i = 1; i <= n; i++) cout << a[i].se << " " << a[i].fi << endl;
	}
}