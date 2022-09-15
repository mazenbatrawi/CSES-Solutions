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
    int crnt = -1e18 - 5, mx = 0;
    for(int i = 0; i < n; i++){
        mx += a[i];
        crnt = max(crnt, mx);
        if(mx < 0){
            mx = 0;
        }
    }
    cout << crnt << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}