#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pb push_back

using namespace std;
const ll MAX = 100005;

ll n, a[MAX], b[MAX], d[MAX], p[MAX], cx[MAX];
ll res;
vector <ll> ke[MAX];
queue <ll> q;

void BFS(){
    memset(p, 0, sizeof(p));
    memset(d, 0, sizeof(d));
    for (ll i = 0; i <= n; i++) cx[i] = 1;

    q.push(1);
    cx[1] = 0;

    while (!q.empty()){
        ll u = q.front();
        ll real_u = a[u];
        if (d[p[p[u]]] % 2) real_u = 1 - a[u];
        if (real_u != b[u]) d[u] = 1;
        else d[u] = 0;
        res += d[u];
        d[u] += d[p[p[u]]];
        q.pop();
        for (ll i = 0; i < ke[u].size(); i++){
            ll v = ke[u][i];
            if (cx[v] && !p[v]){
                cx[v] = 0;
                p[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
//    freopen("in.txt", "r", stdin);
    cin >> n;
    ll x, y;
    for (ll i = 1; i < n; i++){
        cin >> x >> y;
        ke[x].pb(y);
        ke[y].pb(x);
    }
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) cin >> b[i];

    res = 0;

    BFS();

    cout << res;
}
