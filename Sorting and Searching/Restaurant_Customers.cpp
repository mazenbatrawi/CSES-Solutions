#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n;
    cin >> n;
    set<vector<int>> s;
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        s.insert({a, 1});
        s.insert({b, -1});
    }
    int ans = 0;
    int crnt = 0;
    for(auto v : s){
        crnt += v[1];
        ans = max(ans, crnt);
    }
    cout << ans << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}