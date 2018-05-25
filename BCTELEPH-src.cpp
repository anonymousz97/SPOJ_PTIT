#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long t, n;
string s[10001];

long kiemTra(string a, string b)
{
	long m = a.length();
	long n = b.length();
	if (m > n) return 0;
	for (long i = 0; i < m; i++)
	  if (a[i] != b[i]) return 0;
	return 1;	
}

long nhatQuan(string s[])
{
	for (long i = 2; i <= n; i++)
	  if (kiemTra(s[i - 1], s[i])) return 0;
	return 1;	
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n;
		for (long i = 1; i <= n; i++) cin >> s[i];
		sort(s + 1, s + 1 + n);
		if (nhatQuan(s)) cout << "YES"; else cout << "NO";
		cout << endl;
	}
}