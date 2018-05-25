#include <iostream>
#include <string>
using namespace std;
long n;
string s, rs;
long sl, rsl, t, rt;
long a, b;
main()
{
	cin >> n;
	rsl = 0;
	for (long i = 0; i < n; i++)
	{
		cin >> s;
		sl = 0;
		t = 0;
		for (long i = 1; i <= 4; i++)
		{
			cin >> a >> b;
			if (b == 0) continue;
			sl++;
			t += b + (a - 1) * 20;
		}
		if ( (sl > rsl) || ((sl == rsl) && (t < rt)) ) 
		{
			rs = s;
			rsl = sl;
			rt = t;
		}
	}
	cout << rs << " " << rsl << " " << rt;
}