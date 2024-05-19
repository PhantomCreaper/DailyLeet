// 3068. Find Maximum Sum of Node Values.
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> maxValues(n);

        for(int i = 0; i < n; i++){
            maxValues[i] = (nums[i]^k) - nums[i];
        }
        sort(maxValues.rbegin(), maxValues.rend());

        long long maxSum = 0;
        for(long value:nums){
            maxSum += value;
        }

        for(int i = 0; i < n-1; i += 2){
            long long delta = maxValues[i] + maxValues[i+1];
            if(delta > 0){
                maxSum += delta;
            }
            else{
                break;
            }
        }

        return maxSum;
    }
};
