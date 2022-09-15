#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    auto check = [&] (int time) -> bool {
        int made = 0;
        for(int i = 0; i < n; i++){
            made += time / a[i];
            if(made >= t){
                return 1;
            }
        }
        return 0;
    };
    int lo = 0, hi = 1e18 + 5;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << hi << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}