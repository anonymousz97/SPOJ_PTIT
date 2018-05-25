#include <iostream>
#include <string>
using namespace std;
string s, t;
int ds['z' + 1], dt['z' + 1];
int res = 0;

void Init()
{
	for (int i = 'a'; i <= 'z'; i++)
	{
		ds[i] = 0;
		dt[i] = 0;
	}
	for (int i = 0; i < s.length(); i++) ds[s[i]]++;	
	for (int i = 0; i < t.length(); i++) dt[t[i]]++;
}

void Process()
{
	if (s.find(t) >= 0 && s.find(t) < s.length())
	{
		res = 1;
		return;
	}
	if (s.length() == t.length())
	{
		for (int i = 'a'; i <= 'z'; i++)
		  if (ds[i] != dt[i]) return;
		res = 2;
		return;
	}
	for (int i = 'a'; i <= 'z'; i++)
	  if (ds[i] < dt[i]) return;
	int i = 0, j = 0;
	while (i < s.length() && j < t.length())
	{
		while (i < s.length() && s[i] != t[j]) i++;
		if (i < s.length())
		{
			i++;
			j++;
			if (j == t.length())
			{
				res = 1;
				return;
			}
		}
	}
	res = 3;
	return;
}

main()
{
	cin >> s >> t;
	Init();
	Process();
	if (!res) cout << "need tree";
	else
	if (res == 1) cout << "automaton";
	else
	if (res == 2) cout << "array";
	else cout << "both";
}
