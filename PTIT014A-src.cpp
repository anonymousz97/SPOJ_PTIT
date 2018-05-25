#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
main()
{
	int n;
	char s[30],x[30];
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		if (strcmp(s,"dung")==0) cout<<"2"<<endl; else
		{
		cin>>x; 
		if (strcmp(s,"lon")==0) cout<<"1"<<endl; else
		if (strcmp(s,"nho")==0) cout<<"3"<<endl;
		}
	}
}