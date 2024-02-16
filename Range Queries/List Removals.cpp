#include<bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &A : a){
        cin >> A;
    }
    for(auto &B : b){
        cin >> B;
    }
    ordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(i);
    }
    for(int i = 0; i < n; i++){
        b[i]--;
        int idx = *s.find_by_order(b[i]);
        s.erase(idx);
        cout << a[idx] << " \n"[i == n - 1];
    }
    cout << '\n';
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
