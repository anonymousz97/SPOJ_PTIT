#include<iostream>
#include<math.h>
using namespace std;
long n,x,q[50002];
bool ck=false;

bool find(long x)
{
	bool ck=false;
	long mid,d,c;
	d=1;c=sqrt(n)+1;
	while (d<=c)
	{
		mid=(c+d)/2;
		if (q[mid]==x) 
		{
			ck=true;
			break;
		} else
		if (x>q[mid]) d=mid+1; 
		else c=mid-1;
	}
	return ck;
}
main()
{
	cin>>n;
	n=2*n;
	for (long i=0;i<=sqrt(n)+1;i++) q[i]=i*(i+1);
	for (long i=1;i<=sqrt(n)+1;i++)
	{
		if (find(n-q[i]))
		{
			ck=true;
			break;
		}
		
	}
	if (ck) cout<<"YES"; else cout<<"NO";
}