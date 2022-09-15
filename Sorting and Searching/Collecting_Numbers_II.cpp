#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    vector<int> pos(n + 1, -1);
    for(int i = 0; i < n; i++){
        pos[a[i]] = i + 1;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++){
        ans += pos[i] < pos[i - 1];
    }
    while(q--){
        int i, j;
        cin >> i >> j;
        int x = a[i - 1], y = a[j - 1];
        set<pair<int, int>> s;
        if(x != 1){
            s.insert({x - 1, x});
        }
        if(x != n){
            s.insert({x, x + 1});
        }
        if(y != 1){
            s.insert({y - 1, y});
        }
        if(y != n){
            s.insert({y, y + 1});
        }
        for(auto p : s){
            ans += pos[p.first] < pos[p.second];
        }
        swap(pos[x], pos[y]);
        swap(a[i - 1], a[j - 1]);
        for(auto p : s){
            ans -= pos[p.first] < pos[p.second];
        }
        cout << ans << '\n';
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