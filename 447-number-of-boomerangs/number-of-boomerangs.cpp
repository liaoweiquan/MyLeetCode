// Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//
// Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
//
// Example:
//
// Input:
// [[0,0],[1,0],[2,0]]
//
// Output:
// 2
//
// Explanation:
// The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
//
//


class Solution {
public:
    int dis(const pair<int, int>&pa, const pair<int, int>&pb){
        return (pa.first - pb.first) * (pa.first - pb.first) + (pa.second - pb.second) * (pa.second - pb.second);
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); ++i){
            unordered_map<int,int> mpt;
            for(int j = 0; j < points.size(); ++j)
                if(j != i)
                    ++ mpt[dis(points[i],points[j])];
            for(unordered_map<int,int>::iterator it = mpt.begin(); it != mpt.end(); ++it){
                if(it->second >= 2)
                    res += (it->second) * (it->second - 1);
            }
        }
        return res;
    }
    
};
