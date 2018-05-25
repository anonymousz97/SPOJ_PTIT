#include<iostream>
using namespace std;
char s[255];
long p1,p2,l;

long mm(char s[255])
{
	for (long i=0;i<=l-1;i++)
	 {
	 	int x= int (s[i]) -48;
	 	if ((x!=4)&&(x!=7)) return 0;
	 	
	 }
	p1=0; p2=0;
	for (long i=0;i<=l/2-1;i++) p1=p1+int (s[i]) -48;
	for (long i=l/2;i<=(l-1);i++) p2=p2+ int (s[i]) -48;
	if (p1==p2) return 1; else return 0;
}

main()
{
	cin>>l>>s;
	if (mm(s)) cout<<"YES";
	else cout<<"NO";
}