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
    map<int, int> cnt;
    cnt[0] = 1;
    int s = 0;
    for(int x : a){
        s += x;
        s %= n;
        if(s < 0){
            s += n;
        }
        cnt[s] += 1;
    }
    int ans = 0;
    for(auto p : cnt){
        int x = p.second;
        ans += x * (x - 1) / 2;
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