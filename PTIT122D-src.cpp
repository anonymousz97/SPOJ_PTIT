#include <iostream>
#include <string>
using namespace std;
long t;
string s;
long d[123];

long xuli(string s)
{
	for (long i = 97; i <= 122; i++) d[i] = -1;
	long x = s.find("++", 0);
	while (x != -1)
	{
		s[x] = '*';
		s.erase(x + 1, 1);
		x = s.find("++", 0);
	}
	
	x = s.find("--", 0);
	while (x != -1)
	{
		s[x] = '/';
		s.erase(x + 1, 1);
		x = s.find("--", 0);
	}
	
	long dau = 1;
	long l = s.length();
	long res = 0;
	long delay = 0;
	
	for (long i = 0; i < l; i++)
	{
		if (('a' <= s[i]) && (s[i] <= 'z'))
		{
			d[long (s[i])] = 0;
			d[s[i]] += long (s[i]) - 96 + delay;
			res +=  dau * d[s[i]];
			dau = 1;	
			delay = 0;
		}
		else
		if (s[i] == '-') dau = -1;
		else
		if (s[i] == '*')
		{
			if ((i > 0) && (('a' <= s[i - 1]) && (s[i - 1] <= 'z')))
			{
				 d[long (s[i - 1])] ++;
				 delay = 0;
			}
			else delay = 1;
		}
		else 
		if (s[i] == '/')
		{
			if ((i > 0) && (('a' <= s[i - 1]) && (s[i - 1] <= 'z')))
			{
				d[long (s[i - 1])] --;
				delay = 0;
			}
			else delay = -1;
		}
	}
	if (delay != 0) d[long (s[l])] += delay; 
	return res;
}
main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> s;
		string s2 = s;
		long val = xuli(s);
		cout << "Expression: " << s2 << endl;
		cout << "value = " << val << endl;
		for (long i = 97; i <= 122; i++)
		if (d[i] != -1)
		  	cout << char(i) << " = " << d[i] << endl; 
	}
}