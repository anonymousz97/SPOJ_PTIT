#include <bits/stdc++.h>

#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FO(i, a, b) for (ll i = a; i < b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
#define pb push_back

using namespace std;

string s;
stack <int> st;

bool check(string s){
	while (!st.empty()) st.pop();
	int l = s.length();
	FO(i, 0, l){
		if (s[i] == '(') st.push(0);
		else if (s[i] == '[') st.push(1);
		else if (s[i] == ')') {
			if (!st.empty() && st.top() == 0) st.pop();
			else return 0;
		}
		else if (s[i] == ']') {
			if (!st.empty() && st.top() == 1) st.pop();
			else return 0;
		}
	}
	if (st.empty()) return 1;
	return 0;
}

int main(){
//	FILEIN;
	while (getline(cin, s) && s != "."){
		if (check(s)) cout << "yes"; else cout << "no";
		cout << endl;
	}
}