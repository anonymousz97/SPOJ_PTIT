#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
main()
{
	int n,x,sum;
	double res;
	cin>>n;
	sum=0;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		sum=sum+x;
	}
	res= (double) sum/n;
	printf("%0.12f",res);
}