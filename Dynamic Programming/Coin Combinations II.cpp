#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    const int MOD = 1e9 + 7;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - a[i] >= 0){
                dp[j] += dp[j - a[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}
 
int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
