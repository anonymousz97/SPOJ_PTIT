#include<iostream>
#include<string.h>
using namespace std;
char s[255];
long x,a[100001],top;
main()
{
	cin>>s;
	while (strcmp(s,"end") != 0)
	{
		if (strcmp(s,"init") == 0) top=0;
		else if (strcmp(s,"push") == 0)
		{
			cin>>x;
			top++;
			a[top]=x;
		}
		else if (strcmp(s,"pop") == 0)
		{
			if (top>0) top--;
		}
		else if (strcmp(s,"top") == 0)
		{
			if (top == 0) cout<<"-1"<<endl;
			else cout<<a[top]<<endl;
		}
		else if (strcmp(s,"size") == 0) cout<<top<<endl;
		else if (strcmp(s,"empty") == 0) 
		{
			if (top==0) cout<<"1"<<endl; else cout<<"0"<<endl;
		}
		cin>>s;
	}
}