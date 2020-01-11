// Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
//
//
// Example :
// Input: 
// S = "abcde"
// words = ["a", "bb", "acd", "ace"]
// Output: 3
// Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
//
//
// Note:
//
//
// 	All words in words and S will only consists of lowercase letters.
// 	The length of S will be in the range of [1, 50000].
// 	The length of words will be in the range of [1, 5000].
// 	The length of words[i] will be in the range of [1, 50].
//
//


class Solution {
public:
    
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt = 0;
        int len = S.length();
        unordered_map<string,bool>mpt;
        unordered_map<string,bool>mpt_f;
        for(auto word:words){
            if(mpt[word] == true){
                ++ cnt;
                continue;
            }
            if(mpt_f[word] == true){
                continue;
            }
            int i = 0, j = 0;
            int size = word.size();
            while(i < size && j < len){
                while(i < size && j < len && S[j] == word[i]) ++ i, ++ j;
                while(j < len && i < size && S[j] != word[i]) ++ j;
            }
            if(i == size){
                ++ cnt;
                mpt[word] = true;
            }else{
                mpt_f[word] = true;
            }
        }

        return cnt;
    }
};
