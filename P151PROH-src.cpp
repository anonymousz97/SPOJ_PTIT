#include <iostream>
#include <string>
using namespace std;
string s;
int l;

int kiemTra()
{
	int d = 0;
	for (int i = 0; i < l; i++)
	  if (s[i] == '4')
	  {
	  	d++;
	  	if (d == 3) return 0;
	  }
	  else d = 0;
	return 1;
}

int ketQua()
{
	if (s[0] == '4') return 0;
	if (!kiemTra()) return 0;
	for (int i = 0; i < l; i++)
	  if ((s[i] != '1') && (s[i] != '4')) return 0;
	return 1;	
}

main()
{
	cin >> s;
	l = s.length();
	if (ketQua()) cout << "YES";
	else cout << "NO";
}
