#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solve(){
    int n; cin >> n;
    vector<int> adj[n + 1];
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }
    vector<int> dp(n + 1, 0);
    vector<bool> visited(n + 1, 0);
    function<void(int)> dfs = [&] (int s){
        visited[s] = 1;
        dp[s] = 1;
        for(int x : adj[s]){
            if(!visited[x]){
                dfs(x);
            }
            dp[s] += dp[x];
        }
    };
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << --dp[i] << ' ';
    }
    cout << '\n';
}
 
int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
