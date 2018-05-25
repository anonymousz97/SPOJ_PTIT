#include <iostream>
#include <algorithm>
using namespace std;
long a[5], b[5], t;
long x[4], cx[5], cs[5];
long val;
long st[1000001], top = 0;
long kiemTra(long u, long v, long num)	// kiem tra chia het neu co phep chia
{
	if (v == 0) return 0;
	if (u % v != 0) return 0;
	return 1;
}

long phepTinh(long u, long v, long num) // tinh toan
{
	if (num == 1) return (u + v);
	else if (num == 2) return (u - v);
	else if (num == 3) return (u * v);
	return (u / v);
}

long tinh3so(long a, long b, long c, long p, long q)
{
	long s;
	if (p >= 3)
	{
		if ((p == 4) && !kiemTra(a, b, 4)) return 101010101;
		long u = phepTinh(a, b, p);
		if ((q == 4) && !kiemTra(u, c, 4)) return 101010101;
		s = phepTinh(u, c, q);
	} 
	else
	if (q >= 3)
	{
		if ((q == 4) && !kiemTra(b, c, q)) return 101010101;
		long u = phepTinh(b, c, q);
		if ((p == 4) && !kiemTra(a, u, p)) return 101010101;
		s = phepTinh(a, u, p);
	}
	else
	{
		if ((p == 4) && !kiemTra(a, b, 4)) return 101010101;
		long u = phepTinh(a, b, p);
		if ((q == 4) && !kiemTra(u, c, 4)) return 101010101;
		s = phepTinh(u, c, q);
	}
	return s;
}

// __________________________________________TRUONG HOP 0_______________________________________________________________
long tinh0()
{
	long st[10], dau[10], t = 1;
	st[t] = a[1]; 
	for (long i = 1; i <= 3; i++)
	{
		if (x[i] <= 2)
		{
			t++;
			st[t] = a[i + 1];
			dau[t - 1] = x[i];
		}
		else
		{
			if ((x[i] == 4) && !kiemTra(st[t], a[i + 1], 4)) return 101010101;
			st[t] = phepTinh(st[t], a[i + 1], x[i]);
		}
	}
	long s = st[1];
	for (long i = 2; i <= t; i++) s = phepTinh(s, st[i], dau[i - 1]);
	return s;
}

long truongHop0()
{
	long kt = 1;
	if ((x[1] == 4) && !kiemTra(a[1], a[2], 4)) kt = 0;
	else
	if ((x[2] == 4) && !kiemTra(a[2], a[3], 4)) kt = 0;
	else 
	if ((x[3] == 4) && !kiemTra(a[3], a[4], 4)) kt = 0;
	
	if (!kt) return 0;
	else
	{
		val = tinh0();
		if (val == 101010101) return 0;
		return 1;
	}
}
//____________________________________________DONE! TRUONG HOP 0____________________________________________________________________



// ___________________________________________TRUONG HOP 121________________________________________________________________________
long truongHop121()
{
	if ((x[2] == 4) && !kiemTra(a[2], a[3], 4)) return 0;
	val = phepTinh(a[2], a[3], x[2]);
	if ((x[1] == 4) && !kiemTra(a[1], val, 4)) return 0;
	if ((x[3] == 4) && !kiemTra(val, a[4], 4)) return 0;
	val = tinh3so(a[1], val, a[4], x[1], x[3]);
	if (val == 101010101) return 0;
	return 1;
}
//___________________________________________DONE! TRUONG HOP 121__________________________________________________________________



//___________________________________________TRUONG HOP 22_________________________________________________________________________
long truongHop22()
{
	if ((x[1] == 4) && !kiemTra(a[1], a[2], 4)) return 0;
	long p = phepTinh(a[1], a[2], x[1]);
	if ((x[3] == 4) && !kiemTra(a[3], a[4], 4)) return 0;
	long q = phepTinh(a[3], a[4], x[3]);
	if ((x[2] == 4) && !kiemTra(p, q, 4)) return 0;
	val = phepTinh(p, q, x[2]);
	return 1;
}
//__________________________________________DONE! TRUONG HOP 22____________________________________________________________________


