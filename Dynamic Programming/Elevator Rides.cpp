#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    vector<pair<int, int>> dp(1LL << n, {n + 1, x + 1});
    dp[0] = {1, 0};
    for(int i = 0; i < (1LL << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1LL << j)){
                pair<int, int> last = dp[i ^ (1LL << j)];
                int num = last.first, w = last.second;
                if(w + a[j] <= x){
                    w += a[j];
                }
                else{
                    num += 1;
                    w = a[j];
                }
                dp[i] = min(dp[i], make_pair(num, w));
            }
        }
    }
    cout << dp[(1LL << n) - 1].first << '\n';
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
