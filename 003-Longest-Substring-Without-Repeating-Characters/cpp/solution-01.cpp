/**
* Created by yangyangu
* 2017 / 11
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
	    if(s.size()==1) return 1;

	    int cnt=0;
	    int maxn=0;
	    set<char> set1;
	    for(int i=0;i<s.size();i++){
	        for(int j=i;j<s.size();j++){
	            cnt++;
	            set1.insert(s[j]);

	            if(set1.size()!=cnt){
	                cnt=0;
	                if(set1.size()>=maxn) maxn=set1.size();
	                set1.clear();
	                break;
	            }
	        }
	    }
	    return maxn;
	}
};

int main(){
	Solution solution;
	string str = "abcabcbb";
	int len = solution.lengthOfLongestSubstring(str);
	cout << len << endl;
	return 0;
}