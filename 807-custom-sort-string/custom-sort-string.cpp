// S and T are strings composed of lowercase letters. In S, no letter occurs more than once.
//
// S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.
//
// Return any permutation of T (as a string) that satisfies this property.
//
//
// Example :
// Input: 
// S = "cba"
// T = "abcd"
// Output: "cbad"
// Explanation: 
// "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
// Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
//
//
//  
//
// Note:
//
//
// 	S has length at most 26, and no character is repeated in S.
// 	T has length at most 200.
// 	S and T consist of lowercase letters only.
//
//


typedef struct myPair{
    char ch;
    int val;
    myPair(char _ch, int _val): ch(_ch), val(_val){}
}Pair;
bool mycompare(Pair a, Pair b){
    return a.val < b.val;
}
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> mpt;
        int val = 1;
        for(char ch: S){
            mpt[ch] = val ++;
        }
        vector<Pair> inorder;
        vector<char> outorder;
        for(char ch: T){
            if(mpt[ch] != 0){
                Pair p(ch, mpt[ch]);
                inorder.push_back(p);
            }else{
                outorder.push_back(ch);
            }
        }
        sort(inorder.begin(), inorder.end(), mycompare);
        string res = "";
        for(auto p: inorder){
            res += p.ch;
        }
        for(auto ch: outorder){
            res += ch;
        }
        return res;
    }
};
