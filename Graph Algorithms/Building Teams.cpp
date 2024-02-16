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
    vector<int> side(n + 1, -1);
    bool is_bipartite = true;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(side[i] == -1){
            q.push(i);
            side[i] = 0;
            while(!q.empty()){
                int s = q.front();
                q.pop();
                for(int x : adj[s]){
                    if(side[x] == -1){
                        side[x] = side[s] ^ 1;
                        q.push(x);
                    }
                    else{
                        is_bipartite &= side[x] != side[s];
                    }
                }
            }
        }
    }
    if(!is_bipartite){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    output_vector(side, 1, 1);
}
 
int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
