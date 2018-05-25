#include <iostream>
#include <string>
#include <algorithm>
#define fi first
#define se second
using namespace std;
long n;
typedef pair <char, long> record;
record c[100003];
string s, rs;
long cxa[100003], cxb[100003], vt[100003];

long cmp(record a, record b)
{
	if (a.fi < b.fi) return 1;
	if ((a.first == b.first) && (a.second > b.second)) return 1;
	return 0;
}

main()
{
	cin >> n;
	cin >> s;
	s = "*" + s;
	for (long i = 1; i <= n; i++)
	{
		c[i].fi = s[i];
		c[i].se = i;
	}
	sort(c + 1, c + 1 + n, cmp);
	for (long i = 1; i <= n; i++) vt[c[i].se] = i;
	for (long i = 1; i <= n; i++)
	{
		cxa[i] = 1;
		cxb[i] = 1;
	}
	string a, b;
	long l = 1, r = n;
	while (1)
	{
		while ((r > 0) && (!cxa[r])) r--;
		if (r == 0) break;
		a += s[r];
		cxb[vt[r]] = 0;
		r--;
		
		while ((l <= n) && (!cxb[l])) l++;
		if (l > n) break;
		b += c[l].fi;
		cxa[c[l].se] = 0;
		l++;
	}
	if (b < a) cout << "DA"; else cout << "NE";
	cout << endl;
	cout << b;
}
