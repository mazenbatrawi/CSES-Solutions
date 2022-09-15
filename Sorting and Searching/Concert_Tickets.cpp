#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        s.insert(x);
    }
    for(int i = 0, x; i < m; i++){
        cin >> x;
        auto it = s.upper_bound(x);
        if(it != s.begin()){
            it--;
        }
        if(it == s.end()){
            cout << -1 << '\n';
            continue;
        }
        if(*it <= x){
            cout << *it << '\n';
            s.erase(it);
        }
        else{
            cout << -1 << '\n';
        }
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