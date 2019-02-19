// On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.
//
// Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.
//
// Now, we walk in a clockwise spiral shape to visit every position in this grid. 
//
// Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 
//
// Eventually, we reach all R * C spaces of the grid.
//
// Return a list of coordinates representing the positions of the grid in the order they were visited.
//
//  
//
// Example 1:
//
//
// Input: R = 1, C = 4, r0 = 0, c0 = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]
//
//
//
//
//  
//
// Example 2:
//
//
// Input: R = 5, C = 6, r0 = 1, c0 = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
//
//
//
//
//
//
//  
//
// Note:
//
//
// 	1 <= R <= 100
// 	1 <= C <= 100
// 	0 <= r0 < R
// 	0 <= c0 < C
//
//
//
//


class Solution {
public:
    void direction(vector<int>& dir, int d){
        if(d == 0){
            ++ dir[1];
        }else if(d == 1){
            ++ dir[0];
        }else if(d == 2){
            -- dir[1];
        }else if(d == 3){
            -- dir[0];
        }
    }
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<int> cur(2,0);
        int total = R * C;
        cur[0] = r0;
        cur[1] = c0;
        int dis = 1, odis = 1, dc = 0, direct = 0;
        while(total){
            int i = cur[0], j = cur[1];
            if(0 <= i && i < R && 0 <= j && j < C){
                res.push_back(cur);
                -- total;
            }
            direction(cur, direct);
            -- dis;
            if(dis == 0){
                direct = (1 + direct) % 4;
                ++ dc;
                if(dc % 2 == 0){
                    ++ odis;
                }
                dis = odis;
            }
        }
        return res;
    }
};
