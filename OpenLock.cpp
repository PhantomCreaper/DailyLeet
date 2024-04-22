// 752. Open the Lock
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000")){
            return -1;
        }
        if(target == "0000"){
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");

        while(!q.empty()){
            auto [curr, steps] = q.front();
            q.pop();

            vector<string> nextStates = generate(curr);
            for(auto& state:nextStates){
                if(state == target){
                    return steps + 1;
                }
                if(!visited.count(state) && !dead.count(state)){
                    visited.insert(state);
                    q.push({state, steps+1});
                }
            }
        }
        return -1;
    }

    vector<string> generate(string curr){
        vector<string> states;
        for(int i =0; i<4; i++){
            string tmp = curr;
            tmp[i] = (curr[i] - '0' + 1) % 10 + '0';
            states.push_back(tmp);
            tmp[i] = (curr[i] - '0' - 1 + 10) % 10 +'0';
            states.push_back(tmp);
        }
        return states;
    }
};
