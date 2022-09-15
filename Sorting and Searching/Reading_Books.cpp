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
    sort(all(a));
    if(a[n - 1] > accumulate(all(a), 0LL) - a[n - 1]){
        cout << 2 * a[n - 1] << '\n';
    }
    else{
        cout << accumulate(all(a), 0LL) << '\n';
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