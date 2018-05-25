#include<iostream>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

long a[1000001];
void qs(long l, long r)
{
	long i=l,j=r;
	long key=a[l+rand()%(r-l+1)];
	while (i<=j)
	{
		while (a[i]<key) i++;
		while (a[j]>key) j--;
		if (i<=j)
		{
			if (i<j)
			{ 
			 long t=a[i];
			 a[i]=a[j];
			 a[j]=t;
			}
			i++;
			j--;
		}
	}
	if (l<j) qs(l,j);
	if (i<r) qs(i,r);
}
main()
{
	long n,k,x,y;
	cin>>n>>k;
	for (long i=0;i<=n;i++) a[i]=0;
	for (long i=1;i<=k;i++)
	{
		cin>>x>>y;
		a[x]++; a[y+1]--;
	}
	for (long i=1;i<=n;i++)
	{
	 a[i]=a[i-1]+a[i];
    }
    qs(1,n);
    cout<<a[(n+1)/2];
}
