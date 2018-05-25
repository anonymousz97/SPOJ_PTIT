#include <iostream>
#define ll long long
using namespace std;
const ll nmax = 100005;
ll n, a[nmax], s[nmax];

int Process()
{
	s[n + 1] = 0;
	for (int i = n; i > 0; i--)
	{
		ll x = a[i] + s[i + 1];
		s[i] = s[i + 1] + x / i;
		ll d = x % i;
		if (d != 0) return 0;
	}	
	return 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++) cin >> a[i];
	if (Process()) cout << "Yes";
	else cout << "No";
}