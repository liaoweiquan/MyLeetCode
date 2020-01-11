// We have an array A of integers, and an array queries of queries.
//
// For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  Then, the answer to the i-th query is the sum of the even values of A.
//
// (Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)
//
// Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.
//
//  
//
// Example 1:
//
//
// Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
// Output: [8,6,2,4]
// Explanation: 
// At the beginning, the array is [1,2,3,4].
// After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
// After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
// After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
// After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
//
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 10000
// 	-10000 <= A[i] <= 10000
// 	1 <= queries.length <= 10000
// 	-10000 <= queries[i][0] <= 10000
// 	0 <= queries[i][1] < A.length
//
//


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int size = A.size(),sum = 0;
        vector<bool> E;
        for(auto &a: A){
        	if(a % 2 == 0){
        		E.push_back(true);
        		sum += a;
        	}else{
        		E.push_back(false);
        	}
        }
        for(auto &q: queries){
        	int tmp = A[q[1]] + q[0];
        	if(tmp % 2 == 0){
        		if(E[q[1]]){
        			sum += q[0];
        		}else{
        			E[q[1]] = true;
        			sum += tmp;
        		}
        	}else{
        		if(E[q[1]]){
        			E[q[1]] = false;
        			sum -= A[q[1]];
        		}
        	}
        	A[q[1]] = tmp;
        	res.push_back(sum);
        }
        return res;
    }
};
