// 78. Subsets
class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& results){
        results.push_back(current);
        for(int i = start; i < nums.size(); i++){
            current.push_back(nums[i]);
            backtrack(nums, i+1, current, results);
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;
        backtrack(nums, 0, current, results);
        return results;
    }
};
