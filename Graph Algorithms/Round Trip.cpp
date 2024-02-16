#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int) v.size();
    cout << end << '\n';
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
 
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
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, 0);
    int st = -1, en = -1;
    function<bool(int, int)> dfs = [&] (int s, int p) -> bool {
        visited[s] = 1;
        for(int x : adj[s]){
            if(x == p){
                continue;
            }
            if(visited[x]){
                st = x, en = s;
                return true;
            }
            parent[x] = s;
            if(dfs(x, s)){
                return true;
            }
        }
        return false;
    };
    for(int i = 1; i <= n; i++){
        if(!visited[i] && dfs(i, parent[i])){
            break;
        }
    }
    if(st != -1){
        vector<int> ans;
        ans.push_back(st);
        while(en != st){
            ans.push_back(en);
            en = parent[en];
        }
        ans.push_back(st);
        output_vector(ans);
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
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
