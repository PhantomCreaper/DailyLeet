// 330. Patching Array
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long check = 1;
        int count = 0;
        int i = 0;

        while(check <= n){
            if(i < nums.size() && nums[i] <= check){
                check += nums[i];
                i++;
            } else{
                check += check;
                count++;
            }
        }
        return count;
    }
};
