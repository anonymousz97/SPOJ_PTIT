#include <iostream>
#include <algorithm>
#define fi first
#define se second
using namespace std;
long n, c;
struct record
{
	long val;
	long sl;
	long vtmin;	
};
typedef pair <long, long> pii;
pii a[1001];
long t;
record v[1001];

long cmp(record a, record b)
{
	if (a.sl > b.sl) return 1;
	if (a.sl == b.sl)
	  if (a.vtmin < b.vtmin) return 1;
	return 0;
}

main()
{
	cin >> n >> c;
	for (long i = 1; i <= n; i++)
	{
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + 1 + n);
	t = 1;
	v[1].val = a[1].fi;
	v[1].sl = 1;
	v[1].vtmin = a[1].se;
	
	for (long i = 2; i <= n; i++)
	  if (a[i - 1].fi == a[i].fi) v[t].sl++;
	  else
	  {
	  	t++;
	  	v[t].val = a[i].fi;
	  	v[t].sl = 1;
	  	v[t].vtmin = a[i].se;
	  }
	sort(v + 1, v + 1 + t, cmp);
	for (long i = 1; i <= t; i++)
	  for (long j = 1; j <= v[i].sl; j++) cout << v[i].val << " ";
}