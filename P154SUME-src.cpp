#include <iostream>
#include <string>
using namespace std;
long n, m;
string s[101];

long ok(long i, long j)
{
    for (long k = 0; k < i; k++)
     if ((s[k][j] > s[i][j]) && (s[k] > s[i]))
     {
        for (long q = 0; q < m; q++) s[q][j] = s[i][j];
        return 0;
     }
    return 1;   
}

long ketQua()
{
    long res = 0;
    if (m == 1) return 0;
    for (long j = 0; j < n; j++)
    {
        for (long i = 1; i < m; i++)
         if (!ok(i, j))
         {
            res++;
            break;
         }
    }
    return res;
}
main()
{
    cin >> m >> n;
    for (long i = 0; i < m; i++) cin >> s[i];
    cout << ketQua();
}
