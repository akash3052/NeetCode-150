class Solution {
public:
    int solve(int index, int n, string s, string t, string tempStr){
        if(index >= n){
            return tempStr == t ? 1 : 0;
        }
        if(tempStr == t){
            return 1;
        }
        int take = solve(index + 1, n, s, t, tempStr + s[index]);
        int notTake = solve(index + 1, n, s, t, tempStr);
        return take + notTake;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        return solve(0, n, s, t, "");
    }
};


// Time Limit Exceeded
// 15 / 25 test cases

// TC = O(2 ^ n) 

