#include <iostream>
#include <string>
using namespace std;
long t, n;
long x;
string gt[366];

long dem(string s, long x)
{
	long d = 0, l = s.length();
	for (long i = 0; i < l; i++)
	  if (int (s[i]) - 48 == x) d++;
	return d;
}

string xau(long n)
{
	string s = "";
	while (n != 0)
	{
		long x = n % 10;
		n = n / 10;
		s = char (x + 48) + s;
	}
	return s;
}
string cong(string a, string b)
{
	string s = "";
	long l1 = a. length(),
		 l2 = b. length();
	for (long i = l1 + 1; i <= l2; i++) a = "0" + a;
	for (long i = l2 + 1; i <= l1; i++) b = "0" + b;
	long nho = 0;
	l2 = b.length();
	for (long i = l2 - 1; i >= 0; i--)
		{
			long x = int (a[i]) + int (b[i]) - 96 + nho;
			nho = x / 10;
			x = x % 10;
			s = char (x + 48) + s;
		}
	if (nho) s = "1" + s;
	return s;
}

string nhan(string a, string b)
{
	string s = "";
	long k = 0;
	long l2 = b.length();
	for (long i = l2 - 1; i >= 0; i--)
	{
		long x = int (b[i]) - 48;
		string ss = "" ;
		for (long j = 1; j <= x; j++) ss = cong(ss, a);
		for (long j = 1; j <= k; j++) ss += "0";
		k++;
		s = cong(s, ss);
	}
	return s;
}

void build()
{
	gt[1] = "1";
	for (long i = 2; i <= 365; i++) gt[i] = nhan(gt[i - 1], xau(i));
}
main()
{
	build();
	cin >> t;
	for (long q = 0; q < t; q++)
	{
		cin >> n >> x;
		cout << dem(gt[n], x) << endl;
	}
}