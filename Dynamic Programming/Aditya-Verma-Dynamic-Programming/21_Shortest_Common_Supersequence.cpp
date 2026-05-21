// Question Link :- https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// Shortest Common Supersequence

// T.C = O(m*n)
// S.C = O(m*n)

// Approach - 1 (Memoization)
class Solution {
  public:
  
    int dp[505][505];
    int rec(int i, int j, string &s1, string &s2){
        if(i == s1.size()) return s2.size() - j;
        if(j == s2.size()) return s1.size() - i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(s1[i] != s2[j]){
            ans = min(rec(i + 1, j, s1, s2), rec(i, j + 1, s1, s2)) + 1;
        }
        else ans = rec(i + 1, j + 1, s1, s2) + 1;
        
        return dp[i][j] = ans;
    }
  
    int minSuperSeq(string &s1, string &s2) {
        memset(dp, -1, sizeof dp);
        int len = rec(0, 0, s1, s2);
        return len;
    }
};



// Approach - 2 (Tabulation)
class Solution {
  public:
  
    int minSuperSeq(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        int dp[n + 1][m + 1];
        for(int j = 0; j <= m; j++) dp[n][j] = m - j;
        for(int i = 0; i <= n; i++) dp[i][m] = n - i;
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int ans;
                if(s1[i] != s2[j]){
                    ans = min(dp[i + 1][j], dp[i][j + 1]) + 1;
                }
                else ans = dp[i + 1][j + 1] + 1;
                
                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }
};