#include <iostream>
using namespace std;
int n, x, q[200];
main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		q[x] = i;
	}
	for (int i = 1; i <= n; i++) cout << q[i] << " ";
}
