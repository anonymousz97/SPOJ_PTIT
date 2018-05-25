#include <iostream>
#include <string>
using namespace std;
long t, n;
string s[15];
string rs;
long res;

long kiemTra(string ss)
{
	for (long i = 1; i <= n; i++)
	  if (s[i].find(ss) == -1) return 0;
	return 1;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n;
		for (long i = 1; i <= n; i++) cin >> s[i];
		res = 0;
		for (long i = 0; i < 58; i++)
		  for (long j = i + 2; j < 60; j++)
		  {
		  	if (j - i + 1 < res) continue;
		  	string ss = s[1].substr(i, j - i + 1);
		  	if (kiemTra(ss))
		  	{
		  		if (j - i + 1 > res)
		  		{
		  			rs = ss;
		  			res = j - i + 1;
		  		}
		  		else
		  		if (j - i + 1 == res)
		  		{
		  			if (rs > ss) rs = ss;
		  		}
		  	}
		  }
		if (res > 2) cout << rs;
		else cout << "no significant commonalities";
		cout << endl;
	}
}