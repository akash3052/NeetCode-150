class Solution {
public:
    void solve(vector<vector<int>> &alluniquesubsets, vector<int> &input, vector<int> &op, int index, int target){
        // Note -> Here, we are not checking index == input.size() because in the for loop it is already checked, we are running for loop till input.size(), so it index will not go beyond this.
        if(target==0){
            alluniquesubsets.push_back(op);
            return;
        }
        for(int i=index;i<input.size();i++){
            // Note -> Many times I did mistake of writing "index" instead of i. So, be careful about this.
            if(i>index and input[i] == input[i-1])
                continue;
            if(input[i] > target)
                break;
            op.push_back(input[i]);
            // Note -> In this recursive call also, I used index+1, instead of i+1. So, was getting wrong output.
            solve(alluniquesubsets, input, op, i+1, target-input[i]);
            op.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> alluniquesubsets;
        vector<int> op;
        int index=0;
        sort(candidates.begin(),candidates.end());
        solve(alluniquesubsets,candidates,op,index,target);
        return alluniquesubsets;
    }
};


Time Complexity:O(2^n*k)
Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). 
        we also add the op to our ans when we reach the base case that will take “k”//average space for the op.

Space Complexity:O(k*x)
Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
  
  
  
  
  
