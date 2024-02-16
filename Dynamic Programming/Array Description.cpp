#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int MOD = 1e9 + 7;
int n, m;
vector<int> a;
int dp[100005][205];
 
int calc(int i, int j){
    if(i == n){
        return 1;
    }
    if(a[i] != 0 && abs(j - a[i]) > 1){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ret = 0;
    if(j == 0){
        for(int k = 1; k <= m; k++){
            ret += calc(i + 1, k);
            ret %= MOD;
        }
    }
    else if(a[i] != 0){
        ret += calc(i + 1, a[i]);
        ret %= MOD;
    }
    else{
        for(int k = j - 1; k <= j + 1; k++){
            if(k <= 0 || k > m){
                continue;
            }
            ret += calc(i + 1, k);
            ret %= MOD;
        }
    }
    return dp[i][j] = ret;
}
 
void solve(){
    cin >> n >> m;
    a = vector<int> (n);
    for(auto &A : a){
        cin >> A;
    }
    memset(dp, -1, sizeof(dp));
    cout << calc(0, a[0]) << '\n';
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
