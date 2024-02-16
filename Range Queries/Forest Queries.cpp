#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    for(auto &S : s){
        cin >> S;
    }
    vector<vector<int>> pre(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (s[i - 1][j - 1] == '*');
        }
    }
    auto get = [&](int x1, int y1, int x2, int y2){
        return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
    };
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << get(x1, y1, x2, y2) << '\n';
    }
    return 0;
}
