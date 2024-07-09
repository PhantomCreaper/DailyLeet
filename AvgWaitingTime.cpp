// 1701. Average Waiting Time
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long current_time = 0;
        long long total_waiting_time = 0;
        int n = customers.size();
        
        for (int i = 0; i < n; ++i) {
            int arrival_time = customers[i][0];
            int preparation_time = customers[i][1];
            
            current_time = max(current_time, (long long)arrival_time);
            current_time += preparation_time;
            
            long long waiting_time = current_time - arrival_time;
            
            total_waiting_time += waiting_time;
        }
        
        return (double)total_waiting_time / n;
    }
};
