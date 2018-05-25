#include <iostream>
using namespace std;
int n, a[2000], b[2000];

int KhongThe(int k)
{
	for (int i = 1; i <= n; i++)
	  if ((k != i) && (a[k] == b[i])) return 0;
	return 1;	
}

main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	int res = 0;
	for (int i = 1; i <= n; i++)
	  if (KhongThe(i)) res++;
	cout << res;
}
