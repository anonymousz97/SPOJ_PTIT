#include <iostream>
using namespace std;
long long n, gt[20];

long long build()
{
	gt[0] = 0;
	gt[1] = 1;
	for (long i = 2; i <= 15; i++) gt[i] = gt[i - 1] * i;
}
void timDay()
{
	long long s, a[20], cx[20];
	cin >> s;
	long pos = 0;
	for (long i = 1; i <= n; i++) cx[i] = 1;
	while (s != 0)
	{
		pos++;
		for (long i = 1; i <= n; i++)
		  if (s < i * gt[n- pos])
		  {
		  	s -= (i - 1) * gt[n - pos];
		  	long k = 0;
		  	for (long j = 1; j <= n; j++)
		  	  if (cx[j])
		  	  {
		  	  	k++;
		  	  	if (k == i)
		  	  	{
		  	  		a[pos] = j;
		  	  		cx[j] = 0;
		  	  		break;
		  	  	}
		  	  }
		  	break;
		  }
		  else if (s == i * gt[n - pos])
		  {
		  	long k = 0;
		  	for (long j = 1; j <= n; j++)
		  	 if (cx[j])
		  	 {
		  	 	k++;
		  	 	if (k == i)
		  	 	{
		  	 		a[pos] = j;
		  	 		cx[j] = 0;
		  	 		for (long p = n; p >= 1; p--)
		  	 		  if (cx[p])
		  	 		  {
		  	 		  	pos++;
		  	 		  	a[pos] = p;
		  	 		  	cx[p] = 0;
		  	 		  }
		  	 		s = 0;
		  	 		break;
		  	 	}
		  	 }
		  }
	}
	for (long i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
}

void timViTri()
{
	long long res = 0;
	long long a[20], cx[20];
	for (long i = 1; i <= n; i++) cin >> a[i];
	for (long i = 1; i <= n; i++) cx[i] = 1;
	for (long i = 1; i <= n; i++)
	{
		long k = 0;
		for (long j = 1; j < a[i]; j++)
		  if (cx[j]) k++;
		res += k * gt[n - i];  
		cx[a[i]] = 0;
	}
	res++;
	cout << res << endl;
}
main()
{
	build();
	while ((cin >> n) && (n != 0))
	{
		long type;
		cin >> type;
		if (type == 1) timViTri();
		else timDay();
	}
}