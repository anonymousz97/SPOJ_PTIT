#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char s[101];
long a[100],top;
void convert(char s[101])
{
	int x;
	long l=strlen(s);
	top=0;
	for (int i=0;i<=l-1;i++)
	{
		x=int (s[i]);
		if (x>90) x=x-32;
		long b;
		if ((65<=x)&&(x<=67)) b=2; else
		if ((68<=x)&&(x<=70)) b=3; else
		if ((71<=x)&&(x<=73)) b=4; else
		if ((74<=x)&&(x<=76)) b=5; else
		if ((77<=x)&&(x<=79)) b=6; else	
		if ((80<=x)&&(x<=83)) b=7; else
		if ((84<=x)&&(x<=86)) b=8; else
		if ((87<=x)&&(x<=90)) b=9;
		top++;
		a[top]=b;
	}
}

bool  kt()
{
	long i=1,j=top;
	while (i<=j)
	  if (a[i]==a[j])
	  {
	  	i++;
	  	j--;
	  } else return false;
	return true;
}
main()
{
	int t;
	cin>>t;
	for (long k=1;k<=t;k++)
	{
		cin>>s;
		convert(s);
		if (kt()) cout<<"YES"; else cout<<"NO";
		cout<<endl;
	}
}