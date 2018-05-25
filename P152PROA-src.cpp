#include <iostream>
#include <math.h>
using namespace std;
int t, n, res;

int ucln(int a, int b)
{
	if (!b) return a;
	return ucln(b, a % b);	
}

void Process()
{
	res = 0;
	for (int i = 1; i < n; i++)
	  if (ucln(n, i) == 1) res++;
}

int ngTo(int n)
{
	if (n < 2) return 0;
	for (int i = 2; i <= sqrt(n); i++)
	  if (n % i == 0) return 0;
	 return 1;	
}

main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		Process();
		cout << ngTo(res) << endl;
	}
}
