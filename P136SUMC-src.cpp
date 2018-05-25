#include<iostream>
#include<math.h>
using namespace std;
long res,a,b,x,y;

long nd(long m)
{
	long x,y;
	x=m;
	y=0;
	while (x!=0)
	{
		y=y*10+x%10;
		x=x/10;
	}
	return y;
}
main()
{
	cin>>a>>b;
	x=nd(a);
	y=nd(b);
	if (x>y) res=x; else res=y;
	cout<<res;
}