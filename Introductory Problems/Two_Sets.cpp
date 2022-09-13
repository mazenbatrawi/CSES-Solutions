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
    if((n * (n + 1) / 2) & 1){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    int sum = n * (n + 1) / 4;
    set<int> s;
    int crnt = n;
    s.insert(crnt);
    for(int i = n - 1; i >= 1; i--){
        int left = sum - crnt;
        if(left > 0 && left <= n && s.find(left) == s.end()){
            s.insert(left);
            break;
        }
        if(left == 0){
            break;
        }
        s.insert(i);
        crnt += i;
    }
    cout << sz(s) << '\n';
    for(int x : s){
        cout << x << ' ';
    }
    cout << '\n';
    cout << n - sz(s) << '\n';
    for(int i = 1; i <= n; i++){
        if(s.find(i) == s.end()){
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}