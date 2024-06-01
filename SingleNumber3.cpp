// 260. Single Number III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int num : nums) {
            xorr ^= num;
        }

        int bit = xorr & -xorr;

        int n1 = 0;
        int n2 = 0;
        for (int num : nums) {
            if (num & bit) {
                n1 ^= num;
            } else {
                n2 ^= num;
            }
        }

        return {n1, n2};
    }
};
