#include<iostream>
using namespace std;
long t,n,d,a[102];
main()
{
	cin>>t;
	for (long k=1;k<=t;k++)
	{
		cin>>n;
		for (long i=1;i<=n;i++) a[i]=0;
		for (long i=1;i<=n;i++)
		{
			long j=i;
			while (j<=n)
			{
				a[j]++;
				j=j+i;
			}
		}
		d=0;
		for (long i=1;i<=n;i++)
		  if (a[i]%2 != 0) d++;
		cout<<d<<endl;
	}
}