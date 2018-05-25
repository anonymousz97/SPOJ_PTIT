#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
long t,n,m,sum,a[101],res;

long find(long x, long l, long r)
{
	long t,cl=300001;
	long d=l,c=r;
	t=-300001;
	while (d<=c)
	{
		long mid=(d+c)/2;
		if (a[mid]==x) return a[mid]; else
		if (a[mid]>x) c=mid-1; else
		{
			if (x-a[mid]<cl)
			{
			 t=a[mid];
			 cl=x-a[mid];
			}
			d=mid+1;
		}
	}
	return t;
}
main()
{
	cin>>t;
	for (long k=1;k<=t;k++) {
		
	cin>>n>>m;
	for (long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	res=0;
	for (long i=1;i<=n-2;i++)
	  for (long j=i+1;j<=n-1;j++)
	    {
	    	long x=m-a[i]-a[j];
	    	long p=find(x,j+1,n);
	    	sum=a[i]+a[j]+p;
	    	if (sum>res) res=sum;
	    }
	cout<<res<<endl;
	}
}