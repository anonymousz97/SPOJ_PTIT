#include <iostream>
#include <string>
using namespace std;
string s[20], a, b;
long t;

void build()
{
	s[0] = "{}";
	s[1] = "{{}}";
	string f = s[0] + "," + s[1];
	for (long i = 2; i <= 15; i++)
	{
		s[i] = "{" + f + "}";
		f += ("," + s[i]);
	}
}

main()
{
	build();
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> a >> b;
		long vt1, vt2;
		for (long i = 0; i <= 15; i++)
		  {
		  	if (a == s[i]) vt1 = i;
		  	if (b == s[i]) vt2 = i;
		  }
		cout << s[vt1 + vt2] << endl;
	}
}