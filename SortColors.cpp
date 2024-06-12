// 75. Sort Colors
class Solution {
private:
    void swap(int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int curr = 0;
        while(curr<=r){
            if(nums[curr] == 0){
                swap(nums[curr], nums[l]);
                curr++;
                l++;
            }
            else if(nums[curr] == 1){
                curr++;
            }
            else{
                swap(nums[curr], nums[r]);
                r--;
            }
        }
    }
    
};
