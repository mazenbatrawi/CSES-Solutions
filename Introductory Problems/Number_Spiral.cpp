#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int x, y;
    cin >> x >> y;
    if(x + y == 2){
        cout << 1 << '\n';
        return;
    }
    if(y > x){
        int range = (y % 2 == 1 ? y * y : (y - 1) * (y - 1) + 1);
        if(y & 1){
            cout << range - x + 1 << '\n';
        }
        else{
            cout << range + x - 1 << '\n';
        }
    }
    else{
        int range = (x % 2 == 0 ? x * x : (x - 1) * (x - 1) + 1);
        if(x & 1){
            cout << range + y - 1 << '\n';
        }
        else{
            cout << range - y + 1 << '\n';
        }
        
    }
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