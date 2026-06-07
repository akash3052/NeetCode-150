class Solution {
public:
    int solve(int i, int j, int m, int n, string word1, string word2, vector<vector<int>> &dp){
        if(i == m){
            return n - j;
        }
        if(j == n){
            return m - i;
        }
        int ans = 0;
        if(word1[i] == word2[j]){
            ans = solve(i + 1, j + 1, m, n, word1, word2, dp);
        }else{
            int insert = 1 + solve(i, j + 1, m, n, word1, word2, dp);
            int replace = 1 + solve(i + 1, j + 1, m, n, word1, word2, dp);
            int delet = 1 + solve(i + 1, j, m, n, word1, word2, dp);
            ans = min({insert, delet, replace});
        }
        return ans;
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, word1, word2, dp);
    }
};


// Time Complexity: O(3^(m+n)) (exponential)
// Space Complexity: O(m+n) (recursion stack depth)
