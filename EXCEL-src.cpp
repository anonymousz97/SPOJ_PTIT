#include <iostream>
#include <string>
using namespace std;

string xau(long m)
{
	string s = "";
	long du, thuong;
	while (m != 0)
	{
		du = m % 26;
		thuong = m / 26;
		if (du != 0)
		{
			s = char (du + 64) + s;
			m = thuong;
		}
		else
		{
			s = "Z" + s;
			m = thuong - 1;
		}
	}
	return s;
}

main()
{
	string s;
	while (1)
	{
		cin >> s;
		long r = s.find('R', 0), c = s.find('C', 0);
		long n = 0;
		for (long i = r + 1; i < c; i++)
		{
			long x = long (s[i]) - 48;
			n = n * 10 + x;
		}
		if (n == 0) break;
		long m = 0;
		for (long i = c + 1; i < s.length(); i++)
		{
			long x = long (s[i]) - 48;
			m = m * 10 + x;
		}
		cout << xau(m) << n << endl;
	}
}