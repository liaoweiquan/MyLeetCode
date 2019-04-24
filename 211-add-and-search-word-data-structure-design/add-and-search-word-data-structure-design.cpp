// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
//


struct TrieNode{
    bool isword;
    unordered_map<char,TrieNode*>next;
    explicit TrieNode():isword(false){
    }
};
class WordDictionary {
private:
    TrieNode * root;
    int size;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
        size = 0;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = root;
        for(auto &ch: word){
            if(! p->next[ch]){
                p->next[ch] = new TrieNode();
            }
            p = p->next[ch];
        }
        // help(word, p, 0);
        p->isword = true;
        ++ size;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        auto p = root;
        return match(word, p, 0);
    }
    bool match(string word, TrieNode * p, int pos){
        if(pos == word.length() && p->isword)
            return true;
        if(pos >= word.length())
            return false;
        if(word[pos] == '.'){
            bool res = false;
            for(auto it = p->next.begin(); it != p->next.end(); ++ it){
                if(p->next[(*it).first])
                    res = res || match(word, p->next[(*it).first], pos + 1);
            }
            return res;
        }else{
            if(! p->next[word[pos]])
                return false;
            else
                return match(word, p->next[word[pos]], pos + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
