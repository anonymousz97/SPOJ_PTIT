#include <iostream>
#include <math.h>
using namespace std;
long long y, g, d, r, delta;
main()
{
cin >> g >> y;
delta = (g + 4) * (g + 4) / 4 - 4 * (y + g);
d = ((g + 4) / 2 + sqrt(delta)) / 2;
r = (y +g) / d;
cout << r << " " << d;
}
