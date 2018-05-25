#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
long xh['z' + 1];
typedef pair<char, long> record;
record c[10001];
long res, m, n;

long Find(char ch, long vt)
{
	long l = 1, r = n;
	long mid, res = -1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (c[mid].first < ch) l = mid + 1;
		else
		if (c[mid].first > ch) r = mid - 1;
		else
		{
			if (c[mid].second > vt)
			{
				res = c[mid].second;
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	return res;
}

long ketQua()
{
	long vt, x, res;
	if (xh[b[0]] == -1) return -1;
	for (long i = 1; i <= n; i++)
	  if (b[0] == c[i].first)
	  {
	  	res = 1;
	  	vt = c[i].second;
	  	break;
	  }
	for (long i = 1; i < m; i++)
	{
		if (xh[b[i]] == -1) return -1;
		x = Find(b[i], vt);  // x la vi tri gan nhat  > vt cua ki tu b[i] trong a; 
		if (x == -1)
		{
			res++;
			vt = xh[b[i]];
		}
		else vt = x;
	}
	return res;
}

void buildC()
{
	long t = 0;
	for (long i = 0; i < n; i++)
	{
		t++;
		c[t].first = a[i];
		c[t].second = i;
	}
}

main()
{
	cin >> a >> b;
	n = a.length();
	m = b.length();
	for (long i = 'a'; i <= 'z'; i++) xh[i] = -1;
	for (long i = 0; i < n; i++)
	  if (xh[a[i]] == -1) xh[a[i]] = i;
	buildC();
	sort(c + 1, c + 1 + n);
	cout << ketQua();
}