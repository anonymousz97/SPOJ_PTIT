#include <iostream>
#include <algorithm>
#define nmax 1000006
#define x first
#define y second
using namespace std;
typedef pair <int, int> record;
int n, t;
record a[nmax], b[nmax];

void input(record a[])
{
	int k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x;
		a[i].y = i;
	}	
	sort(a + 1, a + 1 + n);
}

void Process()
{
	cout << "Case " << t << ": ";
	for (int i = n; i > 0; i--)
	  if (a[i].y != b[i].y)
	  {
	  	cout << (n - i + 1) << endl;
	  	return;
	  }
	cout << "agree" << endl;
}

main()
{
	t = 0;
//	freopen("in.txt", "r", stdin);
	while (cin >> n)
	{
		t++;
		input(a);
		input(b);
		Process();
	}
}