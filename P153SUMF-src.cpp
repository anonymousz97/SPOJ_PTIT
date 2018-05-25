#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
string s;
int n, d['z' + 1];

int ketQua()
{
	for (int i = 'A'; i <= 'Z'; i++)
	  if (d[i] == 0) return 0;
	return 1;	
}

main()
{
	cin >> n >> s;
	
	for (int i = 0; i < n; i++)
	  if (s[i] > 90) s[i] -= 32; 
	  
	for (int i = 'A'; i <= 'Z'; i++) d[i] = 0;
	
	for (int i = 0; i < n; i++) d[s[i]]++;
	
	if (ketQua()) cout << "YES"; else cout << "NO";
}