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
    vector<int> a(n);
    for(auto &A : a){
        cin >> A;
    }
    if(k == 1){
        for(int i = 0; i < n - k + 1; i++){
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }
    multiset<int> lower, upper;
    int sum_lower = 0, sum_upper = 0;
    auto ins = [&] (int x){
        int y = *lower.rbegin();
        if(x > y){
            upper.insert(x);
            sum_upper += x;
            if(sz(upper) > k / 2){
                lower.insert(*upper.begin());
                sum_lower += *upper.begin();
                sum_upper -= *upper.begin();
                upper.erase(upper.begin());
            }
        }
        else{
            lower.insert(x);
            sum_lower += x;
            if(sz(lower) > (k + 1) / 2){
                upper.insert(*lower.rbegin());
                sum_lower -= *lower.rbegin();
                sum_upper += *lower.rbegin();
                auto it = lower.end();
                it--;
                lower.erase(it);
            }
        }
    };
    auto del = [&] (int x){
        if(lower.find(x) != lower.end()){
            sum_lower -= x;
            lower.erase(lower.find(x));
        }
        else{
            sum_upper -= x;
            upper.erase(upper.find(x));
        }
        if(sz(lower) == 0){
            sum_upper -= *upper.begin();
            sum_lower += *upper.begin();
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
    };
    lower.insert(a[0]);
    sum_lower += a[0];
    for(int i = 1; i < k; i++){
        ins(a[i]);
    }
    cout << sum_upper - sum_lower + (k & 1) * (*lower.rbegin()) << ' ';
    for(int i = k; i < n; i++){
        del(a[i - k]);
        ins(a[i]);
        cout << sum_upper - sum_lower + (k & 1) * (*lower.rbegin()) << ' ';
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