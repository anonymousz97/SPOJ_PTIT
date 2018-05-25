#include <iostream>
#include <algorithm>
using namespace std;
main()
{
	long a[6], res;
	for (long i = 1; i <= 4 ; i++) cin >> a[i];
	sort(a + 1, a + 1 + 4);
	res = 1;
	for (long i = 2; i <= 4; i++)
	  if (a[i] != a[i - 1]) res++;
	res = 4 - res;
	cout << res;	
}
