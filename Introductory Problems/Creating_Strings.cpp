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
    vector<string> ans;
    sort(all(s));
    do{
        ans.push_back(s);
    } while(next_permutation(all(s)));
    cout << sz(ans) << '\n';
    for(auto S : ans){
        cout << S << '\n';
    }
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}