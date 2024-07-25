// 912. Sort An Array
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void quick(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        int pivot = partition(nums, left, right);
        quick(nums, left, pivot - 1);
        quick(nums, pivot + 1, right);
    }

    int partition(vector<int>&nums, int left, int right){
        int pivot = nums[right];
        int  i = left - 1;
        for(int j = left; j < right; j++){
            if(nums[j] < pivot){
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
};
