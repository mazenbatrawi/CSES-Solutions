#include<bits/stdc++.h>
 
using namespace std;
 
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for(auto &x : price) cin >> x;
    for(auto &x : pages) cin >> x;
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j - price[i] >= 0){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - price[i]] + pages[i]);
            }
        }
    }
    cout << dp[n][x] << '\n';
}
 
int main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
