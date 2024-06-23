// 1248. Nice Sub-arrays
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int countOdd = 0, result = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                countOdd++;
            }
            if (prefixCount.find(countOdd - k) != prefixCount.end()) {
                result += prefixCount[countOdd - k];
            }
            prefixCount[countOdd]++;
        }

        return result;
    }
};
