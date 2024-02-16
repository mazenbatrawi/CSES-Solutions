#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
struct edge{
    int a, b, c;
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].c;
    }
    vector<int> cost(n + 1, -1e18 - 5);
    cost[1] = 0;
    set<int> seen;
    for(int i = 0; i < n; i++){
        for(auto e : edges){
            if(cost[e.a] != -1e18 -5 && cost[e.a] + e.c > cost[e.b]){
                cost[e.b] = cost[e.a] + e.c;
                if(i == n - 1){
                    seen.insert(e.b);
                }
            }
        }
    }
    vector<int> adj[n + 1];
    for(auto e : edges) adj[e.b].push_back(e.a);
    vector<bool> visited(n + 1, 0);
    bool ok = 0;
    function<void(int)> dfs = [&] (int s) {
        visited[s] = 1;
        ok |= seen.count(s);
        for(int x : adj[s]){
            if(!visited[x]) dfs(x);
        }
    };
    dfs(n);
    if(ok){
        cost[n] = -1;
    }
    cout << cost[n] << '\n';
}
 
int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
