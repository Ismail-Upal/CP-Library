// Question Link :- https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// Longest Common Substring

// Notes:- https://www.geeksforgeeks.org/longest-common-substring-dp-29/

// T.C = O(n*m)
// S.C = O(n*m)

// IMPORTANT - in this question the final answer could be anywhere in the matrix, not always in
//             t[n][m] last row col. So that's why we ar using ans variable to stroe the max value.


class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int dp[n + 3][m + 3]; memset(dp, 0, sizeof dp);
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else dp[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};