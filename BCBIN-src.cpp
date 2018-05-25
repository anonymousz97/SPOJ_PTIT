#include<iostream>
#include<math.h>
using namespace std;
long n,l,sum,wait,d,r,g;
main()
{
	cin>>n>>l;
	sum =0;
	for (long i=1;i<=n;i++)
	{
		cin>>d>>r>>g;
		sum+=d;
		wait= sum % (r+g);
		if (wait>=r) wait=r;
		sum+= (r-wait-d);
	}
	sum+=l;
	cout<<sum;
}