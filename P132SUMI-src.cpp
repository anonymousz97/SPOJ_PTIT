#include <iostream>
#include <string>
using namespace std;
string s, rs, ss;
main()
{
	cin >> s;
	rs = s;
	long l = s.length();
	for (long i = 0; i < l - 2; i++)
	  for (long j = i + 1; j < l - 1; j++)
	    {
	    	ss = "";
	    	for (long k = i; k >= 0; k --) ss += s[k];
	    	for (long k = j; k > i; k--) ss += s[k];
	    	for (long k = l - 1; k > j; k--) ss += s[k];
	    	if (ss < rs) rs = ss;
	    }
	cout << rs;
}