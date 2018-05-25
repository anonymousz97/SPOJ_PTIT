#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int l1, l2, n, h;
string s1, s2;
main()
{
	cin >> n >> s1 >> s2;
	l1 = s1.length();
	l2 = s2.length();
	int lmin = min(l1, l2);
	int i;
	for (i = 0; i < lmin; i++)
	  if (s1[i] != s2[i]) break;
	if (s1[i] == s2[i]) i++;
	int r1 = l1 - i, r2 = l2 - i;
	if (r1 + r2 > n) cout << "NO";
	else cout << "YES";  
}
