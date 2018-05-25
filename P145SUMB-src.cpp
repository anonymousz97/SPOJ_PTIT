#include<iostream>
#include<math.h>
using namespace std;
long n,m,r,sl1,sl2,x,y,k;
long min(long a, long b)
{
	if (a>b) return b;
	return a;
}
main()
{
	cin>>n>>m;
	sl1=0;sl2=0;
	for (long i=1;i<=n;i++)
	{
		cin>>x;
		if (x==1) sl1++; else sl2++;
	}
	k=min(sl1,sl2);
	for (long i=1;i<=m;i++)
	{
		cin>>x>>y;
		r=y-x+1;
		if (r%2 != 0) cout<<"0"<<endl;
		else 
		{
			r=r/2;
			if (k>=r) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
	}
}