// 5: https://leetcode.com/problems/numbers-at-most-n-given-digit-set
using ll = long long;
class Solution {
public:
    ll dp[20][2][2];

    ll rec(int i, bool tight, bool lz, string &s, vector<string> &digits){
        if(i == s.size()) return !lz;

        if(dp[i][tight][lz] != -1) return dp[i][tight][lz];

        int up = tight ? (s[i] - '0') : 9;
        ll ans = 0;
        if(lz){
            ans += rec(i + 1, tight && (0 == up), 1, s, digits);
        }
        for(auto j : digits){
            int d = stoi(j);
            if(d > up) break;
            ans += rec(i + 1, tight && (d == up), lz && (d == 0), s, digits);
        }
        return dp[i][tight][lz] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof dp);
        return rec(0, 1, 1, s, digits);
    }
};