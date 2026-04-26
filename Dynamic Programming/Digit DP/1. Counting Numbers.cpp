// 1: https://cses.fi/problemset/task/2220
#include<bits/stdc++.h>
using namespace std;
 
#define fast {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define ll long long
#define endl '\n'
#define sz(x) (ll)(x).size()
 
ll dp[20][2][2][10];
 
ll rec(int i, bool tight, bool lz, int prev, string &s){
    if(i == s.size()) return 1;
 
    if(dp[i][tight][lz][prev] != -1) return dp[i][tight][lz][prev];
    
    int up = tight ? (s[i] - '0') : 9;
    ll ans = 0;
    for(int d = 0; d <= up; d++){
        if(d == prev and !lz) continue;
        ans += rec(i + 1, tight && (d == up), lz && (d == 0), d, s);
    }
    return dp[i][tight][lz][prev] = ans;
}
 
void Solve(){
    ll a, b; cin >> a >> b;
 
    string s = to_string(a - 1);
    memset(dp, -1, sizeof dp);
    ll l = rec(0, 1, 1, 0, s);
 
    s = to_string(b);
    memset(dp, -1, sizeof dp);
    ll r = rec(0, 1, 1, 0, s);
    
    cout << r - l << endl;
}
 
int main()
{   
    fast;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        Solve();
    }
    
    return 0;
}