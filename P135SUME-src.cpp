#include<iostream>
using namespace std;
int a[10],z,x;
main()
{
	for (int i=1;i<=8;i++) cin>>a[i];
	z=1;x=1;
	for (int i=2;i<=8;i++) 
	{
	 if (z)
	  if (a[i-1]>=a[i]) z=0;
	 if (x) 
	  if (a[i-1]<=a[i]) x=0; 
	}
	if (z) cout<<"ascending";
	else
	if (x) cout<<"descending";
	else
		   cout<<"mixed";
}