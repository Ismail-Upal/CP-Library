// 2: https://leetcode.com/problems/number-of-digit-one/
using ll = long long;
class Solution {
public:
    ll dp[20][2][20];
    ll rec(int i, bool tight, ll cnt, string &s){
        if(i == s.size()) return cnt;
        if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];

        int up = tight ? (s[i] - '0') : 9;
        ll ans = 0;
        for(int d = 0; d <= up; d++){
            ans += rec(i + 1, tight && (d == up), cnt + (d == 1), s);
        }

        return dp[i][tight][cnt] = ans;
    }

    int countDigitOne(int n) {
        string r = to_string(n);
        memset(dp, -1, sizeof dp);
        return rec(0, 1, 0, r);
    }
};