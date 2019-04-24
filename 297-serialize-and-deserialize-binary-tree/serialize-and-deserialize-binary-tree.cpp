// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
// Example: 
//
//
// You may serialize the following tree:
//
//     1
//    / \
//   2   3
//      / \
//     4   5
//
// as "[1,2,3,null,null,4,5]"
//
//
// Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
//


class Codec {
private:
    int str2int(string str){
        int res = 0;
        if(str[0] == '-'){
            for(int i = 1; i < str.size(); ++ i){
                res = 10 * res + (str[i] - '0');
            }
            res *= -1;
        }else{
            for(int i = 0; i < str.size(); ++ i){
                res = 10 * res + (str[i] - '0');
            }
        }
        return res;
    }
    vector<string> split(string &str, char ch){
        vector<string> res;
        string tmp;
        for(auto &s: str){
            if(s != ch){
                tmp += s;
            }else{
                res.push_back(tmp);
                tmp.clear();
            }
        }
        if(!tmp.empty())
            res.push_back(tmp);

        return res;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string null = "null";
        if(!root)
            return "[" + null + "]";
        string res;
        vector<string> r;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            queue<TreeNode*> p;
            while(!que.empty()){
                auto top = que.front();
                que.pop();
                if(top){
                    r.push_back(to_string(top->val));
                    p.push(top->left);
                    p.push(top->right);
                }else{
                    r.push_back(null);
                }
            }
            while(!p.empty()){
                que.push(p.front());
                p.pop();
            }
        }
        res += "[";
        for(int i = 0; i < r.size(); ++ i){
            res += r[i];
            if(i < r.size() - 1)
                res += ",";
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data == "[null]")
            return nullptr;
        string str(data.begin() + 1, data.end() - 1);
        auto arr = split(str, ',');
        size_t size = arr.size();
        TreeNode * root = new TreeNode(str2int(arr[0]));
        queue<TreeNode*> que;
        que.push(root);
        for(size_t i = 1; i < size;){
            auto top = que.front();
            que.pop();
            if(top){
                if(arr[i] != "null")
                    top->left = new TreeNode(str2int(arr[i]));
                else
                    top->left = nullptr;
                ++ i;
                if(i < size){
                    if(arr[i] != "null")
                        top->right = new TreeNode(str2int(arr[i]));
                    else
                        top->right = nullptr;
                    ++ i;
                }
                if(top->left)
                    que.push(top->left);
                if(top->right)
                    que.push(top->right);
            }
        }
        return root;
    }
};
