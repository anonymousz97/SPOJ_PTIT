#include <iostream>
#include <string>
using namespace std;
string s, rs, s1, s2;
long  d, n, res;
main()
{
	cin >> n;
	while (n != 0)
	{
		cin >> s1;
		cin >> s2;
		cin >> rs;
		d = 0;
		s = "cai deo gi cung duoc";
		res = -1;
		while ((d <= 50) && ( s != rs))
		{
			d++;
			s = "";
			for (long i = 0; i < n; i++)
			{
				s += s2[i];
				s += s1[i];
			}
			s1 = s.substr(0, n);
			s2 = s.substr(n, n);
		}
		if (d <= 50) res = d;
		cout << res << endl;
		cin >> n;
	}
}