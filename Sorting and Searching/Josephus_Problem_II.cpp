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
    oset<int> s;
    for(int i = 1; i <= n; i++){
        s.insert(i);
    }
    int i = k % sz(s);
    while(sz(s)){
        int x = *s.find_by_order(i);
        cout << x << ' ';
        s.erase(s.find(x));
        i += k;
        if(sz(s)){
            i %= sz(s);
        }
    }
}

int main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}