#include <iostream>
using namespace std;
int a, b, t;

void Process(int a, int b)
{
	cout << a/b << ".";
	a = a % b;
int top = 0;
int xh[10005], tp[10005];

	for (int i = 0; i <= 10005; i++) xh[i] = 0;
	
	while (a != 0 && a < b)
	{
		a *= 10;
		if (!xh[a])
		{
			tp[++top] = a / b;
			xh[a] = top;
			a = a % b;
		}
		else break;
	}
		
	if (!a)
	{
		for (int i = 1; i <= top; i++) cout << tp[i];
		if (!top) cout << 0;
	}
	else
	{
		for (int i = 1; i < xh[a]; i++) cout << tp[i];
		cout << "(";
		for (int i = xh[a]; i <= top; i++) cout << tp[i];
		cout << ")";
	}
	
	cout << endl;
}

main()
{
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		Process(a, b);
	}
}