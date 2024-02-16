#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
class SegTree {
    public:
        struct node{
            int val, idx;
        };
        vector<node> seg;
        void build(int p, int l, int r, vector<int> &a){
            if(l == r){
                seg[p].val = a[l];
                seg[p].idx = l + 1;
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m, a);
            build(2 * p + 1, m + 1, r, a);
            if(seg[2 * p].val > seg[2 * p + 1].val){
                seg[p] = seg[2 * p];
            }
            else{
                seg[p] = seg[2 * p + 1];
            }
        }
        void build(vector<int> &a){
            int n = sz(a);
            seg.resize(4 * n);
            build(1, 0, n - 1, a);
        }
        int query(int p, int l, int r, int need){
            if(seg[p].val < need){
                return 0;
            }
            if(l == r){
                seg[p].val -= need;
                return seg[p].idx;
            }
            int m = (l + r) / 2;
            if(seg[2 * p].val >= need){
                int idx = query(2 * p, l, m, need);
                if(seg[2 * p].val >= seg[2 * p + 1].val){
                    seg[p] = seg[2 * p];
                }
                else{
                    seg[p] = seg[2 * p + 1];
                }
                return idx;
            }
            if(seg[2 * p + 1].val >= need){
                int idx = query(2 * p + 1, m + 1, r, need);
                if(seg[2 * p].val >= seg[2 * p + 1].val){
                    seg[p] = seg[2 * p];
                }
                else{
                    seg[p] = seg[2 * p + 1];
                }
                return idx;
            }
            return 0;
        }
};
 
int32_t main(){
    FAST
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &A : a) cin >> A;
    SegTree tree;
    tree.build(a);
    while(m--){
        int x;
        cin >> x;
        cout << tree.query(1, 0, n - 1, x) << ' ';
    }
    cout << '\n';
    return 0;
}
