#include <iostream>
#include <string>
using namespace std;
string s;
long n, a[100], res;
main()
{
	cin >> n >> s;
	long t = 0;
	for (long i = 0; i <= n; i++)
	 if (s[i] == 'S')
	 {
	 	t++;
	 	a[t] = 1;
	 }
	 else
	 if (s[i] == 'L')
	 {
	 	t++;
	 	a[t] = 2;
	 	s[i + 1] = '0';
	 }
	 //for (long i = 1; i <= t; i++) cout << a[i] << " ";
	 res = 0;
	 for (long i = 1; i <= t; i++)
	   if (a[i] == 2)
	   {
	   	res = 1;
	   	break;
	   }
	res += t;
	cout << res;
}