#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
vector<int> parent, sz;
 
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
 
bool unite(int a, int b){
    a = find(a), b = find(b);
    if(a == b){
        return false;
    }
    if(sz[a] < sz[b]){
        swap(a, b);
    }
    sz[a] += sz[b];
    parent[b] = a;
    sz[b] = 0;
    return true;
}
 
int32_t main(){
    FAST
    int n, m;
    cin >> n >> m;
    parent = vector<int> (n + 1);
    sz = vector<int> (n + 1, 1);
    iota(all(parent), 0);
    vector<vector<int>> edges(m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }
    sort(all(edges));
    int ans = 0;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        if(unite(edges[i][1], edges[i][2])){
            ans += edges[i][0];
            adj[edges[i][1]].push_back(edges[i][2]);
            adj[edges[i][2]].push_back(edges[i][1]);
        }
    }
    vector<int> visited(n + 1, 0);
    function<void(int)> dfs = [&] (int s){
        visited[s] = 1;
        for(int x : adj[s]) if(!visited[x]) dfs(x);
    };
    dfs(1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
