#include <iostream>
#include <cmath>
using namespace std;
int n, a[100005], res;
int k;

int ketQua()
{
	int p;
	for (int i = k + 1; i <= n; i++)
	  if (a[i] > a[i + 1])
	  {
	  	p = i;
	  	break;
	  }	
	if (p < n) return -1;
	return (n - k);
}

main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = a[n] - 1;
	for (int i = 1; i <= n; i++)
	  if (a[i] > a[i + 1])
	  {
	  	k = i;
	  	break;
	  }
	cout << ketQua();
}
