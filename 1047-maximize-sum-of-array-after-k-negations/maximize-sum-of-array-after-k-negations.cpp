// Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)
//
// Return the largest possible sum of the array after modifying it in this way.
//
//  
//
// Example 1:
//
//
// Input: A = [4,2,3], K = 1
// Output: 5
// Explanation: Choose indices (1,) and A becomes [4,-2,3].
//
//
//
// Example 2:
//
//
// Input: A = [3,-1,0,2], K = 3
// Output: 6
// Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
//
//
//
// Example 3:
//
//
// Input: A = [2,-3,-1,5,-4], K = 2
// Output: 13
// Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
//
//
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 10000
// 	1 <= K <= 10000
// 	-100 <= A[i] <= 100
//
//


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        vector<int> listp, listn;
        int zero = 0;
        for(auto &i: A){
            if(i > 0){
                listp.push_back(i);
            }else if(i < 0){
                listn.push_back(i);
            }else{
                ++ zero;
            }
        }
        sort(listn.begin(),listn.end());
        sort(listp.begin(),listp.end());
        int sum = 0;
        if(listn.empty()){
            for(auto &it: listp){
                    sum += it;
            }
            if(zero > 0 || K % 2 == 0){
                return sum;
            }else{
                return sum - 2 * listp[0];
            }
        }else{
            if(K <= listn.size()){
                for(int i = 0; i < listn.size(); ++ i){
                    if(i < K)
                        sum += -listn[i];
                    else
                        sum += listn[i];
                }
                for(auto &it: listp){
                    sum += it;
                }
                return sum;
            }else{
                for(auto &it: listn){
                    sum += -it;
                }
                for(auto &it: listp){
                    sum += it;
                }
                K -= listn.size();
                if(zero > 0 || K % 2 == 0)
                    return sum;
                else{
                    int minx = min(-listn.back(), listp[0]);
                    return sum - 2 * minx;
                }
            }
        }
    }
};
