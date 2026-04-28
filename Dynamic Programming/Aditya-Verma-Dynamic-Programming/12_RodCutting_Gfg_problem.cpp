// Question Link :- https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// Rod Cutting

// T.C = O(N^2)
// S.C = O(N)

// Approach - 1

class Solution {
  public:
    int dp[1004][1004];
    int rec(int i, int len, vector<int> &price){
        if(i == price.size() or len == price.size()) return 0;
        if(dp[i][len] != -1) return dp[i][len];
        
        int ans = 0;
        if(len + i + 1 <= price.size()){
            ans = rec(i, len + i + 1, price) + price[i];
        }
        ans = max(ans, rec(i + 1, len, price));
        
        return dp[i][len] = ans;
    }
    
    int cutRod(vector<int> &price) {
        int n = price.size();
        memset(dp, -1, sizeof dp);
        return rec(0, 0, price);
    }
};