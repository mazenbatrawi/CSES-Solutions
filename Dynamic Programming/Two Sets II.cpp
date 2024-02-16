#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 501, M = 125251;
const int MOD = 1e9 + 7;
int dp[N][M];
int n;
 
int calc(int i, int one){
    if(one > n * (n + 1) / 4){
        return 0;
    }
    if(i == n + 1){
        return one == (n * (n + 1) / 4);
    }
    if(dp[i][one] != -1){
        return dp[i][one];
    }
    int ret = calc(i + 1, one + i) % MOD;
    ret += calc(i + 1, one);
    ret %= MOD;
    return dp[i][one] = ret;
}
 
int fastpow(int v,  int p){
    if (p == 0){
        return 1;
    }
    if (p == 1){
        return v;
    }
    int ans = fastpow(v, p / 2);
    ans *= ans;
    ans %= MOD;
    if (p & 1){
        return (ans * v) % MOD;
    }
    return ans;
}
 
void solve(){
    cin >> n;
    if((n * (n + 1)) % 4){
        cout << 0 << '\n';
        return;
    }
    memset(dp, -1, sizeof(dp));
    int ans = calc(1, 0);
    ans *= fastpow(2, MOD - 2);
    ans %= MOD;
    cout << ans << '\n';
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
