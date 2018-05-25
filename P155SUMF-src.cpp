#include <iostream>
#define ll long long
using namespace std;
ll n, b[200], a[200];

main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];
	a[1] = b[1];
	for (int i = 2; i <= n; i++) a[i] = b[i] * i - b[i - 1] * (i - 1);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
