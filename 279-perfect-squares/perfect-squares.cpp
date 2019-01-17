// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
//
// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
//
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.


class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>> q;
        q.push(make_pair(n,0));
        vector<bool> visited(n + 1, false);
        visited[n] = true;
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i = 1; ; ++ i){
                int a = num - i * i;
                if(a < 0) break;
                if(a == 0) return step + 1;
                if(!visited[a]){
                    q.push(make_pair(num - i * i, step + 1));
                    visited[num - i * i] = true;
                }
            }
                
            
        }
    }
};
