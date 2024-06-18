// 826. Most Profit Assigning Work
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        
        for (int i = 0; i < n; ++i) {
            jobs[i] = {difficulty[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end());
        
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        int maxProfitSoFar = 0;
        int j = 0;
        
        for (int i = 0; i < worker.size(); ++i) {
            while (j < n && jobs[j].first <= worker[i]) {
                maxProfitSoFar = max(maxProfitSoFar, jobs[j].second);
                ++j;
            }
            maxProfit += maxProfitSoFar;
        }
        
        return maxProfit;
    }
};
