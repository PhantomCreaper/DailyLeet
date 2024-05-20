// 1863. Sum of All Subset XOR totals.
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return backtrack(nums, 0, 0);
    }
    int backtrack(vector<int>& nums, int index, int sum){
        if(index == nums.size()){
            return sum;
        }

        int included = backtrack(nums, index+1, sum^nums[index]);
        int excluded = backtrack(nums, index+1, sum);

        return included+excluded;
    }
};
