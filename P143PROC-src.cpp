#include<iostream>
#include<math.h>
using namespace std;
long y,n,k;
main()
{
	cin>>y>>k>>n;
	long t=n/k;
	if (t*k<=y) cout<<"-1"; else
	for (long i=1;i<=t;i++)
	  if (i*k>y) cout<<i*k-y<<" ";
}