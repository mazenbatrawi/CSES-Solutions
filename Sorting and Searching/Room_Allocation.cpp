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
    vector<vector<int>> a;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, 1, i});
        a.push_back({y + 1, -1, i});
    }
    sort(all(a));
    vector<int> ans(n);
    set<int> has;
    int num = 0;
    for(int i = 0; i < sz(a); i++){
        if(a[i][1] == 1){
            if(has.empty()){
                ans[a[i][2]] = ++num;
            }
            else{
                ans[a[i][2]] = *has.begin();
                has.erase(has.begin());
            }
        }
        else{
            has.insert(ans[a[i][2]]);
        }
    }
    cout << num << '\n';
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