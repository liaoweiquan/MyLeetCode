// Suppose we abstract our file system by a string in the following manner:
//
// The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
//
// dir
//     subdir1
//     subdir2
//         file.ext
//
//
// The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
//
// The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
//
// dir
//     subdir1
//         file1.ext
//         subsubdir1
//     subdir2
//         subsubdir2
//             file2.ext
//
//
// The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
//
// We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
//
// Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
//
// Note:
//
// The name of a file contains at least a . and an extension.
// The name of a directory or sub-directory will not contain a ..
//
//
//
// Time complexity required: O(n) where n is the size of the input string.
//
// Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.


class Solution {
private:
	vector<string> split(string str, char ch){
		vector<string> res;
		string tmp;
		for(auto c: str){
			if(c != ch){
				tmp += c;
			}else{
				res.emplace_back(tmp);
				tmp.clear();
			}
		}
		if(!tmp.empty()){
			res.emplace_back(tmp);
		}
		return res;
	}
	int lastIndexOf(string str, char ch){
		for(int i = str.length() - 1; i >= 0; -- i){
			if(str[i] == ch)
				return i;
		}
		return -1;
	}
	bool contain(string str, char ch){
		for(auto s: str){
			if(s == ch)
				return true;
		}
		return false;
	}
public:
    int lengthLongestPath(string input) {
        int res = 0;
        vector<string> sp = split(input, '\n');
        vector<int> sums(sp.size() + 1, 0);
        for(auto s: sp){
        	// cout << s << endl;
        	int lvl = lastIndexOf(s, '\t') + 2;
        	int len = s.length() - lvl + 1;
        	if(contain(s, '.')){
        		res = max(res, sums[lvl - 1] + len);
        	}else{
        		sums[lvl] = sums[lvl - 1] + len + 1;
        	}
        }
        return res;
    }
};
