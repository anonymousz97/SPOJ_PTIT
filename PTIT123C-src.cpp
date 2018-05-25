#include<iostream>
#include<math.h>
#include<algorithm>
#define swap(type,a,b){type t=a;a=b;b=t;}
using namespace std;
typedef pair<long,long> record;
record a[1000002],b[1000002],c[1000002];
long n,k1,k2,t;
main()
{
	cin>>n>>k1>>k2;
	t=0;
	while (n!=0)
	{
		t++;
		for (long i=1;i<=n;i++)
		{
			cin>>a[i].first;
			a[i].second=i;
		}
		sort(a+1,a+1+n);
		cout<<"Case "<<t<<endl;
		for (long i=1;i<=k1;i++)
		{
			b[i]=a[i];
			swap(long ,b[i].first,b[i].second)
		}
		sort(b+1,b+1+k1);
		for (long i=1;i<=k1;i++) cout<<b[i].first<<" ";
		cout<<endl;
		for (long i=1;i<=k2;i++)
		{
			c[i]=a[n-i+1];
			swap(long, c[i].first,c[i].second);
		}
		sort(c+1,c+1+k2);
		for (long i=k2;i>=1;i--) cout<<c[i].first<<" ";
		cout<<endl;
		cin>>n>>k1>>k2;
	}
}