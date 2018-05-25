#include <iostream>
#define ll long long
using namespace std;
ll n, k, res;
main()
{
	cin >> n >> k;
	if (k >= n) res = 2 * n - 1;
	else
		res = (2*(n*(n-1)/2 - k*(k+1)/2) + n-1)/k + 2*k +1;
	cout << res;
}