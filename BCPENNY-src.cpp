#include <iostream>
#include <string>
using namespace std;
string s;
long a[8], n, t;
main()
{
	cin >> t;
	for (long k = 1; k <= t; k++)
	{
		cin >> n;
		for (long i = 0; i <= 8; i++) a[i] = 0;
		cin >> s;
		while (s.length() >= 3)
		{
			string x = s.substr(0, 3);
			if (x == "TTT") a[0]++;
			else if (x == "TTH") a[1]++;
			else if (x == "THT") a[2]++;
			else if (x == "THH") a[3]++;
			else if (x == "HTT") a[4]++;
			else if (x == "HTH") a[5]++;
			else if (x == "HHT") a[6]++;
			else a[7]++;
			s.erase(0, 1);
		}
		cout << k << " ";
		for (long i = 0; i < 8; i++) cout << a[i] << " ";
		cout << endl; 
	}
}
