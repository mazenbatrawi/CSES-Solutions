#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define int int64_t
#define rep(n) for(ll i=0;i<n;i++)
#define rrep(n) for(ll i=n-1;i>=0;i--)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define coutArray(a,n) for(int i = 0; i < n; i++){cout << a[i] << " ";};cout << endl;
#define ld long double
#define PI 3.141592653589793238
#define srt(v) sort(v.begin(),v.end())
#define all(v) v.begin(), v.end()
 
const int N = 2e5 + 9;
int seg[4*N];
int a[N];
 
void build(int p, int s, int e){
    if(s == e){
        seg[p] = a[s];
        return;
    }
    build(2*p, s, (s+e)/2);
    build(2*p +1, (s+e)/2 +1, e);
    seg[p] = seg[2*p] + seg[2*p +1];
}
void update(int p, int s, int e, int i, int v){
    if(s == e){
        seg[p] += v - a[i];
        a[i] = v;
        return;
    }
    if(i <= (s+e)/2){
        update(2*p, s, (s+e)/2, i, v);
    }
    else if(i >= (s+e)/2 + 1){
        update(2*p +1, (s+e)/2 +1, e, i, v);
    }
    seg[p] = seg[2*p] + seg[2*p +1];
}
int get(int p, int s, int e, int a, int b){
    if(a > e || b < s){
        return 0;
    }
    if(a <= s && b >= e){
        return seg[p];
    }
    return get(2*p, s, (s+e)/2, a, b) + get(2*p +1, (s+e)/2 +1, e, a, b);
}
 
int32_t main(){
    FAST
    int t=1;
    //cin >> t;
    while(t--){
        int n,q; cin >> n >> q;
        for(int i = 0;i < n; i++){
            cin >> a[i];
        }
        build(1, 0, n-1);
        while(q--){
            int x,a,b; cin >> x >> a >> b;
            if(x == 1){
                a--;
                update(1, 0, n-1, a, b);
            }
            else{
                a--; b--;
                cout << get(1, 0, n-1, a, b) << endl;
            }
        }
    }
    return 0;
}
