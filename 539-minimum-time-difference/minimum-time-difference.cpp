// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list. 
//
// Example 1:
//
// Input: ["23:59","00:00"]
// Output: 1
//
//
//
// Note:
//
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.
//
//


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int t = 24 * 60;
        int n = timePoints.size();
        vector<int> vec;
        for(auto &timePoint: timePoints){
            vec.push_back(((timePoint[0] - '0') * 10 + (timePoint[1] - '0')) * 60 + (timePoint[3] - '0') * 10 + (timePoint[4] - '0'));
        }
        sort(vec.begin(), vec.end());
        int minx = INT_MAX;
        for(int i = 1; i < n; ++ i){
            minx = min(minx, vec[i] - vec[i - 1]);
        }
        minx = min(minx, 1440 + vec[0] - vec[n - 1]);
        return minx;
    }
};
