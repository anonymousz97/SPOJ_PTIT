#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<long, long> record;
record a[100001];
long n, res, d;
main()
{
	cin >> n;
	for (long i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
	sort(a + 1, a + 1 + n);
	a[n+1].first = 24; a[n + 1].second = 0;
	d = 1; res = 1;
	for (long i = 2; i <= n + 1; i++)
	  if ((a[i].first == a[i - 1].first) && (a[i].second == a[i - 1].second)) d++;
	  else
	  {
	  	if (d > res) res = d;
	  	d = 1;
	  }
	cout << res;
}