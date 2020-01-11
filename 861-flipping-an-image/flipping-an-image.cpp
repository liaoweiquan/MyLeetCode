// Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.
//
// To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
//
// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
//
// Example 1:
//
//
// Input: [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
//
//
// Example 2:
//
//
// Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
//
//
// Notes:
//
//
// 	1 <= A.length = A[0].length <= 20
// 	0 <= A[i][j] <= 1
//
//


class Solution {
public:
    void func(vector<int> & nums){
        int size = nums.size();
        int lt = 0, gt = size - 1;
        while(lt < gt){

            if(nums[lt] == nums[gt]){
                nums[gt] = nums[gt] == 1 ? 0 : 1;
                nums[lt] = nums[gt];
            }
            ++ lt;
            -- gt;
        }
        if(size % 2 == 1){
            nums[size / 2] = nums[size / 2] == 1 ? 0 : 1;
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        for(auto &a: A){
            func(a);
        }
        return A;
    }
};
