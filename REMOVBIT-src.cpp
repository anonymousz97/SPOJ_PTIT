#include<iostream>
#include<string.h>
using namespace std;
char s[100001];
main()
{
	long i,timchuso0dautien=0;
	cin>>s;
	long l=strlen(s);
	for (long i=0;i<=l-1;i++)
	  if (timchuso0dautien==0)
	    {
	      int x= int (s[i]) -48;	
	      if (x==0) timchuso0dautien=1;
	      else 
		   if (i!=l-1) cout<<s[i];
		}
	else cout<<s[i];
}