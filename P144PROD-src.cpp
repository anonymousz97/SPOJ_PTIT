#include <iostream>
#include <string>
using namespace std;
string s[51];
long n;

long bangNhau()
{
	string x = s[1];
	for (long i = 1; i <= n; i++)
	  if (s[i] != x) return 0;
	return 1 ;
}

long lonhon(string a, string b)
{
	long m = a.length(), n = b.length();
	if (m > n) return 1;
	if (m < n) return 0;
	for (long i = 0; i < m; i++)
	  if (a[i] < b[i]) return 0;
	return 1;
}
main()
{
	long d = 0;
	cin >> n;
	while (n > 0)
	{
		d++;
		for (long i = 1; i <= n; i++)
		{
			cin >> s[i];
			while (s[i][0] == '0') s[i].erase(0, 1);
			if (s[i] == "") s[i] = "0";
		}
		string smax = s[1], smin = s[1];
		for (long i = 2; i <= n; i++)
		{
			if (lonhon(s[i], smax)) smax = s[i];
			if (lonhon(smin, s[i])) smin = s[i];
		}
		if (not bangNhau()) cout << "Case " << d << ": "<< smin << " " << smax;
		else cout << "Case " << d << ": "<< "There is a row of trees having equal height.";
		cout << endl;
		cin >> n;
	}
}