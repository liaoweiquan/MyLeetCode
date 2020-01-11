// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
//
// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
//
//
// Example:
// Input: [[1,2], [3], [3], []] 
// Output: [[0,1,3],[0,2,3]] 
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
//
//
// Note:
//
//
// 	The number of nodes in the graph will be in the range [2, 15].
// 	You can print different paths in any order, but you should keep the order of nodes inside one path.
//


class Solution {
public:
    vector<vector<int>> res;
    void search(vector<vector<int>>& graph, vector<int>& vec, int v){
        if(v == graph.size() - 1){
            vec.push_back(v);
            res.push_back(vec);
        }else if(!graph[v].empty()){
            for(auto v1: graph[v]){
                vector<int> temp(vec.begin(), vec.end());
                temp.push_back(v);
                // vec.push_back(v);
                search(graph, temp, v1);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        if(!graph[0].empty()){
            for(auto v: graph[0]){
                vector<int> temp;
                temp.push_back(0);
                search(graph, temp,v);
            }
        }
        
        return res;
    }
};
