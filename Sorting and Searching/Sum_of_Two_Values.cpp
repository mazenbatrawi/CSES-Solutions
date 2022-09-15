#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    map<int, vector<int>> pos;
    for(int i = 0; i < n; i++){
        pos[a[i]].push_back(i + 1);
    }
    for(int i = 0; i < n; i++){
        int need = x - a[i];
        if(need == a[i]){
            if(sz(pos[need]) > 1){
                cout << pos[need][0] << ' ' << pos[need][1] << '\n';
                return;
            }
        }
        else{
            if(sz(pos[need]) > 0){
                cout << i + 1 << ' ' << pos[need][0] << '\n';
                return;
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