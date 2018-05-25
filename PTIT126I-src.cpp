#include<iostream>
#include<string>
using namespace std;
string a,b;
long m,n,x,y;

void ghib( long n)
{
		for (long i = 0; i < x ; i++) cout << ".";
		cout << b[n];
		for (long i = x + 1; i < m; i++) cout << ".";
		cout << endl;	
}

main()
{
	cin >> a >> b;
	m = a.length();
	n = b.length();
	int c = 0;
	for (long i = 0; i < m ; i++)
	  if (c) break;
	  else
	  {
	  	for (long j = 0; j < n ; j++)
	  	  if (a[i] == b[j]) 
	  	  {
	  	  	x = i;
	  	  	y = j;
	  	  	c = 1;
	  	  	break;
	  	  }
	  }
	for (long i = 0; i < y; i++) ghib(i);
	cout << a << endl;
	for (long i = y + 1; i < n; i++) ghib(i);
}