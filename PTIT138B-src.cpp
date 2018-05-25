#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long n, thuTu = 0;
struct banGhi
{
	string cha;
	string con;
	long cl;
};
banGhi khaiSinh[101];
long t;

long bfs()
{
	thuTu++;
	string q[101];
	long tuoi[101];
	long l, r;
	q[1] = "Ted";
	tuoi[1] = 100;
	l = 1; r = 1;
	do
	{
		string s = q[l];
		long t = tuoi[l];
		l++;
		for (long i = 1; i <= n; i++)
		  if (khaiSinh[i].cha == s)
		  {
		  	r++;
		  	q[r] = khaiSinh[i].con;
		  	tuoi[r] = t - khaiSinh[i].cl;
		  }
	}
	while (l <= r);
	for (long i = r - 1; i >= 1; i--)
	  for (long j = 1; j <= i; j++)
	    if ((tuoi[j] < tuoi[j + 1]) || ((tuoi[j] == tuoi[j + 1]) && (q[j] > q[j + 1])))
	    {
	    	swap(tuoi[j], tuoi[j + 1]);
	    	swap(q[j], q[j + 1]);
	    }
	cout << "DATASET " << thuTu << endl;
	for (long i = 2; i <= r; i++) cout << q[i] << " " << tuoi[i] << endl; 
}
main()
{
	cin >> t;
	for (long q = 1; q <= t; q++)
	{
		cin >> n;
		for (long i = 1; i <= n; i++) cin >> khaiSinh[i].cha >> khaiSinh[i].con >> khaiSinh[i].cl;
		bfs();
	}
}