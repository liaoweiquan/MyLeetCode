// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: [3]
//
// Example 2:
//
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
//


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        if( n == 0) return res;
        int canA = nums[0], canB = nums[0];
        int cntA = 0, cntB = 0;
        for(int num: nums){
            if(num == canA){
                ++ cntA;
                continue;
            }
            if(num == canB){
                ++ cntB;
                continue;
            }
            
            if(cntA == 0){
                canA = num;
                ++ cntA;
                continue;
            }
            if(cntB == 0){
                canB = num;
                ++ cntB;
                continue;
            }
            
            -- cntA;
            -- cntB;
        }
        cntA = 0;
        cntB = 0;
        for(int num: nums){
            if(num == canA)
                ++ cntA;
            else if(num == canB)
                ++ cntB;
        }
        
        if(cntA > n / 3){
            res.push_back(canA);
        }
        if(cntB > n / 3){
            res.push_back(canB);
        }
        return res;
    }
};
