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
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    if(n == 2 || n == 3){
        cout << "NO SOLUTION" << '\n';
        return;
    }
    for(int i = 2; i <= n; i += 2){
        cout << i << ' ';
    }
    for(int i = 1; i <= n; i += 2){
        cout << i << ' ';
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