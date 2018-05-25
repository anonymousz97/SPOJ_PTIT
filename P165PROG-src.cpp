#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define FILEIN freopen("in.txt", "r", stdin)
using namespace std;

string s;

int l;

bool Greater(string a, string b){
	if (a[0] == '-' && b[0] != '-') return false;
	if (a[0] != '-' && b[0] == '-') return true;
	if (a == b) return true;
	
	int l1 = a.length();
	int l2 = b.length();
	
	if (a[0] != '-' && b[0] != '-') {
		if (l1 > l2) return true;
		else
		if (l1 == l2 && a > b) return true;
		return false;
	}
	
	if (l1 > l2) return false;
		else
		if (l1 == l2 && a > b) return false;
	return true;
}

void Process(){
	if (Greater(s, "-128") && Greater("127", s)){
		cout << "byte";
		return;
	}
	if (Greater(s, "-32768") && Greater("32767", s)){
		cout << "short";
		return;
	}
	if (Greater(s, "-2147483648") && Greater("2147483647", s)){
		cout << "int";
		return;
	}
	if (Greater(s, "-9223372036854775808") && Greater("9223372036854775808", s)){
		cout << "long";
		return;
	}
	cout << "BigInteger";
}

int main(){
	cin >> s;
	Process();
}