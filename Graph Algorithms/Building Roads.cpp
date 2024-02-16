#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> visited(n + 1, 0);
    vector<int> v;
    function<void(int)> dfs = [&] (int s) {
        visited[s] = 1;
        v.push_back(s);
        for(int x : adj[s]){
            if(!visited[x]){
                dfs(x);
            }
        }
    };
    vector<vector<int>> comps;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            v.clear();
            dfs(i);
            comps.push_back(v);
        }
    }
    cout << sz(comps) - 1 << '\n';
    for(int i = 0; i < sz(comps) - 1; i++){
        cout << comps[i][0] << ' ' << comps[i + 1][0] << '\n';
    }
}
 
int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
