class Solution {
public:
    vector<int> delx = {0, 0, 1, -1};
    vector<int> dely = {1, -1, 0, 0};

    bool isValid(int i, int j, int row, int col){
        if(i < 0 || j <0 || i >= row || j >= col){
            return false;
        }
        return true;
    }

    int solve(int i, int j, int row, int col, vector<vector<int>> &dp, vector<vector<int>> &matrix){
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int res = 1;
        for(int k = 0; k < 4; k++){
            int newi = i + delx[k];
            int newj = j + dely[k];
            if(isValid(newi, newj, row, col) && matrix[newi][newj] > matrix[i][j]){
                res = max(res, 1 + solve(newi, newj, row, col, dp, matrix));
            }
        }
        return dp[i][j] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        int maxPathLength = 0; 
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                maxPathLength = max(maxPathLength, solve(i, j, row, col, dp, matrix)); 
            }
        }
        return maxPathLength;
    }
};


// Time Complexity: O(m × n), Space Complexity: O(m × n).





