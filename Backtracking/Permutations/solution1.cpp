class Solution {
public:
    void solve(int index, int n, vector<int> input, vector<vector<int>> &res){
        if(index >= n){
            res.push_back(input);
            return;
        }
        for(int i = index; i < n; i++){
            swap(input[index], input[i]);
            solve(index + 1, n, input, res);
            swap(input[index], input[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        solve(0, n, nums, res);
        return res;
    }
};


// Time Complexity: O(n² · n!)

