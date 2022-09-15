#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(auto &A : a) cin >> A;
    map<int, vector<pair<int, int>>> cnt;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            cnt[a[i] + a[j]].push_back({i, j});
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int s = x - a[i] - a[j];
            if(!cnt.count(s)) continue;
            int t = 0;
            for(auto p : cnt[s]){
                int x = p.first, y = p.second;
                if(x != i && y != i && x != j && y != j){
                    cout << i + 1 << ' ' << j + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
                    return;
                }
                t += 1;
                if(t == 6){
                    break;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}