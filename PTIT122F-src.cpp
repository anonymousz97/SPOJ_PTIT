#include <iostream>
#include <string>
using namespace std;
string a, b;
long long lt[12];

long bang()
{
	string s1 = "", s2 = "";
	long i = a.length();
	while (a[i] != '?')
	{
		s1 = a[i] + s1;
		s2 = b[i] + s2;
		i--;
	}
	if (s1 <= s2) return 0;
	return 1;
}

long long res( string a, string b, long d)
{
	long long s = 0;
	long l = a.length();
	for (long i = 0; i < l; i++)
	  if (a[i] != '?')
	  {
	  	if (a[i] > b[i]) s += lt[d];
	  	if (a[i] != b[i]) break;
	  }
	  else
	  {
	  	d--;
	  	s += (9 - long (b[i]) + 48) * lt[d];
	  	if (d == 0)
	  	{
	  		if (bang()) s++;
	  		break;
	  	}
	  }
	return s;
}
main()
{
	lt[0] = 1;
	for (long i = 1; i <= 11; i++) lt[i] = lt[i - 1] * 10;
	while ((cin >> a) && (a != "#"))	
	{
		cin >> b;
		long d = 0;
		for (long i = 0; i < a.length(); i++)
		  if (a[i] == '?') d++;
		cout << res(a, b, d) << endl;
	}
}