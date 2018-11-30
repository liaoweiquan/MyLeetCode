/**
* Created by yangyangu
* 2017 / 11
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> pq;
        int t=0;
        for(int i=0;i<nums1.size();i++){
            t=nums1.at(i);
            pq.push(t);
        }
        for(int i=0;i<nums2.size();i++){
            t=nums2.at(i);
            pq.push(t);
        }
        int cnt=nums1.size()+nums2.size();
        double m=0;
        int n=0;
        if(cnt%2==0)n=cnt/2-1;
        else n=cnt/2;
        int ant=0;
        while(n--){
            pq.pop();
        }

        if(cnt%2==0){
            m=pq.top();
            pq.pop();
            m+=pq.top();
            m/=2;
        }
        else{
            m=pq.top();
        }
        return m;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double res = solution.findMedianSortedArrays(nums1,nums2);
    cout << res << endl;
    return 0;
}