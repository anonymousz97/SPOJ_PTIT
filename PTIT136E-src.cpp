#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
int n, d1[1000006] = {0}, d2[1000006] = {0};
int x[4], y[4];

void Build()
{
	int xmin, xmax, ymin, ymax;
	xmin = x[1];
	xmax = x[1];
	
	ymin = y[1];
	ymax = y[1];
	
	for (int i = 1; i <= 3; i++)
	{
		xmin = min(xmin, x[i]);
		xmax = max(xmax, x[i]);
		
		ymin = min(ymin, y[i]);
		ymax = max(ymax, y[i]);
	}
	
	d1[ymin + 1]++;
	d1[ymax]--;
	
	d2[xmin + 1]++;
	d2[xmax]--;
}

main()
{
//	freopen("in.txt", "r", stdin);
	int xm = -1, ym = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> x[j] >> y[j];
			xm = max(xm, x[j]);
			ym = max(ym, y[j]);
		}
		Build();
	}
	
	for (int i = 0; i <= ym; i++) d1[i] += d1[i - 1];
	for (int i = 0; i <= xm; i++) d2[i] += d2[i - 1];
	
	int m;
	cin >> m;
	string s, b;
	int t;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> b >> t;
		if (s == "x") cout << d2[t];
		else cout << d1[t];
		cout << endl;
	}
}