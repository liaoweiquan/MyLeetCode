// Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.
//
// Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.
//
//
//
// Example 2:
//
//
// Input: ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
//
//
//
// Example 3:
//
//
// Input: ["a==b","b==c","a==c"]
// Output: true
//
//
//
// Example 4:
//
//
// Input: ["a==b","b!=c","c==a"]
// Output: false
//
//
//
// Example 5:
//
//
// Input: ["c==c","b==d","x!=z"]
// Output: true
//
//
//  
//
// Note:
//
//
// 	1 <= equations.length <= 500
// 	equations[i].length == 4
// 	equations[i][0] and equations[i][3] are lowercase letters
// 	equations[i][1] is either '=' or '!'
// 	equations[i][2] is '='
//
//
//
//
//
//
//


class UnionFind{

private:
    int * parent;
    int * rank;
    int count;

public:
    UnionFind(int count){
        parent=new int[count];
        rank=new int[count];
        this->count=count;
        for(int i=0;i<count;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int find(int p){
        if(p!=parent[p])
            parent[p]=find(parent[p]);
        return parent[p];
    }
    bool isConnected(int p,int q){
        return find(p)==find(q);
    }
    void unionElements(int p,int q){
        int pRoot=find(p);
        int qRoot=find(q);

        if(pRoot==qRoot)
            return;
        if(rank[pRoot]<rank[qRoot])
            parent[pRoot]=qRoot;
        else if(rank[qRoot]<rank[pRoot])
            parent[qRoot]=pRoot;
        else{
            parent[pRoot]=qRoot;
            rank[qRoot]+=1;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(256);
        for(auto it: equations){
            if(it[1] == '='){
                uf.unionElements(it[0],it[3]);
            }
        }
        for(auto it: equations){
            if(it[1] == '!'){
                if(uf.isConnected(it[0],it[3]))
                    return false;
            }
        }
        return true;
    }
};
