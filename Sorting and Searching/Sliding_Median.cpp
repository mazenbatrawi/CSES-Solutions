#include<bits/stdc++.h>

using namespace std;

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    oset<pair<int, int>> s;
    for(int i = 0; i < k - 1; i++){
        s.insert({a[i], i});
    }
    for(int i = k - 1; i < n; i++){
        if(i != k - 1){
            s.erase(s.find({a[i - k], i - k}));
        }
        s.insert({a[i], i});
        auto p = *s.find_by_order((k - 1) / 2);
        cout << p.first << ' ';
    }
    cout << '\n';
}

int main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}