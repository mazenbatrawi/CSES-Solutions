#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 2e5 + 5;
int n;
vector<vector<int>> a;
vector<pair<int, int>> v;
vector<int> dp;
 
int calc(int i){
    if(i == n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int ret = calc(i + 1);
    pair<int, int> p = {a[i][1] + 1, 0};
    int idx = lower_bound(v.begin(), v.end(), p) - v.begin();
    if(idx >= (int) v.size()){
        idx = n;
    }
    ret = max(ret, calc(idx) + a[i][2]);
    return dp[i] = ret;
}
 
void solve(){
    cin >> n;
    a = vector<vector<int>> (n, vector<int> (3));
    dp = vector<int> (n, -1);
    v = vector<pair<int, int>> (n);
    for(auto &V : a){
        for(auto &x : V){
            cin >> x;
        }
    }
    for(int i = 0; i < n; i++){
        v[i].first = a[i][0], v[i].second = a[i][1];
    }
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
    cout << calc(0) << '\n';
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
