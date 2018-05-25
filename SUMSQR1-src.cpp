#include <iostream>
#include <string>
using namespace std;
string n, res;

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
	long l2 = b.length(), l1 = a.length();
	for (long i = l2 - 1; i >= 0;  i--)
	{
		long nho = 0;
		long p = int (b[i]) - 48;
		string ss = "";
		for (long j = l1 - 1; j >= 0; j--)
		{
			long x = int (a[j]) - 48;
			x = x * p + nho;
			nho = x / 10;
			x = x % 10;
			ss = char (x + 48) + ss;
		}
		if (nho != 0) ss = char (nho + 48) + ss;
		for (long j = 1; j <= k; j++) ss += "0";
		k++;
		s = cong(s, ss);
	}
	return s;
} 


main()
{
	cin >> n;
	res = nhan (cong(nhan(n, "2"), "1"), n);
	res = nhan (res, cong(n, "1"));
	long l = res.length();
	long du = 0;
	string kq = "";
	for (long i = 0; i < l; i++)
	{
		du = du * 10 + int (res[i]) - 48;
		kq += char ( du / 6 + 48);
		du = du % 6;
	}	
	if ((kq != "0") && (kq[0] == '0')) kq.erase(0, 1);
	cout << kq; 
}
