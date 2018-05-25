#include<iostream>
#include<math.h>
using namespace std;
int x,c[43],d;
main()
{
	for (int i=0;i<=41;i++) c[i]=0;
	for (int i=1;i<=10;i++)
	{
		cin>>x;
		c[x%42]=1;
	}
	d=0;
	for (int i=0;i<=41;i++)
	  if (c[i]) d++;
	cout<<d;
}