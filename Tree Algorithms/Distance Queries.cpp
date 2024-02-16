#include<bits/stdc++.h>
 
using namespace std;
 
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
const int N = 2e5 + 5;
const int LOG = 20;
vector<int> adj[N];
int up[N][LOG], in[N], depth[N];
bool visited[N];
 
void dfs(int s){
    visited[s] = 1;
    for(int x : adj[s]){
        if(!visited[x]){
            depth[x] = depth[s] + 1;
            up[x][0] = s;
            for(int i = 1; i < LOG; i++){
                up[x][i] = up[up[x][i - 1]][i - 1];
            }
            dfs(x);
        }
    }
}
 
int get_ans(int a, int b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    int ans = k;
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)){
            a = up[a][i];
        }
    }
    if(a == b){
        return ans;
    }
    ans += 2;
    for(int i = LOG - 1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            ans += 2 * (1 << i);
            a = up[a][i], b = up[b][i];
        }
    }
    return ans;
}
 
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    while(q--){
        int a, b;
        cin >> a >> b, a--, b--;
        cout << get_ans(a, b) << '\n';
    }
}
 
int main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
