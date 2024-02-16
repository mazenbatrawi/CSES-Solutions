#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
struct edge {
    int a, b, w;
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<edge> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].a >> v[i].b >> v[i].w;
        v[i].a -= 1, v[i].b -= 1;
    }
    vector<int> d(n);
    vector<int> p(n, -1);
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < m; j++) {
            if (d[v[j].b] > d[v[j].a] + v[j].w) {
                d[v[j].b] = d[v[j].a] + v[j].w;
                p[v[j].b] = v[j].a;
                x = v[j].b;
            }
        }
    }
    if (x == -1) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        x = p[x];
    }
    vector<int> cycle;
    for (int crnt = x; true; crnt = p[crnt]) {
        cycle.push_back(crnt);
        if (crnt == x && (int) cycle.size() > 1) {
            break;
        }
    }
    reverse(cycle.begin(), cycle.end());
    for (int x : cycle) {
        cout << ++x << ' ';
    }
    cout << '\n';
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
