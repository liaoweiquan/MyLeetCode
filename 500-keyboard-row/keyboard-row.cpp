// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
//
//  
//
//
//  
//
// Example:
//
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
//  
//
// Note:
//
//
// 	You may use one character in the keyboard more than once.
// 	You may assume the input string will only contain letters of alphabet.
//
//


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> m1;
    m1['Q'] = m1['W'] = m1['E'] = m1['R'] = m1['T'] = m1['Y'] = m1['U'] = m1['I'] = m1['O'] = m1['P'] = 1;
    m1['q'] = m1['w'] = m1['e'] = m1['r'] = m1['t'] = m1['y'] = m1['u'] = m1['i'] = m1['o'] = m1['p'] = 1;
    m1['A'] = m1['S'] = m1['D'] = m1['F'] = m1['G'] = m1['H'] = m1['J'] = m1['K'] = m1['L'] = 2;
    m1['a'] = m1['s'] = m1['d'] = m1['f'] = m1['g'] = m1['h'] = m1['j'] = m1['k'] = m1['l'] = 2;
    m1['Z'] = m1['X'] = m1['C'] = m1['V'] = m1['B'] = m1['N'] = m1['M'] = 3;
    m1['z'] = m1['x'] = m1['c'] = m1['v'] = m1['b'] = m1['n'] = m1['m'] = 3;

    vector<string> vt;
    if(words.size()== 0) return vt;
    for(int i = 0 ; i <= words.size() - 1; ++i){
        int j = 0;
        int cnt = m1[words[i][j]];
        bool is = true;
        for(j = 1; j <= words[i].size() - 1; ++j){
            if(m1[words[i][j]] != cnt){
                is = false;
                break;
            }
        }
        if(is) vt.push_back(words[i]);
    }

    return vt;
    }
};
