// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
//
// Return the intersection of these two interval lists.
//
// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
//
//
//  
//
// Example 1:
//
//
//
//
// Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
// Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
//
//
//  
//
// Note:
//
//
// 	0 <= A.length < 1000
// 	0 <= B.length < 1000
// 	0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
//
//
//


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> res;
        int a = A.size(), b = B.size();
        int i = 0, j = 0;
        
        while(i < a && j < b){
            if(A[i].start < B[j].start){
                if(A[i].end < B[j].start){
                    ++ i;
                }else if(A[i].end <= B[j].end){
                    res.push_back(Interval(B[j].start, A[i].end));
                    ++ i;
                }else{
                    res.push_back(Interval(B[j].start, B[j].end));
                    ++ j;
                }
            }else{
                if(B[j].end < A[i].start){
                    ++ j;
                }else if(B[j].end <= A[i].end){
                    res.push_back(Interval(A[i].start, B[j].end));
                    ++ j;
                }else{
                    res.push_back(Interval(A[i].start, A[i].end));
                    ++ i;
                }
            }
        }
        return res;
    }
};
