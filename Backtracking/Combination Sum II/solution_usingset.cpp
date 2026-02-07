class Solution {
public:

    void solve(int index, int n, vector<int> &input, vector<int> op, int target, set<vector<int>> &res){
        if(index >= n){
            if(target == 0){
                res.insert(op);
            }
            return;
        }
        if(input[index] <= target){
            op.push_back(input[index]);
            solve(index + 1, n, input, op, target - input[index], res);
            op.pop_back();
        }
        solve(index + 1, n, input, op, target, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        set<vector<int>> uniqueSubsets;
        vector<int> op;
        int n = candidates.size();
        solve(0, n, candidates, op, target, uniqueSubsets);
        for(auto op : uniqueSubsets){
            res.push_back(op);
        }
        return res;
    }
};


// Time Complexity: O(n² · 2ⁿ)

// Cost of this insert:
// Comparing vectors in a set takes O(k), where k = size of the vector.
// Set insert takes O(log M), where M = number of unique combinations.

// In the worst case, the number of combinations can be exponential.
// So, each insert ≈ O(k · log(2ⁿ)) = O(k · n).
// And this happens for many nodes.
