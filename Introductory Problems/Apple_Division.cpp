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
    int ans = 1e18 + 5;
    for(int i = 0; i < (1LL << n); i++){
        int x = 0, y = 0;
        for(int j = 0; j < n; j++){
            if(i & (1LL << j)){
                x += a[j];
            }
            else{
                y += a[j];
            }
        }
        ans = min(ans, abs(x - y));
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