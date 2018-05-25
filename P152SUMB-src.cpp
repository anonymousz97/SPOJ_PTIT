#include <iostream>
#include <algorithm>
using namespace std;
long n, a[100001], vt[1000001], next[100001], ck[100001];
long t;
typedef pair <long, long> record;
record kq[100001];
main()
{
	cin >> n;
	for (long i = 0; i <= 1000001; i++) vt[i] = 0;
	for (long i = 0; i <= 100001; i++)
	{
		 next[i] = n+1;
		 ck[i] = 1;
	}
	for (long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (vt[a[i]] == 0) vt[a[i]] = i;
		else 
		{
			next[vt[a[i]]] = i;
			vt[a[i]] = i;
		}
	}
	t = 0;	
	/*for (long i = 1; i <= n; i++) cout << next[i] << " ";
	cout << endl; */
	for (long i = 1; i <= n; i++)
	  if (ck[i])
	  {
	  	long k = next[i];
	  	long q = i;
	  	long p = next[i] - i;
	  	if (k == n + 1) 
		  {
		  	t++;
			  kq[t].first = a[i];
			  kq[t].second = 0;
		  }
	  	else 
	  	{
	  		long c = 1;
	  		while (k <= n)
	  		{
	  			ck[k] = 0;
	  			if ((c) && (k - q != p)) c = 0;
	  			q = k;
	  			k = next[q];
	  		}
	  		if (c == 0) p = 0;
	  		else
	  		{
	  			t ++;
	  			kq[t].first = a[i];
	  			kq[t].second = p;
	  		}
	  	}
	  }
	  cout << t << endl;
	  sort(kq + 1, kq + 1 + t);
	  for (long i = 1; i <= t; i ++) cout << kq[i].first << " " << kq[i].second << endl;
}