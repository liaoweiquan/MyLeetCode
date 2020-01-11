// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//
//
//
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
//
//
//
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//
//


class Solution {
public:
    string frequencySort(string s) {
        int freq[256] = {0};
        for(char ch : s)
            ++ freq[ch];
        int maxn = 0, index = -1;
        string str;
        while(true){
            maxn = 0;
            index = -1;
            for(int i = 0; i < 256; ++i)
                if(freq[i] > maxn){
                    maxn = freq[i];
                    index = i;
                }
            if(index == -1)break;
            else{
                while(freq[index]--)
                    str.push_back(index);
            }
        }
        return str;
    }
};
