// Given an integer n, return 1 - n in lexicographical order.
//
// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
//


struct cmp
{
	bool operator()(const string & a, const string & b){
	return a > b;
}
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vec;
        priority_queue<string, vector<string> ,cmp > q;
        for(int i = 1; i <= n; ++ i){
        	q.push(to_string(i));
        }
        // sort(vec.begin(), vec.end());
        vector<int> res;
        // for(auto v: vec){
        // 	// res.emplace_back(stoi(v));
        // }
        while(!q.empty()){
        	res.push_back(stoi(q.top()));
        	q.pop();
        }
        return res;

    }
};
