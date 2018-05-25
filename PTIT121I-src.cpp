#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
main()
{
	int n,r;
	char s[25];
	cin>>n;
	for (int k=1;k<=n;k++)
	{
		int j;
		cin>>j>>r>>s;
		int l=strlen(s);
		cout<<j<<" ";
		for (int i=0;i<=l-1;i++)
		  for (int j=1;j<=r;j++) cout<<s[i];
		cout<<endl;
	}
}