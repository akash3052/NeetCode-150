class Solution {
public:
    void solve(int index, int n, vector<int> &input, vector<int> op, set<vector<int>> &res){
        if(index >= n){
            res.insert(op);
            return;
        }

        op.push_back(input[index]);
        solve(index + 1, n, input, op, res);
        op.pop_back();
        solve(index + 1, n, input, op, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> op;
        set<vector<int>> res;
        solve(0, n, nums, op, res);
        
        vector<vector<int>> uniqueSubsets;
        for(auto op : res){
            uniqueSubsets.push_back(op);
        }
        return uniqueSubsets;
    }
};


// Time Complexity: O(n² · 2ⁿ)
// Reason (brief): the recursion generates 2ⁿ subsets, and each insertion into set<vector<int>> costs O(k · log(2ⁿ)) = O(n²) in the worst case (vector comparison + tree insert).
