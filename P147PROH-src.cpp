#include <iostream>
#include <string>
using namespace std;
string a, b;
long d1[1001], d2[1001], t;
main()
{
	t = 0;
	cin >> a >> b;
	while (a != "END")
	{
		t++;
		long c = 1;
		for (long i = 0; i <= 1000; i++)
		{
			d1[i] = 0;
			d2[i] = 0;
		}
		long l = a.length();
		for (long i = 0; i < l; i++)
		{
			d1[ int (a[i]) ]++;
			d2[ int (b[i]) ]++;
		}
		for (long i = 0; i <= 1000; i++)
		  if (d1[i] != d2[i])
		  {
		  	c = 0;
		  	break;
		  }
		if (c) cout << "Case " << t <<": same" << endl;
		else cout << "Case " << t << ": different" << endl;
		cin >> a >> b;
	}
}