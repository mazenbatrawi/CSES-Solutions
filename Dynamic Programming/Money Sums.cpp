#include<bits/stdc++.h>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.out", "w", stdout);
#define pb push_back
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define int long long
 
const int N = 105, S = 100 * 1000 + 5;
int dp[N][S];
int n;
int a[N];
set<int> s;
 
int calc(int i, int sum){
    s.insert(sum);
    if(i == n){
        return 0;
    }
    if(dp[i][sum] != -1){
        return dp[i][sum];
    }
    return dp[i][sum] = calc(i + 1, sum) + calc(i + 1, sum + a[i]);
}
 
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    int x = calc(0, 0);
    s.erase(s.begin());
    cout << sz(s) << '\n';
    for(int y : s){
        cout << y << ' ';
    }
    cout << '\n';
}
 
int32_t main(){
    FAST
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
