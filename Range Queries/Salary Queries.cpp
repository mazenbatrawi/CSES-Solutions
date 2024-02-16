#include<bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
void solve(){
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(auto &A : a){
        cin >> A;
    }
    ordered_set<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        s.insert(make_pair(a[i], i));
    }
    while(q--){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == '!'){
            s.erase(make_pair(a[x - 1], x - 1));
            a[x - 1] = y;
            s.insert(make_pair(y, x - 1));
        }
        else{
            cout << s.order_of_key(make_pair(y + 1, -1)) - s.order_of_key(make_pair(x, -1)) << '\n';
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
