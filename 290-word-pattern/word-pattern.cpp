// Given a pattern and a string str, find if str follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Example 1:
//
//
// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true
//
// Example 2:
//
//
// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false
//
// Example 3:
//
//
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false
//
// Example 4:
//
//
// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false
//
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
//


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        string s;
        queue<char> que;
        int i = 0;
        while(i <= str.size() - 1){
            que.push(str[i]);
            if(i == str.size() - 1 || (i + 1 <= str.size() - 1 && str[i+1] == ' ')){
                s.clear();
                while(!que.empty()){
                    s.push_back(que.front());
                    que.pop();
                }
                strs.push_back(s);
                i += 2;
            }
            else ++ i;
            
        }
        if(pattern.size() != strs.size()) return false;
        unordered_map<char,string> mpt1;
        unordered_map<string,char> mpt2;
        mpt1.insert(make_pair(pattern[0],strs[0]));
        mpt2.insert(make_pair(strs[0],pattern[0]));
        for(int i = 0; i <= pattern.size() - 1; ++i){
            if(mpt1.find(pattern[i])!=mpt1.end()){
                if(mpt1[pattern[i]] != strs[i])
                    return false;
            }
            if(mpt2.find(strs[i])!=mpt2.end()){
                if(mpt2[strs[i]] != pattern[i])
                    return false;
            }
            else{
                mpt1.insert(make_pair(pattern[i],strs[i]));
                mpt2.insert(make_pair(strs[i],pattern[i]));
            }
        }
        return true;
    }
};
