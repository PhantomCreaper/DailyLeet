// 1438. Longest Continuous Subarray With Absolute Difference Less Than Or Equal To Limit
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, right = 0;
        int longest = 0;
        
        while (right < nums.size()) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                left++;
                if (maxDeque.front() < left) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() < left) {
                    minDeque.pop_front();
                }
            }
            
            // Update the longest length
            longest = max(longest, right - left + 1);
            right++;
        }
        
        return longest;
    }
};
