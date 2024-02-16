#include<bits/stdc++.h>
 
using namespace std;
 
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solve(){
    long long n;
    cin >> n;
    const int MOD = 1e9 + 7;
    auto multiply = [&] (vector<vector<long long>> &a, vector<vector<long long>> &b) -> vector<vector<long long>> {
        vector<vector<long long>> c(2, vector<long long> (2, 0));
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    c[i][k] += a[i][j] * b[j][k];
                    c[i][k] %= MOD;
                }
            }
        }
        return c;
    };
    auto exp = [&] (vector<vector<long long>> &a) -> vector<vector<long long>> {
        vector<vector<long long>> res = {{1, 0}, {0, 1}};
        while(n){
            if(n & 1){
                res = multiply(res, a);
            }
            a = multiply(a, a);
            n /= 2;
        }
        return res;
    };
    vector<vector<long long>> a = {{0, 1}, {1, 1}};
    a = exp(a);
    cout << a[0][1] << '\n';
}
 
int main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
