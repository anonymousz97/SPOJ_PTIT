#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const ll nmax = 1000006;
ll t, u[nmax] = {0}, v[nmax] = {0};
ll p[nmax] = {0}, q[nmax] = {0};

void BuildUV()
{
	u[0] = 0;
	v[0] = 0;
	u[1] = 1;
	v[1] = 1;
	p[0] = 0;
	q[0] = 0;
	p[1] = 1;
	q[1] = 1;
	
	for (int i = 2; i < nmax; i++)
	{
		u[i]++;
		v[i]++;
		ll j = i;
		while (j < nmax)
		{
			u[j]++;
			v[j] += i;
			j += i;
		}
	}
	for (int i = 2; i < nmax; i++)
	{
		p[i] = p[i - 1] + u[i];
		q[i] = q[i - 1] + v[i];
	}
}

main()
{
	BuildUV();
	cin >> t;
	int x, y;
	while (t--)
	{
		cin >> x >> y;
		cout << p[y] - p[x - 1] << " " << q[y] - q[x -1] << endl;
	}
}