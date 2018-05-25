#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
main()
{
	char s[255];
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>s;
		int l,sum;
	
		
			sum=0;
			l=strlen(s);
			for (int i=0;i<=l-1;i++) sum=sum+int (s[i])-48;
		if (sum==0) sum=1;
		if (sum%9==0) cout<<"1"<<endl; else cout<<"0"<<endl;
	}
}