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
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    multiset<int> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = s.upper_bound(a[i]);
        if(it == s.end()){
            ans += 1;
            s.insert(a[i]);
            continue;
        }
        s.erase(it);
        s.insert(a[i]);
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