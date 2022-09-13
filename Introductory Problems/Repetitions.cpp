#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    string s;
    cin >> s;
    int n = sz(s);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 1;
        i += 1;
        while(i < n && s[i] == s[i - 1]){
            cnt += 1;
            i += 1;
        }
        i -= 1;
        ans = max(ans, cnt);
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