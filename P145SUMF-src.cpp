#include<iostream>
#include<string>
using namespace std;
long f[101][101], r, c, a, b;
string s1,s2;

void khoiTaoxau()
{
	s1 = ""; s2 = "";
	long k = 0;
	while (k < c*b)
	{
		for (long p = 1; p <= b; p++)
		{
			k++;
			s1 = s1 + "X";
			s2 = s2 + ".";
		}
		if (k == c*b) break;
		for (long p = 1; p <= b; p++)
		{
			k++;
			s1 = s1 + ".";
			s2 = s2 + "X";
		}
	}	
}

main()
{
	cin >> r >> c >> a >> b;
	khoiTaoxau();
	long k = 0;
	while (k < r*a)
	{
		for (long p = 1; p <= a; p++)
		{
			k++;
			cout << s1 << endl;
		}
		if (k == r*a) break;
		for (long p = 1; p <= a; p++)
		{
			k++;
			cout << s2 << endl;
		}
	}
}