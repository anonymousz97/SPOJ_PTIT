#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int a[4],sl[103];
	cin>>a[1]>>a[2]>>a[3];
	int x,y,tmax;
	tmax=0;
	for (int i=1;i<=102;i++) sl[i]=0;
	for (int k=1;k<=3;k++)
	{
		cin>>x>>y;
		if (y>tmax) tmax=y;
		for (int i=x;i<=y-1;i++) sl[i]++; 	
	}
	long d,s;
	s=0;a[0]=0;d=1;
	sl[tmax]=sl[tmax-1]+1;
	for (int i=1;i<=tmax-1;i++)
	  if (sl[i]!= sl[i+1]) 
	  {
	    s=s+sl[i]*d*a[sl[i]];
	    d=1;
	  } else d++;
	cout<<s;
}