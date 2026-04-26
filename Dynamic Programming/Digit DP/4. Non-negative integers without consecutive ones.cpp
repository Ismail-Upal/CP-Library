// 4: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones
using ll = long long;
class Solution {
public: 
    ll dp[33][2][2][2];

    ll rec(int i, bool tight, bool lz, int prev, string &s){
        if(i == s.size()) return 1;

        if(dp[i][tight][lz][prev] != -1) return dp[i][tight][lz][prev];

        int up = tight ? (s[i] - '0') : 1;
        ll ans = 0;
        for(int d = 0; d <= up; d++){
            if(lz){
                ans += rec(i + 1, tight && (d == up), lz && (d == 0), d, s);
            }
            else{
                if(d == 1 and d == prev) continue;
                ans += rec(i + 1, tight && (d == up), 0, d, s);
            }
        }
        return dp[i][tight][lz][prev] = ans;
    }

    int findIntegers(int n) {
        string s = bitset<32> (n).to_string();
        memset(dp, -1, sizeof dp);
        return rec(0, 1, 1, 0, s);
    }
};