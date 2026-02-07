class Solution {
public:
    void solve(int index, int n, vector<int> &input, vector<int> op, vector<vector<int>> &res){
        res.push_back(op);

        for(int i = index; i < n; i++){
            if(i > index && input[i] == input[i - 1]){
                continue;
            }
            // Note here : we are not using index anywhere, we are using i everywhere
            // using index just to iterate the for loop only
            op.push_back(input[i]);
            solve(i + 1, n, input, op, res);
            op.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> op;
        vector<vector<int>> res;
        solve(0, n, nums, op, res);
        return res;
    }
};


// Time Complexity: O(n · 2ⁿ)
// Reason (brief): the algorithm generates 2ⁿ subsets, and each subset takes up to O(n) time to build/store, with duplicates avoided during recursion (no set).
