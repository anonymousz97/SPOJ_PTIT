#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int x, y;

int nguyenTo(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	  if (n % i == 0) return 0;
	return 1;
}
main()
{
	cin >> x >> y;
	int res = 0;
	for (int i = x + 1; i <= 50; i++)
	  if (nguyenTo(i))
	  {
	  	res = i;
	  	break;
	  }
	if (res == y) cout << "YES";
	else cout << "NO";
}
