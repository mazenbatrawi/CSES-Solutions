#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    sort(all(a));
    multiset<int> s;
    for(int i = 0, x; i < m; i++){
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = a[i] - k;
        auto it = s.lower_bound(x);
        if(it == s.end()){
            continue;
        }
        int y = *it;
        if(abs(a[i] - y) <= k){
            s.erase(it);
            ans += 1;
        }
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