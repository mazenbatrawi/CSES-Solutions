#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define coutArray(a,n) for(int i = 0; i < n; i++){cout << a[i] << " ";};cout << endl;
#define pb push_back
using namespace std;
int main(){
    FAST
    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string>v;
    do{
        v.pb(s);
    }
    while(next_permutation(s.begin(),s.end()));
    int n = (int)v.size();
    cout << n << endl;
    for(int i=0;i<n;i++){
        cout << v[i] << endl;
    }
    return 0;
}
