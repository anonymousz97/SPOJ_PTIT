#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
main()
{
	char s[100];
	long t,a[100],x;
	cin>>t;
	for (long k=1;k<=t;k++)
	{
		cin>>x>>s;
		long l=strlen(s);
		long n=0;
		for (long i=0;i<=l-1;i++)
		{
			n++;
			a[n]=int (s[i]) -48; 
		}
		cout<<x<<" ";
		long vt=n-1;a[0]=0;
		while ((vt>=1)&&(a[vt]>=a[vt+1])) vt--;
		if (vt==0) 
		{
			cout<<"BIGGEST"<<endl;
		} else
			{
				long min=vt+1;
			 	for (long i=vt+1;i<=n;i++)
			 	  if (a[i]>a[vt])
			 	    if (a[i]<a[min]) min=i;
			 	swap(a[vt],a[min]);
			 	vt++;
			 	for (long i=n-1;i>=vt;i--)
			 	  for (long j=vt;j<=i;j++)
			 	    if (a[j]>a[j+1]) swap(a[j],a[j+1]);
			
		for (long i=1;i<=n;i++) cout<<a[i];
		cout<<endl;
			}
	}
}