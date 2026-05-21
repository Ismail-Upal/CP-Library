// Question Link :- https://leetcode.com/problems/shortest-common-supersequence/
// Shortest Common Supersequence 

// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int dp[n + 1][m + 1];
        for(int j = 0; j <= m; j++) dp[n][j] = m - j;
        for(int i = 0; i <= n; i++) dp[i][m] = n - i;

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int ans;
                if(str1[i] == str2[j]){
                    ans = dp[i + 1][j + 1] + 1;
                }
                else ans = min(dp[i + 1][j], dp[i][j + 1]) + 1;
                dp[i][j] = ans;
            }
        }

        string ans = "";
        int i = 0, j = 0;
        while(i < n and j < m){
            if(str1[i] == str2[j]){
                ans += str1[i];
                i++, j++;
            }
            else if(dp[i + 1][j] < dp[i][j + 1]){
                ans += str1[i];
                i++;
            }
            else{
                ans += str2[j];
                j++;
            }
        }
        while(i < n) ans += str1[i++];
        while(j < m) ans += str2[j++];
        
        return ans;
    }
};