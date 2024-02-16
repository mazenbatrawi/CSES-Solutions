#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> visited(N, 0);
 
bool dfs1(int s){
    visited[s] = 1;
    bool ret = 1;
    for(int x : adj[s]){
        if(visited[x] == 1){
            return 0;
        }
        else if(visited[x] == 0){
            ret &= dfs1(x);
        }
    }
    visited[s] = 2;
    return ret;
}
 
void dfs(int s){
    visited[s] = 1;
    for(int x : adj[s]){
        if(!visited[x]){
            dfs(x);
        }
    }
    cout << s << ' ';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    bool can = 1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            can &= dfs1(i);
        }
    }
    if(!can){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    visited = vector<int> (N, 0);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    cout << '\n';
    return 0;
}
