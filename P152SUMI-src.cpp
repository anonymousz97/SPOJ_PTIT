#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#define nmax 100005
using namespace std;
string s;
int f[nmax];
int m, n;

void Init()
{
	n = s.length();
	s = "*" + s;
	f[1] = 0;	
	for (int i = 2; i <= n; i++)
	  if (s[i] == s[i - 1]) f[i] = f[i - 1] + 1;
	  else f[i] = f[i - 1];
}

main()
{
	cin >> s;
	Init();
	cin >> m;
	int l, r;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		cout << (f[r] - f[l]) << endl;
	}
}
