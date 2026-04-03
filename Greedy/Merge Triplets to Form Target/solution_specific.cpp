class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        bool foundx = false, foundy = false, foundz = false;

        for(auto triplet : triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]){
                continue;
            }

            if(triplet[0] == target[0]){
                foundx = true;
            }
            if(triplet[1] == target[1]){
                foundy = true;
            }
            if(triplet[2] == target[2]){
                foundz = true;
            }
            
        }

        return foundx && foundy && foundz;
    }
};


