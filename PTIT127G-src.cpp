#include <iostream>
#include <string>
using namespace std;
string s;
string a[1001];
long n, t;

long lonhon(string a, string b)
{
	long l1 = a.length(), l2 = b.length();
	if (l1 > l2) return 1;
	if (l1 < l2) return 0;
	if (a > b) return 1;
	return 0;
}
main()
{
	cin >> n;
	t = 0;
	for (long i = 1; i <= n; i++)
	{
		cin >> s;
		s+= "a";
		string ss = "";
		long l = s.length();
		for (long i = 0; i < l; i++)
			if (('0' <= s[i]) && (s[i] <= '9')) ss+= s[i];
			else
			{
				if (ss != "")
				{
					while (ss[0] == '0') ss.erase(0, 1);
					if (ss == "") ss = "0";
					t++;
					a[t] = ss;
					ss = "";
				}
			}
	}
	for (long i = t - 1; i >= 1; i--)
	  for (long j = 1; j <= i; j++)
	    if (lonhon(a[j], a[j + 1]))
	    {
	    	string tg = a[j];
	    	a[j] = a[j + 1];
	    	a[j + 1] = tg;
	    }
	for (long i = 1; i <= t; i++) cout << a[i] << endl;
}