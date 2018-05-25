#include <iostream>
#include <string>
using namespace std;
long n, x;
string s;
main()
{
	cin >> n;
	x = 0;
	for (long i = 1; i <= n; i++)
	  {
	  	cin >> s;
	  	if ((s == "X++") || (s == "++X")) x++;
	  	else x--;
	  }
	cout << x;
}