#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int x, n;
    cin >> x >> n;
    set<int> st;
    st.insert(0);
    st.insert(x);
    auto comp = [&] (pair<int, int> a, pair<int, int> b) -> bool {
        return abs(a.second - a.first) > abs(b.second - b.first);
    };
    multiset<pair<int, int>, decltype(comp)> s(comp);
    s.insert({0, x});
    for(int i = 0; i < n; i++){
        int y;
        cin >> y;
        auto it = st.lower_bound(y);
        auto after = it;
        it--;
        auto before = it;
        s.erase(s.find({*before, *after}));
        s.insert({*before, y});
        s.insert({y, *after});
        st.insert(y);
        auto p = *s.begin();
        cout << p.second - p.first << ' ';
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