class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(256, 0);
        int left = 0, maxLength = 0, maxFreq = 0;
        for(int right = 0; right < s.size(); right++){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            while((right - left + 1) - maxFreq > k ){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};


// 🎯 Final Answer
// Time Complexity:
//   O(n)
// Space Complexity:
//   O(1)

// 🚀 Interview-Level Summary
// If interviewer asks:
// Why is this O(n) even with nested loop?
// You say:
// Because both left and right pointers move forward at most n times each. The inner while loop does not reset; it advances left cumulatively. Therefore total operations are linear.
// That answer = strong sliding window understanding 💪
