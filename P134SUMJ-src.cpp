#include <iostream>
#include <string>
using namespace std;
string s, res;
long l, cap[102];

char pre(long x)
{
	long k = long (s[x]);
	string ss;
	long t = 1;
	if ((65 <= k) && (k <= 67)) ss = "ABC";
	if ((68 <= k) && (k <= 70)) ss = "DEF";
	if ((71 <= k) && (k <= 73)) ss = "GHI";
	if ((74 <= k) && (k <= 76)) ss = "JKL";
	if ((77 <= k) && (k <= 79)) ss = "MNO";
	if ((80 <= k) && (k <= 83)) 
	{
		ss = "PQRS";
		t = 0;
	}
	if ((84 <= k) && (k <= 86)) ss = "TUV";
	if ((87 <= k) && (k <= 90))
	{
		ss = "WXYZ";
		t = 0;
	}
	ss += ss;
	long c = 0;
	for (long i = 0; i < ss.length(); i++)
	 if (ss[i] == s[x])
	 {
	 	c++;
	 	if (c == 2)
	 	{
	 		c = i;
	 		break;
	 	}
	 }
	 long b;
	 if (t) b = x % 3; else b = x % 4; 
	 if (cap[x]) return (ss[c - b]);
	 return (char(long (ss[c - b] + 32)));
}

main()
{
	while ((cin >> s) && (s != "#"))
	{
		l = s.length();
		s = "@" + s;
		for (long i = 1; i <= l; i++)
		{
			long x = long (s[i]);
			if (x < 97)
			{
				cap[i] = 1;
			}
			else
			{
				cap[i] = 0;
				s[i] = char (long (s[i]) - 32);
			}
		}
		res = "";
		for (long i = 1; i <= l; i++) res += pre(i);
		cout << res << endl;
	}
}