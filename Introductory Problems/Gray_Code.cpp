#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

vector<string> get(int n){
    vector<string> v;
    if(n == 1){
        v.push_back("0");
        v.push_back("1");
        return v;
    }
    vector<string> v2 = get(n - 1);
    for(int i = 0; i < sz(v2); i++){
        v.push_back('0' + v2[i]);
    }
    for(int i = sz(v2) - 1; i >= 0; i--){
        v.push_back('1' + v2[i]);
    }
    return v;
}

void solve(){
    int n;
    cin >> n;
    vector<string> ans = get(n);
    for(string s : ans){
        cout << s << '\n';
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