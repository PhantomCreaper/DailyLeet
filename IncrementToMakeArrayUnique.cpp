// 945. Minimum Increments to Make Array Unique
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                int change = (nums[i-1] - nums[i] + 1);
                count += change;
                nums[i] += change;
            }
        }
        return count;
    }
};
