// 857, Minimum Cost to hire K workers
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>>workers;
        for(int i =0; i<n; i++){
            workers.emplace_back((double)wage[i]/quality[i], quality[i]);
        }

        sort(workers.begin(), workers.end());

        double minCost = INT_MAX;
        double qualitySum = 0;
        priority_queue<int> pq;

        for(auto& worker:workers){
            double ratio = worker.first;
            int qual = worker.second;

            qualitySum += qual;
            pq.push(qual);

            if(pq.size()>k){
                qualitySum -= pq.top();
                pq.pop();
            }

            if(pq.size()==k){
                minCost = min(minCost, qualitySum * ratio);
            }
        }
        return minCost;
    }
};
