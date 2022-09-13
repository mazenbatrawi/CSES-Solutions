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
    vector<int> cnt(26, 0);
    for(char c : s){
        cnt[c - 'A'] += 1;
    }
    int odd = 0;
    int idx = -1;
    for(int i = 0; i < 26; i++){
        odd += (cnt[i] & 1);
        idx = (cnt[i] % 2 == 1 ? i : idx);
    }
    if(odd > 1){
        cout << "NO SOLUTION" << '\n';
        return;
    }
    string t = "";
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < cnt[i] / 2; j++){
            t += (char) (i + 'A');
        }
    }
    string ans = t;
    reverse(all(t));
    if(idx != -1){
        ans += (char) (idx + 'A');
    }
    ans += t;
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