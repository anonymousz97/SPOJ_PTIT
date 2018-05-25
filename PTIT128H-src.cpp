#include <iostream>
#include <vector>
#include <string>
#define x first
#define y second
#define pb push_back
using namespace std;
int t, a[10][10];
typedef pair <int, int> viTri;
vector <int> v[10];
viTri vt[10];
int n, x[10];
int OK;

void Find()
{
	n = 0;
	for (int i = 1; i < 10; i++)
	  for (int j = 1; j < 10; j++)
	    if (!a[i][j])
		{
			n++;
			vt[n].x = i;
			vt[n].y = j;
		}
	// n = 5 trong ca qua trinh sau
}

void Chon(int k)
{
	int dd[10];
	for (int i = 1; i < 10; i++) dd[i] = 0;
	
	int xx = vt[k].x;
	for (int j = 1; j < 10; j++) dd[a[xx][j]] = 1;
	int yy = vt[k].y;
	for (int i = 1; i < 10; i++) dd[a[i][yy]] = 1;
	
	if (vt[k].x <= 3) xx = 1;
	else
	if (vt[k].x <= 6) xx = 4;
	else xx = 7;
	
	if (vt[k].y <= 3) yy = 1;
	else
	if (vt[k].y <= 6) yy = 4;
	else yy = 7;
	
	for (int i = xx; i < xx + 3; i++)
	  for (int j = yy; j < yy + 3; j++) dd[a[i][j]] = 1;
	
	for (int i = 1; i < 10; i++)
	  if (!dd[i]) v[k].pb(i);
	
}

void BuildVT()
{
	for (int i = 1; i <= 5; i++) v[i].clear();  // khoi tao lai Vector
	for (int i = 1; i <= n; i++) Chon(i); // tim cac kha nag cho moi vi tri i
}

int kiemTraNgang(int k)
{
	int i = vt[k].x;
	int dd[10];
	for (int j = 1; j < 10; j++) dd[j] = 0;
	for (int j = 1; j < 10; j++) dd[a[i][j]]++;
	for (int j = 1; j  < 10; j++)
	  if (dd[j] != 1) return 0;
	return 1;
}

int kiemTraDoc(int k)
{
	int j = vt[k].y;
	int dd[10];
	for (int i = 1; i < 10; i++) dd[i] = 0;
	for (int i = 1; i < 10; i++) dd[a[i][j]]++;
	for (int i = 1; i < 10; i++)
	  if (dd[i] != 1) return 0;
	return 1;
}

int kiemTraVuong(int k)
{
	int dd[10];
	for (int i = 1; i < 10; i++) dd[i] = 0;
	int xx, yy;
	if (vt[k].x <= 3) xx = 1;
	else
	if (vt[k].x <= 6) xx = 4;
	else xx = 7;
	
	if (vt[k].y <= 3) yy = 1;
	else
	if (vt[k].y <= 6) yy = 4;
	else yy = 7;
	
	for (int i = xx; i < xx + 3; i++)
	  for (int j = yy; j < yy + 3; j++) dd[a[i][j]]++;
	for (int i = 1; i < 10; i++)
	  if (dd[i] != 1) return 0;
	return 1;
}

void Update()
{
	for (int i = 1; i <= n; i++) a[vt[i].x][vt[i].y] = x[i];
	for (int i = 1; i <= n; i++)
	  if (kiemTraNgang(i) && kiemTraDoc(i) && kiemTraVuong(i))
	  {
	  	// do nothing
	  }
	  else return;
	OK = 1;
	return;
}

void Try(int i)
{
	for (int j = 0; j < v[i].size(); j++)
	{
		if (OK) return;
		int k = v[i][j];
		x[i] = k;
		if (i == n) Update();
		else Try(i + 1);
	}
}

void Process()
{
	OK = 0;
	Find(); // tim cac vi tri can dien;
	BuildVT(); // xay dung cac kha nang cho moi vi tri
	Try(1); //try x[1]
	if (!OK)
	{
		cout << "Could not complete this grid.";
		cout << endl;
		return;
	}
	for (int i = 1; i < 10; i++) // ghi ket qua
	{
	  for (int j = 1; j < 10; j++) cout << a[i][j];
	  cout << endl;
	}
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--)
	{
		string s;
		for (int i = 1; i < 10; i++)
		{
			cin >> s;
			s = "*" + s;
			for (int j = 1; j < 10; j++) a[i][j] = s[j] - '0';
		}
		Process();
		cout << endl;
	}
}