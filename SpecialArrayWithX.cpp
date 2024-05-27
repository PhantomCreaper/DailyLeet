// 1608. Special Array with X Elements Greater than or Equal X
class Solution {
public:
    int specialArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); i++){
            int count = nums.size() - (lower_bound(nums.begin(), nums.end(), i) - nums.begin());
            if(count == i){
                return i;
            }
        }
        return -1;
    }
};
