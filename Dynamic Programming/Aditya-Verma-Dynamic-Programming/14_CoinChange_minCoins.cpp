// Question Link :- https://leetcode.com/problems/coin-change/description/
// Coin Change I

/*
Brute Force
arr = [9, 6, 5, 1]
target = 11
A Greedy solution will be to take the highest denomination coin first, so we will take an item on 
index 0, with a value of 9. Now the remaining target sum will be 2. Therefore we can only consider 
coins with a value of 1. We will take 2 coins of value 1 to meet the target. So a greedy solution 
gives us the answer 3 {9,1,1}.

Now we can clearly see that a non-greedy solution of taking 2 coins valued 6 and 5 will give us a 
better option. So we can say that the greedy solution doesn’t work for this problem. 

As the greedy approach doesn’t work, we will try to generate all possible combinations using 
recursion and select the combination which gives us the minimum number of coins.

*/

class Solution {
public:
    int dp[13][10005];
    int rec(int i, long long sum, vector<int>& coins, int amount){
        if(i == coins.size()){
            if(sum == amount) return 0;
            else return 1e9;
        }
        if(dp[i][sum] != -1) return dp[i][sum];

        int ans = 1e9;
        if(sum + coins[i] <= amount){
            ans = rec(i, sum + coins[i], coins, amount) + 1;
        }
        ans = min(ans, rec(i + 1, sum, coins, amount));

        return dp[i][sum] =  ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = rec(0, 0, coins, amount);
        if(ans == 1e9) ans = -1;
        return ans;
    }
};