// Question Link :- https://leetcode.com/problems/coin-change-ii/description/
// Coin Change max no. of ways (Coin Change II)

// Similar to [06_count of subset with given sum.cpp]

// T.C = O(n*amount)
// S.C = O(n)

// Approach - 1 (Recursion + Memoization)
class Solution {
public:
    int dp[304][5005];
    int rec(int i, int sum, int amount, vector<int> &coins){
        if(i == coins.size()){
            if(sum == amount) return 1;
            else return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];

        int ans = 0;
        if(sum + coins[i] <= amount){
            ans = rec(i, sum + coins[i], amount, coins);
        }
        ans = ans + rec(i + 1, sum, amount, coins);

        return dp[i][sum] = ans;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, amount, coins);    
    }
};