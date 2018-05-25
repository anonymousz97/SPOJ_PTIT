#include <iostream>
#define ll long long
using namespace std;
ll n, a[500005], res, p, s[500005], x1[500005], x2[500005];
int main()
{
	cin >> n;
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	s[0] = 0;	
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	p = s[n] / 3;
	if (3 * p != s[n])
	{
		cout << 0;
		return 0;
	}
	else
	{
		x1[0] = 0;
		x2[0] = 0;
		for (int i = 1; i <= n; i++)
		  if (s[i] == 2 * p) x2[i] = x2[i - 1] + 1;
		  else x2[i] = x2[i - 1];
		res = 0;
		for (int i = 1; i <= n - 2; i++)
		  if (s[i] == p) res += (x2[n - 1] - x2[i]);
		cout << res;
	}
}
