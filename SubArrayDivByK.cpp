// 974. Subarray Sums Divisible by K
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> remainder;

        remainder[0] = 1;
        
        for(int num:nums){
            sum += num;
            int curr = sum % k;

            if(curr < 0){
                curr += k;
            }

            if(remainder.find(curr) != remainder.end()){
                count += remainder[curr];
            }

            remainder[curr]++;
        }
        return count;
    }
};
