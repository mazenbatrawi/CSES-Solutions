#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int) v.size();
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    vector<int> ans(n, 0);
    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.push({a[i], i + 1});
            continue;
        }
        while(!s.empty() && a[i] <= s.top().first){
            s.pop();
        }
        if(!s.empty()){
            ans[i] = s.top().second;
        }
        s.push({a[i], i + 1});

    }
    output_vector(ans);
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}