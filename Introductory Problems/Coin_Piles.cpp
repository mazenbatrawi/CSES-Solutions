#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int a, b;
    cin >> a >> b;
    if(a > b){
        swap(a, b);
    }
    if(a + b == 0){
        cout << "YES" << '\n';
        return;
    }
    if(a == 0 || b == 0){
        cout << "NO" << '\n';
        return;
    }
    cout << ((a + b) % 3 == 0 && b <= 2 * a ? "YES" : "NO") << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}