/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(Interval a, Interval b){
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto interval : intervals){
            if(!minHeap.empty() && interval.start >= minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};



// TC = O(n log n)

// Intuition (Interview-ready)
// “I use a min-heap to track end times of ongoing meetings.
// If the next meeting starts after the earliest one ends, I reuse the room; otherwise, I allocate a new room. The heap size gives me the number of rooms required.”

// This problem is about tracking active intervals, and min-heap helps us efficiently reuse the earliest finishing room.












