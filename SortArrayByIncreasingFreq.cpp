// 1636. Sort Arrays By Increasing Frequency
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;

        for (int num : nums) {
            frequencyMap[num]++;
        }

        auto comp = [&frequencyMap](int a, int b) {
            if (frequencyMap[a] == frequencyMap[b]) {
                return a > b;
            }
            return frequencyMap[a] < frequencyMap[b];
        };

        sort(nums.begin(), nums.end(), comp);

        return nums;
    }
};
