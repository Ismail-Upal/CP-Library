// Question Link :- https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// Minimum number of deletions and insertions

// T.C = O(n*m)
// S.C = O(n*m)
class Solution {

  public:
    int dp[1003][1003];
    int rec(int i, int j, string &s1, string &s2){
        if(i == s1.size()) return s2.size() - j;
        if(j == s2.size()) return s1.size() - i;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(s1[i] != s2[j]){
            ans = min(rec(i + 1, j, s1, s2), rec(i, j + 1, s1, s2)) + 1;
        }
        else ans = rec(i + 1, j + 1, s1, s2);
        
        return dp[i][j] = ans;
    }
  
    int minOperations(string &s1, string &s2) {
        memset(dp, -1, sizeof dp);
        int len = rec(0, 0, s1, s2);
        return len;
    }
};


// Input :-
// heap
// pea

// Output :-
// 3 (deletions = 2 + insertions = 1)
