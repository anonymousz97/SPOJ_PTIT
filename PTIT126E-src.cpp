#include<iostream>
#include<string.h>
using namespace std;
//khai bao
char s[75];
int dy,kdy,v,l;
main()
{
	cin>>s;
	while (strcmp(s,"#") !=0)
	{
		l=strlen(s);
		dy=0;kdy=0;v=0;
		for (int i=0;i<=l-1;i++)
		switch (s[i])
		{
			case 'Y': dy++;break;
			case 'N': kdy++;break;
			case 'A': v++;break;
		}
		if (l%2!=0) l++;
		if (v>=(l/2)) cout<<"need quorum"<<endl; else
		if (dy>kdy) cout<<"yes"<<endl; else
		if (dy<kdy) cout<<"no"<<endl; else
		if (dy==kdy) cout<<"tie"<<endl;
		cin>>s;
	}
}
