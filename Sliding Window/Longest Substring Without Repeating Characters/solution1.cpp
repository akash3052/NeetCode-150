class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, n = s.size(), maxUniqueLength = 0;
        unordered_set<char> uniqueChar;
        while(left < n && right < n){
            // note : even if duplicate character will be present in between
            while(uniqueChar.find(s[right]) != uniqueChar.end() ){
                uniqueChar.erase(s[left]);
                left++;
            }
            uniqueChar.insert(s[right]);
            maxUniqueLength = max(maxUniqueLength, right - left + 1);
            right++;
        }
        return maxUniqueLength;
    }
};


// The time complexity is O(n) average.
// Although there is a nested loop, each character is inserted and removed at most once, so total operations are bounded by 2n.
