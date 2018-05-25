#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FILEIN freopen("in.txt", "r", stdin)
#define fi first
#define se second
 
using namespace std;
 
int a[105][105] = {0};
int n;
string s;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
bool check(){
	FOR(i, 1, n){
		FOR(j, 1, n){
			int d = 0;
			FOR(k, 0, 3){
				int x = i + dx[k];
				int y = j + dy[k];
				d += a[x][y];
			}
			if (d % 2) return false;
		}
	}
	return true;
}
 
int main(){
//	FILEIN;
	cin >> n;
	FOR(i, 1, n){
		cin >> s;
		s = "*" + s;
		FOR(j, 1, s.length()){
			if (s[j] == 'o') a[i][j] = 1;
		}
	}
	if (check()) cout << "YES"; else cout << "NO";
}