#include <iostream>
using namespace std;
int m, n;
main()
{
	cin >> n >> m;
	if (n > m) n = m;
	if (n % 2) cout << "Xavi";
	else cout << "Wilshere";
}
