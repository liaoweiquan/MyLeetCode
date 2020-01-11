// There are N network nodes, labelled 1 to N.
//
// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
//
// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.
//
//  
//
// Example 1:
//
//
//
//
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
// Output: 2
//
//
//  
//
// Note:
//
//
// 	N will be in the range [1, 100].
// 	K will be in the range [1, N].
// 	The length of times will be in the range [1, 6000].
// 	All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
//
//


struct Node{
    int v, dis;
    Node(int _v, int _dis): v(_v), dis(_dis){}
};
const int INF = 0x6FFFFFFF;
const int MAXV = 102;
class Solution {
public:
    vector<int> d, num;
    vector<Node> Adj[MAXV];
    vector<bool> inq;
    bool SPFA(int N, int K){
        priority_queue<int, vector<int>, greater<>> Q;
        Q.push(K);
        inq[K] = true;
        ++ num[K];
        while(!Q.empty()){
            int u = Q.top();
            Q.pop();
            inq[u] = false;

            for(int j = 0; j < Adj[u].size(); ++ j){
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if(d[u] + dis < d[v]){
                    d[v] = d[u] + dis;
                    if(!inq[v]){
                        Q.push(v);
                        inq[v] = true;
                        ++ num[v];
                        if(num[v] >= N)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        d = vector<int>(N + 1, INF);
        num = vector<int>(N + 1, 0);
        d[K] = 0;
        inq = vector<bool>(N + 1, false);
        for(auto time: times){
            int u = time[0], v = time[1], dis = time[2];
            Node node(v, dis);
            Adj[u].push_back(node);
        }
        SPFA(N, K);
        int maxn = 0;
        for(int i = 1; i <= N; ++ i){
            maxn = max(maxn, d[i]);
        }
        return maxn == INF ? -1 : maxn;
    }
};
