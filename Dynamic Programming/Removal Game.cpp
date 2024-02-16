#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
const int N = 5001;
vector<vector<int>> dp;
vector<int> a;
int n;
 
int calc(int i, int j){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int turn = (i - 0) + (n - 1 - j);
    turn %= 2;
    if(turn){
        return dp[i][j] = min(calc(i + 1, j) - a[i] , calc(i, j - 1) - a[j]);
    }
    return dp[i][j] = max(calc(i + 1, j) + a[i], calc(i, j - 1) + a[j]);
}
 
void solve(){
    cin >> n;
    a.resize(n);
    for(auto &A : a){
        cin >> A;
    }
    dp = vector<vector<int>> (n, vector<int> (n, -1));
    int ans = calc(0, n - 1);
    cout << (ans + accumulate(a.begin(), a.end(), 0LL)) / 2 << '\n';
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
