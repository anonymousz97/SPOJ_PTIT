#include <iostream>
#include <string>
#include <cmath>
#define ll long long
using namespace std;
string s;
ll res, n, a[100005], f[100005], t[100005];
main()
{
	cin >> n;
	t[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		t[i] = t[i - 1] + a[i];
	}
	cin >> s;
	int l = s.length();
	s = "*" + s;
	f[0] = 0;
	for (int i = 1; i <= l; i++)
	  if (s[i] == '1') f[i] = max(a[i] + f[i - 1], t[i - 1]);
	  else f[i] = f[i - 1];
	cout << f[l];
}