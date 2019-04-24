// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//


class Solution {

public:
    int findMax(vector<int> &height, int start, int end){
        int maxn = height[start];
        int pos = start;
        for(auto i = start + 1; i <= end; ++ i){
            if(height[i] > maxn){
                maxn = height[i];
                pos = i;
            }
        }
        return pos;
    }
    int trap(vector<int>& height) {
        int res = 0,size = height.size();
        for(auto i = 0; i < size; ++ i){
            int left, right;
            int j = findMax(height, 0, i);
            if(j >= 0 && j < size && j != i)
                left = height[j];
            else
                continue;
            j = findMax(height, i, size - 1);
            if(j >= 0 && j < size && j != i)
                right = height[j];
            else
                continue;
            int minx = min(left, right);
            if(minx > height[i])
                res += minx - height[i];
        }
        return res;
    }
};

