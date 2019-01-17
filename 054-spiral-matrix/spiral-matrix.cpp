// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> mat;
    	if(matrix.size() == 0) return mat;
        int ul = 0, lc = 0, rc = matrix[0].size() - 1 , dl = matrix.size() - 1;
    	int l = 0, c = 0;
    	int cnt = (rc + 1) * (dl + 1);
    	int ant = 0;
        while(lc <= rc && ul <= dl){
        	

        	for(c = lc; c <= rc && ant < cnt; ++ c){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	c = rc;
        	++ ul;
        	for(l = ul; l <= dl && ant < cnt; ++ l){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	l = dl;
        	-- rc;
        	for(c = rc; c >= lc && ant < cnt; -- c){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	c = lc;
        	-- dl;
        	for(l = dl; l >= ul && ant < cnt; -- l){
        		mat.push_back(matrix[l][c]);
        		++ ant;
        		//cout << l << " " << c << endl;
        	}
        	++ lc;
        	l = ul;
        }

        return mat;
    }
};
