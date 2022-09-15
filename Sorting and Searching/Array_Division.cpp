#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    auto check = [&] (int m) -> bool {
        int s = 0, cnt = 1;
        for(int i = 0; i < n; i++){
            s += a[i];
            if(a[i] > m){
                return 0;
            }
            if(s > m){
                s = a[i];
                cnt += 1;
            }
        }
        return cnt <= k;
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