// 3: https://leetcode.com/problems/numbers-with-repeated-digits
using ll = long long;
class Solution {
public:
    ll dp[10][2][2][2][1 << 10];
    ll rec(int i, bool tight, bool lz, bool ok, int mask, string &s){
        if(i == s.size()) return ok;

        if(dp[i][tight][lz][ok][mask] != -1) return dp[i][tight][lz][ok][mask];

        int up = tight ? (s[i] - '0') : 9;
        ll ans = 0;
        for(int d = 0; d <= up; d++){
            if(lz){
                if(d == 0) ans += rec(i + 1, tight && (d == up), 1, 0, 0, s);
                else ans += rec(i + 1, tight && (d == up), 0, 0, mask | (1 << d), s);
            }
            else ans += rec(i + 1, tight && (d == up), 0, ok || (mask & (1 << d)), mask | (1 << d), s); 
        }

        return dp[i][tight][lz][ok][mask] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string r = to_string(n);
        memset(dp, -1, sizeof dp);
        return rec(0, 1, 1, 0, 0, r);
    }
};