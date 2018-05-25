#include <iostream>
#include <stack>
#include <cmath>
#include <cstdio>
#define ll long long
using namespace std;
ll n, a[200015], L[200015], R[200015], f[200015];

void Init()
{
	a[0] = -1e9;
	a[n + 1] = -1e9;	
}

void BuildL()
{
ll top = 0;
ll st[200015];
st[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top > 0 && a[i] <= a[st[top]]) top--;
		L[i] = st[top];
		st[++top] = i;
	}
}

void BuildR()
{
ll top = 0;
ll st[200005];
st[0] = n + 1;
	for (int i = n; i > 0; i--)
	{
		while (top > 0 && a[i] <= a[st[top]]) top--;
		R[i] = st[top];
		st[++top] = i;
	}	
}

void BuildF()
{
	for (int i = 1; i <= n; i++)
	{
		ll x = R[i] - L[i] - 1;
		if (a[i] > f[x]) f[x] = a[i];
	}	
}

main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	BuildL();
	BuildR();
	BuildF();
	for (int i = n - 1; i > 0; i--)
	  if (f[i + 1] > f[i]) f[i] = f[i + 1];
	for (int i = 1; i <= n; i++) cout << f[i] << " ";
}