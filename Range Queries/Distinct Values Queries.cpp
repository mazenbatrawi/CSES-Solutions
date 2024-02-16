#include<bits/stdc++.h>
 
using namespace std;
 
int block_size = (int) sqrt(200005) + 1;
 
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int) v.size();
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << '\n';
}
 
struct Query {
    int l, r, idx;
    bool operator<(Query other) const{
        if(l / block_size != other.l / block_size)
            return l < other.l;
        return l / block_size % 2 ? r < other.r : r > other.r;
    }
};
 
void solve(){
    int n, q;
    cin >> n >> q;
    block_size = (int) sqrt(n) + 1;
    vector<int> a(n);
    int ID = 0;
    map<int, int> id;
    for(auto &A : a){
        cin >> A;
        if(id.count(A)){
            A = id[A];
            continue;
        }
        id[A] = ID++;
        A = id[A];
    }
    vector<Query> query(q);
    for(int i = 0; i < q; i++){
        cin >> query[i].l >> query[i].r;
        query[i].l--, query[i].r--;
        query[i].idx = i;
    }
    sort(query.begin(), query.end());
    int l = 0, r = -1;
    vector<int> cnt(n + 5, 0);
    vector<int> answers(q, 0);
    int ans = 0;
    auto fix = [&](int i, int add){
        cnt[a[i]] += add;
        if(cnt[a[i]] == 1 && add == 1){
            ans += 1;
        }
        if(cnt[a[i]] == 0 && add == -1){
            ans -= 1;
        }
    };
    for(int i = 0; i < q; i++){
        while(l > query[i].l){
            fix(--l, +1);
        }
        while(l < query[i].l){
            fix(l++, -1);
        }
        while(r > query[i].r){
            fix(r--, -1);
        }
        while(r < query[i].r){
            fix(++r, +1);
        }
        answers[query[i].idx] = ans;
    }
    output_vector(answers);
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
