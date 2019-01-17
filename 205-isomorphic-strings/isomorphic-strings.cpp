// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// Example 1:
//
//
// Input: s = "egg", t = "add"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
//
//
// Input: s = "paper", t = "title"
// Output: true
//
// Note:
// You may assume both s and t have the same length.
//


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.empty()&&t.empty()) return true;
        if(s.size() != t.size()) return false;
        unordered_map<char,char> mpt1;
        unordered_map<char,char> mpt2;
        //unordered_map<char,char>::iterator it;
        mpt1.insert(make_pair(s[0],t[0]));
        mpt2.insert(make_pair(t[0],s[0]));
        for(int i = 1; i <= s.size() - 1; ++i){
            if(mpt1.find(s[i]) != mpt1.end()){
                if(t[i] != mpt1[s[i]])
                    return false;
            }
            if(mpt2.find(t[i]) != mpt2.end()){
                if(s[i] != mpt2[t[i]])
                    return false;
            }
            
            else{
                mpt1.insert(make_pair(s[i],t[i]));
                mpt2.insert(make_pair(t[i],s[i]));
            }
        }
        
        return true;
    }
};
