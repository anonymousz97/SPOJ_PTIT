#include <iostream>
#include <algorithm>
using namespace std;
long a[5], s;
int main()
{
for (long i = 1; i <= 4; i++) cin >> a[i];
sort(a + 1, a + 1 + 4);
s = a[1] * a[3];
cout << s;
}
