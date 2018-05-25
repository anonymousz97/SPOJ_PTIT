#include<iostream>
#include<math.h>
using namespace std;

long n,chua,cay,x[20],s[20],b[20],res;
bool c=true;

void Try(long i)
{
	for (int j=0;j<=1;j++)
	{
		x[i]=j;
		if (j==1)
		{
			chua=chua*s[i];
			cay=cay+b[i];
		}
		if (i==n) 
		{
			if (c)
			{ 
			  c=false;
			  continue;
			}
			if (fabs(chua-cay)< res) res=fabs(chua-cay);
		} else Try(i+1);
		if (j==1)
		{
			chua=chua/s[i];
			cay=cay-b[i];
		}
	}
}

main()
{
	cin>>n;
	for (long i=1;i<=n;i++) cin>>s[i]>>b[i];
	res=1000000002;chua=1;cay=0;
	Try(1);
	cout<<res;
}