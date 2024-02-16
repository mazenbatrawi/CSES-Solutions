#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
vector<int> adj[100005];
int n;
int dp[100005];
const int MOD = 1e9 + 7;
 
int calc(int x){
    if(x == n){
        return 1;
    }
    if(dp[x] != -1){
        return dp[x];
    }
    int ret = 0;
    for(int s : adj[x]){
        ret += calc(s);
        ret %= MOD;
    }
    return dp[x] = ret;
}
 
int32_t main(){
    FAST
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    cout << calc(1) << '\n';
    return 0;
}
