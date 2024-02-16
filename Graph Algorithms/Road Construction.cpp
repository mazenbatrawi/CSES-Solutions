#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
vector<int> parent, sz;
int mx = 1;
 
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
 
bool unite(int a, int b){
    a = find(a), b = find(b);
    if(a == b){
        return false;
    }
    if(sz[a] < sz[b]){
        swap(a, b);
    }
    sz[a] += sz[b];
    mx = max(mx, sz[a]);
    parent[b] = a;
    sz[b] = 0;
    return true;
}
 
int32_t main(){
    FAST
    int n, m;
    cin >> n >> m;
    parent = vector<int> (n + 1);
    sz = vector<int> (n + 1, 1);
    iota(all(parent), 0);
    int comps = n;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(unite(a, b)){
            comps -= 1;
        }
        cout << comps << ' ' << mx << '\n';
    }
    return 0;
}
