#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    sort(all(a));
    int ans = 0, p1 = 0, p2 = n - 1;
    while(p1 <= p2){
        if(p1 == p2){
            ans += 1;
            break;
        }
        if(a[p1] + a[p2] > x){
            ans += 1;
            p2 -= 1;
        }
        else{
            ans += 1;
            p1 += 1;
            p2 -= 1;
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