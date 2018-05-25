#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#define x first
#define y second
using namespace std;
int n;
string s;

main()
{
	cin >> s;
	n = s.length();
	s = "*" + s;
	for (int i = 1; i <= n; i++)
	  if (s[i] == 'r') cout << i << " ";
	for (int i = n; i > 0; i--)
	  if (s[i] == 'l') cout << i << " ";
}