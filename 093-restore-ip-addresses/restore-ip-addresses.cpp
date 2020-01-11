// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
//
//


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        for(int i = 0; i< n; ++ i){
            for(int j = i; j < n; ++ j){
                if(j == i){
                    mem[i][j] = s[j] - '0';
                }else{
                    int pre = mem[i][j - 1], temp = pre;
                    temp = (s[j] - '0') + temp * 10;
                    if(temp <= 255 && pre > 0)
                        mem[i][j] = temp;
                }
            }
        }
        for(int i = 0; i < n && mem[0][i] != -1; ++ i){
            int first = mem[0][i];
            for(int j = i + 1; j < n && mem[i + 1][j] != -1; ++ j){
                int second = mem[i + 1][j];
                for(int k = j + 1; k < n && mem[j + 1][k] != -1; ++ k){
                    int third = mem[j + 1][k];
                    for(int t = k + 1; t < n && mem[k + 1][t] != -1; ++ t){
                        int fourth = mem[k + 1][t];
                        if(t == n - 1){
                            string str = to_string(first) + "." + to_string(second) + "." + to_string(third) + "." + to_string(fourth);
                            res.push_back(str);
                        }
                    }
                }
            }
        }
        return res;
    }
};
