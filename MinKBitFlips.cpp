// 995. Minimum Number of K bit Flips
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flip(n + 1, 0);
        int flips = 0, result = 0;
        
        for (int i = 0; i < n; ++i) {
            flips ^= flip[i];
            
            if (nums[i] == flips % 2) {
                if (i + k > n) {
                    return -1;
                }
                
                ++result;
                flips ^= 1;
                flip[i + k] ^= 1;
            }
        }
        
        return result;
    }
};
