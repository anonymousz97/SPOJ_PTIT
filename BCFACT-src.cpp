#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
main()
{
	long long s,gt;
	cin>>s;
	while (s!=0)
	{
		gt=1;
		for (long i=2;i<=s;i++) gt=gt*i;
		cout<<gt<<endl;
		cin>>s;
	}
}
