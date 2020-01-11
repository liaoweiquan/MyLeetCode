// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//
// Example:
//
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
//
// return 13.
//
//
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ n2.


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            int j = matrix[0].size() - 1;
            for(int i = 0; i < matrix.size(); ++ i){
                while(j >= 0 && matrix[i][j] > mid) -- j;
                cnt += (j + 1);
            }
            if(cnt < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
