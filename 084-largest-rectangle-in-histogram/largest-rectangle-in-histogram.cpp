// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//  
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//  
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//  
//
// Example:
//
//
// Input: [2,1,5,6,2,3]
// Output: 10
//
//


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int res = -1, size = heights.size();
        set<int>hs(heights.begin(), heights.end());
        for(auto height: hs){
            int sum = 0;
            for(auto i = 0; i < size; ++ i){
                if(heights[i] >= height){
                    sum += height;

                }else{
                    res = max(res, sum);
                    sum = 0;
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};

