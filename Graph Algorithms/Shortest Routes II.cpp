#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    ll dp[n + 1][n + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = 1e18 + 5;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = dp[a][b] = min({dp[b][a], dp[a][b], (ll) c});
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[j][i] = min({dp[j][i], dp[i][j], dp[i][k] + dp[k][j]});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == 1e18 + 5) dp[i][j] = -1;
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << dp[u][v] << '\n';
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
