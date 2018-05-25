#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long n, t;
string a, b;
typedef pair <long, string> record;
record x[21];


long thutu()
{
	long ir, k = 0;
	for (long i = n; i >= 1; i--)
	  if (x[i].second == a)
	  {
	  	ir = i;
	  	break;
	  }
	for (long i = n; i >= 1; i--)
	  if (x[i].first > x[ir].first) k++;
	  else 
	  if ((x[i].first == x[ir].first) && (x[i].second < x[ir].second)) k++;
	return (k + 1);
}
long thang()
{
	long res;
	for (long i = 1; i <= n; i++) 
	  if (x[i].second == a)
	  {
	  	x[i].first += 3;
	  	break;
	  }
	sort(x + 1, x + 1 + n);
	res = thutu();
	for (long i = 1; i <= n; i++)
	  if (x[i].second == a)
	  {
	  	x[i].first -= 3;
	  	return res;
	  }
}

long thua()
{
	long w;
	for (long i = 1; i <= n; i++)
	  if (x[i].second == b) 
	  {
	  	x[i].first += 3;
	  	break;
	  }
	sort(x + 1, x + 1 + n);
	w = thutu();
	for (long i = 1; i <= n; i++)
	  if (x[i].second == b)
	  {
	  	x[i].first -= 3;
	  	return w;
	  }
}

long hoa()
{
	long w;
	for (long i = 1; i <= n; i++)
	  if ((x[i].second == a) || (x[i].second == b)) x[i].first++;
	sort(x + 1, x + 1 + n);
	w = thutu();
	for (long i = 1; i <= n; i++)
	  if ((x[i].second == a) || (x[i].second == b)) x[i].first--;
	return w;
}

main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n;
		cin >> a;
		cin >> b;
		for (long i = 1; i <= n; i++) cin >> x[i].second >> x[i].first;
		cout << thang() << " " << thua() << " " << hoa() << endl;
	}
}