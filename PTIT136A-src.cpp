#include <iostream>
#include <string>
using namespace std;
typedef pair<string, long> record;
record hs[101];
string s;
long n, res, vt, t = 0;

int xh(string s)
{
	for (long i = 1; i <= t; i++)
	  if (s == hs[i].first) 
	  {
	  	vt = i;
	  	return 1;
	  }
	return 0;
}

main()
{
	cin >> n;
	res = 0;
	for (long i = 1; i <=n; i++)
	{
		cin >> s;
		if (xh(s))
		{
			if (hs[vt].second > (i - 1 - hs[vt].second)) res++;
			hs[vt].second++; 
		}
		else 
		{
			t++;
			hs[t].first = s;
			hs[t].second = 1;
		}
	}
	cout << res;
}