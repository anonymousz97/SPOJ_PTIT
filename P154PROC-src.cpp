#include <iostream>
#include <string>
using namespace std;
int n, a[20];
main()
{
	cin >> n;
	a[1] = 4;
	for (int i = 2; i <= 11; i++) a[i] = 3;
	int k = 1;
	while (k <= 11)
	{
		a[k] = min(a[k], n);
		n -= a[k];
		k++;
	}
	cout << "+------------------------+" << endl;
	for (int i = 1; i <= 4; i++)
	{
		if (i == 3)
		{
		
		  if (a[1] > 0)
		  {
		  	cout << "|O.......................|" << endl;
		  	a[1]--;
		  }
		  else cout << "|#.......................|" << endl;
		}
		else	
		{
			cout << "|";
			for (int j = 1; j <= 11; j++) 
			  if (a[j] > 0)
			  {
			  	cout << "O.";
			  	a[j]--;
			  }
			  else cout << "#.";
			cout << "|";
			if (i == 1) cout << "D|"; else cout << ".|";
			if ((i == 1) || (i == 4)) cout << ")";
			cout << endl;
		}
	}
	cout << "+------------------------+";
}
