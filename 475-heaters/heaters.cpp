// Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
//
// Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
//
// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
//
// Note:
//
//
// 	Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
// 	Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
// 	As long as a house is in the heaters' warm radius range, it can be warmed.
// 	All the heaters follow your radius standard and the warm radius will the same.
//
//
//  
//
// Example 1:
//
//
// Input: [1,2,3],[2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
//
//
//  
//
// Example 2:
//
//
// Input: [1,2,3,4],[1,4]
// Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
//
//
//  
//


/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 *
 * https://leetcode.com/problems/heaters/description/
 *
 * algorithms
 * Easy (30.80%)
 * Total Accepted:    41.2K
 * Total Submissions: 133.8K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * Winter is coming! Your first job during the contest is to design a standard
 * heater with fixed warm radius to warm all the houses.
 * 
 * Now, you are given positions of houses and heaters on a horizontal line,
 * find out minimum radius of heaters so that all houses could be covered by
 * those heaters.
 * 
 * So, your input will be the positions of houses and heaters seperately, and
 * your expected output will be the minimum radius standard of heaters.
 * 
 * Note:
 * 
 * Numbers of houses and heaters you are given are non-negative and will not
 * exceed 25000.
 * Positions of houses and heaters you are given are non-negative and will not
 * exceed 10^9.
 * As long as a house is in the heaters' warm radius range, it can be warmed.
 * All the heaters follow your radius standard and the warm radius will the
 * same.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3],[2]
 * Output: 1
 * Explanation: The only heater was placed in the position 2, and if we use the
 * radius 1 standard, then all the houses can be warmed.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4],[1,4]
 * Output: 1
 * Explanation: The two heater was placed in the position 1 and 4. We need to
 * use radius 1 standard, then all the houses can be warmed.
 * 
 * 
 */
class Solution {
public:
    int max_(int a, int b){
        return a >= b ? a : b;
    }
    int mix_(int a, int b){
        return a <= b ? a : b;
    }
    int binarySerach(vector<int> &list, int item){
        int n = list.size();
        if(item > list[n - 1]){
            return -(n + 1);
        }else if(item < list[0]){
            return -1;
        }
        int lt = 0, gt = list.size() - 1;
        while(lt < gt){
            int mid = (gt - lt) / 2 + lt;
            if(list[mid] == item){
                return mid;
            }else if(list[mid] > item){
                gt = mid - 1;
            }else{
                lt = mid + 1;
            }
        }
        if(list[lt] > item){
            while(list[lt] > item){
                -- lt;
            }
            return lt + 1;
        }else if(list[lt] < item){
            ++ lt;
        }
        return lt;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = -1;
        for(auto house: houses){
            int index = binarySerach(heaters, house);
            if(index < 0){
                index = -(index + 1);
            }
            int dL = index - 1 >= 0 ? house - heaters[index - 1] : INT32_MAX;
            int dR = index < heaters.size() ? heaters[index] - house : INT32_MAX;
            res = max_(res, mix_(dL, dR));
        }

        return res;
    }
};

