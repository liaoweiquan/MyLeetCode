//
// A string S of lowercase letters is given.  We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
//
//
// Example 1:
//
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
//
//
//
// Note:
// S will have length in range [1, 500].
// S will consist of lowercase letters ('a' to 'z') only.
//


class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int i = 0, n = S.size();
        int maxn = 0, state = 0;
        while(i < n){
            if(state == 0){
                int j = n - 1;
                while(j - 1 >= i && S[j] != S[i]) -- j;
                maxn = j;
                state = 1;
            }else if(state == 1){
                for(int j = i + 1; j < maxn; ++ j){
                    int t = n - 1;
                    while(t - 1 >= j && S[t] != S[j]) -- t;
                    if(t > maxn){
                        maxn = t;
                    }
                }
                res.push_back(maxn - i + 1);
                i = maxn + 1;
                state = 0;
            }
        }
        
        return res;
    }
};
