#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007
using namespace std;
int main(){
    FAST
    int n; cin >> n;
    if(n==2 || n==3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    vector<int>vecodd;
    vector<int>veceven;
    for(int i=0;i<n;i++){
        if((i+1)%2!=0){
            vecodd.pb(i+1);
        }
        else{
            veceven.pb(i+1);
        }
    }
    if(n==4){
       for(int i=0;i<veceven.size();i++){
        cout << veceven[i] << " ";
    }
    for(int i=0;i<vecodd.size();i++){
        cout << vecodd[i] << " ";
    }
    return 0;
    }
    for(int i=0;i<vecodd.size();i++){
        cout << vecodd[i] << " ";
    }
    for(int i=0;i<veceven.size();i++){
        cout << veceven[i] << " ";
    }
 
 
    return 0;
}
