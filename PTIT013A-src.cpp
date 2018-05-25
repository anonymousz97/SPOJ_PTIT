#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
main()
{
	long t;
	char s[255];
	cin>>t;
	for (long k=1;k<=t;k++)
	{
		cin>>s;
		long l=strlen(s);
		long x,y;
		x= int(s[l-2])-48;
		y= int(s[l-1])-48;
		if ((x==8)&&(y==6)) cout<<"1"<<endl; 
		else cout<<"0"<<endl;
	}
}