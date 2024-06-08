// 523. Continuous SUbarray Sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> index;
        index[0] = -1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int remainder = k == 0 ?  sum : sum%k;
            if(remainder < 0){
                remainder += k;
            }
            if(index.find(remainder) != index.end()){
                if(i - index[remainder] > 1){
                    return true;
                }
                else{
                    index[remainder] = i;
                }
            }
        }
        return false;
    }
};
