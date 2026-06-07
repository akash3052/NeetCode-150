class Solution {
public:
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j == t.size()){
            return 1;
        }

        if(i >= s.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int take = 0;
        if(s[i] == t[j]){
            take = solve(i + 1, j + 1, s, t, dp);
        }
        int notTake = solve(i + 1, j, s, t, dp);
        return dp[i][j] = take + notTake;
    }

    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, s, t, dp);
    }
};


// Time Complexity: O(n × m) (each state (i, j) is computed once)
// Space Complexity: O(n × m) for DP + O(n) recursion stack, which simplifies to O(n × m).
