#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int h, m, s, t, faster;
int ord;
string s1, s2, x;
int ho1, mi1, se1, ti1;
int rs, rm, rh, rt;

void tachXau(string s)
{
	string x[5];
	x[1] = s.substr(0, s.find(":"));
	s.erase(0, x[1].length() + 1);
	x[2] = s.substr(0, 2);
	x[3] = s.substr(3, 2);
	x[4] = s.substr(6, 3);
//	for (int i = 1; i <= 4; i++) cout << x[i] << " ";
	
	ho1 = 0;
	for (int i = 0; i < x[1].length(); i++) ho1 = ho1 * 10 + (x[1][i] - '0');
	mi1 = 0;
	for (int i = 0; i < x[2].length(); i++) mi1 = mi1 * 10 + (x[2][i] - '0');
	se1 = 0;
	for (int i = 0; i < x[3].length(); i++) se1 = se1 * 10 + (x[3][i] - '0');
	ti1 = 0;
	for (int i = 0; i < x[4].length(); i++) ti1 = ti1 * 10 + (x[4][i] - '0');
	
//	cout << ho1 << " " << mi1 << " " << se1 << " " << ti1 << " ";
	
}

void cong()
{
	int nho = 0;
	rh = -1; rm = -1; rs = -1; rt = -1;
	
	rt = (ti1 + t) % 1000;
	nho = (ti1 + t) / 1000;
	rs = (se1 + s + nho) % 60;
	nho = (se1 + s + nho) / 60;
	rm = (mi1 + m + nho) % 60;
	nho = (mi1 + m + nho) / 60;
	rh = ho1 + h + nho;
}

void tru()
{
	int nho = 0;
	rh = -1; rm = -1; rs = -1; rt = -1;
	
	rt = ti1 - t;
	if (rt < 0)
	{
		rt += 1000;
		nho = 1;
	}
	else nho = 0;
	rs = se1 - s - nho;
	if (rs < 0)
	{
		rs += 60;
		nho = 1;
	}
	else nho = 0;
	rm = mi1 - m - nho;
	if (rm < 0)
	{
		rm += 60;
		nho = 1;
	}
	else nho = 0;
	rh = ho1 - h - nho;
}

void Process(string s1)
{
	tachXau(s1); // lay ho1, mi1, se1, ti1;
	if (faster) cong();
	else tru();
	if (rh < 10 && rh >= 0) cout << 0;
	cout << rh << ":";
	if (rm < 10) cout << 0;
	cout << rm << ":";
	if (rs < 10) cout << 0;
	cout << rs << ",";
	if (rt < 10) cout << "00";
	else
	if (rt < 100) cout << 0;
	cout << rt;
}

main()
{
//	freopen("in.txt", "r", stdin);
	cin >> h >> m >> s >> t >> x;
	if (x == "faster") faster = 1;
	else faster = 0;
	while (cin >> ord)
	{
		cout << ord << endl;
		string muiTen;
		cin >> s1 >> muiTen >> s2;
		Process(s1);
		cout << " --> ";
		Process(s2); 
		cout << endl;
		cin.ignore();
		string ss;
		do
		{
			getline(cin, ss);
			int l = ss.length();
			cout << ss << endl;
		}
		while (ss != "");
	}
}
