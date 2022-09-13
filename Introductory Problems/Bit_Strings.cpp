#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int MOD = 1e9 + 7;

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
    int n;
    cin >> n;
    cout << fastpow(2LL, n) << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}