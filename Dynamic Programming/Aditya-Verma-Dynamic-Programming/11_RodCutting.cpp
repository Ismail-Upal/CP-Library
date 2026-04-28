// Note :- https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

// The first approach that comes to our mind is greedy. A greedy solution will fail in this problem 
// because there is no ‘uniformity’ in data. While selecting a local better choice we may choose an 
// item that will in long term give less value.

// As the greedy approach doesn’t work, we will try to generate all possible combinations using 
// recursion and select the combination which gives us the maximum value in the given constraints.


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