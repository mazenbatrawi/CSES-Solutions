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
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    map<int, int> cnt;
    int ans = 1;
    int p1 = 0, p2 = 0;
    int add = 1;
    while(p2 < n){
        while(p2 < n && cnt[a[p2]] == 0){
            cnt[a[p2]] += 1;
            p2 += 1;
        }
        ans = max(ans, p2 - p1);
        while(p2 < n && cnt[a[p2]] > 0){
            cnt[a[p1]] -= 1;
            p1 += 1;
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