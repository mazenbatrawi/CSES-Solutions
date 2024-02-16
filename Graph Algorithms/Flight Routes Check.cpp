#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
int32_t main(){
    FAST
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1][2];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    vector<int> visited(n + 1, 0);
    function<void(int, int)> dfs = [&] (int s, int i) {
        visited[s] = 1;
        for(int x : adj[s][i]){
            if(!visited[x]){
                dfs(x, i);
            }
        }
    };
    dfs(1, 0);
    bool ok = 1;
    int node = -1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ok = 0;
            node = i;
        }
    }
    if(!ok){
        cout << "NO" << '\n';
        cout << 1 << ' ' << node << '\n';
        return 0;
    }
    visited = vector<int> (n + 1, 0);
    dfs(1, 1);
    ok = 1;
    node = -1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ok = 0;
            node = i;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
    if(!ok){
        cout << node << ' ' << 1 << '\n';
    }
    return 0;
}
