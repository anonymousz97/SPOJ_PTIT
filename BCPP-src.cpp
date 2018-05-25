#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char s[255],smax[255],smin[255];
long n,d,m,y,dmax,mmax,ymax,dmin,mmin,ymin;
int c1,c2;

int sosanh(long a, long b,long c,long aa,long bb,long cc)
{
	if (cc>c) return 1;
	if (cc==c)
	  {
	  	if (bb>b) return 1;
	  	if (bb==b)
	  	  if (aa>a) return 1;
	  }
	return 0;
}
main()
{
	cin>>n;
	cin>>s>>d>>m>>y;
	strcpy(smax,s);
	strcpy(smin,s);
	dmax=d; dmin=d;
	mmax=m; mmin=m;
	ymax=y; ymin=y;
	for (long i=2;i<=n;i++)
	{
		cin>>s>>d>>m>>y;
		if (sosanh(dmax,mmax,ymax,d,m,y)) 
		{
			strcpy(smax,s);
			dmax=d;
			mmax=m;
			ymax=y;
		}
		if (sosanh(d,m,y,dmin,mmin,ymin))
		{
			strcpy(smin,s);
			dmin=d;
			mmin=m;
			ymin=y;
		}
	}
	cout<<smax<<endl;
	cout<<smin;
}