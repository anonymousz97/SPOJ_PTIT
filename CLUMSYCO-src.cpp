#include <iostream>
#include <string>
using namespace std;
string s;
long l, d, res;
main()
{
	cin >> s;
	l = s.length();
	d = 0;
	res = 0;
	for (long i = 0; i < l; i++)
	  if (s[i] == '(') d++;
	  else 
	  {
	  	if (d > 0) d--;
	  	else
	  	{
	  		d++;
	  		res++;
	  	}
	  }
	res += d / 2;
	cout << res;
}