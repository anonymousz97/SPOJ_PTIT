#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#define ll unsigned long long
using namespace std;
ll n, t;
string s;
char c;
ll l, row, g[27][1000005], res;

void Init()
{
	l = s.length();	
	s = "*" + s;
	for (int i = 1; i <= 26; i++) g[i][0] = 0;
	for (int i = 1; i <= 26; i++)
	{
		for (int j = 1; j <= l; j++)
		  if (s[j] == i + 64) g[i][j] = g[i][j - 1] + 1;
		  else g[i][j] = g[i][j - 1]; 
	}
}

void Process(ll row, int c)
{
	ll p, h;
	if (row % 2 == 0)
	{
		p = row / 2;
		h = row - 1;
	}
	else 
	{
		p = row;
		h = (row - 1) / 2;
	}
	ll start = (p % l)  * (h % l) % l;
	ll vt = (start + 1) % l;
	if (!vt) vt = l;
	ll x = row / l;
	ll du = row % l;	
	if (du + vt - 1 <= l) res = x * g[c][l] + (g[c][du + vt - 1] - g[c][vt - 1]);
	else 
	res = x * g[c][l] + (g[c][l] - g[c][vt - 1]) + g[c][du - l + vt - 1];
}

main()
{
	cin >> n >> s >> t;
	Init();
	while (t--)
	{
		cin >> row >> c;
		Process(row, c - 64);
		cout << res << endl;
	}
}
