#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n); for(auto &A : a) cin >> A;
    int s = 0, ans = 0;
    map<int, int> cnt;
    cnt[0] = 1;
    for(int i = 0; i < n; i++){
        s += a[i];
        ans += cnt[s - x];
        cnt[s] += 1;
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