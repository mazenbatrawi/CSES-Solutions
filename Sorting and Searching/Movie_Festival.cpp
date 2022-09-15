#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

bool comp(array<int, 2> &a, array<int, 2> &b){
    return a[1] < b[1];
}

void solve(){
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(auto &v : a){
        cin >> v[0] >> v[1];
    }
    sort(all(a), comp);
    int ans = 0, last = 0;
    for(int i = 0; i < n; i++){
        if(a[i][0] >= last){
            ans += 1;
            last = a[i][1];
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