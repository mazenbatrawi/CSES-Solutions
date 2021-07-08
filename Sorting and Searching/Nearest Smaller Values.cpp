#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define inF freopen("input.txt", "r", stdin);
#define outF freopen("output.txt", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define ld long double
#define PI 3.141592653589793238463
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define int ll

#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#endif
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);

struct debug {
#ifdef LOCAL
~debug() { cerr << '\n'; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &A : a) cin >> A;
    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top().first >= a[i]) s.pop();
        if(s.empty()){
            cout << 0 << " ";
        }
        else{
            cout << s.top().second << " ";
        }
        s.push({a[i], i + 1});
    }
    cout << endl;
}

int32_t main(){
    FAST
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
