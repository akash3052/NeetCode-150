class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);
        int left = 0, maxLength = 0;
        for(int right = 0; right < s.size(); right++){
            left = max(left, lastIndex[s[right]] + 1);
              // 🎯 What abov Line Really Means
              // It means:
              // If duplicate is inside current window → move left just after its last occurrence.
              // If duplicate is outside current window → ignore it.
            lastIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};


// 🔥 Complexity Now
// Time: O(n)
// Space: O(1) (since 256 is constant)
// And it’s faster because:
// No hashing
// No collisions
// Pure array access (very fast)



