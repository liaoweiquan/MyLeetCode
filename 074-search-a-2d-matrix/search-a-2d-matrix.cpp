// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        for(auto item: matrix){
            if(item.empty())
                continue;
            if(item[0] > target)
                return false;
            if(item[item.size() - 1] < target)
                continue;
            int lt = 0, gt = item.size() - 1;
            while(lt <= gt){
                int mid = lt + (gt - lt) / 2;
                if(item[mid] == target) return true;
                else if(item[mid] > target) gt = mid - 1;
                else lt = mid + 1;
            }
        }
        return false;
    }
};
