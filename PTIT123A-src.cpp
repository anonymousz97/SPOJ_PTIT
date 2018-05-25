#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
const ll nmax = 100005;
string a[nmax], s, res[nmax];
string mangSo[nmax], mangTu[nmax];
int n, p[nmax], ns, nt;

int kieuSo(string s)
{
	int l = s.length();
	for (int i = 0; i < l; i++)
	  if ('a' <= s[i] && s[i] <= 'z') return 0;
	return 1;
}

void phanLoai()
{
	ns = 0;
	nt = 0;
	for (int i = 1; i <= n; i++)
	  if (kieuSo(a[i]))
	  {
	  	p[i] = 1;
	  	mangSo[++ns] = a[i];
	  }
	  else
	  {
	  	p[i] = 2;
	  	mangTu[++nt] = a[i];
	  }
}

int lonHon(string a, string b)
{
	if (a.length() > b.length()) return 1;
	if (a.length() < b.length()) return 0;
	int l = a.length();
	for (int i = 0; i < l; i++)
	  if (a[i] > b[i]) return 1;
	return 0;
}

int cmp(string a, string b)
{
	int d1 = 1, d2 = 1;
	if (a[0] == '-')
	{
		d1 = -1;
		a.erase(0, 1);
	}
	if (b[0] == '-')
	{
		d2 = -1;
		b.erase(0, 1);
	}
	int l1 = a.length(), l2 = b.length();
	
	if (d1 < d2) return 1;
	if (d1 > d2) return 0;
	if (d1 == d2 && d2 == -1)
	{
		if (lonHon(a, b)) return 1;
	}
	else
	    if (lonHon(b, a)) return 1;
	return 0;
}

void Process()
{
	phanLoai();
	sort(mangTu + 1, mangTu  + 1 + nt);
	sort(mangSo + 1, mangSo + 1 + ns, cmp);
	int k1 = 0, k2 = 0;
	for (int i = 1; i <= n; i++)
	  if (p[i] == 1) res[i] = mangSo[++k1];
	  else res[i] = mangTu[++k2];
}

main()
{
//	freopen("in.txt", "r", stdin);
	while (cin >> s && s != ".")
	{
		n = 0;
		int kt = 0, l = s.length();
		if (s[l - 1] == '.') kt = 1;
		s.erase(l - 1, 1);
		a[++n] = s;
		while (!kt)
		{
			cin >> s;
			int l = s.length();
			if (s[l - 1] == '.') kt = 1;
			s.erase(l - 1, 1);
			a[++n] = s;
		}
		Process();
		for (int i = 1; i < n; i++) cout << res[i] << ", ";
		cout << res[n] << ".";
		cout << endl;
	}
}