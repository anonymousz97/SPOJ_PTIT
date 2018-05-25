// DM bai nay de bai (x, y) cot hang, bai nay lam voi  x, y la hang cot do k doc ki , nen phai sua lai doan nhap :((
#include <iostream>	
#include <algorithm>
#define ULL unsigned long long
using namespace std;
ULL t, m, n, x, y, u, v, res;

void Doc()
{
	if (x > u)
	{
		swap(x, u);
		swap(y, v);
	}
	u -= (x - 1);
	v -= (y - 1);
	x = 1; y = 1;
	ULL a, b;
	a = x + (m - u);
	if (a >= u) b = a - u + 1; else b = 0;
	res = m * n - (2 * a * n - b * n);
	return;
}

void Ngang()
{
	if (y > v)
	{
		swap(x, u);
		swap(y, v);
	}
	u -= (x - 1);
	v -= (y - 1);
	x = 1; y = 1;
	ULL a, b;
	a = y + (n - v);
	if (a >= v) b = a - v + 1; else b = 0;
	res = m * n - (2 * a * m - b * m);
	return;
}

void CheoChinh()
{
	u -= (x - 1);
	v -= (y - 1);
	x = 1; y = 1;
	ULL xx, yy;	
	xx = x + (m - u);
	yy = y + (n - v);
	ULL s;
	if ((xx >= u) && (yy >= v)) s = (xx - u + 1) * (yy - v + 1); else s = 0;
	res = m * n - (2 * xx * yy - s);
	return;
}

void CheoPhu()
{
	u -= (x - 1);
	v += (n - y);
	x = 1; y = n;
	ULL xx, yy, s;
	xx = x + (m - u);
	yy = y - (v - 1);
	if ((xx >= u) && (yy <= v)) s= (xx - u + 1) * (v - yy + 1); else s = 0;
	res = m * n - (2 * xx * (n - yy + 1) - s);
	return;	
}

void Process()
{
	if (u == x) Ngang();
	else
	if (v == y) Doc();
	else
	{
		if (x > u)
		{
			swap(x, u);
			swap(y, v);
		}
		if (y < v) CheoChinh();
		else
		if (y > v) CheoPhu();
	}	
}

main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cin >> y >> x >> v >> u;
		Process();
		cout << res << endl;
	}
}
