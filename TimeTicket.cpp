//2073 Time needed to buy tickets.
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        bool finished = false;
        while(!finished){
            for (int i = 0; i < tickets.size() && !finished; ++i) {
                if(tickets[i]>0){
                    tickets[i]--;
                    time++;
                }
                if(i == k && tickets[k]==0){
                    finished = true;
                    break;
                }
            }
        }
        return time;
        
    }
};
