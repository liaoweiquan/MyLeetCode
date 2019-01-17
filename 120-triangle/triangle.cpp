// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
    for(int i = 1; i < n; ++ i){
        for(int j = 0; j < triangle[i].size(); ++j){
            if(i == 1){
                triangle[i][j] += triangle[0][0];
            }
            else if(j == 0){
                triangle[i][j] += triangle[i -1][0];
            }
            else if(j == triangle[i].size() - 1){
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else{
                triangle[i][j] += triangle[i - 1][j - 1] < triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j];
            }
        }
    }
    int minx = triangle[n - 1][0];
    for(int k = 1; k < triangle[n - 1].size(); ++k){
        if(minx > triangle[n - 1][k])
            minx = triangle[n - 1][k];
    }
    return minx;
    }
};
