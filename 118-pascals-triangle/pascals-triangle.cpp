// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vts;
        if(numRows == 0)
            return vts;
        vector<int> vt(1,1);
        vts.push_back(vt);
        if(numRows == 1)
            return vts;
        vt.clear();
        vt = vector<int>(2,1);
        vts.push_back(vt);
        if(numRows == 2)
            return vts;
        // numRows -= 2;
        int cur = 3;
        while(cur <= numRows){
            vt.clear();
            vt.push_back(1);
            for(int i = 1; i < cur - 1; ++ i){
                vt.push_back(vts[cur - 2][i - 1] + vts[cur - 2][i]);
            }
            vt.push_back(1);
            vts.push_back(vt);
            ++ cur;
        }
        return vts;
    }
};
