#include <iostream>
#include <string>
using namespace std;
string s, res = "";
int main()
{
cin >> s;
while (s.length() % 3 != 0) s = "0" + s;
long l = s.length();
long t = l / 3 + 1;
long p = l - 3; 
string ss;
long cs; 
while (p >= 0)
{
ss = s.substr(p, 3);
if (ss == "000") cs = 0;
else if (ss == "001") cs = 1;
else if (ss == "010") cs = 2;
else if (ss == "011") cs = 3;
else if (ss == "100") cs = 4;
else if (ss == "101") cs = 5;
else if (ss == "110") cs = 6;
else if (ss == "111") cs = 7;
res = char (cs + 48) + res;
p-=3;
}
while (res[0] == '0') res.erase(0, 1);
if (res == "") res = "0";
cout << res;
}
