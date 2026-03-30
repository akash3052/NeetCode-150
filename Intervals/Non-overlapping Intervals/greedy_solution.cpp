class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            int currEnd = intervals[i][1];
            int currStart = intervals[i][0];
            if(currStart < prevEnd){
                count++;
                prevEnd = min(prevEnd, currEnd);
            }else{ // currStart >= prevEnd
                prevEnd = currEnd;
                // Notes: simply extending the chain
                // currStart >= prevEnd and currEnd > currStart -> currEnd > prevEnd
                // so no need of doing prevEnd = max(prevEnd, currEnd) as we know currEnd > prevEnd
            }
        }
        return count;
    }
};



// TC = O(nlogn)
// 🎯 Core Principle
// Overlap → choose best → min
// No overlap → accept new → assign directly
