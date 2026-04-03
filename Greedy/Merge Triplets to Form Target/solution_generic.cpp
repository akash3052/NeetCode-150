class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> found;

        for(auto triplet : triplets){
            bool isValid = true;
            // skipping invalid triplets
            for(int i = 0; i < target.size(); i++){
                if(triplet[i] > target[i]){
                    isValid = false;
                    break;
                }
            }

            if(!isValid){
                continue;
            }

            // in valid triplets, we are checking if target[0], target[1] and...target[n] is present or not
            // if present, we are storing its index in found 
            // we are storing index because if target[0] will be present in multiple templates -> then we should count it as 1 only
            // at last, we are checking if we are able to find all the target values or not [found.size() == target.size()]
            for(int i = 0; i < target.size(); i++){
                if(triplet[i] == target[i]){
                    found.insert(i);
                }
            }
        }

        return found.size() == target.size();
    }
};

// Time: O(n) — you scan each triplet once and do a constant (3) amount of work per triplet.
// Space: O(1) — the unordered_set stores at most 3 indices (fixed size).
