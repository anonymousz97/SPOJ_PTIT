#include <iostream>
using namespace std;

int Process(int n)
{
	int a[200][200], t[200];
	for (int i = 1; i <= n; i++) t[i] = 0;
	
	for (int i = 1; i <= n; i++)
	  for (int j = 1; j <= n; j++) cin >> a[i][j];
	  
	for (int i = 1; i <= n; i++)
	  if (!t[i])
	  {
	  	t[i] = 1;
	  	for (int j = i + 1; j <= n; j++)
	  	  if (a[i][j]) t[j] = 2;
	  }
	  else
	  {
	  	for (int j = 1; j <= n; j++)
	  	  if (a[i][j])
	  	  {
	  	  	if (t[i] == t[j]) return 0;
	  	  }
	  }
	  return 1;
}

main()
{
	int n;
	while (cin >> n && n)
	{
	 if (Process(n)) cout << "YES";
	 else cout << "NO";
	 cout << endl;
	}
}
