#include<iostream>
using namespace std;
int n,a[102],res,sl[2],d;
main()
{
	cin>>n;
	d=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1) d++;
	}
	res=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			{
				sl[0]=0;
				sl[1]=0;
				for (int k=i;k<=j;k++) sl[a[k]]++;
				if (d+sl[0]-sl[1]>res) res=d+sl[0]-sl[1];
			}
	cout<<res;
}