//__________________________________________TRUONG HOP 13__________________________________________________________________________
long truongHop13()
{
	if ((x[2] == 4) && !kiemTra(a[2], a[3], 4)) return 0;
	if ((x[3] == 4) && !kiemTra(a[3], a[4], 4)) return 0;
	val = tinh3so(a[2], a[3], a[4], x[2], x[3]);
	if (val == 101010101) return 0;
	if ((x[1] == 4) && !kiemTra(a[1], val, 4)) return 0;
	val = phepTinh(a[1], val, x[1]);
	return 1;
}
//__________________________________________DONE! TH 13____________________________________________________________________________




//__________________________________________TRUONG HOP 31__________________________________________________________________________
long truongHop31()
{
	if ((x[1] == 4) && !kiemTra(a[1], a[2], 4)) return 0;
	if ((x[2] == 4) && !kiemTra(a[2], a[3], 4)) return 0;
	val = tinh3so(a[1], a[2], a[3], x[1], x[2]);
	if (val == 101010101) return 0;
	if ((x[3] == 4) && !kiemTra(val, a[4], 4)) return 0;
	val = phepTinh(val, a[4], x[3]);
	return 1;
}
//__________________________________________DONE!__________________________________________________________________________________

long truongHop112()
{
	if ((x[3] == 4) && !kiemTra(a[3], a[4], 4)) return 0;
	val = phepTinh(a[3], a[4], x[3]);
	val = tinh3so(a[1], a[2], val, x[1], x[2]);
	if (val == 101010101) return 0;
	return 1;
}

long truongHop211()
{
	if ((x[1] == 4) && !kiemTra(a[1], a[2], 4)) return 0;
	val = phepTinh(a[1], a[2], x[1]);
	val = tinh3so(val, a[3], a[4], x[2], x[3]);
	if (val == 101010101) return 0;
	return 1;	
}

void xuli()				//___________________VAL: voi moi kha nang xay ra => co duoc mot KETQUA____________________________________
{
	if (truongHop0()) 
	{
		top++;
		st[top] = val;
	}
	if (truongHop13())
	{
		top++;
		st[top] = val;
	}
	if (truongHop22())
	{
		top++;
		st[top] = val;
	}
	if (truongHop31())
	{
		top++;
		st[top] = val;
	}
	if (truongHop121())
	{
		top++;
		st[top] = val;
	}
	if (truongHop211())
	{
		top++;
		st[top] = val;
	}
	if (truongHop112())
	{
		top++;
		st[top] = val;
	}
}

void Try(long i)	//_____________________________________xet tat ca kha nang co the xay ra______________________________
{
	for (long j = 1; j <= 4; j++)
	{
		x[i] = j;
		if (i == 3) xuli();
		else Try(i + 1);
	}	
}

void hoanvi()
{
	for (long i = 1; i <= 4; i++)
	{
		a[i] = b[cs[i]];
		//cout << a[i] << " ";
	}
	//cout << endl;
	Try(1);
}

void TryHV(long i)
{
	for (long j = 1; j <= 4; j++)
	  if (cx[j])
	  {
	  	cs[i] = j;
	  	cx[j] = 0;
	  	if (i == 4) hoanvi(); else TryHV(i + 1);
	  	cx[j] = 1;
	  }
}

main()				//_____________________________________CHUONG TRINH CHINH: MAIN________________________________________
{
	t = 0;
	for (long i = 1; i < 5; i++) cin >> b[i];
	while (b[1] != 0)
	{
		t++;
		top = 0;
		for (long i = 1; i <= 4; i++) cx[i] = 1;
		//for (long i = 23; i <= 31; i++) xh[i] = 0;
		TryHV(1);
		sort(st + 1, st + 1 + top);
		//for (long i = 1; i <= top; i++) cout << st[i] << " ";
		//cout << endl;
		st[top + 1] = st[top] + 100;
		long d = 1, c = 1, rd = 0, rc = 0;
		for (long i = 2; i <= top + 1; i++)
		if (st[i] != st[i - 1])
		{
			if (st[i] == st[i - 1] + 1) c = i;
			else
			{
				if (st[c] - st[d] + 1 >= st[rc] - st[rd] + 1)
				{
					rd = d;
					rc = c;
				}
				d = i; c = i;
			}
		}
		cout << "Case " << t << ": " << st[rd] << " to " << st[rc] << endl;
		for (long i = 1; i < 5; i++) cin >> b[i];
	}
}