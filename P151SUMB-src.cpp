#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
int n, res;

int OK(int n)
{
	for (int i = n / 5; i >= 0; i--)
	{
		int x = n - i * 5;
		if (x % 3 == 0) 
		{
			res = i + x / 3;
			return 1;
		}
	}
	return 0;
}

main()
{
	cin >> n;
	if (OK(n)) cout << res;
	else cout << -1;
}