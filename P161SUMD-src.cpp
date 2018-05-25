#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
using namespace std;
 
int c, a[6][6], b[6][6], cx[6][6] = {0};
 
void GHI(){
	FOR(i, 1, 4){
		FOR(j, 1, 4) cout << a[i][j] << " ";
		cout << endl;
	}
}
 
void Nap(){
	FOR(i, 1, 4){
		FOR(j, 1, 4) a[i][j] = b[i][j];
	}
}
 
void Left(){
	FOR(i, 1, 4){
		FOR(k, 1, 4) b[k][i] = a[i][4 - k + 1];
	}
	Nap();
}
 
void Right(){
	FOR(i, 1, 4){
		FOR(k, 1, 4) b[k][4 - i + 1] = a[i][k];
	}
	Nap();
}
 
void quayBang(){
	FOR(i, 1, c) Left();
//	GHI();
}
 
void Process(){
	FOR(i, 0, 4) a[i][0] = -1;
	int vt;
	FOR(i, 1, 4){
		vt = 0;
		FOR(j, 2, 4){
			int pos= j;
			while (!a[i][pos - 1]){
				swap(a[i][pos], a[i][pos - 1]);
				pos--;
			}
			if (a[i][pos] == a[i][pos - 1] && !cx[i][pos - 1]){
				a[i][pos - 1] *= 2;
				cx[i][pos - 1] = 1;
				a[i][pos] = 0;
			}
		}
	}
}
 
void TraLai(){
	FOR(i, 1, c) Right();
	GHI();
}
 
int main(){
	
//	freopen("in.txt", "r", stdin);
	char ch;
	cin >> ch;
	if (ch == 'L') c = 0;
	else if (ch == 'U') c = 1;
	else if (ch == 'R') c = 2;
	else if (ch == 'D') c = 3;
	 
	FOR(i, 1, 4){
		FOR(j, 1, 4) cin >> a[i][j];
	}
	
	quayBang();
	
	Process();
	
	TraLai();
} 