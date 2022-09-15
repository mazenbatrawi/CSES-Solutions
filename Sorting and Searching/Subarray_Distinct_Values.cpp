#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for(auto &A : a) cin >> A;
    set<int> s;
    multiset<int> ms;
    int ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        s.insert(a[i]);
        ms.insert(a[i]);
        while(j < n && sz(s) > k){
            ms.erase(ms.find(a[j]));
            if(ms.find(a[j]) == ms.end()){
                s.erase(s.find(a[j]));
            }
            j += 1;
        }
        if(sz(s) <= k) ans += sz(ms);
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