#include<iostream>
#include<math.h>
using namespace std;
main()
{
	long n,a[5001];
	bool c[5001];
	cin>>n;
	for (long i=1;i<=n;i++)
	{ cin>>a[i]; 
	  c[i]=true;	
    }
    for (long i=1;i<=n;i++)
      if ((a[i]<=n) && (c[a[i]])) c[a[i]]=false;
    long d=0;
    for (long i=1;i<=n;i++) 
      if (c[i]) d++;
    cout<<d;
}
