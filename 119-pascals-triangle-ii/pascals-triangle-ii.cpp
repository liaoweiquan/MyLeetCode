// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
// Note that the row index starts from 0.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 3
// Output: [1,3,3,1]
//
//
// Follow up:
//
// Could you optimize your algorithm to use only O(k) extra space?
//


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vt;
        if(rowIndex < 0)
            return vt;
        vt.push_back(1);
        if(rowIndex == 0)
            return vt;
        vt.push_back(1);
        if(rowIndex == 1)
            return vt;
        int cur = 2;
        while(cur <= rowIndex){
            vector<int> temp(cur + 1, 1);
            for(int i = 1; i < cur; ++i)
                temp[i] = vt[i - 1] + vt[i];
            
            vt.clear();
            vt = vector<int>(temp.begin(), temp.end());
            ++ cur;
        }
        return vt;
    }
};
