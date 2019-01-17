// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
//
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
// Example 2:
//
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


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
