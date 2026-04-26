// 6: https://leetcode.com/problems/count-of-integers
using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
public:
    ll dp[25][2][410];

    ll rec(int i, bool tight, int sum, string &s, int min_sum, int max_sum){
        if(i == s.size()){
            return (min_sum <= sum and sum <= max_sum);
        }

        if(dp[i][tight][sum] != -1) return dp[i][tight][sum];

        int up = tight ? (s[i] - '0') : 9;
        ll ans = 0;
        for(int d = 0; d <= up; d++){
            if(sum + d <= max_sum){
                ans += rec(i + 1, tight && (d == up), sum + d, s, min_sum, max_sum);
                ans %= mod;
            }
        }
        return dp[i][tight][sum] = ans;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp, -1, sizeof dp);
        ll r = rec(0, 1, 0, num2, min_sum, max_sum);
   
        for(int i = num1.size() - 1, k = 1; i >= 0; i--){
            int j = num1[i] - '0';
            if(j >= k) num1[i] = (j - k) + '0', k = 0; 
            else num1[i] = '9', k = 1;
        } 
        memset(dp, -1, sizeof dp);
        ll l = rec(0, 1, 0, num1, min_sum, max_sum);
        return ((r % mod) - (l % mod) + mod) % mod;
    }
};