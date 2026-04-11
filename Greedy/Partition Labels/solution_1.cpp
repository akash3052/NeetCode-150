class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurence;
        for(int i = 0; i < s.size(); i++){
            lastOccurence[s[i]] = i;
        }
        vector<int> res;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            end = max(end, lastOccurence[s[i]]);
            if(i == end){
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1) (since at most 26 lowercase letters are stored, even though using unordered_map)
