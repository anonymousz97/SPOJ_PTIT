#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int x[10],n;
bool cx[10];

void Try(int i)
{
	for (int j=0;j<=n;j++)
	 if (cx[j])
	{
		x[i]=j;
		cx[j]=false;
		if (i==n) 
		{
			for (int k=1;k<=n;k++) cout<<x[k];
			cout<<endl;
		}
		else Try(i+1);
		cx[j]=true;
	}
}

main()
{

	cin>>n;
	for (int i=1;i<=n;i++) cx[i]=true;
	Try(1);
}