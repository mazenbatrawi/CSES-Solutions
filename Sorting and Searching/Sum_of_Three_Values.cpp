#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n); for(auto &A : a) cin >> A;
    map<int, vector<int>> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]].push_back(i);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int left = x - a[i] - a[j];
            int t = 0;
            if(!cnt.count(left)){
                continue;
            }
            for(int y : cnt[left]){
                if(y != i && y != j){
                    cout << i + 1 << ' ' << j + 1 << ' ' << y + 1 << '\n';
                    return;
                }
                t++;
                if(t == 4){
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