#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)

#define pb push_back

using namespace std;

int c, k;

string s, ctrl, a[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"}, res = "";

char real(char x){
	FO(i, 0, 3){
		FO(j, 0, a[i].length()){
			if (a[i][j] == x) {
				if (j + k == a[i].length()) return a[i][0];
				else
				if (j + k == -1) return a[i][a[i].length() - 1];
				else return a[i][j + k];
			}
		}
	}
}

void process(){
	
	if (ctrl == "L") k = 1;
	else if (ctrl == "R") k = -1;
	
	FO(i, 0, s.length()){
		res += real(s[i]); 
	}
}

int main(){
	cin >> ctrl >> s;
	process();
	cout << res;
}