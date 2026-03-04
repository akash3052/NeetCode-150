class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int finalRow = -1 ;
        int top = 0, bottom = rows - 1;
        // note -> first search in row in which target value can be present 
        while(top <= bottom){
            int mid = top + (bottom - top)/2;
            if(target > matrix[mid][cols - 1]){
                top = mid + 1;
            }else if(target < matrix[mid][0]){
                bottom = mid - 1;
            }else{
                finalRow = mid;
                break;
            }
        }

        if(finalRow == -1){
            return false;
        }

        // note -> once we have found the row, we will search in that row
        int left = 0, right = cols - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(target > matrix[finalRow][mid]){
                left = mid + 1;
            }else if(target < matrix[finalRow][mid]){
                right = mid - 1;
            }else{
                return true;
            }
        }
        return false;

    }
};

// time complexity =  O(log m + log n)



