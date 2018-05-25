#include <iostream>
#include <string>
using namespace std;
string s[501];
long m, n;
long res[6];

long loai(long r, long c)
{
	string ss = "";
	for (long i = r; i < r + 4; i++) ss += s[i].substr(c, 4);
	if (ss == "................") return 1;
	if (ss == "****............") return 2;
	if (ss == "********........") return 3;
	if (ss == "************....") return 4;
	if (ss == "****************") return 5;
}

main()
{
	cin >> m >>  n;
	for (long i = 1; i <= 5; i++) res[i] = 0;
	for (long i = 0; i <= m * 5; i++) cin >> s[i];
	long r = 1, c = 1;
	long stop = 0;
	while (!stop)
	{
		res[loai(r, c)]++;
		c += 5;
		if (c > n * 5)
		{
			r += 5;
			c = 1;
			if (r > m * 5) stop = 1;
		}
	}
	for (long i = 1; i <= 5; i++) cout << res[i] << " ";
}