//
// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
// Example 1:
//
// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two athletes, you just need to output their relative ranks according to their scores.
//
//
//
// Note:
//
// N is a positive integer and won't exceed 10,000.
// All the scores of athletes are guaranteed to be unique.
//
//
//


class Solution {
public:
    string int2str(int n){
        string str = "";
        while(n){
            str += n % 10 + '0';
            n /= 10;
        }
        string re(str.rbegin(),str.rend());
        return re;
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        string str;
        vector<string> strs(n);
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i <= n - 1; ++i)
            pq.push(make_pair(nums[i],i));
        int cnt = 1;
        while(!pq.empty()){
            if(cnt == 1){
                strs[pq.top().second] = "Gold Medal";
                ++ cnt;
            }
            else if(cnt == 2){
                strs[pq.top().second] = "Silver Medal";
                ++ cnt;
            }
            else if(cnt == 3){
                strs[pq.top().second] = "Bronze Medal";
                ++ cnt;
            }
            else{
                strs[pq.top().second] = int2str(cnt);
                ++ cnt;
            }
            
            pq.pop();
        }
        
        return strs;
    }
};
