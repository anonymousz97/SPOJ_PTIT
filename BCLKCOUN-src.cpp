#include <iostream>
#include <string>
using namespace std;
string s;
long t, l;
main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> s;
		long nho = 0;
		l = s.length();
		if (l == 1)
		{
			cout << s << endl;
			continue;
		}
		for (long i = l - 1; i >= 0; i--)
		{
			long x = int (s[i]) - 48 + nho;
			s[i] = '0';
			if (x >= 5) nho = 1; else nho = 0;
			if (i == 0) 
			 {
			 	if (x < 10) s[i] = char (x + 48);
			 	else s = "1" + s;
			 }
		}
		cout << s << endl;
	}
}