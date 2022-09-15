#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(auto &A : a){
        cin >> A.first >> A.second;
    }
    auto comp = [&] (pair<int, int> &p1, pair<int, int> &p2) -> bool {
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    };
    sort(all(a), comp);
    multiset<int> endings;
    for(int i = 0; i < k; i++){
        endings.insert(0);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = endings.upper_bound(a[i].first);
        if(it == endings.begin()) continue;
        it--;
        endings.erase(it);
        endings.insert(a[i].second);
        ans += 1;
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