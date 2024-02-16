#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> color, parent, cycle;
int st = -1, en = -1;
 
bool dfs(int s){
    color[s] = 1;
    for(int x : adj[s]){
        if(color[x] == 0){
            parent[x] = s;
            if(dfs(x)){
                return 1;
            }
        } 
        else if(color[x] == 1){
            st = x, en = s;
            return 1;
        }
    }
    color[s] = 2;
    return 0;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    parent.assign(n + 1, -1);
    color.assign(n + 1, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0 && dfs(i)){
            break;
        }
    }
    if(st == -1){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    cycle.push_back(st);
    while(en != st){
        cycle.push_back(en);
        en = parent[en];
    }
    cycle.push_back(st);
    reverse(cycle.begin(), cycle.end());
    cout << (int) cycle.size() << '\n';
    for(int x : cycle){
        cout << x << ' ';
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
