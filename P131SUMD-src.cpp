#include<iostream>
#include<math.h>
using namespace std;

long edit(long n, long a)
{
	long x,y,p,k;
	y=1000000;x=n;
	p=0;
	while (y!=0)
	{
		k=x /y;
		x=x-k*y;
		if (k==a) k=11-a;
		p=p*10+k;
		y=y/10;
	}
	return p;
}
main()
{
	long a,b,x,y,min,max;
	cin>>a>>b;
	min=edit(a,6)+edit(b,6);
	max=edit(a,5)+edit(b,5);
	cout<<min<<" "<<max<<endl;
}