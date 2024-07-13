// 2751. Robot Collisions
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n);
        for(int i = 0; i < n; i++){
            order[i] = i;
        }

        sort(order.begin(), order.end(), [&positions](int a, int b){
            return positions[a] < positions[b];
        });
        stack<int> st;
        vector<int> survivors;

        for(int i:order){
            if(directions[i] == 'R'){
                st.push(i);
            }
            else{
                while(!st.empty() && healths[st.top()] < healths[i]){
                    healths[i]--;
                    st.pop();
                }
                if(!st.empty() && healths[st.top()] == healths[i]){
                    st.pop();
                }
                else if(!st.empty()){
                    healths[st.top()]--;
                }
                else{
                    survivors.push_back(i);
                }
            }
        }
        while(!st.empty()){
            survivors.push_back(st.top());
            st.pop();
        }

        sort(survivors.begin(), survivors.end());
        vector<int> results;
        for(int i:survivors){
            results.push_back(healths[i]);
        }

        return results;
    }
};
