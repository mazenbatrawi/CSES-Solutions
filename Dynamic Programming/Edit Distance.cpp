#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5005;
int dp[N][N];
string s, t;
int n, m;
 
int calc(int i, int j){
    if(j == m){
        return n - i;
    }
    if(i == n){
        return m - j;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ret = 1e9 + 5;
    if(s[i] == t[j]){
        ret = calc(i + 1, j + 1);
    }
    else{
        ret = min({calc(i + 1, j + 1), calc(i, j + 1), calc(i + 1, j)}) + 1;
    }
    return dp[i][j] = ret;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.size(); m = t.size();
    memset(dp, -1, sizeof(dp));
    cout << calc(0, 0) << '\n';
    return 0;
}
