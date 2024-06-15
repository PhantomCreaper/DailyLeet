// 502. IPO
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = profits.size();
        vector<pair<int, int>> projects(n);

        for(int i = 0; i < n; i++){
            projects[i] = {capital[i], profits[i]};
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap(projects.begin(), projects.end());
        priority_queue<int> maxProfitHeap;

        while(k > 0){
            while(!minCapitalHeap.empty() && minCapitalHeap.top().first <= w){
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }

            if(maxProfitHeap.empty()){
                break;
            }

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
            k--;
        }

        return w;
    }
};
