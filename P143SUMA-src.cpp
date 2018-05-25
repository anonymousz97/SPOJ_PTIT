#include<iostream>\
#include<math.h>
using namespace std;
long n,s,x[1001],y[1001];
bool ck=true;
main()
{
	cin>>s>>n;
	for (long i=1;i<=n;i++) cin>>x[i]>>y[i];
	for (long i=n-1;i>=1;i--)
	  for (long j=1;j<=i;j++)
	    if (x[j]>x[j+1])
	    {
	    	long t;
	    	t=x[j];
	    	x[j]=x[j+1];
	    	x[j+1]=t;
	    	t=y[j];
	    	y[j]=y[j+1];
	    	y[j+1]=t;
	    }
	for (long i=1;i<=n;i++)
	  if (s<=x[i]) 
	  {
	  	ck=false;
	  	break;
	  } 
	  else s=s+y[i];
	if (ck) cout<<"YES"; else cout<<"NO";
}