// Shuffle a set of numbers without duplicates.
//
//
// Example:
//
// // Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
//
// // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
// solution.shuffle();
//
// // Resets the array back to its original configuration [1,2,3].
// solution.reset();
//
// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();
//
//


class Solution {
public:
    vector<int> num_list;
    vector<int> nums_;
    Solution(vector<int> nums) {
        srand(time(NULL));
        this->num_list = vector<int>(nums.begin(), nums.end());
        this->nums_ = vector<int>(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for(int i = 0; i < num_list.size(); ++ i){
            num_list[i] = nums_[i];
        }
        return num_list;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        // vector<int> res(num_list.begin(), num_list.end());
        int n = num_list.size();
        for(int i = n - 1; i > 0; -- i){
            int t = rand() % (i + 1);
            swap(num_list[i], num_list[t]);
        }
        return num_list;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
