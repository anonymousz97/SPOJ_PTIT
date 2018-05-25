#include <iostream>
#include <string>
using namespace std;
string s;

long dem(char k)
{
    long x = long (k) - 48;
    if (x == 0) return 2;
    if (x == 1) return 7;
    if (x == 2) return 2;
    if (x == 3) return 3;
    if (x == 4) return 3;
    if (x == 5) return 4;
    if (x == 6) return 2;
    if (x == 7) return 5;
    if (x == 8) return 1;
    if (x == 9) return 2;
}

main()
{
    cin >> s;
    long a = dem(s[0]);
    long b = dem(s[1]);
    cout << (a * b);
}
